#include<iostream>

using namespace std;

struct nodo{
    int info; 
    nodo* left,*right; 
    nodo(int a=0, nodo* b=0, nodo*c=0){
        info=a; left=b; right=c;
    }
};

/**
 * PRE
 * 
 *  R è un albero ben costruito e bilanciato
*/
int peso(nodo* R) {
    if (!R) { // (1)
        // PRE && if => R vuoto => numero di nodi dell'albero = 0
        return 0;
    }
    // PRE && !(1) => R non vuoto => numero di nodi dell'albero = numero di nodi nel ramo sx + numero di nodi nel ramo dx + 1
    return peso(R->left) + peso(R->right) + 1;
}
/**
 * POST
 * 
 *  Peso restituisce il numero delle radici e delle foglie dell'albero
 * 
*/

/**
 * PRE
 * 
 *  R è un albero ben costruito e bilanciato
 * 
*/
void insertBil(nodo* & R, int n) {
    if (!R) { //(1)
        // PRE && (1) => R vuoto => per essere bilanciato inserisco il nodo in questo punto
        R = new nodo(n);
    } else {
        // PRE && (!1) => R non vuoto 
        if (peso(R->left) > peso(R->right)) { //(2)
            // R non vuoto && (2) => l'albero ha più nodi a sinistra che a destra => per mantenere il bilanciamento inserisco il nodo a dx
            insertBil(R->right, n);
        } else {
            // R non vuoto && !(2) && PRE => l'albero ha un numero di nodi a dx uguale a quelli a sx => devo inserirlo a dx
            insertBil(R->left, n);
        }
    }
}
/**
 * POST
 * 
 *  R è un albero ben costruito e bilanciato e contiene una foglia con n come campo info
*/

/**
 * PRE
 * 
 *  L albero ben costruito e bilanciato
 *  dim > 0
 * 
*/
nodo * buildtree(nodo* R, int dim) {
    int n;
    cin>>n;
    /**
     * PRE_insertBil
     *  PRE => R è un albero ben costruito e bilanciato  
     *  cin>>n => n contiene un intero
     * */
    insertBil(R, n);
    /**
     * 
     * POST_insertBil
     *  per ipotesi induttiva, PRE_insertBil => R è un albero ben costruito e bilanciato e contiene una foglia con n come campo info
     * 
    */
    // PRE && POST_insertBil => R è un albero ben costruito e bilanciato && contiene 1 elemento in più di v_R (1)
    if (dim > 1) { //(2)
        /**
         * PRE_ric
         *  (1) => R è un albero ben costruito e bilanciato
         *  (2) => dim - 1 > 0
         * 
        */
        R = buildtree(R, dim - 1);
        /**
         * POST_ric
         *  
         * R è un albero bilanciato e ben costruito contenente dim elementi in più
        */
    }
    return R;
}
/**
 * POST
 *  
 *  R è un albero bilanciato e ben costruito contenente dim elementi in più
*/

void stampa_prefisso(nodo* R) {
    if (R) {
        cout<<R->info<<"(";
        stampa_prefisso(R->left);
        cout<<", ";
        stampa_prefisso(R->right);
        cout<<")";
    } else {
        cout<<"_";
    }
}

void stampa_infisso(nodo* R) {
    if (R) {
        cout<<"(";
        stampa_infisso(R->left);
        cout<<"-"<<R->info<<"-";
        stampa_infisso(R->right);
        cout<<")";
    } else {
        cout<<"_";
    }
}

void stampa_postfisso(nodo* R) {
    if (R) {
        cout<<"(";
        stampa_postfisso(R->left);
        cout<<", ";
        stampa_postfisso(R->right);
        cout<<")"<<R->info;
    } else {
        cout<<"_";
    }
}

void stampa_l(nodo* R) {
    stampa_prefisso(R);
}

/**
 * 
 * PRE=(albero(R) è ben formato, k>0, 1<=n<=k)
 * 
*/
int stampa_a_salti(nodo* R, int k, int n) {
    if (!R) { // (1)
        /**
         * PRE && (1) => non stampo niente e ritorno n - (n nodi stampati) = n
        */
       return n;
    }
    // !(1) => R non vuota
    if (n == 1) { // (2)
        // (2) => devo stampare il primo nodo
        cout<<R->info<<" ";
    }
    n--;
    if (n == 0) { // (3)
        n = k;
        // (4)
    }
    // !(3) || (4) => n è il numero di salti rimanenti && 1 <= n <= k
    /**
     * PRE_ric
     * 
     *  1 <= n <= k
     *  !(1) && PRE => R non vuoto => R->left esiste ed è un albero ben costruito
     *  PRE && k non viene modificato => k > 0
     * 
    */
    int left = stampa_a_salti(R->left, k, n);
    /**
     * POST_ric 1
     * 
     *  per ipotesi induttiva => 
     *      ha restituito il numero di nodi che bisogna saltare per arrivare al prossimo
     * 
     *  => left contiene quel valore
     * 
    */

   /**
     * PRE_ric
     * 
     *  POST_ric 1 => 1 <= left <= k
     *  !(1) && PRE => R non vuoto => R->right esiste ed è un albero ben costruito
     *  PRE && k non viene modificato => k > 0
     * 
    */
    return stampa_a_salti(R->right, k, left);
    /**
     * POST_ric
     * 
     *  per ipotesi induttiva => 
     *      ha restituito il numero di nodi che bisogna saltare per arrivare al prossimo
     * 
     *  => la funzione ritorna quel valore
     * 
    */
}
/**
 * POST=(percorre i nodi di albero(r) in ordine prefisso stampando i
campi info di alcuni di essi nel modo seguente: salta i primi n-1, 
stampa il campo info del nodo n-esimo, poi ne salta k-1 e stampa
quello successivo e così via fino a visitare tutti i nodi di
albero(r)) && (restituisce un intero m (1<=m<=k) che indica che
si dovranno saltare m-1 nodi prima di stampare il prossimo)
 * 
*/
main()
{
  int dim,k;
  cin>>dim;
  nodo* R = buildtree(0 ,dim);
  cout<<"start"<<endl;
  stampa_l(R);
  cin>>k;
  int b=stampa_a_salti(R,k,k);
  cout<<"valore restituito="<<b<<endl;
  cout<<"end"<<endl;
}
