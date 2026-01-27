#include<fstream>
#include<iostream>
#include <queue>
#include <cstring>
#define MAXN 10001
using namespace std;

int n, m;
int rezid[MAXN][MAXN];
vector<int> lrezid[MAXN];
int viz[MAXN], tata[MAXN];

int bfs() {
    int s = 0;
    int t = n - 1;

    for (int i = 0; i < n; i++) {
        viz[i] = 0;
        tata[i] = 0;
    }

    queue<int> q;
    q.push(s);
    viz[s] = 1;


    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : lrezid[x]) {
            if (!viz[y] && rezid[x][y] > 0) {
                viz[y] = 1;
                tata[y] = x;

                if (y == t)
                    return 1;

                q.push(y);
            }
        }
    }
    return 0;
}

int main() {
    //ifstream cin("maxflow.in");
    ofstream g("maxflow.out");

    cin >> n >> m;



    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;


        lrezid[x].push_back(y);
        lrezid[y].push_back(x);

        rezid[x][y] += c;
    }

    int fmax = 0;
    int s = 0;
    int t = n - 1;

    while (bfs()) {
        int iP = 110001;

        // calculeaza capacitatea ramasa
        t=n-1;
        while(t!=0)  {

            if(iP>rezid[tata[t]][t])
                iP= rezid[tata[t]][t];
            t=tata[t];
        }

        // revizuieste graful
        t=n-1;
        while(t!=0)  {
            rezid[tata[t]][t]-=iP;
            rezid[t][tata[t]]+=iP;
            t=tata[t];
        }

        fmax += iP;
    }

    cout << fmax;

    return 0;
}


// #include <iostream>
// #include <bits/stdc++.h>
// #define NMAX 1001
//
// using namespace std;
//
// int n, m, INF = 1e9;
// int vizitat[1001], tata[1001], rezidual[NMAX][NMAX]; // rezidual == CAPACITATE
// queue<int> coada;
// vector<int> lista[1001];
//
// int bfs(int start, int t) {
//     // reset viz si tata pt fiecare bfs
//     for (int i = 1; i <= n; i++) {
//         vizitat[i] = 0;
//         tata[i] = 0;
//     }
//
//     coada.push(start);
//     vizitat[start] = 1;
//
//     while (!coada.empty()) {
//         int nodTop = coada.front();
//         coada.pop();
//
//         for (auto vecin : lista[nodTop]) {
//             if (vizitat[vecin] == 0 && rezidual[nodTop][vecin] > 0) { // rezidual mentine capacitatea de la nodTop la vecin --> cand e 0 inseamna ca e saturat arcul
//                 vizitat[vecin] = 1;
//                 tata[vecin] = nodTop;
//
//                 if (vecin == t) {
//                     return 1;
//                 }
//
//                 coada.push(vecin);
//             }
//
//         }
//     }
//     return 0; // cand nu se mai gaseste drum catre t nu se mai continua partea main din Edmonds-Karp
// }
//
// int flux_maxim(int s, int t) {
//     int fluxTotal = 0;
//
//     while (bfs(s, t)) {
//         int fluxMinim = INF;
//         // gasesti flux minim
//         for (int nod = t; nod != s; nod = tata[nod]) {
//             fluxMinim = min(fluxMinim, rezidual[nod][tata[nod]]);
//         }
//         // revizuiesti graful
//         for (int u = t; u != s; u = tata[u]) {
//             int v = tata[u];
//
//             // scazi pe arcul direct
//             rezidual[u][v] -= fluxMinim;
//
//             // adaugi pe arcul indirect
//             rezidual[v][u] += fluxMinim;
//         }
//
//         fluxTotal += fluxMinim;
//     }
//
//     return fluxTotal;
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) {
//         int x, y, c;
//         cin >> x >> y >> c;
//
//         lista[x].push_back(y);
//         lista[y].push_back(x);
//
//         rezidual[x][y] += c;
//         // pentru graful rezidual va fi egal cu 0 la inceput
//     }
//
//     int s = 1, t = n;
//
//     cout << "Max flow" << flux_maxim(1, n);
//
//     return 0;
// }