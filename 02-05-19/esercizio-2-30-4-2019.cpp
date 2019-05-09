#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};

//PRE=(L(n) è una lista ben formata e ordinata)
nodo* inserisci(nodo*n,int x){
	//caso base (lista vuota)
	if(n==0){
		nodo * newn = new nodo(x,0);
		return newn;
	}
	// caso ricorsivo
	if(n->info>x){
		nodo * newn = new nodo(x,n);
		return newn;
	}
	n->next = inserisci(n->next,x);
	return n;
}
//POST=(restituisce la lista ben formata e ordinata
// ottenuta da L(n) inserendo un nuovo nodo con
// campo info=x nella posizione opportuna)

/*
 //CASO BASE
<PRE && condizioni base> + computazione -> POST
L(n) è vuota, viene creato un nuovo nodo con campo
info=x, e restituito un puntatore a esso. =>POST
 //CASO RICORSIVO
  * Vale l'ipotsi ricorsiva.
  <PRE && !condizioni base> + computazione ->PRE
  quando effettuo la chiamata ricorsiva.
  caso A: n->info>x
  	  creo un nuovo nodo che ha come campo info x, e
  	  campo next che punta a n. Poiché vale la PRE,
  	  ogni nodo in L(n) è maggiore di x. Quindi
  	 restituendo il puntatore al nuovo nodo ho la POST.
  caso B: n->info<=x
  	  n non punta alla posizione dove aggiungere il
  	  nuovo nodo. L(n->next) è una lista ben formata e
  	  ordinata, perché è una sottolista di L(n) e l(n)
  	  non è stata modificata.
-per l'ipotesi ricorsiva assumo che la chiamata ricorsiva
restituisca la lista L(n->next) ordinata e ben formata,
 con inserito un nuovo nodo con campo info=x nella
 posizione opportuna.
 	 al nodo n collego la lista restituita
 	 dalla chiamata ricorsiva. Poiché essa è ordinata,
 	 e n->info è minore di ogni nodo in essa contenuta,
 	 anche L(n) è ben formata e ordinata, e vi è stato
 	 aggiunto il nuovo nodo con campo info = x.
 	 =>POST.

  *
 */



nodo* F(nodo*n){
	int x;
	cin>>x;
	// caso base
	if(x ==-1){
		return n;
	}
	// caso ricorsivo
	n=inserisci(n,x);
	F(n);
}

void stampa_lista(nodo* n){
	//caso base
	if(n==0){
		cout<<"lista vuota"<<endl;
		return;
	}
	// caso base 2
	if(n->next==0){
		cout<<n->info<<endl;
		return;
	}
	//caso ricorsivo
	cout<<n->info<<" -> ";
	stampa_lista(n->next);
}

int main()
{
  cout<<"start"<<endl;
  nodo* L= F(0);
  stampa_lista(L);
  cout<<"end"<<endl;
}
