// alg dijkstra
// pe ce e folosit? --> grafuri ORIENTATE (merge si pe neorientate tho) care pot CONTINE CICLURI si au doar ponderi POZITIVE 

// cum functioneaza??
// generalizare a algoritmului de bfs -> cand toate nodurile au distantele egale este chiar echivalent

// complexitate: O(MlogN)

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

int d[500001]; // costul drumului de la sursa la i
int tata[500001]; // tatal lui i pentru distanta curent salvata
int INF = 1e9;

vector<pair<int, int>> lista[500001];
priority_queue<pair<int, int>> Q; // multimea (ponderi, vf neselectate) 

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        // pt graf orientat
        lista[x].push_back({y, c});
    }

    // init
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
        tata[i] = 0;
    }
    d[1] = 0; // start in 1

    Q.push({0, 1});

    while (!Q.empty())
    {
        int nodTop = Q.top().second; // u
        int costCurent = -Q.top().first;
        Q.pop();

        if (costCurent > d[nodTop]) // se verif daca exista deja un drum mai scurt
            continue;

        for (auto vecin : lista[nodTop]) // nodTop parintele vecinuluo
        {
            int nodVecin = vecin.first; // nod v
            int costVecin = vecin.second; // w(u, v) costul arcului (u,v)

            // "relaxarea" muchiei :)
            if (d[nodVecin] > d[nodTop] + costVecin) 
            {
                d[nodVecin] = d[nodTop] + costVecin;
                tata[nodVecin] = nodTop;
                // min-heap prin costul negativ
                Q.push({-d[nodVecin], nodVecin});
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (d[i] == INF) // nu exista drum
            cout << 0 << " ";
        else 
            cout << d[i] << " ";

    return 0;
}