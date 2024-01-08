#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int * array, int len_array) {
  for (int i=0; i<len_array; i++) {
    for (int j=i+1; j<len_array; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char * argv []) {
	if(argc < 3)
    {
        std::cout << "Usage: " << argv[0] << "<input> <n elementi> <elementi da mostrare>" << std::endl;
        return -1;
    }

    std::fstream fs_in(argv[1], std::fstream::in);
    
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    int DIM = atoi(argv[2]);
    int N = atoi(argv[3]);
    int* arr = new int[DIM];
    std::fstream fs_out("out", std::fstream::out); 
    char buffer[12];
    int i = 0;
    while(fs_in >> buffer)
    {
      int n = atoi(buffer);
      arr[i] = n;
      i++;
    }

    sort_array(arr, DIM);
    for(int i = 0; i < N; i++)
    {
      fs_out << arr[DIM-i-1] << endl;
    }

    fs_out.close();
    fs_in.close();

    return 0;
}
