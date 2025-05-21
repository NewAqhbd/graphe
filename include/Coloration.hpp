using namespace std;

// Structure pour stocker les sommets avec leur degré
typedef struct Sommet {
    int id;
    int degre;
} Sommet;

void trierParDegre(vector<Sommet>& sommets);

void welshPowell(const vector<vector<int>>& graphe);

int main_coloration();

