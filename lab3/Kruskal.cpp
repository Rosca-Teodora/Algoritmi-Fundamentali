// ALGORITMUL KRUSKAL
// input: lista de muchii cu costuri asociate
// output: cel mai scurt drum de cost minim (arborele de cost minim, apcm)

// cum functioneaza?
// in primul rand PASTREAZA MUCHIILE INTR-O LISTA SIMPLA (NU avem nevoie de litsa de adiacenta)
// in al doilea rand SORTEAZA MUCHIILE dupa cost!
// conecteaza in ordine crescatoare cele mai eficiente dpdv al costului muchiei
// NU conecteaza doua noduri care deja au fost incluse in arborele de cost minim
//      --> cum verific daca sunt doua noduri in acelasi arbore? functie separata de find parent! daca au acelasi parinte inseamna ca sunt in acelasi nod

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<tuple<int, int, int>> listaMuchii;
vector<pair<int, int>> muchiiRezultat; // muchiile din arborele final
// muchia (u,v) pastrata: nodul u, nodul v, cost

int parinte[100001]; // tine minte parintele fiecarui nod in arborele ce se formeaza (pt a nu face cicluri)
int height[1000001]; // tine minte inaltimea arborelui din care face parte nodul pt a pastra arborele balansat

int comp(tuple<int, int, int> a, tuple<int, int, int> b) // compar termenii in functie de costul muchiei
{
    // sortare ascendenta
    return get<2>(a) < get<2>(b);
}

int find_root_node(int nod)
{
    while (nod != parinte[nod])
    {
        nod = parinte[nod];
    }
    return nod;
}


int main()
{
    int n, m, costTotal = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        tuple<int, int, int> muchie;
        cin >> get<0>(muchie); // citesc nodul u
        cin >> get<1>(muchie); // citesc nodul v
        cin >> get<2>(muchie); // citesc COSTUL muchiei

        listaMuchii.push_back(muchie);
    }

    // muchiile trebuie sortate in ordine creascatoare -> de cele mai multe ori se foloseste un merge sort
    // sortarea din stl -> O(nlogn)
    sort(listaMuchii.begin(), listaMuchii.end(), comp);

    // fiecare nod este propriul parinte la inceput (un nod izolat = o comp conexa de sine statatoare)
    for (int i = 1; i <= n; i++) {
        parinte[i] = i;
        height[i] = 1;
    }

    // conectarea propriu-zisa a muchiilor -> pastrez doar muchiile care intra in arborele de cost minim
    for (auto muchie : listaMuchii)
    {
        if (muchiiRezultat.size() == n - 1)
        {
            break;
        }

        int nod1 = get<0>(muchie);
        int nod2 = get<1>(muchie);
        int cost = get<2>(muchie);

        int a = find_root_node(nod1);
        int b = find_root_node(nod2);

        if (a != b) // sunt in arbori diferiti pana acum = NU  se formeaza ciclu daca se conecteaza
        {
            if (height[a] < height[b])
                swap(a, b);

            parinte[b] = a;
            height[a] += height[b];

            muchiiRezultat.push_back({nod1, nod2});
            costTotal += cost;
        }
    }

    cout << costTotal << "\n";
    cout << muchiiRezultat.size() << "\n";
    for (auto muchie : muchiiRezultat)
    {
        cout << muchie.first << " " << muchie.second << "\n";
    }

    return 0;
}