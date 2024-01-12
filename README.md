### 3ds firmware

A bit of an experimental project for the Nintendo 3DS.

![2024-01-12 08 30 07](https://github.com/PF94/3ds-firmware/assets/45898787/948dfc40-7bad-4aa8-80ab-54b193697bd9)
(Sorry for the crusty console)

### Building:
- The makefile currently contains hardcoded values, you may need to change them if you want to compile this.
- You'll need to install a cross-compiler for the arm-none-eabi platform. On Fedora (and its forks), it's the ``arm-none-eabi-gcc-cs`` package. We currently don't use devkitARM.
- The root directory (as in the 3ds-firmware repository after downloading/git cloning it)'s makefile will attempt to copy boot.firm to `/run/media/bluffingo/WII/luma/payloads/`, change this as needed.
- To launch this firmware, you'll have to press and hold the Start button before powering on the console, akin to launching GodMode9.

Building boot.firm:
```
git clone <this_repo> --recursive
make setup	# install/build dependencies
make		# Compile the code and build the boot.firm image
# In order to recompile you have to 'make clean && make'
# I might switch to meson + ninja in the future to make this less of a problem..
```

### Implemented features
- basic printing
- slab allocator (will be improved as I a get a feel for memory management on this device)
- exception handler
- i2c

### Planned features
- double buffering (bank switching)
- mmu
- scrolling text (maybe idk)
- read files from sd card
- gpu driver
- DOOM!

### Resources
https://developer.arm.com/documentation/ddi0201/d


https://www.3dbrew.org/wiki/Memory_layout

DDI0360F_arm11_mpcore_r2p0_trm.pdf 
