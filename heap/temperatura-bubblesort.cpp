#include <fstream>
#include <iostream>

using namespace std;

void bubble_sort(float* a, int length){
    for(int i = 0; i < length-1; i++)
        for(int j = 1; j < length; j++)
        {
            if(a[j-1] < a[j])
            {
                float tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
}

int main(int argc, char **argv){
    if(argc < 4){
        cout << "Usage: <filename> <n temperature alte> <nMax>" << std::endl;
        return -1;
    }

    fstream fs(argv[1], ios::in);
    const int N = atoi(argv[2]);
    const int M = atoi(argv[3]);

    if(fs.fail())
    {
        cout << "file inestente" << endl;
        return -1;
    }

    float tmp;
    float* temperature = new float[M];
    int i = 0;
    while(fs >> tmp){
        temperature[i] = tmp;
        i++;
    }
    
    bubble_sort(temperature, M);

    for(int i = 0; i < N; i++){
        cout << temperature[i] << endl;
    }

    delete[] temperature;
    return 0;
}