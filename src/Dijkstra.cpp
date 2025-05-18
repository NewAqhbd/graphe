#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

#include "Dijkstra.hpp"

using namespace std;

const int INF = numeric_limits<int>::max();

// Trouve le sommet de distance minimale qui n'est pas encore traité
int trouver_distance_min(const vector<int>& min_distance, const vector<bool>& is_to_process) {
    int minimum_distance = INF;
    int sommet = -1;

    for (size_t i = 0; i < min_distance.size(); i++) {
        if (is_to_process[i] && min_distance[i] < minimum_distance) {
            minimum_distance = min_distance[i];
            sommet = i;
        }
    }

    return sommet;
}

// Mise à jour des distances
void maj_distances(int sommet1, int sommet2, const vector<vector<int>>& graphe, vector<int>& min_distance, vector<int>& predecesseurs) {
    if (graphe[sommet1][sommet2] > 0 && min_distance[sommet2] > min_distance[sommet1] + graphe[sommet1][sommet2]) {
        min_distance[sommet2] = min_distance[sommet1] + graphe[sommet1][sommet2];
        predecesseurs[sommet2] = sommet1; // Le sommet2 a pour prédécesseur le sommet1
    }
}

// Algorithme principal de Dijkstra
void Dijkstra(const vector<vector<int>>& graphe, int sommet_debut, vector<int>& min_distance, vector<int>& predecesseurs) {
    int N = graphe.size();
    min_distance.assign(N, INF);
    
    predecesseurs.assign(N, -1); // Initialisation de la liste des prédecesseurs
    vector<bool> is_to_process(N, true);

    min_distance[sommet_debut] = 0;

    while (true) {
        int sommet1 = trouver_distance_min(min_distance, is_to_process);
        if (sommet1 == -1) break; // Plus aucun sommet accessible
        is_to_process[sommet1] = false;

        for (int sommet2 = 0; sommet2 < N; ++sommet2) {
            if (graphe[sommet1][sommet2] > 0) { // Si le sommet2 est voisin du sommet1
                maj_distances(sommet1, sommet2, graphe, min_distance, predecesseurs);
            }
        }
    }
}

// Fonction pour reconstruire le plus court chemin de sommet_debut à sommet_fin
vector<int> plus_court_chemin(int sommet_debut, int sommet_fin, const vector<int>& predecesseurs) {
    vector<int> chemin;
    for (int sommet = sommet_fin; sommet != -1; sommet = predecesseurs[sommet]) {
        chemin.insert(chemin.begin(), sommet);
        if (sommet == sommet_debut) break;
    }
    if (chemin.front() != sommet_debut) {
        return {}; // Aucun chemin trouvé, donc on retourne un vecteur vide
    }
    return chemin;
}


int main_dijkstra() {
    // Le programme se trouve par défaut dans le répertoire build,
    // donc on remonte min_distance'un niveau pour accéder au fichier matrice.txt
    string filename = "../matrice.txt";

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur: Impossible min_distance'ouvrir le fichier " << filename << endl;
        return -1;
    }

    // Lecture de la taille de la matrice
    int N;
    file >> N;

    // Lecture de la matrice
    vector<vector<int>> graphe(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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
    if (sommet_debut < 0 || sommet_debut >= N || sommet_fin < 0 || sommet_fin >= N) {
        cerr << "Erreur: Sommets invalides" << endl;
        return -1;
    }

    vector<int> min_distance, predecesseurs;
    Dijkstra(graphe, sommet_debut, min_distance, predecesseurs);

    vector<int> chemin = plus_court_chemin(sommet_debut, sommet_fin, predecesseurs);

    if (chemin.empty()) {
        cout << "Aucun chemin n'existe entre " << sommet_debut << " et " << sommet_fin << endl;
    } else {
        cout << "Distance minimale de " << sommet_debut << " a " << sommet_fin << ": " << min_distance[sommet_fin] << endl;
        cout << "Chemin le plus court : ";
        for (size_t num_sommet = 0; num_sommet < chemin.size(); num_sommet++) {
            int sommet = chemin[num_sommet];

            if (num_sommet == chemin.size() - 1) {
                cout << sommet;
            } else {
                cout << sommet << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
