#include <iostream>
#include <fstream>
using namespace std;

bool is_MIU(char input[]){
    bool last_M = input[0] == 'U';
    int I_counter = 0;
    bool not_I = false;

    for(int i = 0; input[i] != '\0'; i++)
    {
        if(last_M && input[i+1] == '\0' && input[i] != 'M') return false; // regola 1
        
        if(input[i] == 'I')
            I_counter++;

        // regola 3
        if(not_I && input[i] == 'I')
            return false;
        else if (not_I)
            not_I = false;

        if(input[i] == 'M')
            not_I = true;
        
    }
    
    if(I_counter%2 != 0) return false; // regola 2
    
    return true;
}

int main(int argc, char * argv [])
{

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
    if(fs_out.fail()) return -1;
  
    char buffer[255];
    bool res;
    while(fs_in >> buffer)
    {
        std::cout << std::endl << "parola: " << buffer;
        res = is_MIU(buffer);
        std::cout << " " << res << std::endl;

        if(res)
            fs_out << buffer << endl;
    }
    fs_in.close();
    fs_out.close();
  return 0;
}
