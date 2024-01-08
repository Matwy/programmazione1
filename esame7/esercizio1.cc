#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    if(argc < 3)
    {
        std::cout << "Usage: " << argv[0] << "<input> <output>" << std::endl;
        return -1;
    }

    std::fstream fs_in(argv[1], std::fstream::in);
    fs_in >> std::noskipws;
    
    if(fs_in.fail())
    {
        std::cout << "file in lettura non esiste" << std::endl;
        return -1;
    }
    
    std::fstream fs_out(argv[2], std::fstream::out); 
    char buffer[256];
    int line_length;
    char linea_lunga[256];
    int linea_lunga_length = -1;
    while(fs_in.getline(buffer, 256))
    {
        line_length = 0;
        for(int i = 0; buffer[i] != '\0'; i++)
            line_length ++;

        if(line_length > linea_lunga_length)
        {
            int i = 0;
            for(; buffer[i] != '\0'; i++)
                linea_lunga[i] = buffer[i];
            linea_lunga[i] = '\0';
            linea_lunga_length = line_length;
        }
        fs_out << line_length << endl;
    }
    fs_out << linea_lunga << endl;
    fs_out.close();
    fs_in.close();

    return 0;
}