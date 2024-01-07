#include "circolare.h"
#include <iostream>

nodo* last;
nodo* head;

void circolare_init()
{
    head = NULL;
    last = NULL;
}
void circolare_insert_start(char c)
{
    if(head == NULL)
    {
        head = new nodo{c, NULL};
        head->next = head;
        last = head;
    }
    else
    {
        nodo* nuovo_nodo = new nodo{c, NULL};
        nuovo_nodo->next = head;
        last->next = nuovo_nodo;
        head = nuovo_nodo;
    }
        
}
void circolare_insert_end(char c)
{
    if(head == NULL)
    {
        head = new nodo{c, NULL};
        head->next = head;
        last = head;
    }
    else
    {
        nodo* nuovo_nodo = new nodo{c, NULL};
        nuovo_nodo->next = head;
        last->next = nuovo_nodo;
        last = nuovo_nodo;
    }
        
}
char circolare_get(int index)
{
    nodo* tmp = head;
    for(int i = 0; i < index; i ++)
        tmp = tmp->next;
    return tmp->value;
}


void circolare_print()
{
    nodo* tmp = head;
    do
    {
        std::cout << tmp->value << "->";
        tmp = tmp->next;
    }  while(tmp != head);
    std::cout << std::endl;
}
