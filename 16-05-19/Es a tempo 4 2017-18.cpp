#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo *left, *right;
	nodo(int a = 0, nodo *b = 0, nodo *c = 0) {info = a; left = b; right = c;}
};

nodo *alberobil(nodo *r, int k);
nodo *buildtree(nodo *r, int n);
int contaNodi(nodo *root);

int main(int argc, char const *argv[])
{
	cout << "start" << endl;

	int n;
	cin >> n;

	nodo *R = buildtree(0, n);

	stampa_l(R);

	cout << endl << "end";
	return 0;
}

//PRE=(albero(r) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r)=albero(r))
nodo *alberobil(nodo *r, int k)
{
	if (r == NULL)
		return new nodo(k);

	if (contaNodi(r->right) == contaNodi(r->left))
		r->left = alberobil(r->left, k);
	else
		r->right = alberobil(r-> right, k);

	return r;
}
//POST=(albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli una nuova foglia con info=k)

//PRE=(albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo *buildtree(nodo *r, int n)
{
	if (n == 0)
		return r;

	int k;
	cin >> k;

	r = alberobil(r, k);

	return buildtree(r, n - 1);
}
//POST=(restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)

//PRE=(A(root) è ben formato)
int contaNodi(nodo *root)
{
	if (root == NULL)
		return 0;

	return 1 + contaNodi(root->left) + contaNodi(root->right);
}
//POST=(ritorna il numero di nodi di A(root))

int min(int a, int b)
{
	return (a < b) ? a : b;
}