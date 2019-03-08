#include<iostream>
using namespace std;

int main()
{
	int M[6][6];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> M[i][j];
		}
	}

	cout << "start" << endl;

	int costante = 0;
	bool prima = true;
	bool magico = true;

	//righe

	//PRE = (M è una matrice 6x6) && magico && prima && (costante==0)
	for (int y = 0; y < 6 && magico; y++)
		//R = (0<=y<=6) && (prima => costante==0) &&
		//    (!prima => costante contiene la somma dei valori della prima riga) &&
		//    (magico sse per ogni k in [0...y-1] la k-esima riga di M ha somma
		//    uguale a costante)
	{
		int So = 0;

		for (int x = 0; x < 6; x++)
		{
			So = So + M[y][x];
		}

		if (prima)
		{
			costante = So;
			prima = false;
		}
		else
		{
			if (So != costante)
			{
				magico = false;
			}
		}
	}

	//POST(1) = (costante contiene la somma della prima riga di M) &&
	//       (magico sse per ogni k in [0...5] la k-esima riga di M ha somma uguale a costante)

	//Notiamo che (!magico => certamente il quadrato non è magico).

	//colonne

	//PRE = POST(1)
	for (int i = 0; i < 6 && magico; i++)
	{
		// R = (0<=i<=6) && (magico sse per ogni k in [0...y-1] la k-esima colonna di M
		//     ha somma uguale a costante) && (costante contiene la somma della prima riga di M)
		int Sv = 0;

		for (int j = 0; j < 6; j++)
		{
			Sv = Sv + M[j][i];
		}

		if (Sv != costante)
		{
			magico = false;
		}
	}

	// POST(2) = (magico sse per ogni k in [0...5] la k-esima riga e la k-esima colonna
	//        di M hanno somma uguale a costante) &&
	//        (costante contiene la somma della prima riga di M)

	// diagonali
	int Sd1 = 0;
	int Sd2 = 0;

	//PRE = POST(2) && (Sd1==Sd2==0)
	for (int i = 0; i < 6 && magico; i++)
	{
		Sd1 = Sd1 + M[i][i];
		Sd2 = Sd2 + M[i][5 - i];
	}

	if (Sd1 != costante || Sd2 != costante)
	{
		magico = false;
	}

	//POST = (magico sse il quadrato è magico) &&
	//       (magico => costante è la costante magica)

	if (magico)
	{
		cout << costante << endl;
	}
	else
	{
		cout << "Non e' un quadrato magico." << endl;
	}
}
