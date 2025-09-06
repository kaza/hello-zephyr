# ESP32-C6 Project Worklog

## 2025-01-06: ESP32-C6 Bare Module Issues

### Problem: Cannot get Zephyr application to run on ESP32-C6-WROOM-1 module

**Hardware:** ESP32-C6-WROOM-1 bare module (not a development board)

### Symptoms:
- Flashing succeeds (esptool reports success)
- Only bootloader messages appear: `[esp32c6] [INF] padd: lma 0x000107f0 vma 0x00000000 len 0xf808`
- No application output (no printk messages)
- Serial shows garbage or bootloader output only

### Root Cause Analysis:

**1. Hardware Difference**
- **Have:** Bare ESP32-C6-WROOM-1 module
- **Expected:** ESP32-C6 DevKit with built-in USB-UART bridge
- **Missing:** Auto-reset circuit, proper boot strapping pins

**2. Boot Mode Problem**
- ESP32-C6 requires GPIO9 pin configuration for boot mode
- Without proper pull-up resistor, module stays in bootloader mode
- Cannot transition from bootloader to application

**3. Missing Components on Bare Module:**
- No USB-to-UART converter (CP2102/CH340)
- No auto-reset circuit (DTR/RTS control)
- No boot mode selection resistors
- No power supply capacitors
- No reset button

### What We Tried:
1. ✅ Basic LED blink code with Device Tree
2. ✅ Simplified code without GPIO (serial only)
3. ✅ Ultra-simple test (just printk counter)
4. ✅ Different baud rates (115200, 74880)
5. ✅ Manual reset (unplug/replug)
6. ❌ All attempts failed - stuck in bootloader

### Solution Required:
To use bare ESP32-C6-WROOM-1 module, need:
1. External pull-up resistor (10kΩ) on GPIO9 to 3.3V
2. Pull-up resistor on EN (chip enable) pin
3. Proper power supply with capacitors
4. Manual boot sequence control
5. OR: Get a proper ESP32-C6 DevKit board

### Workaround:
- **Switch to STM32 NUCLEO-F401RE** - has all required components built-in
- **Get ESP32-C6 DevKit** instead of bare module
- **Build custom PCB** with required support components

### Status: ⚠️ Blocked - Hardware limitation
**Decision:** Proceed with STM32 for tutorial, revisit ESP32 when proper DevKit available