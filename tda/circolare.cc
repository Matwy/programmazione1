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
char circolare_remove(int index)
{
    nodo* tmp = head;
    for(int i = 0; i < index-1; i ++)
        tmp = tmp->next;
    nodo* nodo_da_rimuovere = tmp->next;
    
    if(nodo_da_rimuovere == head) 
        head = nodo_da_rimuovere->next;
    else if(nodo_da_rimuovere == last)
        last = tmp;
    
    tmp->next = nodo_da_rimuovere->next;

    char val = nodo_da_rimuovere->value;
    delete nodo_da_rimuovere;
    return val;
}
int circolare_length()
{
    int i = 0;
    nodo* tmp = head;
    do
    {
        i++;
        tmp = tmp->next;
    }  while(tmp != head);
    return i;
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

char remove_ogni_m(int m)
{
    nodo* tmp = last;

    while(circolare_length() > 1)
    {
        for(int j = 1; j < m; j ++)
            tmp = tmp->next;
        nodo* nodo_da_rimuovere = tmp->next;
        
        if(nodo_da_rimuovere == head) 
            head = nodo_da_rimuovere->next;
        else if(nodo_da_rimuovere == last)
            last = tmp;
        
        tmp->next = nodo_da_rimuovere->next;

        std::cout << nodo_da_rimuovere->value << std::endl;
        delete nodo_da_rimuovere;
    }
    return circolare_get(0);    
}