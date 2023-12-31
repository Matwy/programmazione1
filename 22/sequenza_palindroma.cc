#include <iostream>
#include <fstream>

using namespace std;

bool is_palindroma(int*, int, int index = 0 );
int main(int argc, char** argv)
{
    int dim;
    std::cout << std::endl << "dimensione array";
    std::cin >> dim;

    if(dim < 1 || dim > 100)
    {
        cout << "dimensione non valida" << endl;
        return -1;
    }
    
    int* arr = new int[dim];
    for(int i = 0; i < dim; i++)
    {
        std::cout << std::endl << "arry[i]: ";
        std::cin >> arr[i];
    }
    
    std::cout << std::endl << "is_palindroma: " << is_palindroma(arr, dim) << std::endl;
    delete[] arr;
    return 0;
}

bool is_palindroma(int* arr, int dim , int index)
{
    if(dim-1-index - index < 1) return true;

    if(arr[dim-1-index] != arr[index]) return false;

    if(arr[dim-1-index] == arr[index])
        return is_palindroma(arr, dim, index+1);
}
