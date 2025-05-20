#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

#include "Coloration.hpp"

using namespace std;



// Fonction de comparaison pour trier par degré décroissant
bool comparerParDegre(const Sommet& sommet1, const Sommet& sommet2)
{
    return sommet1.degre > sommet2.degre;
}



void trierParDegre(vector<Sommet>& sommets)
{
    int n = sommets.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (sommets[j].degre < sommets[j+1].degre)
            {
                // On échange les sommets si le degré du sommet j est inférieur au sommet j+1
                Sommet temp = sommets[j];
                sommets[j] = sommets[j+1];
                sommets[j+1] = temp;
            }
        }
    }
}



// Fonction Welsh-Powell
void welshPowell(const vector<vector<int>>& graphe)
{
    int n = graphe.size();
    vector<Sommet> sommets(n);

    // Calcul du degré de chaque sommet
    for (int i = 0; i < n; ++i)
    {
        sommets[i].id = i;
        sommets[i].degre = 0;
        for (int j = 0; j < n; ++j)
        {
            if (graphe[i][j])
            {
                sommets[i].degre++;
            }
        }
    }

    // On range les sommets par ordre de degré décroissant
    trierParDegre(sommets);

    vector<int> couleurs(n, -1); // -1 = pas de couleur
    int couleur_actuelle = 0;


    // Parcours des sommets vierges (non coloriés)
    for (int i = 0; i < n; ++i)
    {
        int sommet_vierge = sommets[i].id; // Représente l'identifiant d'un sommet non colorié
        if (couleurs[sommet_vierge] == -1)
        {
            // Assigner une nouvelle couleur
            couleurs[sommet_vierge] = couleur_actuelle;

            // Colorier tous les sommets compatibles (non adjacents à sommet_vierge) avec la couleur actuelle
            for (int j = i + 1; j < n; ++j)
            {
                int sommet_a_colorier = sommets[j].id;
                if (couleurs[sommet_a_colorier] == -1)
                {
                    bool peut_colorier = true;

                    // Vérifier si le sommet_a_colorier est adjacent à sommet_vierge
                    for (int k = 0; k < n; ++k)
                    {
                        if (graphe[sommet_a_colorier][k] && couleurs[k] == couleur_actuelle)
                        {
                            peut_colorier = false;
                            break;
                        }
                    }
                    if (peut_colorier)
                    {
                        couleurs[sommet_a_colorier] = couleur_actuelle;
                    }
                }
            }
            couleur_actuelle++;
        }
    }

    // Affichage des couleurs
    cout << "Coloration des sommets :" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Sommet " << i << " : Couleur " << couleurs[i] << endl;
    }
}



int main_coloration()
{
    // Le programme se trouve par défaut dans le répertoire build,
    // donc on remonte d'un niveau pour accéder au fichier matrice.txt
    string filename = "../matrice_coloration.txt";

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << endl;
        return -1;
    }

    // Lecture de la taille de la matrice
    int N;
    file >> N;

    // Lecture de la matrice
    vector<vector<int>> graphe(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            file >> graphe[i][j];
        }
    }

/*     // Exemple de graphe (matrice d'adjacence)
    vector<vector<int>> graphe = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    }; */

    welshPowell(graphe);

    return 0;
}
