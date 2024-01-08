#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(char* str);
/* Inserire qui sopra la dichiarazione della funzione extract */
char* extract_ric(char* str, int index=0, int n_chiocciole=0);

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char* extract(char* str)
{
    return extract_ric(str);
}

/* Inserire qui sopra la definizione della funzione estract */
char* extract_ric(char* str, int index, int n_chiocciole)
{
    char* result;
    if(str[index] == '\0')
    {
        result = new char[n_chiocciole+1];
        result[n_chiocciole] = '\0';
    }
    else if(str[index] == '@')
    {
        result = extract_ric(str, index+1, n_chiocciole+1);
        result[n_chiocciole] = '@';
    }
    else
        result = extract_ric(str, index+1, n_chiocciole);
    return result;
}
