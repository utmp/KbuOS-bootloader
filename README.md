# KbuOS

A minimal operating system kernel built from scratch for learning purposes. This project was created for the **build-your-own-x** challenge.

## Features

- Multiboot-compliant bootloader written in x86 Assembly
- Minimal kernel written in C
- VGA text mode output with color support
- Bootable via GRUB


## Prerequisites

Make sure you have the following tools installed:

```bash
# On Debian/Ubuntu
sudo apt install nasm gcc grub-pc-bin xorriso qemu-system-x86
```

- **nasm** - Netwide Assembler for compiling assembly code
- **gcc** - GNU C Compiler (with 32-bit support)
- **grub-pc-bin** - GRUB utilities for creating bootable images
- **xorriso** - Tool for creating ISO images
- **qemu** - For testing the OS in a virtual machine

## How to Build

### Step 1: Compile the bootloader

```bash
nasm -f elf32 boot.asm -o out/boot.o
```

### Step 2: Compile the kernel

```bash
gcc -m32 -ffreestanding -c kernel.c -o out/kernel.o
```

### Step 3: Link everything together

```bash
gcc -m32 -T linker.ld -o out/myos.bin -ffreestanding -nostdlib out/boot.o out/kernel.o
```

### Step 4: Copy the binary to isodir

```bash
cp out/myos.bin isodir/boot/myos.bin
```

### Step 5: Create a bootable ISO

```bash
grub-mkrescue -o out/myos.iso isodir
```

## Quick Build (All in One)

Run all build steps at once:

```bash
# Create output directory if it doesn't exist
mkdir -p out

# Build everything
nasm -f elf32 boot.asm -o out/boot.o && \
gcc -m32 -ffreestanding -c kernel.c -o out/kernel.o && \
gcc -m32 -T linker.ld -o out/myos.bin -ffreestanding -nostdlib out/boot.o out/kernel.o && \
cp out/myos.bin isodir/boot/myos.bin && \
grub-mkrescue -o out/myos.iso isodir
```

## Running the OS

### Using QEMU

```bash
qemu-system-i386 -cdrom out/myos.iso
```

## Output Files

| File | Description |
|------|-------------|
| `out/boot.o` | Compiled bootloader object file |
| `out/kernel.o` | Compiled kernel object file |
| `out/myos.bin` | Linked kernel binary (ELF format) |
| `out/myos.iso` | Bootable ISO image |

## How It Works

1. **GRUB** loads `myos.bin` using the Multiboot specification
2. **boot.asm** sets up the stack and calls `kernel_main()`
3. **kernel.c** writes colored text directly to VGA memory at `0xB8000`


##

<p align="center">
  Made with ❤️ and lots of compilers

</p>
