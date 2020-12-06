// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/list.h>
#include <linux/slab.h>
#include "hello1.h"

MODULE_AUTHOR("Ivan Shkardybarda <ivanshkardybarda@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
struct node {
	ktime_t begin;
	ktime_t end;
	struct list_head list;
};
int print_hello(uint num);
int release_list(void);
struct node *tmp;
struct list_head *pos, *q;
struct node mylist;
int print_hello(uint num)
{
	int i = 0;

	INIT_LIST_HEAD(&mylist.list);
	if (num > 10) {
		pr_err("Error value more then 10\n");
		return -EINVAL;
	} else if ((num == 0) | ((num >= 5) & (num <= 10))) {
		pr_warn("Warning: value is %d\n", num);
		while (i < num) {
			tmp = (struct node *) kmalloc(sizeof(struct node), GFP_KERNEL);
			tmp->begin = ktime_get();
			pr_info("Hello, world!\n");
			tmp->end = ktime_get();
			list_add(&(tmp->list), &(mylist.list));
			i++;
		}
	} else {
		while (i < num) {
			tmp = (struct node *) kmalloc(sizeof(struct node), GFP_KERNEL);
			tmp->begin = ktime_get();
			printk(KERN_EMERG "Hello, world!\n");
			tmp->end = ktime_get();
			list_add(&(tmp->list), &(mylist.list));
			i++;
		}
	}
	return 0;
}
EXPORT_SYMBOL(print_hello);
int release_list(void)
{
	list_for_each_safe(pos, q, &mylist.list) {
		tmp = list_entry(pos, struct node, list);
		pr_info("Time for print = %lld\n", ktime_to_ns(ktime_sub(tmp->end, tmp->begin)));
		list_del(pos);
		kfree(tmp);
	}
	return 0;
}
EXPORT_SYMBOL(release_list);
