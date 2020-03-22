/************************************************/
/* Auteur : S. Gueye							*/
/* TP : Flot maximum							*/
/* Algorithme de Ford et Fulkerson				*/
/* Date dernière maj : 03/02/2020				*/
/************************************************/

#include <iostream>
#include <fstream>
#include <stack>
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
        for(j = 0 ; j<n-1 ; ++j)
        {
            int indexOfNextSpace = line.find(' ');
            this->c[i][j] = stoi(line.substr(0,indexOfNextSpace));
            line.erase(0,indexOfNextSpace+1);
        }
        this->c[i][j] = stoi(line);
        ++i;
    }

    //initialiser f à 0
    for(i=0 ; i<n ; ++i)
        for(j=0 ; j<n ; ++j)
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
    bool visites[this->n];
    stack<int> pile;
    bool stop = false;
    int i;
    for(i = 0 ; i<this->n ; ++i)
    {
        visites[i] = false;
        ch[i] = -1;
    }
    pile.push(s);
    while(!pile.empty() && !stop)
    {
        i = pile.top();
        pile.pop();
        if(i == t)
            stop = true;
        else if(visites[i] == false)
        {
            visites[i] = true;
            for(int j = 0 ; j<this->n ; ++j)
            {
                if(visites[j] == false)
                {
                    if((this->c[i][j] > 0 && this->c[i][j] > this->f[i][j])
                        || (this->c[j][i] > 0 && this->f[j][i] > 0))
                    {
                        pile.push(j);
                        ch[j] = i;
                    }
                }
            }
        }
    }
    
}

/****************************************/
/* Objectif : Méthode affichant la chaîne ch
de s à t
/****************************************/
void graphe::affichage(int ch[N], int s, int t)
{
    // !!! TODO !!! //
    int preds[N];
    int i = 0;
    preds[i] = t; //on commence par t, puis on cherche les pred
    while(ch[preds[i]] != -1)
    {
        preds[i+1] = ch[preds[i]];
        ++i;
    }
             
    for(; i>0 ; --i)
        cout<<preds[i]<<" -- ";
    cout<<preds[0]<<endl;

}

/****************************************/
/* Objectif : Calcul de l'increment pour la chaîne "ch".
/****************************************/
int graphe::increment(int ch[N], int s, int t)
{
    // !!! TODO !!! //
    int preds[N];
    int i = 0;
    preds[i] = t; //on commence par t, puis on cherche les pred
    while(ch[preds[i]] != -1)
    {
        preds[i+1] = ch[preds[i]];
        ++i;
    }
        
        
        
    int increment = 999;    //valeur volontairement grande
    int incrementMax;
    int capa;
    int flot;
    int flotInverse;
    for(; i>0 ; --i)
    {
        // incrementMax = this->c[preds[i]][preds[i-1]]
        //     - this->f[preds[i]][preds[i-1]];
        capa = this->c[preds[i]][preds[i-1]];//
        flot = this->f[preds[i]][preds[i-1]];//
        flotInverse = this->f[preds[i-1]][preds[i]];//

        //incrementMax = flotInverse < (capa - flot)  ? (capa - flot) : flotInverse;//
        /***************************************************
         * S. Gueye, 22/03/2020, 12h20
         * **************************************************
         * Au-dessus vous avez introduit une subtilité qui n'est pas fausse.
         * On fait même en général moins d'itérations comme cela. 
         * Vous prenez le maximum des augmentations possibles en comparant les résidus de l'arc 
         * pris dans le bon sens et celui pris dans le sens inverse. C'est juste !
         * 
         * Ce que j'avais suggéré est plus simple : si on peut augmenter en prenant l'arc
         * dans le bon sens on le fait sinon on regarde le sens inverse. 
         * 
         * C'est ce qui explique que vous trouvez des fois en une chaîne ce que je trouve en deux.
         * 
         * Je vous ai mis ci-dessous l'incrément calculé selon cette méthode. 
         * Mais la vôtre est aussi valable. 
         * Vous verrez également dans votre méthode "fordfulkerson" un changement  analogue.
         * Avec ces deux modifications, vous trouverez normalement les mêmes chaines que les miennes.
         * En cliquant sur "evaluate" vous devriez avoir 100/100 maintenant.
         * 
         * Pour résumer je ne cherchais pas à vous faire trouver les augmentations les plus fortes, simplement à déterminer
         * une chaîne augmentante en regardant en priorité si on peut la parcourir dans le bon sens pour tous les arcs.
         * 
         * Pour info, de manière générale, pour faire le moins d'itérations possibles, il faut en fait chercher les chaînes les plus 
         * courtes en nombre arcs.
         * *************************************************/
         if( (capa - flot) > 0)
            incrementMax = (capa - flot);
        else
            incrementMax = flotInverse;
        /****************************************************/

        if(incrementMax < increment)
            increment = incrementMax;   
    }

	return increment;
}


/****************************************/
/* Objectif : Affichage des contenus des matrices
f et c
/****************************************/
void graphe::affichage()
{
    // !!! TODO !!! //
    cout<<"c ="<<endl;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
            cout<<this->c[i][j]<<'\t';
        cout<<endl;
    }

    cout<<"f ="<<endl;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
            cout<<this->f[i][j]<<'\t';
        cout<<endl;
    }
}


/****************************************/
/* Objectif : Calcul de la somme des flots sortants
du noeud i
/****************************************/
int graphe::flotsortant(int j)
{
    // !!! TODO !!! //
    //il suffit de faire la somme de la i ème ligne de la matrice f
    int sum = 0;
    for(int i = 0 ; i<this->n ; ++i)
        sum += this->f[j][i];
        
    return sum;
}

/****************************************/
/* Objectif : Algorithme de Ford et Fulkerson
/****************************************/
void graphe::fordfulkerson(int s, int t)
{
    // !!! TODO !!! //
    int ch[N];
    int increment;

    do
    {
        //rechercher une chaine augmentante
        this->chaineaugmentante(ch, s, t);

//
        // for(int o : ch)
        //     cout<<o<<",";
        // cout<<endl;
        // this->affichage(ch, s, t);
        // this->affichage();
//

        increment = this->increment(ch, s, t);
        //cout<<"increment pre potentiel break : "<<increment<<endl;//
        if(increment == 0 || increment == 999)
            break;
        
        //afficher la chaine augmentante
        cout<<"Chaine augmentante = ";
        this->affichage(ch, s, t);
        
        //afficher l'increment
        cout<<"incr = "<<increment<<endl;
        
        //augmenter le flot sur cette chaine   
        int preds[N];
        int i = 0;
        preds[i] = t; //on commence par t, puis on cherche les pred
        while(ch[preds[i]] != -1)
        {
            preds[i+1] = ch[preds[i]];
            ++i;
        }
            
        // for(; i>0 ; --i)
        //     this->f[preds[i]][preds[i-1]] += increment;
        for(; i>0 ; --i)
        {
            int capa = this->c[preds[i]][preds[i-1]];
            int flot = this->f[preds[i]][preds[i-1]];
            int flotInverse = this->f[preds[i-1]][preds[i]];
            //bool sensInverse = flotInverse > (capa - flot);
            /***************************************************
            * S. Gueye, 22/03/2020, 12h20
            * Ci-dsssous le petit changement (à la place de la déclaration ci-dessus). 
            * Ce changement est analogue à ce qui est expliqué 
            * dans la méthode "increment".
            * *************************************************/
            bool sensInverse = true;

            if( (capa - flot) > 0)
                sensInverse = false;
            /**************************************************/    
            
            if(!sensInverse)
                this->f[preds[i]][preds[i-1]] += increment;//[i][j]
            else
            {
                // cout<<"SENS INVERSE"<<endl;//
                this->f[preds[i-1]][preds[i]] -= increment;//[j][i] : inverse
            }
                
        }
            

    } while(increment != 0 && increment != 999);
}
