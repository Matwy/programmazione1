#include <fstream>
#include <iostream>

void crypt(char parola [], int chiave);
void decrypt(char parola [], int chiave);

int main (int argc, char **argv){
    if(argc < 3)
    {
        std::cout << std::endl << "Usage: " << argv[0] << "<file input> <file output>" << std::endl;
        return -1;
    }

    std::fstream input(argv[1], std::ios::in);
    if(input.fail())
    {
        std::cout << "File non valido" << std::endl;
        return -1;
    }

    char inputBuffer[1024];
    int key = 3;
    input >> inputBuffer;

    std::fstream output(argv[2], std::ios::out);
    
    crypt(inputBuffer, key);
    output << inputBuffer << std::endl;
    
    decrypt(inputBuffer, key);
    output << inputBuffer << std::endl;

    input.close();
    output.close();
    return 0;
}

void crypt(char parola[], int chiave)
{
    for (int i = 0; parola[i] != '\0'; i++)
    {
        if(parola[i] + chiave > 'z')
            parola[i] += chiave - 'z' + 'a' -1;
        else
            parola[i] += chiave;
    }
}
void decrypt(char parola[], int chiave){
    for (int i = 0; parola[i] != '\0'; i++)
    {
        if(parola[i] - chiave < 'a')
            parola[i] = parola[i] - chiave + ('z' - 'a') + 1;
        else
            parola[i] -= chiave;
    }
}
