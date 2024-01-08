#include <iostream>

using namespace std;

void numeri_esagonli(int n, int* ,int index=0);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: ./a <N>" << std::endl; 
        return -1;
    }

    int dim = atoi(argv[1]);
    int* res = new int[dim];

    numeri_esagonli(dim, res);

    for(int i = 0; i < dim; i++)
        std::cout << res[i] << ", ";
    std::cout << std::endl;

    delete[] res;
    return 0;
}
void numeri_esagonli(int n, int* res, int index)
{
    if(index >= n) return;
    res[index] = index*(2*index - 1);
    numeri_esagonli(n, res, index+1);
}
