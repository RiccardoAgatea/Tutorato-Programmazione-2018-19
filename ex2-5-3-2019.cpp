#include<iostream>
using namespace std;

int main()
{
	int N, A[100];
	int occ[10] = {};

	cin >> N;

	//PRE = (A[0...100] array di lunghezza 100>=N) && (i==0) && (per ogni k occ[k]==0)
	for (int i = 0; i < N; i++)
		//R = (0<=i<=N) && (A[0...i-1] contiene i primi i valori prelevati da cin dopo N) &&
		//    (per ogni k occ[k] contiene il numero di volte in cui k è presente in A[0...i-1])
	{
		cin >> A[i];
		occ[A[i]] = occ[A[i]] + 1;
	}

	//POST = (A[0...N-1] contiene gli N valori prelevati da cin dopo N) &&
	//	     (per ogni k occ[k] contiene in numero di volte in cui k è presente in A[0...N-1])

	int max = 0;

	//PRE = (i==0) && (max==0)
	for (int i = 0; i < 10; i++) //R = (0<=i<=0) && (max contiene il massimo di occ[0...i-1])
		if (occ[i] > max)
			max = occ[i];

	//POST = (max contiene il massimo di occ)

	cout << "start" << endl;

	//PRE = (i==max) && (max contiene il massimo di occ) &&
	//      (per ogni k occ[k] contiene in numero di volte in cui k è presente in A[0...N-1])
	for (int i = max; i > 0; i--) //(#)
		//R = (0<=i<=max) && (sono state stampate max-i righe) &&
		//    (numerando le righe stampate da max a i+1, il k-esimo carattere della n-esima riga
		//    è '*' se occ[k]>=n, altrimenti è ' ')
	{
		//PRE = (j==0)
		for (int j = 0; j < 10; j++)
			//R = (0<=j<=10) && (sono stati stampati j caratteri nella i-esima riga) &&
			//    (fra i caratteri stampati, il k-esimo è '*' se occ[k]>=n, altrimenti è ' ')
		{
			if (occ[j] >= i)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}

		//POST = (è stata stampata l'i-esima riga) &&
		//       (il k-esimo carattere della riga appena stampata è '*' se occ[k]>=n,
		//       altrimenti è ' ')

		cout << endl;
	}

	//POST = (l'istogramma è stato stampato correttamente)


	for (int j = 0; j < 10; j++)
	{
		cout << j;
	}

	cout << endl;
	cout << "end" << endl;
}

/*
PRE, POST e R per l'ultimo  ciclo sono triviali, quindi non le ho messe. Come abbiamo detto, non cambia nulla se al posto del ciclo scrivete "cout << 0123456789 << endl;".
*/
