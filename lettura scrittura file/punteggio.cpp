#include<iostream>
using namespace std;

int punteggio(char []);

int main(int argc, char* argv[]){
    char input[32]; char continuare;
    
    do{
        cin >> input;
        int p = punteggio(input);
        if(p == -1) 
            cout << "stringa non valida" << endl;
        else
            cout << "punteggio: " << p << endl;
        
        cout << "continuare (y/n) [y]";
        cin >> continuare;
    }   while(continuare != 'n' );

    return 0;
}

bool is_maiuscola(char c){
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int punteggio(char str[]){
    if (is_maiuscola(str[0]))
        str[0] = str[0] - 'A' + 'a';
    
    if (str[0] < 'a' || str[0] > 'z') return -1;
    
    int somma = 0;
    for(int i = 1; str[i] != '\0'; i++){
        if (is_maiuscola(str[i]))
            str[1] = str[1] - 'A' + 'a';
        if (str[i] < 'a' || str[i] > 'z') return -1;
        
        somma += abs(str[i] - str[i-1]);
    }
    return somma;
}