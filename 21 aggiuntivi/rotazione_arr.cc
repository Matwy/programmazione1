#include <iostream>

char* ruota_array(char* vet, int dim, int rotazione)
{
    char* result = new char[5];
    for(int i = 0; i < dim; i++)
    {
        int index = i-rotazione;
        while (index < 0)
            index += dim;
        
        result[index] = vet[i];
    }
    return result;
}
char* generate_random_char(int N){
    char* random_array = new char[N];
    for(int i = 0; i < N; i++){
        random_array[i] = 'A' + ( rand() % ('A' - 'Z'));
    }
    return random_array;
}

int main(int argc, char** argv)
{
    int dim;
    int j;
    std::cout << std::endl << "Rotazione array";
    std::cin >> j;
    std::cout << std::endl << "dim ";
    std::cin >> dim;
    char* vet = generate_random_char(dim);
    
    char* res = ruota_array(vet, dim, j);
    for(int i = 0; i < dim; i++)
        std::cout << res[i] << std::endl;
    
    delete[] res;
    delete[] vet;
    return 0;
}