#include <iostream>
int calcola_it(int x, int y) 
{
    int res = 0;
    while (x >= y) {
        x = x-y;
        res++;
    }
    return res;
}
int calcola_ric(int x, int y, int res=0) 
{
    if(x < y) return res; 
    return calcola_ric(x-y, y, res+1);
}

using namespace std;

int main(int argc, char** argv)
{
    cout << "it" << calcola_it(23,2) << endl;
    cout << "ric" << calcola_ric(23,2) << endl;

    return 0;
}