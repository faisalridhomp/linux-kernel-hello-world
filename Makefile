# Makefile for the hello world kernel module.
#
# Builds hello.ko against the headers of the currently running kernel.
# Requires the matching linux-headers package, e.g. on Ubuntu/Debian:
#   sudo apt install linux-headers-$(uname -r)

obj-m += hello.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
