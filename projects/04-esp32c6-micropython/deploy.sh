#!/bin/bash

echo "======================================="
echo "   ESP32-C6 Counter Deploy Script"
echo "======================================="
echo ""

# Activate Python environment
source ~/zephyr-venv/bin/activate

# Install ampy if not installed
pip list | grep adafruit-ampy > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Installing ampy..."
    pip install adafruit-ampy -q
fi

echo "Deploying counter.py as main.py..."

# Use ampy to upload the file
ampy --port /dev/cu.usbmodem11401 put counter.py main.py 2>/dev/null

# If ampy fails, try direct method
if [ $? -ne 0 ]; then
    echo "Ampy failed, trying direct upload..."
    python3 << 'EOF'
import serial
import time

ser = serial.Serial('/dev/cu.usbmodem11401', 115200)
time.sleep(2)

# Stop any running code
ser.write(b'\x03\x03')
time.sleep(0.5)
ser.read_all()

# Read counter.py content
with open('counter.py', 'r') as f:
    code = f.read()

# Write as main.py using paste mode
ser.write(b'\x05')  # Enter paste mode
ser.write(b"f = open('main.py', 'w')\n")
for line in code.split('\n'):
    ser.write(f"f.write('{line}\\n')\n".encode())
ser.write(b"f.close()\n")
ser.write(b'\x04')  # Execute
time.sleep(1)

# Soft reset to run main.py
ser.write(b'\x04')
ser.close()
EOF
fi

echo ""
echo "======================================="
echo "         DEPLOYMENT COMPLETE!"
echo "======================================="
echo ""
echo "To see the counter running:"
echo "  screen /dev/cu.usbmodem11401 115200"
echo ""
echo "To exit screen:"
echo "  Press Ctrl-A, then K, then Y"
echo ""
echo "The counter will run automatically on boot!"