void writeln(char* str)
{
    static unsigned short* VideoMemory = (unsigned short*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
}

extern "C" void kernelMain(const void* multiboot_structure, unsigned int /*magic_number*/)
{
    writeln("Poison Operation System --- github.com/rexionmars");
    while(1);
}
