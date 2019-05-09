#include<iostream>
using namespace std;


void stampa(int*P,int m,int i)
{
  if(i==m)
    {cout<<endl; return;}
  cout<<'('<<i<<','<<P[i]<<')'<<' ';
  stampa(P,m,i+1);
}

//PRE_t=(N ha almeno m*m elementi definiti,
//0<=i<=m, j è definito e P ha m-i posizioni)
bool trova(bool* N, int m, int i, int j, int*P){
	//casi base
	if(i>=m) return true;
	if(N[i*m+j]==false) return false;
	//casi ricorsivi
	P[0]=j;
	bool found=false;
	if(j>0){
		found=trova(N,m,i+1,j-1,P+1);
	}
	if(!found){
		found=trova(N,m,i+1,j,P+1);
	}
	if(!found && j<m-1){
		found=trova(N,m,i+1,j+1,P+1);
	}
	return found;
}
//POST_t=(restituisce true sse in N vista come
//X[m][m] c’è un cammino dalla casella (i,j)
//alla riga m-1 composto da sole caselle bianche)
//&&(se la risposta è true, in P [0..m-i-1] c’è il
//cammino più a sinistra con queste proprietà)

/*
CASO BASE
<PRE && cond.base> + calcolo ->POST
 	 > i==m -> restituito true, vuol dire che da i a m
 	 un cammino esiste. =>POST.
 	 > N[i*m+j]==false -> restituisco false, perché
 	 non esiste un cammino dalla casella (i,j).=>POST.
CASO RICORSIVO
<PRE && !cond.base> +calcolo fino alla chiamata -> PRE
	 j è sempre definito grazie ai controlli degli if
	 P ha m-i posizioni perché viene chiamato P+1
	 a ogni chiamata, n resta definito, 0<=i<=m vale
	 perché non vale la condizione base. =>PRE
<ipotesi ricorsiva && PRE> + calcolo =>POST
	poiché vale l'ipotesi ricorsiva, se una delle
	chiamate restituisce true, esiste un cammino
	dalla casella (i,j) perché esiste un cammino
	dalla casella dove comincia la chiamata ric. e
	quella casella è raggiungibile da (i,j). Inoltre,
	P contiene questo cammino perché P+1 contiene
	il cammino dalla casella di partenza della chiamata
	e P[0] contiene il valore j.
	Il cammino restituito è quello più a sinistra
	perché le chiamate sono ordinate da sinistra a destra
	e se una restituisce true le altre non vengono effettuate.
	=>POST.
 *
 * */



bool partenza(bool*N, int m, int j, int*P){
	//caso base
	if(j==m){
		return false;
	}
	//caso ricorsivo
	bool found;
	found = trova(N, m,0,j,P);
	if(found) return true;

	return partenza(N,m,j+1,P);
}

   
int main()
{
  int m;
  cin>>m;
  int*P=new int[m];
  bool*N =new bool[m*m];
  for(int i=0; i<m*m; i++)
          cin>>N[i];
  bool x=partenza(N,m,0,P);//da fare 
  cout<<"start"<<endl;
  if(x)
    { cout<<"esiste un cammino e quello più a sinistra è:"<<endl;
      stampa(P,m,0);
     
    }    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}

