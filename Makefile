obj-m += ex_softirq.o ex_tasklets.o ex_workqueue.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all: modules

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

format:
	clang-format -i *.c *.h

check:
	@echo "Проверка синтаксиса..."
	@$(MAKE) -C $(KDIR) M=$(PWD) modules_prepare
