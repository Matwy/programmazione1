#include <iostream>
#include "circolare.h"

using namespace std;

int main(int argc, char** argv)
{
    circolare_init();
    circolare_insert_end('a');
    circolare_insert_end('b');
    circolare_insert_end('c');
    circolare_insert_end('d');
    
    int m = 4;
    remove_ogni_m(m);
    circolare_print();


    return 0;
}