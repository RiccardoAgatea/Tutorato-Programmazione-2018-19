/**
 PRE = root è un albero ben formato e non nullo
 */
int cercaFoglia(nodo *root, int key, nodo *&t)
{

	if (!root->left && !root->right)
	{
		// root ha solo un nodo (equivale a dire che siamo
		// in una foglia)
		if (root->info == key)
		{
			// c'è una corrispondenza
			t = root;
			return 0;
		}
		else
		{

			// non c'è una corrispondenza
			return -1;
		}
	}

	int minLeft = -1, minRight = -1;
	nodo *l = NULL, * r = NULL;

	if (root->left)
	{
		// Dalla PRE => root è un albero ben formato e non nullo
		// => root->left è un albero ben formato
		// dall'if => root->left non nullo
		// =>
		// PRE_ric = root->left è un albero ben formato e non nullo
		minLeft = cercaFoglia(root->left, key, l);
		/*
		per Hp induttiva, posso assumere POST_ric:
		 se c'è una foglia con info = key allora restituisce col
		 	return la profondità minima di tale foglia e
		 	assegna a l il puntatore ad essa
		 altrimenti restituisce -1
		 */
	}

	if (root->right)
	{
		minRight = cercaFoglia(root->right, key, r);
		/*
		 se c'è una foglia con info = key allora restituisce col
		 	return la profondità minima di tale foglia e
		 	assegna a l il puntatore ad essa
		 altrimenti restituisce -1
		 */
	}

	// minLeft contiene l'altezza minima in root->left
	// 	oppure -1 se ( root->left è nullo ||
	// 		non è stata trovata una corrispondenza)
	//
	// minRight contiene l'altezza minima in root->right
	// 	oppure -1 se ( root->right è nullo ||
	// 		non è stata trovata una corrispondenza)

	if (minRight == -1 && minLeft == -1)
	{
		// se sono entrambi == -1
		// => non ci sono corrispondenze
		//  => POST
		return -1;
	}

	if (minRight == -1)
	{
		// minRight == -1 && minLeft != -1
		// => assegnamo l a t e ritorno 1 + la distanza
		// tra root e l'altezza trovata in root->left
		//  => POST
		t = l;
		return 1 + minLeft;
	}

	if (minLeft == -1)
	{
		// minLeft == -1 && != minRight -1
		// => assegnamo r a t e ritorno 1 + la distanza
		// tra root e l'altezza trovata in root->right
		//  => POST
		t = r;
		return 1 + minRight;
	}

	// minLeft != -1 && minRight != -1
	if (minLeft <= minRight)
	{
		// minLeft è il minimo
		// => assegnamo l a t e ritorno 1 + la distanza
		// tra root e l'altezza trovata in root->left
		//  => POST
		t = l;
		return 1 + minLeft;
	}
	else
	{
		// minRight è il minimo
		// => assegnamo r a t e ritorno 1 + la distanza
		// tra root e l'altezza trovata in root->right
		//  => POST
		t = r;
		return 1 + minRight;
	}

}
/*
 se c'è una foglia con info = key allora restituisce col
 	return la profondità minima di tale foglia e
 	assegna a t il puntatore ad essa
 altrimenti restituisce -1
 */