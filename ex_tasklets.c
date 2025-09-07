#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>

static void tasklet_func(unsigned long data);
DECLARE_TASKLET(my_tasklet, tasklet_func, 0);

static void tasklet_func(unsigned long data)
{
    pr_info("Tasklet executed\n");
}

static int __init tasklet_init(void)
{
    pr_info("Tasklet module loaded\n");
    tasklet_schedule(&my_tasklet);
    return 0;
}

static void __exit tasklet_exit(void)
{
    tasklet_kill(&my_tasklet);
    pr_info("Tasklet module unloaded\n");
}

module_init(tasklet_init);
module_exit(tasklet_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HW");
MODULE_DESCRIPTION("Tasklet example");
