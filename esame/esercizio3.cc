#include <iostream>
#include "pila.h"


using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int [][5], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 0, 4);
   
    return 0;
}

bool arrivato(int x_arrivo, int y_arrivo){
    cella arrivo;
    top(arrivo);
    if(arrivo.indiceRiga == x_arrivo &&arrivo.indiceColonna == y_arrivo)
        return true;
    return false;
}
bool muovi(int labirinto[][5], int labirinto_visitato[][5], int x_arrivo, int y_arrivo)
{
    bool direzione_presa = false;
    cella a;
    top(a);
    int x = a.indiceRiga;
    int y = a.indiceColonna;
    if(arrivato(x_arrivo, y_arrivo)){
        return true;
    }
    
    // destra
    if(x < 4 && labirinto[y][x+1] == 1 && labirinto_visitato[y][x+1] == 0 && !arrivato(x_arrivo, y_arrivo))
    {
        direzione_presa = true;
        x++;
        labirinto_visitato[y][x] = 1;

        cella* c = new cella;
        c->indiceColonna = y;
        c->indiceRiga = x;
        push(*c);

        muovi(labirinto, labirinto_visitato, x_arrivo, y_arrivo);
    }
    // sinistra
    if(x > 0 && labirinto[y][x-1] == 1 && labirinto_visitato[y][x-1] == 0 && !arrivato(x_arrivo, y_arrivo))
    {
        direzione_presa = true;
        x--;
        labirinto_visitato[y][x] = 1;

        cella* c = new cella;
        c->indiceColonna = y;
        c->indiceRiga = x;
        push(*c);

        muovi(labirinto, labirinto_visitato, x_arrivo, y_arrivo);
    }
    // su
    if(y > 0 && labirinto[y-1][x] == 1 && labirinto_visitato[y-1][x] == 0  && !arrivato(x_arrivo, y_arrivo))
    {
        direzione_presa = true;
        y--;
        labirinto_visitato[y][x] = 1;

        cella* c = new cella;
        c->indiceColonna = y;
        c->indiceRiga = x;
        push(*c);

        muovi(labirinto, labirinto_visitato, x_arrivo, y_arrivo);
    }
    // giu
    if(y < 4 && labirinto[y+1][x] == 1 && labirinto_visitato[y+1][x] == 0  && !arrivato(x_arrivo, y_arrivo))
    {
        direzione_presa = true;
        y++;
        labirinto_visitato[y][x] = 1;

        cella* c = new cella;
        c->indiceColonna = y;
        c->indiceRiga = x;
        push(*c);

        muovi(labirinto, labirinto_visitato, x_arrivo, y_arrivo);
    }
    if(!arrivato(x_arrivo, y_arrivo) && direzione_presa){
        pop();
    }
    if(!arrivato(x_arrivo, y_arrivo)){
        return false;
    }
    return true;
}

void risolviLabirinto(int labirinto[][5], int x_arrivo, int y_arrivo){
    int x = 0;
    int y = 0;
    int labirinto_visitato[5][5] = {
        { 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };

    init();
    cella* init = new cella;
    init->indiceColonna = y;
    init->indiceRiga = x;
    push(*init);

    bool res = muovi(labirinto, labirinto_visitato, x_arrivo, y_arrivo);
    if(!res){
        cout << "Nessun percorso possibile" << endl;
        return;
    }
    cella stampa;
    int i = 0;
    top(stampa);
    do{
        cout << '[' << stampa.indiceColonna << ',' << stampa.indiceRiga << ']' << "  ";
    } while(pop() && top(stampa));
}