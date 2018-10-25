#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _class_t {
	void *data;
	int size;
	int (*init)(struct _class_t *c);
	int (*start)(struct _class_t *c);
	int (*stop)(struct _class_t *c);
} class_t;

int class_init(class_t *class)
{
	return 0;
}

int class_start(class_t *class)
{
	return 0;
}

int class_stop(class_t *class)
{
	return 0;
}

int main(int argc, char *argv[])
{
	class_t *class = NULL;
	int ret;

	class = malloc(sizeof(class_t));
	assert(class);

	class->init = class_init;
	class->start = class_start;
	class->stop = class_stop;

	ret = class->init(class);
	if (ret) {
		printf("init failed: %d\n", ret);
		return -1;
	}

	ret = class->start(class);
	if (ret) {
		printf("start failed: %d\n", ret);
		return -1;
	}

	class->stop(class);
	return 0;
}
