#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _class_t {
	void *data;
	int size;
	struct _class_t *(*clone)(struct _class_t *c);
} class_t; 

class_t *class_clone(class_t *c)
{
	class_t *class = malloc(sizeof(class_t));
	assert(class != NULL);
	memmove(class, c, sizeof(class_t));
	return class;
}

static class_t test_class = {NULL, 0, class_clone};

/* use */
class_t *clone(class_t *c)
{
	return c->clone(c);
}

