# Usage Guide

## Building the Project
```bash
cd FreeRTOS/FreeRTOS/Demo/RISC-V_RV32_QEMU_VIRT_GCC/build/gcc
make clean
make
```

## Running on QEMU
```bash
qemu-system-riscv32 -nographic -machine virt -net none \
  -chardev stdio,id=con,mux=on -serial chardev:con \
  -mon chardev=con,mode=readline -bios none -s \
  --kernel ./output/RTOSDemo.elf
```

## Exit QEMU
Press `Ctrl+A` then `X`

## Expected Output

### Multiplication Task
```
Multiplication: 2 * 3 = 6
Multiplication: 3 * 4 = 12
```

### Mutex Demo
```
Task 1 entered critical section
Task 1 counter = 1
Task 1 leaving critical section
```

### Deadlock Demo
```
Task 1 trying to lock Mutex A
Task 1 locked Mutex A
Task 2 trying to lock Mutex B
Task 2 locked Mutex B
[System halts - deadlock]
```
