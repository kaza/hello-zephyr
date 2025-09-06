# MDB Sniffer Project - Master Documentation

## 🎯 Project Goal
Build a passive MDB bus sniffer that monitors vending machine communication and reports captured data over WiFi.

---

## 📦 HARDWARE INVENTORY

### ✅ WORKING HARDWARE (In Hand)

#### STM32 NUCLEO-F401RE
- **Status:** FULLY WORKING with Zephyr
- **Board ID:** `nucleo_f401re`
- **Features:** 84MHz Cortex-M4, 96KB RAM, 512KB Flash
- **Projects Completed:**
  - 02-nucleo-blink (dynamic speed LED)
  - 03-nucleo-button (button-controlled speed)
- **Can Complete:** Sessions 1-8 of curriculum (all non-WiFi Zephyr)
- **Limitations:** No WiFi, no 9-bit UART

#### ESP32-C6-WROOM-1 DevKit
- **Status:** Working (NOT with Zephyr - bootloader incompatible)
- **Problem Diagnosed:** Zephyr RISC-V bootloader breaks C6 revision 0.1
- **Solution:** Use with Arduino IDE or ESP-IDF
- **Good For:** MDB protocol learning, WiFi 6 projects
- **Recovery:** Flash erased with esptool, fully functional

#### Qwiic MDB-USB Interface
- **Status:** READY TO USE
- **Purpose:** MDB master controller (simulates vending machine)
- **Includes:** 24V power supply
- **Use:** Generate test MDB traffic

### 📦 ORDERED HARDWARE (In Transit)

#### DIYMORE ESP32-S3 DevKitC-1 N16R8 (2-Pack)
- **Ordered:** 2025-09-06
- **Features:** Dual USB-C, 16MB Flash + 8MB PSRAM, 3 UARTs
- **Why S3 Works:** Xtensa architecture (mature Zephyr support)
- **Purpose:** Final MDB sniffer implementation

#### ARCELI MAX485 Modules (5-Pack)
- **Ordered:** 2025-09-06  
- **Model:** 5V MAX485 Module TTL to RS485
- **Purpose:** Convert MDB differential signals to UART
- **Quantity:** 5 pieces

---

## 📚 LEARNING CURRICULUM WITH ESTIMATES

### PHASE 1: Zephyr Fundamentals (Weeks 1-3)
Using STM32 NUCLEO-F401RE

#### Session 1: Advanced GPIO & Interrupts
- **Time:** 3-4 hours
- **Lines of Code:** ~150
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "GPIO interrupts STM32", "button debouncing", "interrupt priority ARM"
- **Concepts:** ISR handling, atomic operations, debouncing

#### Session 2: UART Deep Dive  
- **Time:** 4-5 hours
- **Lines of Code:** ~200
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "UART protocol explained", "RS232 vs RS485", "9-bit UART"
- **Concepts:** Baud rates, flow control, DMA transfers

#### Session 3: Threads & RTOS
- **Time:** 5-6 hours
- **Lines of Code:** ~250
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "RTOS fundamentals", "FreeRTOS threads", "message queues embedded"
- **Concepts:** Scheduling, priorities, IPC mechanisms

#### Session 4: Ring Buffers & DMA
- **Time:** 4-5 hours
- **Lines of Code:** ~180
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "circular buffer implementation", "DMA STM32", "lock-free programming"
- **Concepts:** Memory management, cache coherency

#### Session 5: Power Management
- **Time:** 3-4 hours
- **Lines of Code:** ~120
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "STM32 low power modes", "wake on interrupt", "power profiling embedded"
- **Concepts:** Sleep states, wake sources, consumption measurement

#### Session 6: Device Tree Mastery
- **Time:** 4-5 hours
- **Lines of Code:** ~100 (mostly configuration)
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "device tree tutorial", "Zephyr device tree", "pin multiplexing"
- **Concepts:** Hardware abstraction, overlays, bindings

#### Session 7: Advanced Logging
- **Time:** 2-3 hours
- **Lines of Code:** ~100
- **Complexity:** ⭐ (Low)
- **YouTube Keywords:** "embedded logging best practices", "RTT debugging", "log levels"
- **Concepts:** Debug channels, filtering, performance impact

#### Session 8: State Machines
- **Time:** 4-5 hours
- **Lines of Code:** ~200
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "finite state machine C", "protocol state machine", "event driven programming"
- **Concepts:** State patterns, transition tables, error recovery

### PHASE 2: MDB Protocol (Week 4)
Theory & simulation (no special hardware needed)

#### Session 9: MDB Fundamentals
- **Time:** 3-4 hours
- **Lines of Code:** ~150
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "MDB protocol vending", "RS485 protocol", "9-bit serial communication"
- **Resources:** NAMA MDB 4.3 specification PDF
- **Concepts:** Master/slave, checksums, addressing

#### Session 10: Device Types
- **Time:** 2-3 hours
- **Lines of Code:** ~100 (data structures)
- **Complexity:** ⭐ (Low)
- **YouTube Keywords:** "vending machine technology", "bill validator MDB", "cashless payment vending"
- **Concepts:** Device addressing, capabilities, responses

#### Session 11: Transaction Flow
- **Time:** 4-5 hours
- **Lines of Code:** ~300
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "vending machine payment flow", "MDB session", "protocol timing diagrams"
- **Concepts:** Session management, timeouts, error handling

#### Session 12: QEMU Testing
- **Time:** 3-4 hours
- **Lines of Code:** ~200
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "QEMU serial port", "virtual serial testing", "protocol simulation"
- **Concepts:** Virtual hardware, test automation

### PHASE 3: WiFi & Networking (Week 5)
Using ESP32-S3 when arrives

#### Session 13: WiFi Basics
- **Time:** 3-4 hours
- **Lines of Code:** ~150
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "ESP32 WiFi programming", "WiFi provisioning", "mDNS embedded"
- **Concepts:** Connection management, security, discovery

#### Session 14: WebSocket Server
- **Time:** 5-6 hours
- **Lines of Code:** ~250
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "WebSocket protocol", "real-time embedded web", "binary WebSocket frames"
- **Concepts:** HTTP upgrade, frame encoding, keepalive

#### Session 15: Data Persistence
- **Time:** 3-4 hours
- **Lines of Code:** ~180
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "ESP32 NVS storage", "flash wear leveling", "SPIFFS filesystem"
- **Concepts:** Flash management, data structures, recovery

#### Session 16: OTA Updates
- **Time:** 4-5 hours
- **Lines of Code:** ~200
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "ESP32 OTA update", "firmware rollback", "secure boot"
- **Concepts:** Dual partition, verification, rollback

### PHASE 4: Integration (Week 6)
Final MDB sniffer assembly

#### Session 17: Hardware Setup
- **Time:** 2-3 hours
- **Lines of Code:** ~50
- **Complexity:** ⭐ (Low - mostly wiring)
- **YouTube Keywords:** "MAX485 wiring", "RS485 termination", "differential signaling"
- **Concepts:** Impedance matching, isolation, grounding

#### Session 18: Passive Monitoring
- **Time:** 3-4 hours
- **Lines of Code:** ~150
- **Complexity:** ⭐⭐ (Medium)
- **YouTube Keywords:** "passive network tap", "high impedance monitoring", "signal integrity"
- **Concepts:** Non-intrusive tapping, signal quality

#### Session 19: Protocol Decoder
- **Time:** 6-8 hours
- **Lines of Code:** ~400
- **Complexity:** ⭐⭐⭐⭐ (Very High)
- **YouTube Keywords:** "protocol analyzer design", "packet decoder", "real-time parsing"
- **Concepts:** Pattern matching, correlation, timing analysis

#### Session 20: System Integration
- **Time:** 4-5 hours
- **Lines of Code:** ~200
- **Complexity:** ⭐⭐⭐ (High)
- **YouTube Keywords:** "embedded system integration", "field deployment", "remote monitoring"
- **Concepts:** Reliability, maintenance, monitoring

### TOTAL ESTIMATES
- **Total Time:** 75-95 hours (3-4 hours/day = 4-5 weeks)
- **Total Lines of Code:** ~3,500-4,000
- **Prerequisite Knowledge:** Basic C programming, basic electronics
- **Difficulty Progression:** Gradual increase from simple GPIO to complex protocol analysis

---

## 🔧 TECHNICAL DETAILS

### MDB Bus Specifications
- **Electrical:** RS485-like differential (MDB+/MDB-)
- **Protocol:** 9-bit UART, 9600 baud, 1 start, 8 data, 1 mode/address bit
- **Voltage:** 24V DC power, 5V logic
- **Topology:** Multi-drop bus, up to 32 devices
- **Master:** VMC (Vending Machine Controller)
- **Slaves:** Peripherals with addresses 08H-6FH

### Why MAX485 Required
```
MDB Bus (Differential)    MAX485 Chip    ESP32 (Single-ended)
MDB+ ←→                    A ←→ IC ←→     RX pin
MDB- ←→                    B ←→           TX pin
                                          DE/RE (direction)
```

### ESP32 Architecture Comparison
| Chip | Architecture | Zephyr Status | Use Case |
|------|-------------|---------------|----------|
| C6 | RISC-V | Broken | Arduino/ESP-IDF only |
| S3 | Xtensa | Stable | Perfect for Zephyr |

---

## 🐛 DIAGNOSED ISSUES

### ESP32-C6 + Zephyr = Incompatible
- **Root Cause:** Zephyr's 2nd stage bootloader incompatible with C6 rev 0.1
- **Symptoms:** Flash succeeds, board won't boot, USB disappears
- **Fix Applied:** Erased flash with `esptool.py --chip esp32c6 erase_flash`
- **Resolution:** C6 works perfectly with Arduino/ESP-IDF, just not Zephyr

---

## 🗂️ PROJECT STRUCTURE

```
hello-zephyr/
├── PROJECT-DOCUMENTATION.md    # THIS FILE - Master reference
├── CLAUDE.md                   # AI assistant rules
├── projects/
│   ├── 02-nucleo-blink/       # ✅ Completed
│   ├── 03-nucleo-button/      # ✅ Completed  
│   └── 04-nucleo-interrupts/  # Next session
└── build.sh                    # Build helper scripts
```

---

## ✅ SUCCESS METRICS
- [ ] Capture 100% of MDB bus traffic
- [ ] Decode all standard MDB commands
- [ ] Stream via WiFi in real-time
- [ ] 24/7 operation stability
- [ ] Web dashboard visualization

---

## 📝 NOTES
- Total hardware investment: ~$100
- ESP32-C6 can be used for non-Zephyr MDB work
- STM32 NUCLEO handles 80% of Zephyr learning
- ESP32-S3 will complete the final 20% + integration