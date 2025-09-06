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
west init ~/zephyrproject -m https://github.com/zephyrproject-rtos/zephyr --mr v3.7.0
cd ~/zephyrproject
west update
```
**Why:** Downloads Zephyr v3.7.0 LTS source code and modules
**Location:** `~/zephyrproject/`
**Decision:** Using v3.7.0 LTS for stability and long-term support (until ~2029)

### Step 5: Install Python Dependencies
**Command to run:**
```bash
pip3 install --user -r ~/zephyrproject/zephyr/scripts/requirements.txt
```
**Why:** Python tools for building and flashing
**Location:** `~/.local/` (Python user packages)

### Step 1 Status: ✅ Completed
- All system dependencies installed via Homebrew

### Step 2 Status: ✅ Completed  
- West v1.4.0 installed via pipx
- Location: `/opt/homebrew/bin/west`

### Step 3 Status: ✅ Completed
- Zephyr SDK 0.16.8 downloaded and extracted
- Location: `~/zephyr-sdk-0.16.8/`
- CMake package registered

### Step 4 Status: ✅ Completed
- Initialized workspace with v3.7.0 LTS
- Downloaded all modules (~7GB total)
- Location: `~/zephyrproject/`
- Cleaned up SDK archive (saved 1GB)

### Step 5 Status: ✅ Completed
- Created Python virtual environment: `~/zephyr-venv`
- Installed all Python dependencies
- **To activate env:** `source ~/zephyr-venv/bin/activate`
- **Note:** Always activate this venv before building Zephyr projects!