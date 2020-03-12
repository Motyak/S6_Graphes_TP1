/************************************************/
/* Auteur : S. Gueye							*/
/* TP : Flot maximum							*/
/* Algorithme de Ford et Fulkerson				*/
/* Date dernière maj : 03/02/2020				*/
/************************************************/

#include <iostream>
#include "flotmax.h"

using namespace std;

// g++ --std=c++11 -o p flotmax.cpp main.cpp
int main(int argc,char** argv)
{	
	if(argc < 2)
		cout << "Nombre d'arguments insuffisants" << endl;
	else{

		graphe obj(argv[1]);
		obj.affichage();

		// int s = 0;
		// int t = obj.getn()-1;

		// obj.fordfulkerson(s,t);
		// obj.affichage();
		// cout << "Le flot maximum de " << s << " à " << t << " est  = " << obj.flotsortant(s) << endl;
	}
}
