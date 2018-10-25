#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _class_t {
	struct _class_t **ppobject;
	int number;
	void (*operate)(struct _class_t *pobject);
} class_t;

void class_operate(class_t *object)
{
	int index;

	assert(object != NULL);
	assert(object->ppobject != NULL);

	for (index = 0; index < object->number; index++) {
		object->ppobject[index]->operate(object->ppobject[index]);
	}
}

