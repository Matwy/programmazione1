#include <iostream>
#include "pila.h"
using namespace std;

bool is_bilanciato(char str[]){
    pila_init();
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(')
            pila_push(0);

        if(str[i] == ')')
            if(!pila_pop())
                return false;
    }
    int res = 0;
    return !pila_top(res);
}

int main(int argc, char** argv)
{
    char str[] = "()(())(()))";
    cout << str << endl;
    cout << is_bilanciato(str) << endl;
    return 0;
}