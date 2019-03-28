#include<iostream>
using namespace std;

int main()
{
	int N, A[100];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << "start" << endl;
	//N pari -> controllo la prima metà
	//N dispari -> controllo i primi (N-1)/2, quello centrale è ininfluente
	int i = 0;
	bool palindromo = true;

	//PRE = (A[0...n-1] contiene gli N valori prelevati da cin dopo N) && (i==0) && palindromo
	while (i < N / 2 && palindromo)
		//R = (0<=i<=N/2) &&
		//    (palindromo sse per ogni k in [0...i-1] A[k]==A[N-k-1])
	{
		palindromo = A[i] == A[N - i - 1];

		i++;
	}

	//POST = (palindromo sse A[0...n-1] contiene una sequenza palindroma)

	if (palindromo)
	{
		cout << "A è un palindromo" << endl;
	}
	else
	{
		cout << "A non è un palindromo e la prima contraddizione riguarda gli elementi di indice " << i <<
		     " e " << (N - i - 1) << endl;
	}

	cout << "end" << endl;
}
