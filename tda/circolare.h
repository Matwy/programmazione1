#ifndef CIRCOLARE_H
#define CIRCOLARE_H

struct nodo {
	char value;
	nodo* next;
};

void circolare_insert_start(char);
void circolare_insert_end(char);
void circolare_init();
char circolare_get(int);
void circolare_print();

#endif
