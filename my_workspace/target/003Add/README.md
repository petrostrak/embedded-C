In `STM32F3DISCOVERY`: 

*   The available `Flash Memory` ranges from `0x08000000` to `0x0807FFFF`. All of our program instructions are stored here. 
*   The `System Memory` of the microcontroller is located within the addresses `0x1FFFD800` and `0x1FFFF7FF`. This area is reserved from ST and cannot be accessed.
*   The `Data Memory` (SRAM) is locatted at the address `0x20000000`. This is where the data or variables of our program are stored.

### But how is the Data Memory (SRAM) populated in the first place?
These data are part of the executable `.elf` file.
To analize the `.elf` file we use the following command:

```
arm-none-eabi-objdump -h 003Add.elf
```
`.elf` file has many sections.

*   `.text` section of the elf file contains 'code' or all the 'instructions' of the program
*   `.rodata` sections contains all the 'read-only' data of the program
*   `.data` section contains all the 'data' of the program
    *   location of data in LMA - Load Memory Address (Source in FLASH) where the section is currently loaded.
    *   location of data in VMA - Virtual Memory Address (Destination in SRAM) where the section should finally be copied to.

The copy from the LMA to VMA is done by the startup code provided by the ST
```
CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4
```

