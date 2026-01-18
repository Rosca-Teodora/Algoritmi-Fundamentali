// cand se face o parcurgere dfs se itereaza prin vecini -> atunci cand un nod nu mai are vecini DAR mai sunt noduri de parcurs

#include <iostream>
#include <vector>

using namespace std;

// array de vizitat
int vizitat[101];

// lista adiacenta
vector<int> lista[101];

void dfs(int nod)
{
    vizitat[nod] = 1;

    for (auto vecin : lista[nod])
    {
        if (vizitat[vecin] == 0)
            dfs(vecin);
    }
}

int main() 
{
    int n, m, nrCompConexe;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) 
    {
        int x, y;
        cin >> x >> y;
        
        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    for (int nod = 1; nod <= n; n++)
    {
        if (vizitat[nod] == 0) // la inceput SAU nu se pot lega nodurile
        {
            dfs(nod); 
            nrCompConexe++;
        }
    }


    return 0;
}