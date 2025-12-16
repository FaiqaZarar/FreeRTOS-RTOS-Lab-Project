# Real-Time Operating System Lab Project
### FreeRTOS Implementation on RISC-V Architecture

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-RISC--V-blue.svg)](https://riscv.org/)
[![FreeRTOS](https://img.shields.io/badge/FreeRTOS-Kernel-green.svg)](https://www.freertos.org/)

---

## Project Overview

This project demonstrates the implementation and extension of **FreeRTOS**, a real-time operating system, on the **RISC-V RV32** architecture using **QEMU** emulation. The project explores real-time scheduling, task creation, priority handling, inter-task communication, synchronization mechanisms, and intentional deadlock scenarios.

### Academic Information
- **Course**: Operating Systems Lab
- **Institution**: School of Interdisciplinary Engineering & Sciences, National University of Sciences and Technology (NUST)
- **Program**: BS Bioinformatics UG-1
- **Date**: December 17, 2025

### Team Members
- Namra Basharat (476203)
- Faiqa Zarar Noor (471543)
- Alishbah Sajid (482058)
- Ghania Munir (460673)

---

##  Project Objectives

1. **Understand RTOS Fundamentals**: Study the architecture and scheduling mechanisms of real-time operating systems
2. **Implement Custom Tasks**: Create and integrate custom tasks into the FreeRTOS framework
3. **Demonstrate Synchronization**: Implement mutex-based mutual exclusion
4. **Illustrate Deadlock**: Create an intentional deadlock scenario to understand concurrency hazards
5. **Analyze Performance**: Evaluate memory footprint and task scheduling behavior

---

## Key Features

### Custom Task Implementations
- **Multiplication Task**: Periodic arithmetic computation with 1-second intervals
- **Mutex Demonstration**: Two tasks accessing a shared resource with proper synchronization
- **Deadlock Scenario**: Intentional circular wait condition demonstrating deadlock conditions

### FreeRTOS Configurations
- **Full Demo Mode**: Comprehensive test suite with queue, semaphore, timer, and interrupt tests
- **Blinky Mode**: Minimal demonstration for basic scheduler verification

### Technical Highlights
- Priority-based preemptive scheduling
- Deterministic context switching
- Inter-task communication using queues and semaphores
- Software timers for periodic events
- Bounded response time guarantees

---

## Architecture

### System Components

```
┌─────────────────────────────────────────┐
│         Custom Application Tasks        │
│  (Multiplication, Mutex, Deadlock)      │
├─────────────────────────────────────────┤
│          FreeRTOS Kernel API            │
│  (Task, Queue, Semaphore, Timer)        │
├─────────────────────────────────────────┤
│       FreeRTOS Portable Layer           │
│      (RISC-V Specific Code)             │
├─────────────────────────────────────────┤
│         RISC-V RV32 Hardware            │
│        (QEMU Emulation)                 │
└─────────────────────────────────────────┘
```

### Directory Structure

```
FreeRTOS-RTOS-Lab-Project/
├── src/
│   ├── custom_tasks/
│   │   ├── mult_task.h          # Multiplication task header
│   │   ├── mult_task.c          # Multiplication task implementation
│   │   ├── mutex_task.h         # Mutex demonstration header
│   │   ├── mutex_task.c         # Mutex demonstration implementation
│   │   ├── deadlock_task.h      # Deadlock demonstration header
│   │   └── deadlock_task.c      # Deadlock demonstration implementation
│   └── modified_files/
│       ├── main_blinky.c        # Modified Blinky demo entry point
│       ├── main_full.c          # Modified Full demo entry point
│       └── Makefile             # Modified build configuration
├── docs/
│   ├── OS_LabProject.pdf        # Complete project report
│   ├── images/                  # Screenshots and diagrams
│   └── build_logs/              # Compilation outputs
├── scripts/
│   └── setup.sh                 # Automated setup script
├── README.md                    # This file
├── LICENSE                      # Project license
└── .gitignore                   # Git ignore rules
```

---

## 🔧 Prerequisites

### Software Requirements
- **Operating System**: Linux (Ubuntu 20.04+ recommended)
- **RISC-V Toolchain**: `riscv-none-elf-gcc` v14.2.0-2 or later
- **QEMU**: `qemu-system-riscv32` v8.2.2-1 or later
- **Git**: v2.25.0 or later
- **Make**: GNU Make 4.2.1 or later

### Hardware Requirements
- **RAM**: Minimum 4GB
- **Storage**: 2GB free space
- **Processor**: Any modern x86_64 or ARM64 processor

---

##  Installation and Setup

### Step 1: Clone the Repository

```bash
git clone https://github.com/FaiqaZarar/FreeRTOS-RTOS-Lab-Project.git
cd FreeRTOS-RTOS-Lab-Project
```

### Step 2: Set Up Environment Variables

```bash
# Set project root directory
export OS_PROJECT=$(pwd)
export PATH=$PATH:$OS_PROJECT/tools/riscv-toolchain/bin
export PATH=$PATH:$OS_PROJECT/tools/qemu/bin
```

### Step 3: Clone FreeRTOS Source

```bash
# Clone official FreeRTOS repository
git clone https://github.com/FreeRTOS/FreeRTOS.git
cd FreeRTOS

# Initialize and update submodules
git submodule update --init --recursive
cd ..
```

### Step 4: Install RISC-V Toolchain

```bash
# Download prebuilt toolchain
wget https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v14.2.0-2/xpack-riscv-none-elf-gcc-14.2.0-2-linux-x64.tar.gz

# Extract
tar -zxvf xpack-riscv-none-elf-gcc-14.2.0-2-linux-x64.tar.gz -C tools/

# Add to PATH
export PATH=$PATH:$OS_PROJECT/tools/xpack-riscv-none-elf-gcc-14.2.0-2/bin
```

### Step 5: Install QEMU

```bash
# Download QEMU RISC-V
wget https://github.com/xpack-dev-tools/qemu-riscv-xpack/releases/download/v8.2.2-1/xpack-qemu-riscv-8.2.2-1-linux-x64.tar.gz

# Extract
tar -zxvf xpack-qemu-riscv-8.2.2-1-linux-x64.tar.gz -C tools/

# Add to PATH
export PATH=$PATH:$OS_PROJECT/tools/xpack-qemu-riscv-8.2.2-1/bin
```

### Step 6: Copy Custom Files

```bash
# Copy custom tasks to FreeRTOS demo directory
cp src/custom_tasks/* FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/

# Copy modified files
cp src/modified_files/main_blinky.c FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/
cp src/modified_files/main_full.c FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/
cp src/modified_files/Makefile FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/build/gcc/
```

---

## 🔨 Building the Project

### Navigate to Build Directory

```bash
cd FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/build/gcc
```

### Select Demo Mode

Edit `main.c` to choose between modes:

```c
// For Full Demo Mode (comprehensive tests)
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY 0

// For Blinky Mode (minimal demonstration)
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY 1
```

### Build Commands

```bash
# Clean previous builds
make clean

# Build the project
make

# Expected output: RTOSDemo.elf in output/ directory
```

### Memory Footprint Analysis

After successful compilation, the build process displays memory usage:

**Full Demo Mode:**
```
text    data     bss     dec     hex filename
65406      84   89232  154722   25c62 output/RTOSDemo.elf
```

**Blinky Mode:**
```
text    data     bss     dec     hex filename
11156      28   86064   97248   17be0 output/RTOSDemo.elf
```

---

## ▶️ Running the Project

### Execute on QEMU

```bash
qemu-system-riscv32 \
  -nographic \
  -machine virt \
  -net none \
  -chardev stdio,id=con,mux=on \
  -serial chardev:con \
  -mon chardev=con,mode=readline \
  -bios none \
  -s \
  --kernel ./output/RTOSDemo.elf
```

### Expected Output

**Full Demo Mode:**
```
Multiplication: 2 * 3 = 6
FreeRTOS Demo Start
Multiplication: 3 * 4 = 12
FreeRTOS Demo SUCCESS: 1000
Multiplication: 4 * 5 = 20
FreeRTOS Demo SUCCESS: 2000
```

**Blinky Mode:**
```
Message received from task
Multiplication: 2 * 3 = 6
Message received from software timer
Multiplication: 3 * 4 = 12
Message received from task
```

### Exit QEMU

Press `Ctrl+A` then `X` to exit QEMU

---

##  Testing and Demonstrations

### 1. Multiplication Task
Demonstrates periodic task execution with 1-second intervals:
- Creates independent thread of execution
- Uses `vTaskDelay()` for precise timing
- Prints arithmetic results to console

### 2. Mutex Demonstration
Shows proper synchronization between concurrent tasks:
- Two tasks compete for shared resource (console)
- Mutex ensures mutual exclusion
- Prevents race conditions and data corruption

**Expected Behavior:**
```
Task 1 entered critical section
Task 1 counter = 1
Task 1 leaving critical section
Task 2 entered critical section
Task 2 counter = 2
Task 2 leaving critical section
```

### 3. Deadlock Demonstration
Illustrates circular wait condition (Coffman conditions):
- Two mutexes (A and B)
- Task 1: locks A → waits for B
- Task 2: locks B → waits for A
- Results in permanent blocking

**Expected Output:**
```
Task 1 trying to lock Mutex A
Task 1 locked Mutex A
Task 2 trying to lock Mutex B
Task 2 locked Mutex B
Task 1 trying to lock Mutex B
Task 2 trying to lock Mutex A
[System halts - deadlock detected]
```

---

## Performance Metrics

### Task Scheduling Analysis
- **Context Switch Time**: < 100 CPU cycles (deterministic)
- **Interrupt Latency**: Bounded by FreeRTOS tick rate
- **Task Response Time**: Priority-based, predictable

### Memory Efficiency
| Component | Full Demo | Blinky Mode |
|-----------|-----------|-------------|
| Code (text) | 65.4 KB | 11.2 KB |
| Data | 84 B | 28 B |
| BSS (stacks) | 89.2 KB | 86.1 KB |
| **Total** | **154.7 KB** | **97.2 KB** |

---

## 🐛 Troubleshooting

### Common Issues

**Issue 1: Compiler Not Found**
```bash
# Verify toolchain installation
which riscv-none-elf-gcc

# If not found, check PATH variable
echo $PATH

# Re-export PATH
export PATH=$PATH:/path/to/toolchain/bin
```

**Issue 2: QEMU Not Starting**
```bash
# Verify QEMU installation
which qemu-system-riscv32

# Test QEMU
qemu-system-riscv32 --version
```

**Issue 3: Build Errors**
```bash
# Clean and rebuild
make clean
make

# Check Makefile variable syntax
grep "COMMON_DEMO_FILES" Makefile
# Should show $( not just (
```

**Issue 4: Timing Test Failures**
This is expected in QEMU emulation. The Abort Delay Test may fail due to non-deterministic timing in virtual environments. This does not indicate kernel errors.

---

## Documentation

### Complete Project Report
The full academic report is available in `docs/OS_LabProject.pdf` and covers:
- Theoretical background on RTOS concepts
- FreeRTOS architecture analysis
- Implementation methodology
- Experimental results and analysis
- Limitations and future work

### Code Documentation
All custom tasks include inline comments explaining:
- Function purpose and behavior
- Parameter descriptions
- Return values
- Usage examples

---

##  Learning Outcomes

This project demonstrates mastery of:

1. **Real-Time Operating Systems**
   - Preemptive scheduling algorithms
   - Priority-based task management
   - Deterministic timing behavior

2. **Concurrency Control**
   - Mutex-based synchronization
   - Race condition prevention
   - Deadlock detection and analysis

3. **Embedded Systems Development**
   - Cross-compilation for RISC-V
   - Bare-metal programming
   - Hardware emulation with QEMU

4. **Software Engineering Practices**
   - Modular code design
   - Version control with Git
   - Build system configuration

---

##  Known Limitations

1. **Emulation Environment**: QEMU provides functional emulation, not cycle-accurate simulation
2. **Timing Tests**: Some timing-sensitive tests may fail due to emulator limitations
3. **Hardware Peripherals**: Limited peripheral support compared to real hardware
4. **WCET Analysis**: Worst-case execution time cannot be reliably measured in emulation

---

##  Future Enhancements

- [ ] Port to physical RISC-V hardware (HiFive1 Rev B board)
- [ ] Implement priority inheritance for mutex deadlock prevention
- [ ] Add rate-monotonic scheduling analysis
- [ ] Create graphical task execution timeline visualization
- [ ] Integrate with FreeRTOS+Trace for runtime analysis
- [ ] Implement additional IPC mechanisms (message queues, event groups)
- [ ] Add power management and low-power modes

---

## References

### Official Documentation
- [FreeRTOS Official Documentation](https://www.freertos.org/Documentation/RTOS_book.html)
- [FreeRTOS GitHub Repository](https://github.com/FreeRTOS/FreeRTOS)
- [RISC-V ISA Specification](https://riscv.org/technical/specifications/)
- [QEMU Documentation](https://www.qemu.org/documentation/)

### Academic Resources
- Labrosse, J. J. (2002). *MicroC/OS-II: The Real-Time Kernel*
- Buttazzo, G. C. (2011). *Hard Real-Time Computing Systems*
- Liu, C. L., & Layland, J. W. (1973). "Scheduling Algorithms for Multiprogramming in a Hard-Real-Time Environment"

### Related Projects
- [FreeRTOS Community Forums](https://forums.freertos.org/)
- [RISC-V Software Ecosystem](https://github.com/riscv-software-src)

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

##  Contributing

While this is an academic project, suggestions and improvements are welcome:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

---

## Contact

For questions or discussions about this project:

- **Namra Basharat** - [GitHub Profile](https://github.com/YOUR_USERNAME)
- **Project Repository** - [FreeRTOS-RTOS-Lab-Project](https://github.com/YOUR_USERNAME/FreeRTOS-RTOS-Lab-Project)

---

## Acknowledgments

- FreeRTOS development team for the excellent open-source RTOS
- NUST faculty for guidance and support
- RISC-V Foundation for the open ISA specification
- xPack project for prebuilt toolchains
- QEMU development team for the emulation platform

---

**Note**: This project was completed as part of the Operating Systems Lab course at the National University of Sciences and Technology (NUST), Pakistan.

---

*Last Updated: December 17, 2025*
