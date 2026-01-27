// Floyd-Warshall
// Într-un oraș mare, există o rețea subterană complicată de tuneluri bidireționale care leagă mai multe locații importante. Fiecare tunel are un cost de întreținere diferit, iar administrația orașului vrea să optimizeze cheltuielile. Totuși, un detectiv care investighează dispariția unor obiecte de valoare suspectează că anumite locații joacă un rol important în transportul acestora.
//
// Rețeaua subterană poate fi reprezentată sub forma unui graf neorientat:
//
// Fiecare locație este un nod numerotat de la  la .
// Fiecare tunel între două locații are un cost asociat.
// Detectivul trebuie să răspundă la  întrebări pentru a-și rezolva cazul. Fiecare întrebare are forma: , însemnând "Este locația  implicată în cel mai ieftin traseu (adică pe un drum de cost minim) între locațiile  și ?"
//
// Dacă locația  se află pe un drum de cost minim între  și , atunci detectivul o marchează drept „critică” (afișează valoarea 1), dacă nu, afișează valoarea 0.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;
int d[301][301], p[301][301];

void initializare_matrice_distante(int n, int m) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
}

bool verifica_nod_critic(int i,int j, int k) {
    if (i != j) {
        return verifica_nod_critic(i, p[i][j], k);
    }
    if (k == i)
        return true;
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m;

    initializare_matrice_distante(n, m);

    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        d[x][y] = c;
        d[y][x] = c;
        //p[x][y] = x;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    //p[i][j] = p[k][j];
                }
            }

    cin >> q;
    for (int l = 1; l <= q; l++) {
        int i, j, k;
        cin >> i >> j >> k;

        if (d[i][j] == d[i][k] + d[k][j])
            cout << 1;
        else
            cout << 0;
    }

    return 0;
}