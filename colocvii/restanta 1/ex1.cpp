#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int vizitat[100001];
int tata[100001];
vector<int> lista[100001], descendenti, ascendenti;
int c;

void dfs_tati (int nod, int parinte) {
    vizitat[nod] = 1;
    for (auto vecin : lista[nod]) {
        if (vizitat[vecin] == 0 && vecin != parinte) {
            tata[vecin] = nod;
            dfs_tati(vecin, nod);
        }
    }
}

void dfs_desc(int nod, int parinte) {
    vizitat[nod] = 1;

    for (auto vecin : lista[nod]) {
        if (vizitat[vecin] == 0 && vecin != parinte) {
            descendenti.push_back(vecin);
            dfs_desc(vecin, nod);
        }
    }
}

void parcurge_tati(int nod) {
    while (tata[nod]) {
        if (nod != c) ascendenti.push_back(nod);
        nod = tata[nod];
    }
}

int main() {
    int n, r;
    cin >> n >> r >> c;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    dfs_tati(r, 0);

    for (int i = 1; i <= n; i++) {
        vizitat[i] = 0;
    }

    dfs_desc(c, tata[c]);

    if (ascendenti.size() == 0) {
        cout << 0;
    }
    else {
        for (auto asc : ascendenti) {
            cout << asc << " ";
        }
    }

    cout << "\n";

    if (descendenti.size() == 0) {
        cout << 0;
    }
    else {
        for (auto desc : descendenti) {
            cout << desc << " ";
        }
    }

    return 0;
}