# Hello Zephyr

Learning project for Zephyr RTOS development.

## Setup

1. Install Zephyr SDK and dependencies:
```bash
# macOS
brew install cmake ninja gperf python3 ccache qemu dtc wget libmagic

# Install West
pip3 install west
```

2. Initialize Zephyr workspace:
```bash
west init ~/zephyrproject
cd ~/zephyrproject
west update
```

3. Set up environment:
```bash
export ZEPHYR_BASE=~/zephyrproject/zephyr
source $ZEPHYR_BASE/zephyr-env.sh
```

## Building

```bash
# Build for QEMU Cortex-M3
west build -b qemu_cortex_m3

# Run in QEMU
west build -t run
```

## Project Structure

- `src/main.c` - Main application code
- `prj.conf` - Kernel configuration
- `CMakeLists.txt` - Build configuration
- `CLAUDE.md` - Development notes and commands