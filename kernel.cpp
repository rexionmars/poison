
void writeln(char* str)
{
    static unsigned short* VideoMemory = (unsigned short*)0xb80000;

    for(int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void kernelMain(void* multiboot_structure, unsigned int magic_number)
{
    writeln("Poison OS");
    while(1);
}

