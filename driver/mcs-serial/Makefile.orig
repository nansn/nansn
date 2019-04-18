KDIR:=/lib/modules/$(shell  uname -r)/build/ 

DEBIAN_VERSION_FILE:=/etc/debian_version
DEBIAN_DISTRO:=$(wildcard $(DEBIAN_VERSION_FILE))

obj-m +=99xx.o

default:
	$(RM) *.mod.c *.o *.ko .*.cmd *.symvers
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

install:
	mkdir  -p   /lib/modules/$(shell uname -r)/kernel/drivers/serial/
	cp 99xx.ko  /lib/modules/$(shell uname -r)/kernel/drivers/serial/
	depmod -A
	chmod +x mcs99xx
	cp mcs99xx /etc/init.d/
ifeq ($(DEBIAN_DISTRO), $(DEBIAN_VERSION_FILE))
	ln -s /etc/init.d/mcs9865 /etc/rcS.d/Smcs9865 || true
else
	ln -s /etc/init.d/mcs99xx /etc/rc.d/rc3.d/Smcs99xx || true  	
	ln -s /etc/init.d/mcs99xx /etc/rc.d/rc5.d/Smcs99xx || true
endif
	modprobe 99xx

uninstall:
	modprobe -r 99xx
	rm /lib/modules/$(shell uname -r)/kernel/drivers/serial/99xx.*
	depmod -A
	rm -f /etc/init.d/mcs99xx
ifeq ($(DEBIAN_DISTRO), $(DEBIAN_VERSION_FILE))
	ln -s /etc/init.d/mcs9865 /etc/rcS.d/Smcs9865 || true
else
	rm -f /etc/rc.d/rc3.d/Smcs99xx
	rm -f /etc/rc.d/rc5.d/Smcs99xx
endif

clean:
	$(RM) *.mod.c *.o *.ko .*.cmd *.symvers
	rm -rf .tmp_version*
	rm -rf Module.markers modules.*
