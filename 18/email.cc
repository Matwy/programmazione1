#include <iostream>
#include <fstream>

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
bool is_numero(char c){
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

bool is_mail(char* mail);

int main()
{
    std::fstream input("f", std::ios::in);

    char buffer[255];
    bool res;
    while(input >> buffer)
    {
        std::cout << std::endl << "mail: " << buffer;
        res = is_mail(buffer);
        std::cout << " " << res << std::endl;
    }
    input.close();
    return 0;
}

bool is_mail(char* mail)
{
    int utente_length = 0;

    for(int i = 0; mail[i] != '@'; i++)
    {
        if(mail[i] == '\0')
            return false;
        if(!is_maiuscola(mail[i]) && !is_minuscola(mail[i]) &&
            !is_numero(mail[i]) && mail[i] != '.' && mail[i] != '_')
        {
            return false;
        }
        utente_length++;
    }
    
    if(utente_length < 1) return false;

    int dominio_length = 0;
    for(int i = utente_length+1; mail[i] != '\0'; i++)
    {
        if(mail[i] == '@')
            return false;
        if(!is_maiuscola(mail[i]) && !is_minuscola(mail[i]) &&
            !is_numero(mail[i]) && mail[i] != '.' && mail[i] != '_')
        {
            return false;
        }
        dominio_length++;
    }
    if(dominio_length < 1) return false;

    return true;
}