# xv6 Shared Memory and Virtual Memory Management

## Overview
This project extends the xv6 operating system with new functionalities for managing virtual memory and shared memory between processes. The goal is to provide a mechanism for processes to share a portion of their virtual address space, similar to the `mmap()` system call in Unix, but implemented as a simpler version called `smem()`.

## Key Features
- **Shared Memory Creation**: Processes can create a shared memory region that can be inherited by child processes.
- **Memory Management**: Enhancements to the kernel for efficient management of virtual memory.
- **System Calls**: New system calls `kpages`, `udirs`, and `kdirs` to assist in memory management and debugging.

## Getting Started

### Prerequisites
- A working setup of the xv6 operating system.
- QEMU emulator to run and test xv6.

### Installation
1. Clone the xv6 repository with the `smem` implementation.
2. Build the xv6 kernel using the `make` command.
3. Start the xv6 operating system in QEMU with the new kernel.

## Usage
To create a shared memory region within a process:
```c
int smem(char *addr, int n);
```
`addr`: Starting address of the memory region (must be a multiple of 4096).

`n`: Size of the memory region in bytes (must be a multiple of 4096).

Example:

```c
smem((char *)0x40000000, 4 * 4096); // Allocates 4 pages starting at 1GB.
```

## Testing
Use the `kpages`, `udirs`, and `kdirs` system calls to verify the correct implementation of memory management features.

Test the `smem` system call with various scenarios to ensure proper allocation, inheritance, and deallocation of shared memory regions.

Acknowledgments
Special thanks to **Professor Greg Benson** and the developers and maintainers of xv6 for their dedication to creating an educational platform for learning operating systems.