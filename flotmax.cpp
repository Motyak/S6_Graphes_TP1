/************************************************/
/* Auteur : S. Gueye							*/
/* TP : Flot maximum							*/
/* Algorithme de Ford et Fulkerson				*/
/* Date dernière maj : 03/02/2020				*/
/************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "flotmax.h"

using namespace std;

/****************************************/
/* Objectif : Lecture du graphe
/* Celui-ci est contenu dans le fichier "filename"
/* (voir description TP pour explications)
/****************************************/
graphe::graphe(char* filename)
{
    // !!! TODO !!! //

    ifstream fs;
    fs.open(filename);
    string line;

    //initialiser n avec le contenu du fichier
    getline(fs,line);
    this->n = stoi(line);

    //initialiser c avec le contenu du fichier
    int i,j;
    i = 0;
    while(getline(fs,line))
    {
        j = 0;
        for(j; j<n-1 ; ++j)
        {
            int indexOfNextSpace = line.find(' ');
            this->c[j][i] = stoi(line.substr(0,indexOfNextSpace));
            line.erase(0,indexOfNextSpace+1);
            // std::cout<<line<<std::endl;
        }
        this->c[j][i] = stoi(line);
        ++i;
    }

    //initialiser f à 0
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<n ; ++j)
            this->f[i][j]=0;

    fs.close();
}

/****************************************/
/* Objectif : Accesseur au nombre de 
/* noeuds du graphe
/****************************************/
int graphe::getn()
{
	return(n);
}


/***************************************************/
/* Objectif : Méthode trouvant (si elle existe) et
stockant dans ch une chaîne augmentante de s à t
/***************************************************/
void graphe::chaineaugmentante(int ch[N],int s, int t)
{
    // !!! TODO !!! //
}

/****************************************/
/* Objectif : Méthode affichant la chaîne ch
de s à t
/****************************************/
void graphe::affichage(int ch[N], int s, int t)
{
    // !!! TODO !!! //
}

/****************************************/
/* Objectif : Calcul de l'increment pour la chaîne "ch".
/****************************************/
int graphe::increment(int ch[N], int s, int t)
{
    // !!! TODO !!! //
	return(0);
}


/****************************************/
/* Objectif : Affichage des contenus des matrices
f et c
/****************************************/
void graphe::affichage()
{
    // !!! TODO !!! //
    for(int i = 0 ; i<n ; ++i)
    {
        for(int j = 0 ; j<n ; ++j)
        {
            std::cout<<this->c[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for(int i = 0 ; i<n ; ++i)
    {
        for(int j = 0 ; j<n ; ++j)
        {
            std::cout<<this->f[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}


/****************************************/
/* Objectif : Calcul de la somme des flots sortants
du noeud i
/****************************************/
int graphe::flotsortant(int i)
{
    // !!! TODO !!! //
    return 0;
}

/****************************************/
/* Objectif : Algorithme de Ford et Fulkerson
/****************************************/
void graphe::fordfulkerson(int s, int t)
{
    // !!! TODO !!! //
}