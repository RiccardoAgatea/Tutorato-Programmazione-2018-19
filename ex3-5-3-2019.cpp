#include<iostream>
using namespace std;
main()
{
	int N, A[100];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << "start" << endl;

	//PRE = (i==1) && (A[0...N-1] contiene gli N valori prelevati da cin dopo N, che sono
	//      tutti 0 o 1) && (OldA = A)
	for (int i = 1; i < N; i++)
		//R = (1<=i<=N) && (A[0...i-1] è ordinato) &&
		//    (A[0...n-1] è una permutazione di OldA)
	{
		int x = A[i];
		int j = i - 1;

		//PRE = (j==i-1) && (A[0...i-1] è ordinato) && (x == A[i])
		while (j >= 0 && A[j] > x)
			//R = (-1<=j<=i-1) && (A[0...j] e A[j+2...i] sono ordinati) &&
			//    (per ogni k in [j+2...i] A[k]>x) && (x è l'elemento da inserire)
		{
			A[j + 1] = A[j];
			j--;
		}

		//POST = (x è stato inserito in A[0...i-1] nella posizione esatta perchè sia
		//       ancora ordinato)

		A[j] = x;
	}

	//POST = (A[0...n-1] contiene gli stessi elementi di OldA in ordine)

	for (int i = 0; i < N; ++i)
		cout << A[i];

	cout << "end" << endl;
}

/*
Alcune note:
-> OldA è un array ausiliare che ho definito perchè mi serve "ricordarmi" com'è composto l'array originale. Nelle prove di correttezza può essere comodo definire variabili inesistenti, che non servono a nulla ai fini del programma, ma che ci facilitano la vita.
*/