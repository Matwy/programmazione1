#include <fstream>
#include <iostream>

using namespace std;

bool is_minuscola(char c){
    if(c >= 'a' && c <= 'z')
        return true;
    return false;
}
bool is_maiuscola(char c){
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
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
    
    // scrittura
    std::fstream fs_out(argv[2], std::fstream::out);
    char carattere;
    fs_in.get(carattere);
    if (is_minuscola(carattere)){
        carattere = carattere - 'a' + 'A';  
        fs_out << carattere;
    }

    bool maiuscola = false;
    while(fs_in.get(carattere) && !fs_in.fail())
    {
        if(carattere == '.' || carattere == '!' || carattere == '!'){
            maiuscola = true;
        }
        if(is_maiuscola(carattere) && maiuscola){
            maiuscola = false;
        }
        if (is_minuscola(carattere) && maiuscola){
            carattere = carattere - 'a' + 'A';  
            maiuscola = false;
        }

        fs_out << carattere;
    }
    fs_out << std::endl;

    fs_out.close();
    fs_in.close();

    return 0;
}