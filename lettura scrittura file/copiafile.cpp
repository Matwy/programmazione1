#include <fstream>
#include <iostream>

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
    char buffer[24];
    while(!fs_in.eof() && !fs_in.fail())
    {
        fs_in >> buffer;
        fs_out << buffer;
    }
    fs_out << std::endl;

    fs_out.close();
    fs_in.close();

    return 0;
}