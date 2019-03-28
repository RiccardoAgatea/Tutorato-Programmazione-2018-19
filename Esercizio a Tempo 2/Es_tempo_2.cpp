#include<iostream>
using namespace std;

bool match(int *t, int *P, int lP);
bool matchStrato(int *t, int lT, int *P, int lP);
int matchTorta(int *T, int lT, int *P, int lP);

int main()
{
	int X[400], n_ele, nP, P[20];
	cin >> n_ele;

	for (int i = 0; i < n_ele; i++)
		cin >> X[i];

	int lim1, lim2, lim3;
	cin >> lim1 >> lim2 >> lim3;
	cin >> nP;

	for (int i = 0; i < nP; i++)
		cin >> P[i];

	cout << "start" << endl;
	int lung = n_ele < lim1 * lim2 * lim3 ? n_ele : lim1 * lim2 * lim3;
	int i = matchTorta(X, lung, P, nP, lim1, lim2, lim3);

	if (i == -1)
		cout << "Nessun match" << endl;
	else
		cout << "Match nello strato " << i << endl;

	cout << "end" << endl;
}

//Pre: t è abbanstanza lungo da contenere il pattern P
bool match(int *t, int *P, int lP)
{
	bool flag = true;

	for (int i = 0; i < lP && flag; ++i)
		if (t[i] != P[i])
			flag = false;

	return flag;
}
//Post: match ritorna true sse t[0...lP-1]==P[0...lP-1]

//Pre: t è array valido di lunghezza lT (&& lT>=0 && lP>=0)
bool matchStrato(int *t, int lT, int *P, int lP)
{
	bool found = false;

	for (int i = 0; i < lT - lP + 1 && !found; ++i)
		if (match(t + i, P, lP))
			found = true;

	return found;
}
//Post: matchStrato ritorna true sse l'array t[0..lT-1] contiene P

//Pre: T è array valido di lunghezza lT &&
//	   lim1*lim2*lim3<=lT
int matchTorta(int *T, int lT, int *P, int lP, int lim1, int lim2, int lim3)
{
	int delta = lim2 * lim3;
	bool found = false;
	int i = 0;

	for (; i < lim1 && !found; ++i)
	{
		int lung = (lT - i * delta) > delta ? delta : (lT - i * delta);

		if (matchStrato(T + i * delta, lung, P, lP))
			found = true;
	}

	return i == lim1 ? -1 : i;
}
//Post: matchTorta ritorna l'indice dello strato che contiene P se esiste, altrimenti -1