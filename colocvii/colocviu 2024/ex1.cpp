#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, vizitat[1001], tata[1001];
vector<int> lista[1001];
int capacitate[1001][1001];
queue<int> coada;

int bfs(int s, int t) {
    for (int i = 1; i <= n; i++) {
        vizitat[i] = 0;
        tata[i] = 0;
    }
    coada.push(s);
    vizitat[s] = 1;

    while (!coada.empty()) {
        int nodFront = coada.front();
        coada.pop();

        for (auto vecin : lista[nodFront]) {
            if (vizitat[vecin] == 0 && capacitate[nodFront][vecin] > 0) {
                vizitat[vecin] = 1;

                coada.push(vecin);
                tata[vecin] = nodFront;

                if (vecin == t) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int mainEK(int s, int t) {
    int nrTotal = 0;

    while (bfs(s, t)) {

        for (int v = t; v != s; v = tata[v]) {
            int u = tata[v];

            capacitate[u][v]--;
            capacitate[v][u]++;
        }
        nrTotal++;
    }
    return nrTotal;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);

        capacitate[x][y] = 1;
        capacitate[y][x] = 1;
    }

    cout << mainEK(1, n);

    return 0;
}