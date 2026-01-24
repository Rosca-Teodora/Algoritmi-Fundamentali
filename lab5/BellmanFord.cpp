// Bellman-Ford
// cum functioneaza?
// itereaza de MAXIM n - 1 ori prin toate nodurile grafului si updateaza distantele de fiecare data in functie de distantele modificate

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;

// ifstream cin("bellmanford.in");
// ofstream cout("bellmanford.out");

vector<pair<int, int>> lista[50001];
queue<int> q; // varfurile care au fost actualizate pana acum! (daca stiva e vida inseamna ca nu se mai actualizeaza nimic de la o iteratie la alta -> programul se poate opri/ au fost gasite drumurile minime)
int nr[50001], isInQ[50001]; // de cate ori a fost introdus varful in stiva; (pt determinarea ciclurilor de cost negativ)
int d[50001], tata[50001], INF = 1e9;

int main()
{
    int n, m, start = 1;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        lista[x].push_back({y, c});
        //lista[y].push_back({x, c});
    }

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        tata[i] = 0;
    }
    d[start] = 0;
    q.push(start);
    // tb marcat varful ca fiind in coada
    isInQ[start] = 1;
    while (!q.empty()) {
        int nodFront = q.front(); // nu e stiva e coada asa ca nu folosesti top
        q.pop();
        isInQ[nodFront] = 0;

        // pt fiecare vecin al nodului tocmai extras din stiva
        for (auto vecin : lista[nodFront]) {
            int nodVecin = vecin.first;
            int costCatreVecin = vecin.second;

            if (d[nodFront] < INF && d[nodFront] + costCatreVecin < d[nodVecin]) {
                d[nodVecin] = d[nodFront] + costCatreVecin;
                tata[nodVecin] = nodFront;

                // adauga in coada doar daca nu e deja adaugat
                if (isInQ[nodVecin] == 0) {
                    q.push(nodVecin);
                    nr[nodVecin]++;
                    if (nr[nodVecin] >= n) { // daca NU avem aceasta linie se va repeta la nesfarsit si algoritmul acesta :(( womp womp
                        cout << "Ciclu negativ!";
                        return 0;
                    }
                    isInQ[nodVecin] = 1;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << d[i] << " ";
    }

    return 0;
}
