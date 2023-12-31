#include <iostream>

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


void print_sottomatrice(int** matrix, int row, int col, int x, int y, int h, int w){
    for(int i = y; i < row && i < y+h; i++){
        for(int j = x; j < col && j < x+w; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}


int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout<< "usage: " << "row col" << std::endl;
        return -1;
    }

    int** random_matrix = generate_matrix(atoi(argv[1]), atoi(argv[2]));
    print_matrix(random_matrix, atoi(argv[1]), atoi(argv[2]));

    int x,y,h,w;
    std::cout << std::endl << "Sottomatrice x";
    std::cin >> x;
    std::cout << std::endl << "Sottomatrice y";
    std::cin >> y;
    std::cout << std::endl << "Sottomatrice h";
    std::cin >> h;
    std::cout << std::endl << "Sottomatrice w";
    std::cin >> w;
    
    if(x == 0 || y == 0) return -1;
    x--;y--;
    
    print_sottomatrice(random_matrix, atoi(argv[1]), atoi(argv[2]), x , y , h , w);


    delete[] random_matrix;

    return 0;
}