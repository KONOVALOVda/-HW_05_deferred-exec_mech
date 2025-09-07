#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/kernel.h>

static struct workqueue_struct *my_wq;
static struct work_struct my_work;

static void work_func(struct work_struct *work)
{
    pr_info("Workqueue executed\n");
}

static int __init workqueue_init(void)
{
    pr_info("Workqueue module loaded\n");
    my_wq = create_singlethread_workqueue("my_wq");
    if (!my_wq) {
        pr_err("Failed to create workqueue\n");
        return -ENOMEM;
    }
    INIT_WORK(&my_work, work_func);
    queue_work(my_wq, &my_work);
    return 0;
}

static void __exit workqueue_exit(void)
{
    flush_workqueue(my_wq);
    destroy_workqueue(my_wq);
    pr_info("Workqueue module unloaded\n");
}

module_init(workqueue_init);
module_exit(workqueue_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HW");
MODULE_DESCRIPTION("Workqueue example");
