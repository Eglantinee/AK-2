ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
ccflags-y := -I$(src)/inc
obj-m	:= hello1.o hello2.o
else
# normal makefile
KDIR ?= /home/vanya/Eglantine/ak_2/lab4/repos/linux-stable/

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
install:
	$(MAKE) -C $(KDIR) M=$$PWD modules_install
