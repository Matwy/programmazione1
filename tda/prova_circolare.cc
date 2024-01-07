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
    circolare_print();
    char c = circolare_get(16);
    cout << c << endl;


    return 0;
}