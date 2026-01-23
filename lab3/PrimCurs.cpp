#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> lista[100001];
priority_queue<pair<int, int>> Q; // {-cost, u}
int d[1000001]; // costul muchiei (u, tata[u])
int tata[1000001];
int INF = 1e9;
int vizitat[1000001];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i<= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        lista[x].push_back({y, c});
        lista[y].push_back({x, c});
    }

    // initializare 
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
        tata[i] = 0;
    }

    // nodul start
    int start = 1;
    d[start] = 0;
    Q.push({-0, start});

    while (!Q.empty())
    {
        int cost = -Q.top().first;
        int nod = Q.top().second;

        Q.pop();
        if (vizitat[nod] == 0)
        {
            vizitat[nod] = 1;

            for (auto vecin : lista[nod])
            {
                int nodVecin = vecin.first;
                int costVecin = vecin.second;

                // diferenta practica dintre algoritmul scris de mine si asta prezentat la curs -> eu nu verificam daca exista deja un cost minim pentru nod si doar MUNEAM TOATE MUCHIILE INTR-UN HEAP!!!
                if (vizitat[nodVecin] == 0 && d[nodVecin] > costVecin)
                {
                    d[nodVecin] = costVecin;
                    tata[nodVecin] = nod;

                    // stocare in HEAP!
                    Q.push({-d[nodVecin], nodVecin});
                }
            }
        }
    }
    
    cout << "Muchiile arborelui sunt: \n";
    for (int i = 1; i <= n; i++)
    {
        if (tata[i] != 0)
        {
            cout << tata[i] << " " << i << "\n"; 
        }
    }
    return 0;
}