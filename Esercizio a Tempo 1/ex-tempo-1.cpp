#include<iostream>
using namespace std;

int main()
{
	int A1[10][5], A2[10][5];

	for (int i = 0; i < 50; ++i) //1
	{
		int temp = 0;

		cin >> temp;

		A1[i / 5][i % 5] = temp;
		A2[i % 10][i / 10] = temp;
	}

	cout << "start" << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << A1[i][j] << " ";

		cout << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << A2[i][j] << " ";

		cout << endl;
	}

	cout << endl;

	bool B[10][10] = {};


	for (int i = 0; i < 10; i++) //2
		for (int j = i; j < 10; j++) //3
		{
			//j parte da i, perchè siccome B è simmetrica gli elementi da 0 a i-1 sono già fatti

			bool found = false;

			for (int p = 0; (p < 5) && !found; ++p) //4
				for (int q = 0; (q < 5) && !found; ++q) //5
					if (A2[i][p] == A2[j][q])
						found = true;

			B[i][j] = !found;
			B[j][i] = !found;
		}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << B[i][j] << " ";

		cout << endl;
	}

	cout << "end" << endl;
}
/*
#Alcune note

Il ciclo di inserimento si basa sull'idea che un array multidimensionale A con M
righe e N colonne in memoria effettivamente è un unico array unidimensionale
con M*N elementi. Se consideriamo l'elemento A[i][j], questo nell'array in memoria
avrà indice k = i*N+j, e quindi volendo fare il calcolo inverso i = k/N e j = k%N,
ricordando che la divisione per gli int ritorna un int (e quindi tronca il risultato),
e che il modulo (%) ritorna il resto della divisione intera.
L'altra osservazione è che leggere A2 per colonna è come leggere per riga la sua
trasposta, e quindi basta scambiare i due indici.

Ci sono due cose importanti da notare dei 4 cicli annidati: la precondizione
di un ciclo interno contiene la condizione di entrata e l'invariante del ciclo
immediatamente più esterno. Questo rappresenta il fatto che il ciclo interno viene
"raggiunto" ed eventualmente eseguito solo se viene eseguito il ciclo esterno.

#Invarianti, Pre e Post

PRE1 = (i==0) && (cin contiene 50 interi)
R1 = (0<=i<=50) && (i primi i elementi sono stati prelevati da cin) &&
     (per j in [0...i-1], il j-esimo elemento è salvato in A1 nella i/5-esima riga
     e la i%5-esima colonna) &&
     (per j in [0...i-1], il j-esimo elemento è salvato in A2 nella i/10-esima
     colonna e la i%10-esima riga)
POST1 = (A1 contiene gli interi prelevati da cin per riga) &&
		(A2 contiene gli interi prelevati da cin per colonna)

PRE2 = (i==0) && (A2 contiene i 50 valori letti da cin inseriti per colonna)
R2 = (0<=i<=10) && (per ogni x in [0...i-1], per ogni y in [0...9] (B[x][y] sse A2[x]
	 e A2[y] non hanno elementi in comune) && (B[x][y] == B[y][x]))
POST2 = (per ogni x,y in [0...9] B[x][y] sse A2[x] e A2[y] non hanno elementi in comune)

PRE3 = (i<10) && (j==i) && R2
R3 = (i<=j<=10) && (per ogni y in [0...j-1] (B[i][y] sse A2[i] e A2[y] non hanno elementi
	 in comune) && (B[x][y] == B[y][x]))
POST3 = (per ogni y in [0...9] (B[i][y] sse A2[i] e A2[y] non hanno elementi
	 in comune) && (B[x][y] == B[y][x]))

PRE4 = (j<10) && (p==0) && !found && R3
R4 = (0<=p<=5) && (found sse esiste almeno un elemento in comune fra A2[i][0...p-1] e
	 A2[j])
POST4 = (found sse esiste almeno un elemento in comune fra A2[i] e A2[j])

PRE5 = (p < 5) && !found && (q==0) && R4
R5 = (0<=q<=5) && (found sse esiste almeno un elemento in comune fra A2[i][0...p-1] e
	 A2[j][0...q-1])
POST5 = (found sse esiste almeno un elemento in comune fra A2[i][0...p-1] e A2[j])
*/