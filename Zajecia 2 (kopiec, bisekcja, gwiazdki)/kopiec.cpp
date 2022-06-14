#include <iostream>
#include <fstream>
using namespace std;

void pom(int tab[], int n, int i)
{
    int najw=i;
    int l=2*i+1;
    int p=2*i+2;

    if (l<n && tab[l]>tab[najw])
    {
        najw = l;
    }
    if (p<n && tab[p]>tab[najw])
    {
        najw = p;
    }
    if (najw!=i)
    {
        swap(tab[i], tab[najw]);
        pom(tab, n, najw);
    }
}

void kopcowanie(int tab[], int n)
{
    for (int i=n/2-1; i>=0; i--)
    {
        pom(tab, n, i);
    }
    for (int i=n-1; i>0; i--)
    {
            swap(tab[0], tab[i]);
            pom(tab, i, 0);
    }
}

int main()
{
ifstream wej ("In0201.txt");
ofstream wyj ("Out0201.txt");
int n,i;
wej>>n;
int tab[n];

for(i=0;i<n;i++)
{
    wej>>tab[i];
}

kopcowanie(tab, n);

for (i = 0; i < n; ++i)
{
    wyj<<tab[i] << " ";
}
}
