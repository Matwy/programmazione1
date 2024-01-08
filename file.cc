#include <fstream>
#include <iostream>

int main(int argc, char **argv){
    if(argc < 3)
    {
        std::cout << "Usage: " << argv[0] << "<input> <output>" << std::endl;
        return -1;
    }

    std::fstream fs_in(argv[1], std::fstream::in);
    // fs_in >> std::noskipws;
    
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    // scrittura
    std::fstream fs_out(argv[2], std::fstream::out); 
    // std::fstream fs_out(argv[2], std::fstream::out | std::fstream::app); // per aggiungere alla fine del file 
    char buffer[24];
    // char buffer;
    // while(fs_in.get(buffer)) 
    while(fs_in >> buffer)
    {
        fs_in >> buffer;
        fs_out << buffer;
    }
    fs_out << std::endl;

    fs_out.close();
    fs_in.close();

    return 0;
}