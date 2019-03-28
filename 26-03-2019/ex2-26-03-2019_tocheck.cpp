//VERSIONE PARZIALE CORRETTA
#include<iostream>
using namespace std;

int S(int* A, int n)
{
    int s = 0;
    int j = 0;
	//PRE: A è un array di un numero >= 0 di (sotto)sequenze (-1)-terminated che finisce per -2 && n>=0
    while(s != n && A[j] != -2) //R: s != n && j>= 0 && s è il numero di -1 presenti A[0,...,j-1] (ovvero di sottosequenze) && (j è il numero di caratteri letti)
    {
        int x = A[j];
        if(x==-1)
        {
            s++;
        }
        j++;
    }
	//POST: A[j]=-2 => non esiste la sottosequenza n OPPURE A[j] != -2 => j-1 è l'indice dell'(n-1) esimo (-1) 
	//CORRETTEZZA:
	//1) j = 0 => j>=0 &&( s==0 && A[0,...,j-1] è vuoto)  => s è il numero di (-1) in A[0,...,j-1]
	//2) R && cond => R: j>=0 && j viene incrementato => j>=0; s è il numero di (-1) in A[0,...,j-1] && A[j]==-1 => s è incrementato
	//	&& j viene incrementato => R
	//3) R && !cond => POST: !cond= s== n || A[j+1]==-2
	// s== n: ci sono n-1 (-1) in A[0,...,j-1] => j+1 è l'indice del primo elemento della sottosequenza n
	// A[j] == -2 && s!=n: s è il numero di (-1) letti e non è n => A non contiene n (-1) => non esiste la sottosequenza n-esima
	
    if(A[j]!=-2)
    {
        return j;
    }
    else
    {
        return -2;
    }
	
}

main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
   cin >>X[i];
    
    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=S(X,n); // da fare
    if(b==-2)
     cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }
