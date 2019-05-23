#include <iostream>

using namespace std;


struct nodoA{
    int info;
    nodoA* left, *right;
    nodoA(int a=0, nodoA*b=0, nodoA*c=0) {
        info=a;
        left=b;
        right=c;
    }
};
struct nodo{
    nodoA* info;
    nodo* next;
    nodo(nodoA* a=0, nodo*b=0) {
        info=a; next=b;
    }
};

void stampa_l(nodoA *r) {
    if(r) {
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }
    else cout<< '_';
}
int conta_n(nodoA*r) {
    if(!r) return 0;
    else return conta_n(r->left) + conta_n(r->right) + 1;
}

nodoA* insert(nodoA*r, int y) {
    if(!r) return new nodoA(y);
    if(conta_n(r->left) <= conta_n(r->right)) r->left=insert(r->left,y);
    else r->right=insert(r->right,y); 
    return r;
}

nodoA* buildtree(nodoA*r, int dim) {
    if(dim) {
        int z;
        cin>>z;
        nodoA* x = insert(r, z);
        return buildtree(x, dim-1);
    }
    return r;
}


void riempi(int*P,int m) {
    if(m) {
        cin>>*P;
        riempi(P+1,m-1);
    }
}

void stampaL(nodo*a) {
    if(a) {
        cout<<a->info->info<<' ';
        stampaL(a->next);      
    }
    else cout<<endl;
}

/**
 * PRE
 *  p è una lista ben formata
 *  s è una lista ben formata
*/
nodo* concat(nodo* p, nodo* s) {
    if (!p) { // (1)
        // (1) => la concatenazione tra una lista vuota e una lista
        //  è la seconda lista
        // => ritorno la seconda lista (s)
        return s;
    }
    // !(1) && PRE => p esiste non nullo => p->next è una lista ben formata
    // &&
    // s non è modificata && PRE => 
    // PRE_ric
    p->next = concat(p->next, s);
    /**
     * per ipotesi induttiva
     *  =>
     * POST_ric
     * 
    */
    // assegnazione && POST_ric => p->next contiene la concatenazione di
    // p->next e s
    //  =>
    // p contiene la concatenazione tra p e s
    // => ritorno p
    return p;
}
/**
 * POST
 * 
 *  ritorna la concatenazione di p e s
*/

// NB PRE, POST e casi base sono simili quanto a sopra
void concat_ric(nodo* & p, nodo* s) {
    if (!p) {
        p = s;
        // return;
    } else {
        concat_ric(p->next, s);
        // return;
    }
}

// PRE=(albero(r) ben formato, P ha dimP elementi con dimP > 0
nodo* match(nodoA* r, int* P, int dimP) {
    if (!r) { // (1)
        // (1) => ritorno una lista vuota
        return 0;
    }
    // !(1) => r non nullo

    if (P[0] == r->info) { // (2)
        if (dimP == 1) { // (3)
            // (2) && (3) => la lista è composta solo dalla corrispondenza appena trovata
            return new nodo(r);
        } else {
            // (2) && !(3) => la lista è composta dalla corrispondenza attuale e il resto
            /**
             * PRE_ric_1
             *  !(1) => r->left esiste
             *  PRE && (3) => (dimP > 0 && dimP != 1) => dimP > 1 => dimP - 1 > 0 
             *      inoltre P contiene dimP elementi => P + 1 contiene dimP - 1 elementi
            */
            nodo* resto = match(r->left, P + 1, dimP - 1);
            /**
             * POST_ric_1
             *  match ritorna 0 se non trova nessun match completo, altrimenti ritorna la lista dei nodi
             *  alle corrispondenze
            */
            if (!resto) { // (4)
                // POST_ric_1 && (4) => nel ramo sinistro non ho trovato corrispondenza
                /**
                 * PRE_ric_2
                 *  !(1) => r->right esiste
                 *  PRE && (3) => (dimP > 0 && dimP != 1) => dimP > 1 => dimP - 1 > 0 
                 *      inoltre P contiene dimP elementi => P + 1 contiene dimP - 1 elementi
                */
                resto = match(r->right, P + 1, dimP - 1);
                /**
                 * POST_ric_2
                 *  match ritorna 0 se non trova nessun match completo, altrimenti ritorna la lista dei nodi
                 *  alle corrispondenze
                */
            }
            // resto contiene le corrispondenze dei due alberi sottostanti (priorità a sx)
            if (resto) { // (5)
                // (5) => esiste un resto => esiste una corrispondenza completa
                return new nodo(r, resto);
            } else {
                // !(5) => non esiste una corrispondenza completa
                return 0;
            }
        }
    } else {
        /**
         * PRE_ric_3
         *  !(1) && PRE => r->left esiste
         *  PRE && non ho modificato dimP => dimP > 0 
         *      inoltre P contiene dimP elementi
        */
        nodo* resto = match(r->left, P, dimP);
        /**
         * POST_ric_3
         *  match ritorna 0 se non trova nessun match completo, altrimenti ritorna la lista dei nodi
         *  alle corrispondenze
        */
        if (!resto) {
            /**
             * PRE_ric_4
             *  !(1) && PRE => r->right esiste
             *  PRE => dimP > 0 
             *      inoltre P contiene dimP elementi
            */
            resto = match(r->right, P, dimP);
            /**
             * POST_ric_4
             *  match ritorna 0 se non trova nessun match completo, altrimenti ritorna la lista dei nodi
             *  alle corrispondenze
            */
        }
        // Se c'è una corrispondenza, io non lo posso sapere ora. Se la trovo successivamente bene, altrimenti pace!
        return resto;
    }
}
/**
 * POST=(se esiste su un cammino di albero(r) un match di P, allora,
restituisce una lista concatenata con dimP nodi ciascuno dei quali punta
ad un nodo di albero(r) che partecipa al match trovato)&&(altrimenti
restituisce 0)
*/

main() {
    int  n,m;
    cout<<"start"<<endl;
    cin>> n;
    nodoA*R = buildtree(0,n);
    stampa_l(R);
    cout<<endl;
    int P[50];
    cin>> m;
    riempi(P,m);
    nodo*a = match(R,P,m);
    if(a) stampaL(a);
    else cout<<"no match found"<<endl;
    cout<<"end"<<endl;
}