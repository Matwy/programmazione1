#include <iostream>
#include <cstdlib>

using namespace std;

int coppie(char* str, int n_precedente=11,int index=0, int counter_coppie=0)
{
	if(str[index] == '\0')
		return counter_coppie;

	if(str[index] == n_precedente)
		counter_coppie++;

	return coppie(str, str[index], index+1, counter_coppie);
}

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"

int funzione(int n)
{
	char str[12];
	sprintf(str, "%d", n);
	return coppie(str);
}
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}
