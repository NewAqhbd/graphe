#include <limits>
#include <fstream>
#include <iostream>

#include "Dijkstra.hpp"

using namespace std;

const int INF = numeric_limits<int>::max(); // Permet d'obtenir la valeur maximale d'un int pour initialiser les distances



// Trouve le sommet de distance minimal entre les différents sommets à traiter
int trouver_distance_min(const vector<int>& min_distances, const vector<bool>& a_traiter)
{
    int minimum_distance = INF;
    int sommet = -1;

    for (size_t i = 0; i < min_distances.size(); i++)
    {
        if (a_traiter[i] && min_distances[i] < minimum_distance)
        {
            minimum_distance = min_distances[i];
            sommet = i;
        }
    }

    return sommet;
}



// Met à jour les distances minimales et les prédecesseurs
void Dijkstra(const vector<vector<int>>& graphe, int sommet_debut, vector<int>& min_distances, vector<int>& predecesseurs)
{
    int N = graphe.size();
    min_distances.assign(N, INF);
    
    predecesseurs.assign(N, -1); // Initialisation de la liste des prédecesseurs
    vector<bool> a_traiter(N, true);

    min_distances[sommet_debut] = 0;

    while (true)
    {
        int sommet1 = trouver_distance_min(min_distances, a_traiter);
        if (sommet1 == -1) break; // Plus aucun sommet accessible
        a_traiter[sommet1] = false;

        for (int sommet2 = 0; sommet2 < N; sommet2++)
        {
            if (graphe[sommet1][sommet2] > 0) // Si le sommet2 est voisin du sommet1
            {
                // Met à jour les distances entre deux sommets si le sommet2 est voisin du sommet1 et que la distance est plus courte
                if (graphe[sommet1][sommet2] > 0 && min_distances[sommet2] > min_distances[sommet1] + graphe[sommet1][sommet2])
                {
                    min_distances[sommet2] = min_distances[sommet1] + graphe[sommet1][sommet2];
                    predecesseurs[sommet2] = sommet1; // Le sommet2 a pour prédécesseur le sommet1
                }
            }
        }
    }
}



// Fonction pour reconstruire le plus court chemin de sommet_debut à sommet_fin
vector<int> plus_court_chemin(int sommet_debut, int sommet_fin, const vector<int>& predecesseurs)
{
    vector<int> chemin;
    for (int sommet = sommet_fin; sommet != -1; sommet = predecesseurs[sommet])
    {
        chemin.insert(chemin.begin(), sommet);
        if (sommet == sommet_debut) break;
    }
    if (chemin.front() != sommet_debut)
    {
        return {}; // Aucun chemin trouvé, donc on retourne un vecteur vide
    }
    return chemin;
}



int main_dijkstra()
{
    // Le programme se trouve par défaut dans le répertoire build,
    // donc on remonte d'un niveau pour accéder au fichier matrice.txt
    string filename = "../matrice_dijkstra.txt";

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << endl;
        return -1;
    }

    // Lecture de la taille de la matrice
    int N;
    file >> N;

    // Lecture de la matrice et initialisation du graphe en attribuant les poids des chemins
    vector<vector<int>> graphe(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            file >> graphe[i][j];
        }
    }

    // Lecture des sommets de début et de fin
    int sommet_debut, sommet_fin;
    cout << "Entrez le sommet de depart (0 a " << N-1 << ") : ";
    cin >> sommet_debut;
    cout << "Entrez le sommet d'arrivee (0 a " << N-1 << ") : ";
    cin >> sommet_fin;

    // Vérification des entrées
    if (sommet_debut < 0 || sommet_debut >= N || sommet_fin < 0 || sommet_fin >= N)
    {
        cerr << "Sommets invalides" << endl;
        return -1;
    }

    vector<int> min_distance, predecesseurs;
    Dijkstra(graphe, sommet_debut, min_distance, predecesseurs);

    vector<int> chemin = plus_court_chemin(sommet_debut, sommet_fin, predecesseurs);

    if (chemin.empty())
    {
        cout << "Aucun chemin n'existe entre " << sommet_debut << " et " << sommet_fin << endl;
    }
    else
    {
        cout << "Distance minimale de " << sommet_debut << " a " << sommet_fin << ": " << min_distance[sommet_fin] << endl;
        cout << "Chemin le plus court : ";
        for (size_t num_sommet = 0; num_sommet < chemin.size(); num_sommet++)
        {
            int sommet = chemin[num_sommet];

            if (num_sommet == chemin.size() - 1)
            {
                cout << sommet;
            }
            else
            {
                cout << sommet << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
