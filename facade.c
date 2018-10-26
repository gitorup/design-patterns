#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct eat_t {
	void (*eat)(void);
};

struct food {
	void (*food)(void);
};

struct play_t {
	struct eat_t *e;
	struct food *f;

	void (*play)(void);
};


void play(struct play_t *p)
{
	assert(p);

	p->e->eat();
	p->f->food();
}

