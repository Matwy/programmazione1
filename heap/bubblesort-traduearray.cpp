#include <iostream>
#include <fstream>

using namespace std;

void bubble_sort(int* a, int length)
{
    for(int i = 0; i < length-1; i++)
        for(int j = 1; j < length; j++)
        {
            if(a[j-1] > a[j])
            {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
}

int* append(int* a, int* b, int length, int lengthb);

int main()
{
    int alength, blength;
    cout << "a n elementi: ";
    cin >> alength;
    cout << endl <<"b n elementi: ";
    cin >> blength;
    
    int* a= new int[alength]; 
    int* b= new int[blength];
  
    cout << endl <<"Inserire elementi di a " << endl;
    for(int i = 0; i < alength; i++)
        cin >> a[i];
    
    cout << endl <<"Inserire elementi di b " << endl;
    for(int i = 0; i < blength; i++)
        cin >> b[i];

    int* c = append(a, b, alength, blength);
    for(int i = 0; i < alength+blength; i++)
        cout << endl << c[i];

    delete[] a; 
    delete[] b; 
    delete[] c; 
    return 0;
}

int* append(int* a, int* b, int lengtha, int lengthb)
{
    int* c = new int[lengtha + lengthb];

    for(int i = 0; i < lengtha; i++)
        c[i] = a[i];
        
    for(int i = 0; i < lengthb; i++)
        c[i+lengtha] = b[i];
    
    bubble_sort(c, lengtha + lengthb);
    return c;
}
