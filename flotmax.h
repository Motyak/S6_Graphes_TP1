/************************************************/
/* Auteur : S. Gueye							*/
/* TP : Flot maximum							*/
/* Algorithme de Ford et Fulkerson				*/
/* Date dernière maj : 03/02/2020				*/
/************************************************/

const int N = 30; // Constante permettant de surdimensionner les données

class graphe{
	int n; 		// Nombre de noeuds du graphe
	int c[N][N]; 	// Matrice des capacités des arcs
	int f[N][N]; 	// Matrice des flots sur les arcs
public : 
	graphe(char* filename);
	int getn();
	void affichage();
	void chaineaugmentante(int ch[N],int s, int t);
	int increment(int ch[N], int s, int t);
	void affichage(int ch[N], int s, int t);
	int flotsortant(int i);
	void fordfulkerson(int s, int t);
};