#include <iostream>
#include <fstream>

using namespace std;

struct nodo;
typedef nodo* albero;
struct nodo {
    int value;
    albero left;
    albero right;
};

void stampaAlbero(albero radice, int spazio=0){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}

void inserisci_nodo(albero radice, nodo* new_nodo)
{
    if(radice->value < new_nodo->value)
    {
        if(radice->right == NULL)
            radice->right = new_nodo;
        else
            inserisci_nodo(radice->right, new_nodo);
    }
    else
    {
        if(radice->left == NULL)
            radice->left = new_nodo;
        else
            inserisci_nodo(radice->left, new_nodo);
    }

}
void crea_albero_binario(albero radice, int elementi[], int elementi_length)
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
void print_ricerca(albero radice, int n)
{
    nodo* tmp = radice;
    while(tmp != NULL && tmp->value != n)
    {
        if(n < tmp->value)
        {
            cout << tmp->value << "sinistra" << endl;
            tmp = tmp->left;
        }
        else
        {
            cout << tmp->value << "destra" << endl;
            tmp = tmp->right;
        }
    }
}

int main(int argc, char** argv){
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::fstream fs(argv[1], std::fstream::in);
    if(!fs.is_open()){
        std::cout << "file non trovato" << std::endl;
        return 0;
    }
    
    
    char buffer[12];
    int n[64];
    int i = 0;
    while(!fs.eof() && !fs.fail()){
        fs >> buffer;
        n[i] = atoi(buffer);
        i++;
    }
    fs.close();

    albero radice = new nodo{n[0], NULL, NULL};
    crea_albero_binario(radice, n, i);
    stampaAlbero(radice);
    print_order_asc(radice);
    cout << endl;
    print_ricerca(radice, 765);
    return 0;
}