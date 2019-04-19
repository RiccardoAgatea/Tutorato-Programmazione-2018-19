#include <iostream>
using namespace std;

void read(int *A, int n);
void copy(int *A, int *B, int n);
bool findPath(int *A, int i);

int main(int argc, char const *argv[])
{
	int A[10];
	read(A, 10);

	cout << "Percorso " << (findPath(A, 0) ? "" : "non ") << "trovato" << endl;

	return 0;
}

//PRE_read=(A array di lunghezza n>=0)&&(cin contiene n interi)
void read(int *A, int n)
{
	if (n > 0)
	{
		cin >> A[0];
		read(A + 1, n - 1);
	}
}
//POST=(A[0...n-1] contiene gli n interi prelevati da cin, in ordine)

//PRE_copy=(A e B array di lunghezza n>=0)
void copy(int *A, int *B, int n)
{
	if (n != 0)
	{
		B[0] = A[0];
		copy(A + 1, B + 1, n - 1);
	}
}
//POST_copy=(B[0...n-1] è una copia di A[0...n-1])

//PRE_findPath=(A array di lunghezza 10 con A[9]==0)
bool findPath(int A[10], int i)//il numero non conta, ma rende esplicita la pre
{
	if (i == 9)
		return true;

	if (i < 0 || i > 9 || A[i] == -1)
		return false;

	int B[10];
	copy(A, B, 10);

	B[i] = -1;

	return findPath(B, i - A[i]) || findPath(B, i + A[i]);
}
//POST_findPath=(ritorna true sse esiste un percorso valido da A[i] a A[9] che segue le regole sotto)

/*
 * 1. Un percorso è una sequenza (k1,k2,...,km) di indici tutti distinti, con ki in [0...9]
 * 2. Un percorso è valido sse
 *    a. per ogni j in [2...m] kj=ki+A[ki] oppure kj=ki-A[ki]
 *    b. per ogni i in [1...m] A[ki]!=-1
 */