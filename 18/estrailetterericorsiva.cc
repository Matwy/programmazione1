#include <iostream>

char* estrai(char stringa[], char* result, int indice=0, int indice_risultato=0);

bool is_maiuscola(char c){
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int main(){
    char str[] = "dioCanE";
    
    std::cout << "estrazione: " << str << std::endl;
    
    char* res = new char[80];
    estrai(str, res);
    
    std::cout << "maiuscole " << res << std::endl;

    delete[] res;
    return 0;
}

char* estrai(char stringa[], char* result, int indice, int indice_risultato)
{
    if(is_maiuscola(stringa[indice]))
        result[indice_risultato++] = stringa[indice];

    if(stringa[indice] == '\0')
    {
        result[indice_risultato] = '\0';
        return result;
    }
    estrai(stringa, result, indice+1, indice_risultato);
}
