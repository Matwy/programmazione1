#include <stdlib.h>
#include <iostream>

int* generate_numbers(int N);
int ** generate_matrix(int R, int C);
void print_matrix(int** matrix, int row, int col);

int main(int argc, char** argv){
    int** random_matrix = generate_matrix(atoi(argv[1]), atoi(argv[2]));
    print_matrix(random_matrix, atoi(argv[1]), atoi(argv[2]));
    delete[] random_matrix;
    return 0;
}

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