
void writeln(char *str)
{
    unsigned short* VideoMemory = (unsigned short*)0xb80000;

    for(int i = 0; str[i] != '\0'; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) |  str[i];
}

void kernelMain(void *multiboot_structure, unsigned int magic_number)
{
    writeln("Core State");
    while(1);
}

