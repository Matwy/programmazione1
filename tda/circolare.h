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
char circolare_remove(int);
void circolare_print();
int circolare_length();
char remove_ogni_m(int);
#endif
