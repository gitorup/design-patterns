#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum cal_type_e {
	cal_type_add = 0,
	cal_type_sub = 1,
	cal_type_mul = 2,
	cal_type_div = 3
};

typedef struct {
	int a;
	int b;
	int (*cal)(int a, int b);
} class_t;

int f_add(int a, int b){return (a + b);}
int f_sub(int a, int b){return (a - b);}
int f_mul(int a, int b){return (a * b);}
int f_div(int a, int b){return (b == 0 ? 0 : (a / b));}

class_t *calculte(int a, int b, enum cal_type_e type)
{
	class_t *class = malloc(sizeof(class_t));
	assert(class);

	class->a = a;
	class->b = b;
	switch (type) {
		case cal_type_add: class->cal = f_add; break;
		case cal_type_sub: class->cal = f_sub; break;
		case cal_type_mul: class->cal = f_mul; break;
		case cal_type_div: class->cal = f_div; break;
		default: class->cal = f_add; break;
	}

	return class;
}

int main(int argc, char *argv[])
{
	class_t *class = NULL;

	class = calculte(1, 2, cal_type_add);
	assert(class);

	class->cal(class->a, class->b);
	return 0;
}
