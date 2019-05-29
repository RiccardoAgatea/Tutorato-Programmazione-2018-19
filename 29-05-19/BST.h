#ifndef BST_H
#define BST_H
struct nodo{
    int info;
    nodo* left,*right;
    nodo(int a=0, nodo*b=0, nodo*c=0) 
    {info=a; left=b; right=c;}
    };
    
void stampa_l(nodo*);
nodo* insert(nodo*, int);
bool search (nodo*, int);
bool search(nodo*r, nodo*&, nodo*&, int);
nodo* max(nodo*);
nodo*& min(nodo*&);
int altezza(nodo*);
int altMin(nodo*);
void elim(nodo*&, int x);
#endif
