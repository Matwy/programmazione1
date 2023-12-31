#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::fstream fs("f", std::fstream::in | std::fstream::out | std::fstream::app);
    if(!fs.is_open()){
        std::cout << "file non trovato" << std::endl;
        return 0;
    }
    
    // aggiungo al vettore n i numeri corrispondenti agli asterischi
    int n[64];
    int dim = 0;
    {
        char buffer[10];
        int i;
        while(!fs.eof() && !fs.fail())
        {
            fs >> buffer;
            for(i = 0; buffer[i] != '\0'; i++);
            n[dim] = i;
            dim++;
        }
    }
    fs.close();

    // calcolo media
    int sum = 0;
    for(int i = 0; i < dim; i++)
        sum += n[i];
    int avg = sum / dim;

    // aggiungo al file gli asterischi corrispondenti alla media
    std::fstream fs_out("f", std::fstream::out | std::fstream::app);
    for(int i = 0; i < avg; i++)
        fs_out << '*';
    fs_out << std::endl;

    if (fs_out.fail()) 
    {
        std::cerr << "Errore durante la scrittura sul file." << std::endl;
        return -1;
    }


    return 0;
}