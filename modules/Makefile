# -*- Makefile
obj-m := xt_domain.o
ccflags-y := -O3 -I$(src)/../include
DEPMOD=/sbin/depmod
INSTALL=/usr/bin/install -c
#KERNEL_RELEASE=`uname -r`
#BUILD_DIR=/lib/modules/$(KERNEL_RELEASE)/build

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
install:
	$(MAKE) INSTALL_MOD_DIR=kernel/net/netfilter -C $(KERNEL_DIR) M=$(PWD) modules_install
	$(DEPMOD) -A
check:
