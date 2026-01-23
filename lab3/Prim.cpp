// 
// alg lui prim? 
//      -> ia mereu minimul dintre toate muchiile valabile 
//      -> verifica sa nu se creeze niciun ciclu!
//      -> O(N^2) cu o MATRICE DE ADIACENTA
//      -> O(NlogN + MlogN) cu o LISTA de adiacenta + un MIN HEAP!

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

vector<pair<int, int>> lista[100001]; // u: {v, cost muchie (u,v)}
priority_queue<pair<int, int>> muchii; // va fi un max heap in care greutatea muchiilor va fi introdusa ca negativa 
int vizitat[100001];
long long costTotal = 0;

void alg_prim(int start)
{
    
    muchii.push({0, start});

    while (!muchii.empty())
    {
        int cost = -muchii.top().first;
        int nod = muchii.top().second;

        muchii.pop();

        if (vizitat[nod] == 0)
        {
            vizitat[nod] = 1;
            costTotal += cost;

            for (auto vecin : lista[nod])
            {
                if (vizitat[vecin.first] == 0)
                    muchii.push({-vecin.second, vecin.first}); // in ordinea asta pt ca in lista e marcat nod si dupa cost, iar in priority queue e marcat invers CA SA SE FACA SORTAREA DUP COST!!
            }
        }
    }
    
}

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

    alg_prim(1);

    cout << costTotal << " ";

    return 0;
}
