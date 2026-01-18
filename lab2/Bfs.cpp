// cum functioneaza breadth first search-ul? (bfs-ul?)
// primul nod -> FIECARE vecin al nodului ala -> fiecare vecin al primului vecin -> fiecare veci al celui de-al doilea vecin s.a.m.d
// cum implementam? printr-o coada -> se retin nodurile ce urmeaza sa fie vizitate
// ex: 
// lista de adiacenta: 
// 1: 2, 3, 4
// 2: 1, 4
// 3: 1, 4
// 4: 1, 2, 3, 5
// 5: 4

// parcurgere bfs: 1 2 3 4 5


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// lisat de adiacenta in care sunt retinute initial nodurile
vector<int> lista[101];

// coada (first in first out) prin care se pastreaza nodurile pentru a fi accesate in ordinea corecta
queue<int> coada;

int vizitat[101];

void bfs(int start)
{
    // se ia nodul de start si se pune in coada
    coada.push(start);
    cout << start << " ";

    // cat timp coada NU este goala 
    while (!coada.empty())
    {
        int nodDeMarcat = coada.front();
        coada.pop();

        for (auto vecin : lista[nodDeMarcat])
        {
            if (vizitat[vecin] == 0)
            {
                // cand e pus in coada , vecinul tb marcat ca vizitat pentru ca VA FI VIZITAT!!
                // altfel -> duplicate
                vizitat[vecin] = 1; 
                coada.push(vecin);// pt a afisa cum arata parcurgerea bfs
                cout << vecin << " ";
            }
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    int start = 1;
    bfs(start);

    return 0;
}