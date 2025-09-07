#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>

static struct softirq_action my_softirq;

static void my_softirq_func(struct softirq_action *sa)
{
    pr_info("Softirq executed\n");
}

static int __init softirq_init(void)
{
    open_softirq(1, my_softirq_func);  // 1 — пример номера softirq
    pr_info("Softirq module loaded\n");
    raise_softirq(1); // вызов softirq
    return 0;
}

static void __exit softirq_exit(void)
{
    pr_info("Softirq module unloaded\n");
}

module_init(softirq_init);
module_exit(softirq_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HW");
MODULE_DESCRIPTION("Softirq example");
