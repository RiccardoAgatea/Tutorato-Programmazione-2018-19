#include<iostream>
#include "BST.h"
using namespace std;
//contiene le implementazioni delle 7 funzioni richieste

void stampa_l(nodo* r)
{
    if(r==0)
    {
        cout << "_";
        return;
    }
    cout << r->info << "(";
    stampa_l(r->left);
    cout << ",";
    stampa_l(r->right);
    cout << ")";
}

//PRE: r è un albero ben formato
nodo* insert(nodo*r, int x)
{
  //caso base 0
  if(r==0)
    //essendo l'albe
    return new nodo(x);
  if(!r->left && x < r->info) 
  {
    r->left = new nodo(x);
    return r->left;
  }
  else if(!r->right && x > r->info) 
  {
    r->right = new nodo(x);
    return r->right;
  }
  else
  {
    return insert(x < r->info ? r->left : r->right,x);
   }
 }
 //POST: r è un BST ben formato e contiene x al posto giusto 
 
bool search(nodo* r, int x)
{
    if(!r)
      return false;
    if(r->info==x)
    {
        return true;
    }
    else
    {
        return r->info < x ? search(r->right, x) : search(r->left, x);
    }
}

nodo* max(nodo*r)
 {
         if(r->right)
         {
             return max(r->right);
         }
         else
         {
             return r;
         }
 }
 
nodo*& min(nodo*& r)
 {
         if(r->left)
         {
             return min(r->left);
         }
         else
         {
             return r;
         }
 }
 
int altezza(nodo*r)
{
  if(r==0 || !r->left && !r->right)
    return 0;
  int lHeight = altezza(r->left);
  int rHeight = altezza(r->right);
  return 1+max(lHeight,rHeight);
}
  
int altMin(nodo*r)
{
  if(r==0 || !r->left && !r->right)
    return 0;
  int lHeight = altMin(r->left);
  int rHeight = altMin(r->right);
  return 1+min(lHeight,rHeight);
}

void elim(nodo*& r, int x)
{
  if(r->info==x)
  {
    if(!r->left && !r->right)
    {
        r = NULL;
    }
    else if(r->left && !r->right)
    {
        r = r->left;
    }
    else if(!r->left && r->right)
    {
        r = r->right;
    }
    else
    {
        nodo*& y = min(r->right);
        //il seguente metodo è valido SOLO per alberi con campi info non strutturati, ovvero int char e float et simili
        //per caso generale riferirsi a BST_elim.cpp
        r->info = y->info;
        elim(y, y->info);
    }
    
  }
  else if(x < r->info)
  {
    elim(r->left, x);
  }
  else
  {
    elim(r->right, x);
  }
}








