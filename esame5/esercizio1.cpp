#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool is_maiuscola(char c){
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}
bool is_minuscola(char c){
    if(c >= 'a' && c <= 'z')
        return true;
    return false;
}

char only_minuscola(char c)
{
    if(is_maiuscola(c))
        return c - 'A' + 'a';
    if(is_minuscola(c))
        return c;
    return c;
}
char* ruota_array(char* vet, int dim, int rotazione)
{
    char* result = new char[dim+1];
    for(int i = 0; i < dim; i++)
    {
        int index = i+rotazione;
        while (index > dim-1)
            index -= dim;
        
        result[index] = vet[i];
    }
    result[dim] = '\0';
    return result;
}
bool compare(char* a, char* b)
{
    int indice_a = 0;
    for(int i = 0; b[i] != '\0'; i++)
    {
        if(b[i] == a[indice_a])
            indice_a++;
        else
            indice_a = 0;
        cout << indice_a << endl;
        if(a[indice_a] == '\0')
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: ./a <file>" << std::endl; 
        return -1;
    }

    char sequenza[256];
    cout << "sequenza: ";
    cin >> sequenza;

    for(int i = 0; sequenza[i] != '\0'; i++)
        sequenza[i] = only_minuscola(sequenza[i]);

    int shifting;
    std::cout << std::endl << "valore shifting ";
    std::cin >> shifting;
    char* ruotato = ruota_array(sequenza, strlen(sequenza), shifting);

    std::fstream fs_in(argv[1], std::fstream::in);

    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    cout << ruotato << std::endl;
    char buffer[255];
    int n_occorrenze = 0;
    while(fs_in >> buffer)
    {
        int index_r = 0;
        for(int i  = 0; i < strlen(buffer); i++)
        {
            if(buffer[i] == ruotato[index_r])
            {
                index_r++;
            }
            else
                index_r = 0;

            if (ruotato[index_r] == '\0')
            {
                n_occorrenze++;
                index_r = 0;
            }
        }
    }
    fs_in.close();
    cout << n_occorrenze << endl;
    delete[] ruotato;
    return 0;
}