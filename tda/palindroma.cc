#include <iostream>
#include "pila.h"
#include "coda.h"

using namespace std;

bool palindroma(char str[]){

    pila_init();
    coda_init();
    for(int i = 0; str[i] != '\0'; i++)
    {
        pila_push(str[i]);
        coda_enqueue(str[i]);
    }

    int coda_val, pila_val;
    while(coda_first(coda_val) && pila_top(pila_val)){
        cout << "pila " << pila_val << "coda " << coda_val << endl; 
        if(pila_val != coda_val)
            return false;
        pila_pop(); coda_dequeue();
    }
    return true;
}

int main(int argc, char **argv){
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << "<input> <output>" << std::endl;
        return -1;
    }

    cout << palindroma(argv[1]) << std::endl;
    
    return 0;
}