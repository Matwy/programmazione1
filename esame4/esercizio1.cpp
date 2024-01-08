#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char* ruota_array(char* vet, int dim, int rotazione)
{
    char* result = new char[dim];
    for(int i = 0; i < dim; i++)
    {
        int index = i-rotazione;
        while (index < 0)
            index += dim;
        
        result[index] = vet[i];
    }
    return result;
}
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

int get_testa(char* buffer)
{

  int i = 0;
  while(!is_maiuscola(buffer[i]) && !is_minuscola(buffer[i]))
  {
    i++;
  }
  return i;
}
int get_coda(char* buffer)
{
  int i = strlen(buffer)-1;
  while(!is_maiuscola(buffer[i]) && !is_minuscola(buffer[i]))
  {
    i--;
  }
  return i+1;
}
char* get_centro(char* buffer, int testa, int coda)
{
  char* result = new char[strlen(buffer)];
  int i;
  for(i = testa; i < coda-1; i++)
    result[i] = buffer[i];
  return result;
}

int main(int argc, char **argv){
    if(argc < 3)
    {
        std::cout << "Usage: " << argv[0] << "<input> <output>" << std::endl;
        return -1;
    }

    std::fstream fs_in(argv[1], std::fstream::in);
    
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }

    int shifting;
    std::cout << std::endl << "valore shifting ";
    std::cin >> shifting;

    std::fstream fs_out(argv[2], std::fstream::out); 
    char buffer[24];
    while(fs_in >> buffer)
    {
        int testa = get_testa(buffer);
        int coda = get_coda(buffer);
        char* centro = get_centro(buffer, testa, coda);
        cout << centro << endl;
        char* ruotato = ruota_array(centro, strlen(centro), shifting);
        
        for(int i = 0; i < testa; i++)
        {
          fs_out << buffer[i];
        }

        fs_out << ruotato << coda << " ";

        for(int i = coda; i < strlen(buffer); i++)
        {
          fs_out << buffer[i];
        }


        delete[] centro,ruotato;
    }
    fs_out << std::endl;

    fs_out.close();
    fs_in.close();

    return 0;
}