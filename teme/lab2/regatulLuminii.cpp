
// ------------------------
// NETERMINATA!!!!!
// ------------------------

// În Regatul Luminii, există n orașe conectate printr-o rețea de drumuri bidirecționale. Regele Solaris a primit q cereri (numerotate de la 1 la ) pentru a adăuga noi drumuri între perechi de orașe

// . Totuși, fiecare drum construit consumă resurse importante, așa că regele l-a rugat pe Oracolul Drumurilor să analizeze cererile.

// Pentru fiecare cerere, Oracolul trebuie să răspundă:

//     1 – dacă noul drum reduce drumul cel mai scurt dintre Orașul 1 și Orașul 

//     
//     0 – dacă drumul nu aduce nicio îmbunătățire.

// După evaluare, regele dorește să știe pentru câte cereri răspunsul este 1 și indicele acestor cereri în ordine crescătoare.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> lista[10001];
queue<int> coada;

int vizitat[10001];
int n, m, q;

int distantaNormala[10001];
int distantaInversata[10001];

void bfs(int distanta[10001], int start)
{
    // calculez distanta tuturor
    for (int i = 1; i <= n; i++)
        distanta[i] = -1;
    
    distanta[start] = 0; 
    coada.push(start);

    while (!coada.empty())
    {
        int nodTop = coada.front();
        coada.pop();

        for (auto vecin : lista[nodTop])
        {
            if (distanta[vecin] == -1)
            {
                distanta[vecin] = distanta[nodTop] + 1;
                coada.push(vecin);
            }
        }
    }
}

int main()
{
    int nrMuchiiBune = 0, lenDrumMin;
    vector<int> indiciMuchii;

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    bfs(distantaNormala, 1); // calculez distanta de la 1 la n
    bfs(distantaInversata, n); // calculez distanta de la n la 1
    lenDrumMin = distantaNormala[n];

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;

        int ruta1 = distantaNormala[a] + 1 + distantaInversata[b]; // practic calculez 
        // distanta de la 1 la a + muchia (a, b) + distanta de la b la n
        int ruta2 = distantaNormala[b] + 1 + distantaInversata[a];
        // distanta de la 1 la b + muchia (b, a) + distanta de la a la n
        if (min(ruta1, ruta2) < lenDrumMin)
        {
            nrMuchiiBune++;
            lenDrumMin = min(ruta1, ruta2);
            indiciMuchii.push_back(i);
        }
    }

    cout << nrMuchiiBune << '\n';
    for (auto pozitie : indiciMuchii)
    {
        cout << pozitie << " ";
    }

    return 0;
}