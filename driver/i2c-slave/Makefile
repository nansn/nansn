#
# Kernel module build rules
#

DEVICE=smbus-slave
ifneq ($(KERNELRELEASE),)
	obj-m:=$(DEVICE).o
	$(DEVICE)-objs:= slave.o 

else
	KDIR:=../../${LINUX}
	PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
endif

clean:
	rm -rf .*.cmd .tmp* *.*o *.mod* Module.symvers modules.order *~

