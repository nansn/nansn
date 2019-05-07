DEVICE=tty
EXTRA_CFLAGS += -Wno-date-time #


KERNELDIR=/work/flexbuild_lsdk1809/packages/linux/linux/
PWD :=$(shell pwd)
CC =$(CROSS_COMPILE)gcc
obj-m:=$(DEVICE).o
$(DEVICE)-objs:= 99xx.o
default:
	$(MAKE) -C  $(KERNELDIR) M=$(PWD)  modules 
clean:
	rm -rf *.o *.ko *.mod.o *.mod.c *.symvers *.order
