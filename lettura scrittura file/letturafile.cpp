#include <fstream>
#include <iostream>

int main(int argc, char** argv){
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::fstream fs(argv[1], std::fstream::in);
    if(!fs.is_open()){
        std::cout << "file non trovato" << std::endl;
        return 0;
    }
    char buffer[1024];
    while(!fs.eof() && !fs.fail()){
        fs >> buffer;
        std::cout << buffer << std::endl;
    }
    fs.close();
    
    return 0;
}