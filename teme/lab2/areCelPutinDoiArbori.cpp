// Fie G un graf neorientat cu n noduri, numerotate de la la 1, si  m muchii. 
// Sa se determine daca are cel putin doi arbori partiali distincti ( = care difera prin cel putin o muchie). 
// In caz afirmativ, sa se afiseze doi arbori partiali distincti ai lui .

// Complexitate ceruta: O(n + m)

// Input Format
//
// Programul citeste de la tastatura valorile si apoi perechi reprezentand muchiile grafului.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lista[100001];
int vizitat[100001];
int tata[100001];

// pt a pastra muchiile din ce idoi arbori arbori
vector<pair<int, int>> arbore1, arbore2;

// pt a pastra muchia pe care o vom adauga in arborele 2
pair<int, int> muchie_extra = {-1, -1};

void dfs(int nod, int parinte)
{
    vizitat[nod] = 1;
    tata[nod] = parinte;

    for (auto vecin : lista[nod])
    {
        if (vecin != parinte)
        {
            if (vizitat[vecin] == 0)
            {
                arbore1.push_back({nod, vecin}); // tin minte muchiile primul arbore -> adica cel dat de parcurgerea initiala
                dfs(vecin, nod);
            }
            else 
            {
                if (muchie_extra.first == -1) // daca nu am tinut deja minte o muchie extra 
                    muchie_extra = {nod, vecin};
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

        dfs(1, 0);

        if (arbore1.size() != n - 1) // daca arborele gasit nu uneste toate nodurile (adica nu e conex graful)
        {
            cout << "Nu";
        }
        else 
        {
            cout << "Da" << "\n";
            for (auto muchie : arbore1)
            {
                cout << muchie.first << " " << muchie.second << "\n";
            }

            for (auto muchie : arbore1)
            {
                bool sterge_muchia = (muchie.first == muchie_extra.first && muchie.second == tata[muchie.first]) || 
                                     (muchie.second == muchie_extra.first && muchie.first == tata[muchie.second]);
                if (sterge_muchia)
                {
                    cout << muchie_extra.first << " " << muchie_extra.second << "\n";
                }
                else 
                {
                    cout << muchie.first << " " << muchie.second << "\n";
                }
            }
        }

    return 0;
}