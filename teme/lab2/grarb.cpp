//Se da un graf G neorientat cu N noduri numerotate de la 1 la N si M muchii. 
//Determinati numarul minim de muchii care trebuie eliminate 
//si numarul minim de muchii care trebuie adaugate in graful G astfel incat acesta sa devina arbore.

// exemplu: 
// input: 
//6 5
//1 2
//1 3
//2 4
//1 4
//5 6
// output: 
// 1
// 1

// cum rezolv? 
// nr muchii adaugate = nrCompConexe - 1
// nr muchii sterse = nrMuchii - nrNoduri + nrCompConexe (pt ca un arbore are n - 1 muchii)

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("grarb.in");
ofstream fout("grarb.out");

vector<int> lista[100001];
int vizitat[100001];
int nrMuchiiAdaugate, nrMuchiiSterse;

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
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        fin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vizitat[i] == 0)
        {
            nrMuchiiAdaugate++; // va fi cu una in plus
            dfs(i);
        }
    }

    nrMuchiiSterse = m - n + nrMuchiiAdaugate; // in acest moment nrMuchiiAdaugate = nr componetelor conexe fiindca numara si prima parcurgere
    nrMuchiiAdaugate--; // sterg muchia adaugata in plus

    fout << nrMuchiiSterse << "\n";
    fout << nrMuchiiAdaugate << "\n";
    return 0;
}