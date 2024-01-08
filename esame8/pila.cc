#include "pila.h"
#include <iostream>
using namespace std;

int* arr;
int p1_size;
int p2_size;
int DIM;
void init(int dim)
{
    arr = new int[dim];
    p1_size = 0;
    p2_size = 0;
    DIM = dim;
}

bool pushP1(int valore)
{
    if(p1_size + p2_size + 1 >= DIM)
        return false;
    p1_size++;
    arr[p1_size-1] = valore;
    return true;
}
bool pushP2(int valore)
{
    if(p1_size + p2_size + 1 >= DIM)
        return false;
    p2_size++;
    arr[DIM - p2_size] = valore;
}
bool topP1(int& val)
{
    if(p1_size <=0 ) return false;
    val = arr[p1_size-1];
    return true;
}
bool topP2(int& val)
{
    if(p2_size <=0 ) return false;
    val = arr[DIM - p2_size];
    return true;
}

bool popP1()
{
    if(p1_size <=0 ) return false;
    arr[p1_size-1] = 0;
    p1_size --;
    return true;
}

bool popP2()
{
    if(p2_size <=0 ) return false;
    arr[DIM - p2_size] = 0;
    p2_size --;
    return true;
}

void deinit()
{
    delete[] arr;
    p1_size = 0;
    p2_size = 0;
}

void print()
{
    cout << "p1 ";
    for(int i = 0; i < p1_size; i++)
    {
       cout << arr[i] << ", "; 
    }
    cout << endl;

    cout << "p2 ";
    for(int i = 0; i < p2_size; i++)
    {
       cout << arr[DIM - 1 - i] << ", "; 
    }
    cout << endl;
}
