#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	void *data;
	int size;
} class_t;

class_t *class_init(void)
{
	static class_t *c = NULL;

	if (c == NULL) {
		c = malloc(sizeof(class_t));
		assert(c != NULL);
	}

	return c;
}
