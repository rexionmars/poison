GCCPARAMS = -m32 -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o gdt.o kernel.o

%.o: %.cpp
	g++ $(GPPPARAMS) -o $@ -c $<

loader.o: loader.s
	as $(ASPARAMS) -o $@ $<

pskernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: kernel_test.bin
	sudo cp $< /boot/kernel_test.bin

pskernel.iso: pskernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/

	echo 'set timeout=0' >> iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Poison Operational System" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/pskernel.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg

	grub-mkrescue --output=$@ iso
	rm -rfv iso

run: pskernel.iso
	(killall VirtualBoxVM && sleep 1) || true
	VirtualBoxVM --startvm "Poison OS" &
