#include <vector>

using namespace std;

int Trouve_min(const vector<int>& d, const vector<bool>& inQ);

void maj_distances(int s1, int s2, const vector<vector<int>>& G, vector<int>& d, vector<int>& pred);

void Dijkstra(const vector<vector<int>>& G, int sdeb, vector<int>& d, vector<int>& pred);

vector<int> plusCourtChemin(int sdeb, int sfin, const vector<int>& pred);

int main_dijkstra();