#include "include/common/types.h"
#include "include/gdt.h"

using namespace ostypes;
using namespace common;

void writeln(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*magic_number*/)
{
    writeln("Poison Operation System --- github.com/rexionmars by Joao Leonardi");
    GlobalDescriptorTable gdt;

    while(1);
}
