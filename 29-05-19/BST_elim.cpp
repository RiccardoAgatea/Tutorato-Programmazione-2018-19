#include "BST.h"
#include<iostream>
using namespace std;

//PRE=(albero(r) ben formato e non vuoto)
nodo *&min(nodo *&r)
{
	if (r->left == NULL)
		return r;

	return min(r->left);
}
//POST=(ritorna il nodo con campo info minimo in albero(r) attraverso una reference al puntatore con cui è referenziato nell'albero)

//PRE=(albero(r) è ben formato)
void elim(nodo *&r, int x)
{
	if (r != NULL) // Caso base (1)
	{
		if (r->info == x) //Caso base (2)
		{
			if (r->left == NULL && r->right == NULL)
				r = NULL;
			else if (r->right == NULL)
				r = r->left;
			else if (r->left == NULL)
				r = r->right;
			else
			{
				nodo *&y = min(r->right);
				nodo *p = y;
				y = y->right;
				p->right = r->right;
				p->left = r->left;
				r->right = NULL;
				r->left = NULL;
				r = p;
				//delete r;
			}
		}
		else if (x < r->info) //Caso ricorsivo (1)
		{
			elim(r->left, x);
		}
		else //if(x > r->info) Caso ricorsivo (2)
		{
			elim(r->right, x);
		}
	}
}
//POST=(se in albero(r) è presente un nodo con campo info == x, questo viene rimosso, mantenendo le proprietà del BST)

/*
Caso base (1):
r==NULL => albero(r) vuoto => non c'è un nodo con ampo info == x
	=> è corretto non fare nulla => POST

Caso base (2):
(r->info == x) => bisogna eliminare la radice
(r->left == NULL && r->right == NULL) => la radice è anche una foglia =>
	è corretto eliminarla dall'albero, svuotandolo
!(r->left == NULL && r->right == NULL) => per le leggi di De Morgan
	(r->left != NULL || r->right != NULL) (*)
(r->right == NULL) && (*) => (r->left != NULL) => è corretto sostituire r con 	r->left, come indicato nel testo
analogamente per (r->left == NULL)
(r->right != NULL) && (r->left != NULL) => PRE_min è verificata
	=> per POST_min, y è l'handle al nodo con campo info minimo di albero(r->right)
	=> è corretto sostituire r con y, nel modo indicato nel testo
Segue la POST

Caso ricorsivo (1):
(r != NULL) && PRE => albero(r->left) è ben formato =>
	PRE_ric è verificata. Per hp induttiva, assumo che sia vera POST_ric dopo la chiamata ricorsiva:
	(se in albero(r->left) è presente un nodo con campo info == x, questo viene rimosso, mantenendo le proprietà del BST) => il nodo in questione è stato rimosso anche da albero(r), mantenendo ancora le proprietà di BST, in quanto albero(r->right) non è stato modificato, e i nodi presenti in albero(r->left) prima della chiamata sono stati eventualmente riordinati, ma non altrimenti modificati, quindi hanno ancora campo info > r->info.

Analogamente è vero per il caso ricorsivo (2)
 */

//NB: Il motivo per cui non funzionava è che nel caso in cui r abbia due figli non veniva mai riassegnato r a p. Chiaramente, avendo sostituito il nodo radice con il nodo puntato da p, va anche "spostato" r perchè punti al nuovo nodo radice.