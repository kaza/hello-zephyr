# ESP32-C6 Counter Program
# This runs forever, printing counter every second

import time

counter = 0
print("\n=== ESP32-C6 Counter Started ===")

while True:
    print(f"Counter: {counter}")
    counter += 1
    time.sleep(1)