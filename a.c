#include <linux/atomic.h>
#include <linux/init.h>
#include <linux/crypto.h>
#include <linux/module.h>	/* for module_name() */
#include <linux/rwsem.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>

LIST_HEAD(test_list);

struct k_list {
	struct list_head test_list;
	int temp;
};


static void *c_start(struct seq_file *m, loff_t *pos)
{
	//down_read(&crypto_alg_sem);
	printk("into start");
	return seq_list_start(&test_list, *pos);
}

static void *c_next(struct seq_file *m, void *p, loff_t *pos)
{
	printk("into next");
	return seq_list_next(p, &test_list, pos);
}

static void c_stop(struct seq_file *m, void *p)
{
	printk("into stop");
	//up_read(&crypto_alg_sem);
}

static int c_show(struct seq_file *m, void *p)
{
	struct k_list *alg = list_entry(p, struct k_list, test_list);
	seq_printf(m,"into c_show");
	seq_printf(m, "name : %d\n", alg->temp);
	return 0;
}

static const struct seq_operations q_seq_ops = {
	.start		= c_start,
	.next		= c_next,
	.stop		= c_stop,
	.show		= c_show
};

static int qstatus_open(struct inode *inode, struct file *file)
{
	printk("ito open");
	return seq_open(file, &q_seq_ops);
}
        
static const struct file_operations proc_qstatus_ops = {
	.open		= qstatus_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= seq_release
};

void __init qstatus_init_proc(void)
{
	proc_create("qstatus", 0, NULL, &proc_qstatus_ops);
	
	printk("into init");
	struct k_list *one,*two,*three,*entry;
	struct list_head test_head;
	struct list_head *ptr;

	one=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	two=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	three=kmalloc(sizeof(struct k_list *),GFP_KERNEL);

	one->temp=10;
	two->temp=20;
	three->temp=30;
/*
	INIT_LIST_HEAD(&test_head);
	list_add(&one->test_list,&test_head);
	list_add(&two->test_list,&test_head);
	list_add(&three->test_list,&test_head);
	list_for_each(ptr,&test_head){
	entry=list_entry(ptr,struct k_list,test_list);


	printk(KERN_INFO "\n Hello %d  \n ", entry->temp);

	}*/
}

void __exit qstatus_exit_proc(void)
{
	remove_proc_entry("qstatus", NULL);
}


module_init(qstatus_init_proc);
module_exit(qstatus_exit_proc);
