#include <iostream>
#include <fstream>

using namespace std;

bool compare(char* a, char* b)
{
    int indice_a = 0;
    for(int i = 0; b[i] != '\0'; i++)
    {
        if(b[i] == a[indice_a])
            indice_a++;
        else
            indice_a = 0;

        if(a[indice_a] == '\0')
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: ./a <filename> <stringa>" << std::endl; 
        return -1;
    }
    char* parola_da_cercare = argv[2];

    std::fstream fs_in(argv[1], std::fstream::in);
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    char buffer[24];
    bool find = false;
    while(fs_in >> buffer && !find)
    {        
        if(compare(parola_da_cercare, buffer))
            find = true;
    }
    fs_in.close();

    if(find == true)
        cout << "trovata" << endl;
    else
        cout << "non trovata" << endl;

    return 0;
}