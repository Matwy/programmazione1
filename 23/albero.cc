#include <iostream>
#include <fstream>

using namespace std;

struct nodo;
typedef nodo* albero;
struct nodo {
    char value;
    albero left;
    albero right;
};

void print_order_asc(albero radice);
void crea_albero_binario(albero radice, char elementi[], char elementi_length);
bool inserisci_nodo(albero radice, nodo* new_nodo);
albero init();
bool empty(albero radice);
bool search(albero radice, char n);
bool insert(albero radice, char n);

int main(int argc, char** argv)
{
    albero a = init();
    cout << "vuoto " << empty(a) << endl;
    insert(a, 'e');
    insert(a, 'a');
    insert(a, 'u');
    print_order_asc(a);
    cout << "vuoto " << empty(a) << endl;
    cout << "cerca u " << search(a, 'u') << endl;

    return 0;
}

albero init()
{
    albero radice = new nodo{'\0', NULL, NULL};
    return radice;
}

bool empty(albero radice)
{
    if(radice->value == '\0' && radice->left == NULL && radice->right == NULL) return true;
    return false;
}
bool insert(albero radice, char n)
{
    if(radice->value == '\0')
    {
        radice->value = n;
        return true;
    }
    return inserisci_nodo(radice, new nodo{n, NULL, NULL});
}

bool inserisci_nodo(albero radice, nodo* new_nodo)
{
    if(radice->value == new_nodo->value) return false;
    if(radice->value < new_nodo->value)
    {
        if(radice->right == NULL)
        {
            radice->right = new_nodo;
            return true;
        }
        else
            return inserisci_nodo(radice->right, new_nodo);
    }
    else
    {
        if(radice->left == NULL)
        {
            radice->left = new_nodo;
            return true;
        }
        else
            return inserisci_nodo(radice->left, new_nodo);
    }

}

void crea_albero_binario(albero radice, char elementi[], char elementi_length)
{
    for(int i = 1; i < elementi_length; i++)
    {
        inserisci_nodo(radice, new nodo{elementi[i], NULL, NULL}); 
    }
}
void print_order_asc(albero radice)
{
    if(radice->left != NULL)
        print_order_asc(radice->left);
    cout << radice->value << " ,";
    
    if(radice->right != NULL)
        print_order_asc(radice->right);   
}
bool search(albero radice, char n)
{
    nodo* tmp = radice;
    while(tmp != NULL && tmp->value != n)
    {
        if(n < tmp->value)
            tmp = tmp->left;
        else
            tmp = tmp->right;
        if(n == tmp->value) return true;
    }
    return false;
}