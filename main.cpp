/************************************************/
/* Auteur : S. Gueye							*/
/* TP : Flot maximum							*/
/* Algorithme de Ford et Fulkerson				*/
/* Date dernière maj : 03/02/2020				*/
/************************************************/

#include <iostream>
#include "flotmax.h"

using namespace std;

int main(int argc,char** argv)
{	
	if(argc < 2)
		cout << "Nombre d'arguments insuffisants" << endl;
	else{

		graphe obj(argv[1]);/**/
		obj.affichage();/**/
		
		// int ch[N];
		// obj.chaineaugmentante(ch, 0, 5);
		// for(int i = 0 ; i<obj.getn() ; ++i)
		// 	cout<<ch[i]<<",";
		// cout<<endl;
		// obj.affichage(ch, 0, 5);
		// cout<<"increment = "<<obj.increment(ch, 0, 5)<<endl;

		int s = 0;/**/
		int t = obj.getn()-1;/**/
		
		obj.fordfulkerson(s,t);/**/
		obj.affichage();/**/
		cout << "Le flot maximum de " << s << " à " << t << " est  = " << obj.flotsortant(s) << endl;/**/
	}
}

