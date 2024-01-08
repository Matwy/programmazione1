#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char numeroCodificato []) 
{
    init();
    int numero = 0;
    int dim = strlen(numeroCodificato);
    int tmp;
    int esponente = dim;
    for(int i = 0; i <= dim; i++)
    {
        push(i+1);
        if(numeroCodificato[i] == 'I' || i == dim)
        {
            while(!vuota())
            {
                top(tmp);
                numero += tmp*pow(10,esponente);
                esponente--;
                pop();
            }
        }
    }
    return numero;
}
