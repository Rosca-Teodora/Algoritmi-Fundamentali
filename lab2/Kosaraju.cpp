// ce face?
// gaseste COMPONENTELE TARE CONEXE

// OBS: proprietatea de TARE CONEXITATE se aplica doar pe GRAFURILE ORIENTATE

// pasi?
// 1. dfs traversal of the graph -> push nodes to stack as you go
// 2. reverse original graph -> start a 2nd dfs traversal
// 3. whenever a dfs traversal is found that means you have a strongly connected component (componenta tare conexa) -> incepi cautare dfs doar daca nu a fost vizitat nodul deja
// 4. repeat traversal until graph is empty

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

stack<int> stiva; // first in last out
vector<int> lista[10001];
vector<int> listaInversata[10001];
int vizitat[10001];
int vizitat2[10001]; // pastreaza, in loc de 1, COMPONENTA TARE CONEXA din care face parte nodul
// adica vizitat2[3] = 2 inseamna ca nodul 3 apartine componentei tare conexe 2

int compTareConexe; // nr total (LA FINAL) al componentelor tare conexe + also ajuta sa populezi vizitat2!!

void dfs1(int nod)
{
    vizitat[nod] = 1;

    for (auto vecin : lista[nod])
    {
        if (vizitat[vecin] == 0)
        {
            dfs1(vecin);
        }
    }

    // ft important sa incepi de la FINAL sa pui nodurile in stiva -> dupa ce se termina cu totul dfs-ul
    stiva.push(nod);
}

void dfs2(int nod)
{
    vizitat2[nod] = compTareConexe;

    for (auto vecin : listaInversata[nod])
    {
        if (vizitat2[vecin] == 0)
        {
            dfs2(vecin);
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

        // graf ORIENTAT
        lista[x].push_back(y);

        // se face instant (in loc sa mai apelez o alta functie cum ma gandeam initial) graful inversat
        listaInversata[y].push_back(x);
    }

    // prima parcurgere -> se face stiva
    for (int i = 1; i <= n; i++)
    {
        if (vizitat[i] == 0)
            dfs1(i);
    }

    // processing nodes in order of DECREASING FINISH TIMES (:= de la primul nod terminat pana la ultimul)
    while (!stiva.empty()) 
    {
        int nodTop = stiva.top();
        stiva.pop();

        // pt fiecare nod nevizitat (initial sau care nu se afla in nicio componenta conexa din celelalte parcurgeri)
        // se marcheaza o componenta noua si se reincepe dfs-ul
        if (vizitat2[nodTop] == 0)
        {
            compTareConexe++;
            dfs2(nodTop);
        }
    }

    // nr total comp tare conexe
    cout << compTareConexe << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << vizitat2[i] << " ";
    }

    return 0;
}