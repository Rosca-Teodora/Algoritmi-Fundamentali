// parcurgere bfs de la o sursa data a.i. sa se gaseasca DOAR distanta de la acea sursa catre celelalte noduri

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> lista[101];
queue<int> coada;

int n, m, start;
int distanta[101];

void bfs(int start)
{
    for (int i = 1; i <= n; i++)
        distanta[i] = -1; 
    
    distanta[start] = 0;
    coada.push(start);
    
    while (!coada.empty())
    {
        int nodCurent = coada.front();
        coada.pop();

        for (auto vecin : lista[nodCurent])
        {
            if (distanta[vecin] == -1)
            {
                distanta[vecin] = distanta[nodCurent] + 1;
                coada.push(vecin);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> start;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    bfs(start);

    cout << "sursa este nodul: " << start << "\n"; 
    cout << "distanta de la nodul x la start (format x : distanta) este: \n";

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << distanta[i] << " ";
    }

    return 0;
}