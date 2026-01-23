// calcularea drumului minim intr-un DAG (directed aciclic graph)
// complexit. mai buna decat Dijstra dar nu merge deloc pe cicluri
// poate primi PONDERI NEGATIVE

// compelxitate: O(n + m)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tata[1000001], d[1000001], vizitat[1000001], INF = 1e9;
vector<pair<int, int>> lista[1000001];
stack<int> sortareTop;

void sortare_topologica(int nod) // implementez sortarea topologica printr-un dfs
{
    vizitat[nod] = 1;
    for (auto vecin : lista[nod])
    {
        if (vizitat[vecin.first] == 0)
            sortare_topologica(vecin.first);
    }

    sortareTop.push(nod);
}

int main()
{
    int n, m, start; // zicem ca citesc initial varful de start
    cin >> n >> m >> start;

    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        // orientat
        lista[x].push_back({y, c});
    }

    // initializarea drumului minim si a tatalui
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
        tata[i] = 0;
    }
    d[3] = 0;

    // fiindca e aciclic sunt cazuri in care nu e e conex -> tb totusi sa sortezi TOATE nodurile!
    for (int i = 1; i <= n; i++)
    {
        if (vizitat[i] == 0)
            sortare_topologica(i); // sortez topologic --> vor fi pastrate in stiva sortareTop (ordinea de scoatere din stiva = ordinea sortarii topologice)
    }
    
    while (!sortareTop.empty())
    {
        int nodTop = sortareTop.top();
        sortareTop.pop();

        if (d[nodTop] != INF) // putem considera (ca la curs) ca daca nu se poate accesa nodul din nodul sursa atunci nu tb sa fie luat in calcul nici pt relaxare
        {
            for (auto vecin : lista[nodTop])
            {
                int nodVecin = vecin.first;
                int costVectin = vecin.second;

                // relaxarea muchiei!
                if (d[nodVecin] > d[nodTop] + costVectin)
                {
                    d[nodVecin] = d[nodTop] + costVectin;
                    tata[nodVecin] = nodTop;
                }
            }
        }
        
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            cout << "Nod " << i << ": Inaccesibil\n";
        else
            cout << "Nod " << i << ": dist = " << d[i] << ", tata = " << tata[i] << "\n";
    }

    return 0;
}