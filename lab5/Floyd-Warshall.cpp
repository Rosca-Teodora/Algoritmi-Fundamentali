// Floyd-Warshall
// ce face? calculeaza distanta de la TOATE nodurile la TOATE celelalte noduri
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;
int d[10001][10001], p[10001][10001];

void drum(int i, int j) { // trece prin parintele lui i astfel incat sa refaca drumul pana ajunge la diag principala 
    if (i != j) {
        drum (i, p[i][j]);
    }
    cout << j << " ";
}

int main() {
    int n, m;
    cin >> n >> m;

    // init cu infinit sau 0 pt matricea de adiacenta
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; i++) {
        // se face o matrice de adiacenta in care se pastreaza costurile muchiei de la i la j
        // i == j -> a[i][j] = 0
        // exista muchia (i,j) -> a[i][j] = costul muchiei (i, j)
        // nu exista muchia (i, j) -> a[i][j] = INF
        int x, y, c;
        cin >> x >> y >> c;

        // graf orientat
        d[x][y] = c;
        p[x][y] = i;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
    return 0;
}