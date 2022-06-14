#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x)
{
    return x*x-2;
}


double pierwiastek(double a,double b,double E,double(*funkcja)(double))
{
    if(a>b)
    {
        return -1;
    }
    double srodek=(a+b)/2;
    if(abs(funkcja(srodek))<=E)
    {
        return srodek;
    }
    if(funkcja(srodek)>E)
    {
        return pierwiastek(a,srodek,E,funkcja);
    }
    else
    {
        return pierwiastek(srodek,b,E,funkcja);
    }
}

int main(int argc, char* argv[])
{
    ifstream wej ("In0210.txt");
    ofstream wyj ("Out0210.txt");

    double a,b,e;
    wej>>a>>b>>e;

    wyj<<pierwiastek(a,b,e,f)<<endl;

    return 0;
}
