#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int Licz=0;

long long silnia(int a)
{
 long long c=1;
 int b=2;
 while(b<=a)
 {
     c=b*c;
     b++;
     Licz++;
    }
return c;
}

int main()
{
    cout<<"Wybierz zadanie"<<endl<<"1. Zadanie 1 podpunkt 1 i 5(wyliczanie symbolu Newtona z definicji i iteracyjnie z trojkata Pascala))"<<endl<<"2. Zadanie 5 (Wyznaczanie wszystkich liczb pierwszych z przedzia³u)"<<endl;
    int zad;
    cin>>zad;

    if(zad==1)
    {
    ifstream wej ("In0101.txt");
    ofstream wyj ("Out0101.txt");
    long long sn1;
    int sn5,licz5,n,k,i,j;

    wej>>n>>k;
    sn1=silnia(n)/(silnia(k)*silnia(n-k));
    Licz++;

    wyj<<"n="<<n<<" k="<<k<<endl<<"SN1 = "<<sn1<<", licz = "<<Licz<<endl;

    int tab[n+1][n+1]={0};
    int licz2=0;
    tab[0][0]=1;
    for(i=1;i<=n;i++)
    {
        tab[i][0]=1;
        tab[i][i]=1;
    }
    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
    {
        tab[i][j]=tab[i-1][j-1]+tab[i-1][j];
        licz2++;
    }
    /* test trojkata pascala
        for(i=0;i<=n;i++)
    {
        cout<<endl;
        for(j=0;j<i+1;j++)
        cout<<tab[i][j]<<" ";
    }
*/
    sn5=tab[n][k];

    wyj<<"SN5 = "<<sn5<<", licz = "<<licz2;
    }

    if(zad==2)
    {
    ifstream wej ("In0105.txt");
    ofstream wyj ("Out0105.txt");
    int a,b,c,i,j,liczby=0,operacje=0;
    wej>>b>>a;
    int tab[a+1]={0};
    tab[0]=1;
    tab[1]=1;

    for(i=2;i<=sqrt(a);i++)
    {
        if(tab[i]==0)
        {
            for(j=i*i;j<=a;j=j+1)
            {
                if(j%i==0)
                {
                    tab[j]=1;
                    operacje++;
                }
            }
            operacje++;
        }
    }

    wyj<<"przedzia³: ["<<b<<","<<a<<"]"<<endl;
    wyj<<"I metoda:"<<endl;

    for(c=b;c<=a;c++)
    {
        if(tab[c]==0)
        {
            operacje++;
            wyj<<c<<" ";
            liczby++;
        }
    }

    wyj<<endl<<"iloœæ liczb pierwszych = "<<liczby<<"; "<<"iloœæ wykonanych operacji elementarnych = "<<operacje<<endl;

    operacje=0;
    int q;
    wyj<<"II metoda:"<<endl;

    for(i=b;i<=a;i++)
    {
        for(j=2;j<=a;j++)
        {
            if(i%j==0)
            {
                q++;
                operacje++;
            }
        }
        if(q<2 && i>=2)
        {
            wyj<<i<<" ";
            operacje++;
        }
        q=0;
    }

    wyj<<endl<<"iloœæ liczb pierwszych = "<<liczby<<"; "<<"iloœæ wykonanych operacji elementarnych = "<<operacje;
    }
}
