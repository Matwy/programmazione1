#include <iostream>
#include <ctime>

// Includere qui la libreria da usare, i.e. stack.h o queue.h a
// seconda della richiesta
#include "stack.h"
// #include "queue.h"

#define MAXSIZE 20
using namespace std;
struct list {
  int node;
  struct list * next;
};

bool ** genera(const int N) {
  bool ** result = new bool * [N];
  for (int i = 0; i < N; i++) {
    result[i] = new bool[N]();
    for (int j = 0; j < N; j++) {
      result[i][j] = (bool)(rand()%2);
    }
  }
  return result;
}

void dealloca(bool * * & r, int N) {
  for(int i = 0; i < N; i++) {
    delete [] r[i];
  }
  delete [] r;
  r = NULL;
}

void print(bool ** G, int N) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      std::cout << G[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void print(list * l) {
  std::cout << "Lista: ";
  while(l!=NULL) {
    std::cout << l->node << ((l->next != NULL) ? " " : "");
    l = l->next;
  }
  std::cout << std::endl;
}

void dealloca(list * l) {
  while(l!=NULL) {
    list * t = l;
    l=l->next;
    delete t;
  }
}

// Inserire qui sotto la dichiarazione di visita
list* visita(bool** A, int N, int i);
// Inserire qui sopra la dichiarazione di visita


int main(int argc, char * argv[]) {
  unsigned s = unsigned(time(0));
  srand(s);
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(1688544644);
  int N = 16;
  bool **G = genera(N);
  int i = 1;
  std::cout << "Grafo G["<< N << "][" << N << "]" << std::endl;
  std::cout << "Nodo partenza " << i << std::endl;
  print(G, N);
  list * res = visita(G,N,i);
  print(res);
  dealloca(G,N);
  dealloca(res);
}

// Inserire qui sotto la definizione di visita
list* visita(bool** A, int N, int i)
{
  bool* visited = new bool[N];
    for(int i = 0; i < N; i++)
        visited[i] = false;
  list* result = NULL;
  Stack* s = init();
  push(s, i);
  int nodo;
  while(!isEmpty(s))
  {
    nodo = pop(s);
    visited[nodo] = true;
    result = new list{nodo, result};
    for(int j = 0; j < N; j++){
      if(A[nodo][j] && !visited[j]){
        push(s, j);
      }
    }
  }
  return result;
}
// Inserire qui sopra la definizione di visita
