#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOTIFY_DONE         0x0000    /* Don't care */
#define NOTIFY_OK           0x0001    /* Suits me */
#define NOTIFY_STOP_MASK    0x8000    /* Don't call further */
#define NOTIFY_BAD (NOTIFY_STOP_MASK|0x0002) /* Bad/Veto action */

struct notifier_block
{
	int (*notifier_call)(struct notifier_block *self, unsigned long, void *);
	struct notifier_block *next;
	int priority;
};

int notifier_chain_register(struct notifier_block **list, struct notifier_block *n)
{
	while (*list) {
		if (n->priority > (*list)->priority)
			break;
		list = &((*list)->next);
	}
	n->next = *list;
	*list = n;
	return 0;
}

int notifier_chain_unregister(struct notifier_block **nl, struct notifier_block *n)
{
	while ((*nl) != NULL) {
		if ((*nl) == n) {
			*nl = n->next;
			return 0;
		}
		nl = &((*nl)->next);
	}
	return -1;
}

int notifier_call_chain(struct notifier_block **n, unsigned long val, void *v)
{
	int ret = NOTIFY_DONE;
	struct notifier_block *nb = *n;

	while (nb) {
		ret = nb->notifier_call(nb, val, v);
		if (ret & NOTIFY_STOP_MASK) {
			return ret;
		}
		nb = nb->next;
	}
	return ret;
}

