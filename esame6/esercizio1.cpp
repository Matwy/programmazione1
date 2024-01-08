#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << "<input>" << std::endl;
        return -1;
    }

    std::fstream fs_in(argv[1], std::fstream::in);
    
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    char sequenza[256];
    cout << "sequenza: ";
    cin >> sequenza;

    char buffer[24];
    while(fs_in >> buffer)
    {
      int indice_sequenza = 0;
      for(int i = 0; buffer[i] != '\0'; i++)
      {
        if(sequenza[indice_sequenza] == buffer[i] || sequenza[indice_sequenza] == '*')
          indice_sequenza++;
        else
          indice_sequenza = 0;
        
        if(sequenza[indice_sequenza] == '\0')
        {
          cout << buffer << endl;
          break;
        }
      }
    }

    fs_in.close();

    return 0;
}