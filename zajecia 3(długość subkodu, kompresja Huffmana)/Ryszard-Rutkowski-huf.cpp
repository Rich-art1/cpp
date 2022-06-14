#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

struct Node
{
    Node *next;
    Node *left;
    Node *right;
    char znak;
    double prawd;
    string kod;
};

void kodowanie (Node * p, string b)
{
  if( p->left!=NULL && p->right!=NULL )
  {
      kodowanie (p->left, b+"0" );
      kodowanie (p->right, b+"1");
  }
  else
  {
    if(p->left!=NULL)
    {
        kodowanie (p->left, b+"0" );
    }
    else
    {
        if(p->right!=NULL)
        {
            kodowanie (p->right, b+"1");
        }
        else
        {
            p->kod=b;
            b="";
        }
    }
    }
  }
void MakeTree ( Node * & root )
{
  Node *p, *r, *v1, *v2, *tempor;

  while( true )
  {
    v1 = root;
    v2 = v1->next;

    if( !v2 )
    {
    break;
    }
    root = v2->next;

    p = new Node;
    p->left = v1;
    p->right = v2;
    p->prawd = v1->prawd + v2->prawd;
    p->znak='_';

    if( !root || ( p->prawd <= root->prawd ) )
    {
      p->next = root;
      root = p;
      continue;
    }
    r = root;
    while( r->next && ( p->prawd >= r->next->prawd ) )
    {
        r = r->next;
    }
    p->next = r->next;
    r->next = p;
  }
    tempor=root;
}

int main()
{
    system("chcp 65001  > nul");
    ifstream wej ("In0305.txt");
    ofstream wyj ("Out0305.txt");

    string s;

    getline(wej,s);

    int i,j,tab[255];

    for(i=0;i<255;i++)
    {
        tab[i]=0;
    }
    for(i=0;i<s.size();i++)
    {
        tab[s[i]]++;
    }
    int licz=0;
    for(i=0;i<255;i++)
    {
        if(tab[i]!=0)
        {
            licz++;
        }
    }
    int c;
    for(i=0;i<s.size();i++)
    {
        c=0;
        for(j=0;j<i;j++)
        if(s[i]==s[j])
        c=1;
        if(c==0)
        wyj<<s[i]<<" "<<tab[s[i]]<<", ";
    }
    wyj<<endl;
    double tab2[licz][2]; //0-litera 1-liczba
    int z=0;

    for(i=0;i<255;i++)
    {
        if(tab[i]!=0)
        {
            tab2[z][0]=i;
            tab2[z][1]=(double)tab[i]/(double)s.size();
            z++;
        }
    }

    double temp,temp2;
    for (i=0; i<licz; i++)
    for (j=0; j<licz-1; j++)
        if (tab2[j][1] >= tab2[j+1][1])
            {
                temp=tab2[j][1];
                tab2[j][1]=tab2[j+1][1];
                tab2[j+1][1]=temp;

                temp2=tab2[j][0];
                tab2[j][0]=tab2[j+1][0];
                tab2[j+1][0]=temp2;
            }
     for(i=0;i<licz;i++)
    {
        wyj<<(char)tab2[i][0]<<" "<<tab2[i][1]<<", ";
    }
    wyj<<endl;

    Node * p;
    Node * root;
    root=NULL;

    for(i=licz-1;i>=0;i--)
    {
      p=new Node;
      p->next=root;
      p->left=NULL;
      p->right=NULL;
      p->znak=tab2[i][0];
      p->prawd=tab2[i][1];
      root= p;
    }
    //wypisuje liste
    while(p)
    {
        wyj<<p->znak<<" ";
        wyj<<p->prawd<<", ";
        p=p->next;
    }
    wyj<<endl;
    p=root;

MakeTree(root);

root=p;
p=root;

while(p->next->next!=NULL)
{
p=p->next;
}

Node *temporary;

temporary=new Node;

temporary->znak='_';
temporary->prawd=1;
temporary->left=p;
temporary->right=p->next;
p->next->next=temporary;

kodowanie(temporary,"");

/*testowanie
while(p->prawd!=1)
    p=p->next;
wyj<<endl<<p->right->left->left->znak<<endl;
*/

string wynik="";
p=root;


for(i=0;i<s.size();i++)
{
    p=root;
    while(p->znak!=s[i])
    {
        p=p->next;
    }
    wynik=wynik+p->kod;
}

for(i=0;i<licz;i++)
{
    p=root;
    while(p->znak!=(char)tab2[i][0])
    {
        p=p->next;
    }
    wyj<<(char)tab2[i][0]<<":"<<p->kod<<", ";
}
wyj<<endl;

int reszta;
reszta=wynik.size()%8;

for(i=0;i<8-reszta;i++)
    wynik=wynik+'0';

string zakodowane="",pom;
int wyn=0;
wyj<<wynik<<endl<<endl;

for(i=0;i<wynik.size();i=i+8)
{
    for(j=7;j>=0;j--)
    {
        if(wynik[i+j]=='1')
        {
             wyn=wyn+pow(2,8-j-1);
            //cout<<pow(2,8-j-1)<<endl;
        }
    }
   // cout<<"wyn: "<<wyn<<"  "<<(char)wyn<<endl;
    zakodowane=zakodowane+(char)wyn;
    wyn=0;
}



}
