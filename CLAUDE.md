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

### RULE #3: DOCUMENT DECISIONS
- Document design decisions, technical context, and known issues
- Create/update local documentation as needed
- Track what worked, what didn't, and why

### 🎓 TUTORIAL PROJECT WORKFLOW
**ALWAYS explain what you're doing and WHY:**
- This is a learning project - user needs to understand each step
- Communicate in bullet points to avoid overwhelming
- Show relevant outputs and let user ask follow-up questions
- Focus on teaching Zephyr concepts through practical examples

## Project Overview
This is a Zephyr RTOS learning project focused on embedded systems development.

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
# Initialize workspace
west init -m https://github.com/zephyrproject-rtos/zephyr --mr main

# Update modules
west update

# Build for a specific board (example: qemu_cortex_m3)
west build -b qemu_cortex_m3 samples/hello_world

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