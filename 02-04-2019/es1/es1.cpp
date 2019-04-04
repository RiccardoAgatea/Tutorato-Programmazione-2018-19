#include<iostream>

using namespace std;

int input(string msg) {
	cout<<msg<<endl;
	int a;
	cin>>a;
	return a;
}

/*
	NOTA BENE
	Qui la correttezza è molto verbosa,
	è consigliabile in genere concentrarsi
	sul succo della questione e evitare spiegazioni inutili
*/

// PRE = P e S contengono una riga di caratteri,
// terminante con \0
bool match(char * S, char * P) {
	bool ritorno = P[0] == '\0';
	/* PRE
		i = 0
		ritorno = true sse il pattern e' 
			vuoto
		PRE funzione
	*/
	for(int i=0; P[i] != '\0' && S[i] != '\0' && (P[i] == S[i] || P[i] == '?' || S[i] == '?'); i++) {
		/* R
			i >= 0
			ritorno == true sse 
				P[i] == \0
		*/		
		if (P[i+1] == '\0') {
			ritorno = true;
		}
		// i++;
	}
	/* POST
		ritorno == true sse c'è una 
			serie di corrispondenze 1-1
			tra S[0..i] e P[0..i]
	*/
	return ritorno;
}
// POST = la funzione ritorna true sse c'è un 
// 	una corrispondenza
// 	dalla posizione 0 di S per P


/*
DIMOSTRAZIONE

	B:
		P[i] != '\0' 
		&& 
		S[i] != '\0' 
		&& 
		(
			P[i] == S[i] 
			|| 
			P[i] == '?' 
			|| 
			S[i] == '?'
		)

	1) PRE => R:
		R(i = 0):
			ritorno == true sse 
			P[0] == \0
		Il punto 2 della PRE => R(i = 0);
	2) R && B + {iterazione} => R
		Per ogni i per cui vale R(i) && B(i)
		dopo {iterazione} / per i+1 = nuovo_i
			vale che ritorno == true sse P[nuovo_i] == '\0'
		quindi
			R(i) && B(i) + {it} => R(i+1)
	3) R && !B => POST
		abbiamo tre casi:
			1) 
			P[i] == '\0'
				per il quale, da R:
				P[i] == '\0' && R => ritorno == true
			2) 
			P[i] != '\0' (ovvero non è il primo caso)
			&&	
			S[i] == '\0' //S finisce prima di P
				questo && R => ritorno == false
			3)
			P[i] != '\0' 
			&&	
			S[i] != '\0' (ovvero non sono i primi due casi)
			&& 
			(
				P[i] != S[i] 
				&& 
				P[i] != '?' 
				&& 
				S[i] != '?'
			) //la cella in esame non rappresenta un match
				questo && R => ritorno == false
		riassumendo:
			ritorno == true sse ho trovato un match
*/

// PRE: T e P contengono una sequenza di caratteri terminanti con '\0'
int posMatch(char * T, char * P) {
	/**
		Il metodo che Filé suggeriva a lezione implica che si faccia il
		controllo della lunghezza per ogni riga e che si passi il	
		valore alla funzione match, così da evitare cicli inutili
		in caso la lunghezza del pattern fosse maggiore
		
		Questo è un metodo alternativo, comunque funzionante
	*/	

	int ritorno = -1;
	for(int i = 0; T[i] != '\0' && ritorno == -1; i++) {
		if(match(T+i, P)) {
			ritorno = i;
		}
	}
	return ritorno;
}
// POST: posMatch ritorna l'indice in T del match di P oppure -1 
// 	se non c'era nessun match

int main() {
	char T[100][100], P[100];
	int nrighe;
	cout<<"Pattern: "<<endl;
	cin.getline(P, 100);
	
	nrighe = input("Inserisci nrighe: ");
	cin.ignore();
	cout<<"Frase: "<<endl;
	for(int i=0; i<nrighe; i++) {
		cin.getline(T[i], 100);
	}
	
	
	int i = 0, posizione = -1;
	while(i<nrighe && posizione == -1) {
		posizione = posMatch(T[i], P);
		i++;
	}
	if (posizione == -1) {
		cout<<"Non trovata"<<endl;
	} else {
		cout<<"In riga "<<i<<" e in posizione "<<posizione<<endl;
	}
	return 0;
}