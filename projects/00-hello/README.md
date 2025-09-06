# 00-hello: Toolchain Verification

Simple hello world to verify Zephyr toolchain is working.

## Building for QEMU (no hardware needed!)

```bash
cd projects/00-hello
west build -b qemu_cortex_m3
```

## Running in QEMU

```bash
west build -t run
```

Press `Ctrl+A` then `X` to exit QEMU.

## Building for ESP32

```bash
west build -b esp32_devkitc_wroom
```

## What This Tests
- Toolchain installation
- CMake configuration  
- Console output
- Basic kernel APIs (k_sleep, printk)