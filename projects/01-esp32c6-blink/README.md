# ESP32-C6 LED Blink

## Hardware Setup

### Connection
1. **Connect USB-C cable** to ESP32-C6 DevKit
2. The board has built-in USB-to-UART (no extra hardware needed!)
3. LED is built-in on GPIO8

### Find Your Port
```bash
# Before connecting ESP32
ls /dev/tty.*

# After connecting ESP32
ls /dev/tty.*
# Look for new device like: /dev/tty.usbserial-XXXX
```

## Build & Flash

```bash
# 1. Activate environment
source ~/zephyr-venv/bin/activate
export ZEPHYR_BASE=~/zephyrproject/zephyr

# 2. Build
cd projects/01-esp32c6-blink
west build -b esp32c6_devkitc

# 3. Flash (replace XXXX with your port)
west flash --esp-device /dev/tty.usbserial-XXXX

# 4. Monitor output
screen /dev/tty.usbserial-XXXX 115200
# Exit screen: Ctrl+A, then K, then Y
```

## Troubleshooting

- **Permission denied**: `sudo chmod 666 /dev/tty.usbserial-XXXX`
- **Device not found**: Check USB cable, try different port
- **Build fails**: Make sure ESP32 toolchain is installed