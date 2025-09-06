# Zephyr Installation Worklog

## 2025-01-06: Zephyr SDK Installation on macOS ARM64

### Step 1: Install System Dependencies (via Homebrew)
**Commands to run:**
```bash
# Check if these are already installed
brew list cmake ninja gperf python3 ccache qemu dtc wget

# Install missing ones
brew install cmake ninja gperf python3 ccache qemu dtc wget
```
**Why:** Build tools and QEMU emulator for testing without hardware
**Location:** `/opt/homebrew/` (global)

### Step 2: Install West (Zephyr meta-tool)
**Command to run:**
```bash
pip3 install --user west
```
**Why:** Manages Zephyr source code and dependencies
**Location:** `~/.local/bin/west`

### Step 3: Download Zephyr SDK
**Commands to run:**
```bash
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.8/zephyr-sdk-0.16.8_macos-aarch64.tar.xz
tar xvf zephyr-sdk-0.16.8_macos-aarch64.tar.xz
cd zephyr-sdk-0.16.8
./setup.sh
```
**Why:** Cross-compilation toolchains for ARM/ESP32
**Location:** `~/zephyr-sdk-0.16.8/`

### Step 4: Initialize Zephyr Workspace
**Commands to run:**
```bash
cd ~
west init ~/zephyrproject
cd ~/zephyrproject
west update
```
**Why:** Downloads Zephyr source code and modules
**Location:** `~/zephyrproject/`

### Step 5: Install Python Dependencies
**Command to run:**
```bash
pip3 install --user -r ~/zephyrproject/zephyr/scripts/requirements.txt
```
**Why:** Python tools for building and flashing
**Location:** `~/.local/` (Python user packages)

### Step 1 Status: ⏳ In Progress

**Checked:** Python3 ✅, gperf ✅
**Missing:** cmake, ninja, ccache, qemu, dtc, wget
**Action:** User needs to run: `brew install cmake ninja ccache qemu dtc wget`