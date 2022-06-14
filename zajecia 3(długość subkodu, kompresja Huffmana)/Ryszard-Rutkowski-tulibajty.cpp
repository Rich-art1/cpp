#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

string NWP(string x, string y)
{
int r1=x.size(), r2=y.size();
int S[r1+1][r2+1];

for(int i=0; i<=r1; i++)
{
    S[i][0]=0;
}
for(int i=0; i<=r2; i++)
{
    S[0][i]=0;
}

for(int i=1; i<=r1; i++)
{
 for(int j=1; j<=r2; j++)
 {
     if(x[i-1]==y[j-1])
     {
         S[i][j]=S[i-1][j-1]+1;
     }
     else
     {
        if(S[i-1][j]>=S[i][j-1])S[i][j]=S[i-1][j];
        else S[i][j]=S[i][j-1];
     }
 }
}

string nwp="";

do {
 if(x[r1-1]==y[r2-1])
    {
        nwp+=x[r1-1]; r1--; r2--;
    }
 else
 if(S[r1-1][r2]>=S[r1][r2-1])
 {
     r1--;
 }
    else
    {
        r2--;
    }
} while (S[r1][r2]!=0);

string wynik;
for(int i=0;i<nwp.size();i++)
{
    wynik=nwp[i]+wynik;
}


return wynik; }

int main()
{
    ifstream wej ("In0301.txt");
    ofstream wyj ("Out0301.txt");

    int i,n;
    string s1="",s2="";
    wej>>n;

    for(i=0;i<n;i++)
    {
        wej>>s1>>s2;

        cout<<NWP(s1,s2).size()<<" "<<NWP(s1,s2);
        cout<<endl;
        wyj<<NWP(s1,s2).size()<<" ";
        wyj<<NWP(s1,s2)<<endl;
    }
}
