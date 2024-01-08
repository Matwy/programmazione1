#include <iostream>
#include <fstream>

using namespace std;

int* generate_numbers(int N){
    int* random_array = new int[N];
    for(int i = 0; i < N; i++){
        random_array[i] = rand() % 100;
    }
    return random_array;
}

int ** generate_matrix(int R, int C){
    int** random_matrix = new int*[R];

    // alloco memoria
    for(int i = 0; i < R; i++)
        random_matrix[i] = new int[C];

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            random_matrix[i][j] = rand() % 100;

    return random_matrix;
}

void print_matrix(int** matrix, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}
void print_array(int* arr, int dim){
    for(int i = 0; i < dim; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    // array dinamico da console
    int dim;
    std::cout << std::endl << "dimensione array";
    std::cin >> dim;
    int* arr = new int[dim];
    for(int i = 0; i < dim; i++)
    {
        std::cout << std::endl << "arry[i]: ";
        std::cin >> arr[i];
    }    
    delete[] arr;


    int** random_matrix = generate_matrix(row, col);
    print_matrix(random_matrix, row, col);
    delete[] random_matrix;


    return 0;
}