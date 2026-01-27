//Se considera un graf neorientat cu n noduri si m muchii.
//// Sa se determine cate componente conexe ale acestui graf au cel putin k noduri.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> lista[100001];
int vizitat[100001];

void dfs(int nod, int& nr) {
    nr++;
    vizitat[nod] = 1;
    for (auto vecin : lista[nod]) {
        if (vizitat[vecin] == 0) {
            dfs(vecin, nr);
        }
    }
}

int main() {
    int n, m, k, totalCerut = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    for (int i = 1; i<= n; i++) {
        int nrNoduriCompCurenta = 0;
        if (vizitat[i] == 0) {
            dfs(i, nrNoduriCompCurenta);
        }
        if (nrNoduriCompCurenta >= k)
            totalCerut++;
    }

    cout << totalCerut;
}