#include <fstream>
#include <iostream>
using namespace std;

bool parole_uguali(char[], char[]);
int main(int argc, char** argv){  
    if(argc < 4)
    {
        cout << "Usage: " << argv[0] << "<in> <in> <out>" << endl;
        return -1;
    }

    fstream inputa, inputb, outputc;
    inputa.open(argv[1], ios::in);
    inputb.open(argv[2], ios::in);
    if(inputa.fail() || inputb.fail())
    {
        cout << "file in lettura inesistenti";
        return -1;
    }

    outputc.open(argv[3], ios::out);

    char parole_file_a[1000][100];
    int counter_parole_file_a = 0;
    for(int i = 0; !inputa.eof(); i++)
    {
        inputa >> parole_file_a[i];
        outputc << parole_file_a[i];
        counter_parole_file_a++;
    }

    bool parola_uguale = false;
    char parola[100];
    while(!inputb.eof())
    {
        inputb >> parola;
        for(int i = 0; i < counter_parole_file_a; i++)
        {
            if(parole_uguali(parola, parole_file_a[i]))
                parola_uguale = true;
        }

        if (!parola_uguale)
            outputc << parola;
        parola_uguale = false;
    }
    outputc << endl;
    inputa.close();
    inputb.close();
    outputc.close();

}

bool parole_uguali(char p1[], char p2[]){
    int i;
    for(i = 0; p1[i] != '\0'; i++){
        if(p1[i] != p2[i]) return false;
    }
    if(p2[i] != '\0') return false;
    return true;
}