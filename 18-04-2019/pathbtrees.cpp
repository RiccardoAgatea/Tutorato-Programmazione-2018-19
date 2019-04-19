#include<iostream>
using namespace std;

struct node
{
    int x; //contenuto del nodo
    bool s; //stato del nodo; false <==> non attraversato \ vero <==> attraversato
    node* left;
    node* right;

    node()
    {
        x = 0;
        s = false;
        left = NULL;
        right = NULL;
    }

    node(int label, bool state = false)
    {
        x = label;
        s = state;
        left = NULL;
        right = NULL;
    }
};



bool findPath(node* n)
{
    if(n == nullptr || n->s==true)
    {
        return false;
    }
    else if(n->x==0)
    {
        cout << "Trovato!\n";
        return true;
    }
    else
    {
        n->s = true;
        cout << "Attraverso la casella con contenuto " << n->x << "\n";
        return findPath(n->left) || findPath(n->right);
    }
    
};

const int MAX_LENGTH = 100;

int main()
{
    cout << "Inserisci il numero di caselle:\n";
    int pathLength;
    node* tree = new node[MAX_LENGTH];
    cin >> pathLength;
    cout << "Inserisci i " << pathLength << " numeri nel percorso:\n";
    for(int i = 0; i < pathLength; i++)
    {
        int label;
        cin >> label;
        tree[i].x=label;
        int l = i - label;
        int r = i + label;
        if(l >= 0 & l < pathLength)
        {
            tree[i].left = tree + l;
        }
        if(r>=0 & r < pathLength)
        {
            tree[i].right = tree + r;
        }
    }
    findPath(tree);
    return 0;
};
