ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
ccflags-y := -I$(src)/inc
ccflags-y += -g
obj-m	:= hello1.o hello2.o
else
# normal makefile
KDIR ?= /home/vanya/Eglantine/ak_2/lab4/repos/linux-stable/

default:
	$(MAKE) -C $(KDIR) M=$$PWD
	cp hello1.ko hello1.ko.unstripped
	cp hello2.ko hello2.ko.unstripped
	$(CROSS_COMPILE)strip -g hello2.ko
	$(CROSS_COMPILE)strip -g hello1.ko
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

%.s %.i: %.c
	$(MAKE) -C $(KDIR) M=$$PWD $@

install:
	$(MAKE) -C $(KDIR) M=$$PWD modules_install
endif
