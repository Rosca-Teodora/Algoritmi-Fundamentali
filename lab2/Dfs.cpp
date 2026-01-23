
// cum arata o lista de adiacenta? 
// se da un nr n de noduri si un nr m de muchii
// dupa se listeaza muchiile
// ex: 5 6
// 1 2
// 1 3
// 1 4
// 2 4
// 4 5
// 3 4

// lista de adiacenta va arata: 
// 1: 2, 3, 4
// 2: 1, 4
// 3: 1, 4
// 4: 1, 2, 3, 5
// 5: 4

// parcurgere dfs: 1 2 4 3 5 sau 1 2 4 5

// complexitate: O(n + m)

#include <iostream>
#include <vector>

using namespace std;

// lista de adiacenta
vector <int> lista[101];

// array de int-uri pentru fiecare nod
// vizitat marcat cu 1, neviz cu 0
int vizitat[101];

// functia dfs recursiva
// OBS: implementarea de mai jos parcurge tot graful ATUNCI CAND E CONEX!!
// fiindca itereaza doar prin vecini, in momentul in care exista noduri care sa nu mai fie conectate intre ele NU SE MAI PARCURG!!
void dfs(int nod) 
{
    // tb marcat nodul ca vizitat! (of course)
    vizitat[nod] = 1;
    
    // afiseaza pentru a valida parcurgerea
    cout << nod << " ";

    // parcurgerea vecinilor nodului! 
    for (auto vecin : lista[nod]) {
        if (vizitat[vecin] == 0)
            dfs(vecin);
    }
}

int main() 
{
    // se da un nr n de noduri si un nr m de muchii
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        // se dau muchiile grafului 
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y); // se marcheaza y ca vecin al lui x
        lista[y].push_back(x); // se marcheaza x ca vecin al lui y

        // pt graf ORIENTAT se marcheaza doar o data (intr-o singura directie)
    }

    cout << "parcurgere dfs: ";
    // PT ITEREAREA SI PRIN GRAFURILE CARE NU SUNT CONEXE
    for (int nod = 1; nod <= n; nod++)
    {
        if (vizitat[nod] == 0) 
        {
            dfs(nod);
        }        
    }
    
    return 0;
}  