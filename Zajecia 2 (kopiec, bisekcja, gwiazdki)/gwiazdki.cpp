#include <iostream>
#include <fstream>
using namespace std;

void rekurencja(int n, int p)
{
        ofstream wyj ("Out0202.txt",ios_base::app);
    if(n==1)
    {
        for(int i=p;i>0;i--)
            wyj<<" ";

        wyj<<"*"<<endl;
    }
    else
    {
        rekurencja(n-2,p+1);

        for(int i=p;i>0;i--)
            wyj<<" ";

        for(int i=0;i<n;i++)
            wyj<<"*";

        wyj<<endl;
    }
}
int main()
{
    ifstream wej ("In0202.txt");
    ofstream wyj ("Out0202.txt");
    wyj<<"";
    int n,p=0;
    wej>>n;

    rekurencja(n,p);
}
