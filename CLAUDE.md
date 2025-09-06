# Zephyr RTOS Development Project - Claude AI Assistant Guide

This file provides guidance to Claude when working with this Zephyr learning repository.

## 🚨 CRITICAL INTERACTION RULES 🚨

### RULE #0: KEEP ANSWERS SHORT AND DIRECT
- Answer in 1-3 sentences MAX
- Show code/commands directly without explanation unless asked
- Let user ask for more details if needed
- NO walls of text

### RULE #1: COMMIT REMINDER
- After implementing ANY meaningful feature, remind user to commit
- Suggest clear commit messages
- Don't let work pile up uncommitted

### RULE #2: ASK PERMISSION BEFORE CHANGES
- When user asks questions, ANSWER FIRST
- EXPLAIN the issue/solution
- ASK "Would you like me to fix/implement this?"
- WAIT for explicit approval before making changes

### RULE #3: DOCUMENT EVERYTHING - STRUCTURED APPROACH

**Documentation File Structure:**
```
workspace/
├── CLAUDE-INDEX.md      # Single master index at root - maps ALL documentation
├── CLAUDE.md            # Workspace-level rules and setup
└── any-directory/
    ├── CLAUDE.md        # Technical decisions, architecture, design choices
    └── WORKLOG.md       # Chronological log: attempts, errors, solutions
```

**WORKLOG.md Format:**
```markdown
## YYYY-MM-DD: Task Description
- **Tried:** Command or approach attempted
- **Error:** What went wrong
- **Solution:** What fixed it
- **Workaround:** Temporary fix if needed
- **Status:** ✅ Working / ❌ Failed / ⚠️ Partial
```

**Documentation Rules:**
1. ONE CLAUDE-INDEX.md at root - update when adding ANY documentation
2. Each directory gets its own CLAUDE.md (design) and WORKLOG.md (progress)
3. Document immediately - especially failures (prevents repeating mistakes)
4. Keep entries dated and searchable

### RULE #4: INSTALLATION TRANSPARENCY
**Before installing ANYTHING:**
- Tell user WHAT will be installed
- WHERE it will be installed (prefer LOCAL installations)
- WHY it's needed
- Document in WORKLOG.md immediately after

**Installation Policy:**
- SDK/Toolchains → LOCAL in user home (`~/`)
- Python packages → LOCAL with `--user` flag
- System tools (cmake, ninja) → Global via brew only when necessary
- Document exact paths and versions installed

### 🎓 TUTORIAL PROJECT WORKFLOW
**ALWAYS explain what you're doing and WHY:**
- This is a learning project - user needs to understand each step
- Communicate in bullet points to avoid overwhelming
- Show relevant outputs and let user ask follow-up questions
- Focus on teaching Zephyr concepts through practical examples

## Project Overview
This is a Zephyr RTOS learning project focused on embedded systems development.

### Version Information
- **Zephyr RTOS:** v3.7.0 LTS (Long Term Support until ~2029)
- **Zephyr SDK:** v0.16.8 (Latest stable SDK)
- **West:** v1.4.0

### Hardware Boards

#### ⚠️ ESP32-C6-WROOM-1 (BARE MODULE - ISSUES)
- **Type:** Bare module, NOT a development board
- **Board identifier:** `esp32c6_devkitc` (requires DevKit, not bare module!)
- **Features:** WiFi 6, BLE 5.3, 320KB RAM, 4MB Flash
- **STATUS:** ❌ Not working with Zephyr - stuck in bootloader
- **Issue:** Bare module lacks USB-UART bridge, auto-reset circuit, boot resistors
- **Solution:** Need proper ESP32-C6 DevKit or external circuitry
- **See:** `projects/01-esp32c6-blink/WORKLOG.md` for details

#### ✅ STM32 NUCLEO-F401RE (RECOMMENDED)
- **Type:** Complete development board with built-in debugger
- **Board identifier:** `nucleo_f401re`
- **Features:** 84MHz Cortex-M4, 96KB RAM, 512KB Flash, Arduino headers
- **Built-in:** ST-Link debugger, USB serial, LED, reset button
- **STATUS:** Ready to use - no additional hardware needed

#### QEMU
- For simulation/testing without hardware

## Workspace Structure
```
hello-zephyr/
├── projects/              # Individual learning projects
│   ├── 00-hello/         # Toolchain verification (QEMU & ESP32)
│   ├── 01-blink/         # LED control basics
│   ├── 02-serial/        # UART communication
│   ├── 03-wifi/          # ESP32 WiFi experiments
│   └── ../               # More projects as we learn
├── shared/               # Reusable code and configurations
│   ├── boards/          # Custom board definitions
│   └── lib/             # Shared libraries
├── CLAUDE.md            # Workspace documentation
└── README.md            # Project overview
```

### Project Naming Convention
- `00-99`: Numbered by complexity/order
- Descriptive names after number
- Each project is self-contained with own `CMakeLists.txt` and `prj.conf`

## Development Environment

### Prerequisites
- Zephyr SDK or compatible toolchain
- West (Zephyr's meta-tool)
- CMake (3.20.5+)
- Python (3.8+)
- Device Tree Compiler (dtc)

### Key Commands
```bash
# ALWAYS activate Python environment first!
source ~/zephyr-venv/bin/activate

# Set Zephyr environment
export ZEPHYR_BASE=~/zephyrproject/zephyr

# Build for a specific board (example: qemu_cortex_m3)
west build -b qemu_cortex_m3

# Flash to device
west flash

# Run in QEMU
west build -t run

# Clean build
west build -t pristine

# Check code style
python3 scripts/checkpatch.pl

# Run tests
west twister
```

## Project Structure
```
hello-zephyr/
├── src/           # Application source code
│   └── main.c     # Main application entry point
├── prj.conf       # Kernel configuration
├── CMakeLists.txt # Build configuration
├── boards/        # Board-specific configurations
├── dts/           # Device tree overlays
└── include/       # Header files
```

## Common Zephyr Concepts
- **Device Tree**: Hardware description
- **Kconfig**: Kernel configuration system
- **West**: Meta-tool for managing repos and builds
- **Board Support**: Target hardware definitions
- **Subsystems**: Bluetooth, USB, Networking, etc.

## Useful Resources
- [Zephyr Documentation](https://docs.zephyrproject.org/)
- [Zephyr Samples](https://github.com/zephyrproject-rtos/zephyr/tree/main/samples)
- [Device Tree Guide](https://docs.zephyrproject.org/latest/build/dts/index.html)
- [Kconfig Reference](https://docs.zephyrproject.org/latest/build/kconfig/index.html)