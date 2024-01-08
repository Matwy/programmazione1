#include <iostream>
#include <fstream>

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

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: ./a <file>" << std::endl; 
        return -1;
    }

    char sequenza[256];
    cout << "sequenza: ";
    cin.getline(sequenza, 256);

    std::fstream fs_in(argv[1], std::fstream::in);
    fs_in >> std::noskipws;

    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    char buffer;
    while(fs_in.get(buffer))
    {
        char c = only_minuscola(buffer);
        for(int j = 0; sequenza[j] != '\0'; j++)
            if(c == only_minuscola(sequenza[j]))
                cout << buffer;
    }
    fs_in.close();
    cout << endl;

    return 0;
}