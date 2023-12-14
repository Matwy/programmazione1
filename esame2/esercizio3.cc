#include <iostream>

using namespace std;

bool* init(int dim)
{
    bool* bloom_filter = new bool[dim];
    for(int i = 0; i < dim; i++)
        bloom_filter[i] = false;
    
    return bloom_filter;
}

void insert(bool* bloom_filter, int dim, char* input)
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        if((int)input[i] >= dim)
            bloom_filter[(int)input[i]%dim] = true;
        else
            bloom_filter[(int)input[i]] = true;
    }
}

bool check(bool* bloom_filter, int dim, char* input)
{
    for(int i = 0; input[i] != '\0'; i++)
        if (!bloom_filter[(int)input[i]%dim])return false;
    return true;
}

void deinit(bool* bloom_filter)
{
    delete[] bloom_filter;
}

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}