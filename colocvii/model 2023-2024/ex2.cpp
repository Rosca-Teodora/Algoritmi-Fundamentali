// Se dă un graf neorientat cu  noduri și  muchii reprezentând o rețea de  străzi bidirecționale (muchii) între  obiective (noduri), o stradă unind două obiective.
//
// În această rețea urmează să se asfalteze străzi astfel încât după asfaltări între oricare două obiective să se poată ajunge pe drumuri formate doar din străzi nou asfaltate.
//
// Pentru fiecare stradă se cunoaște costul necesar asfaltării ei. În plus, se dă o listă de  străzi care trebuie obligatoriu asfaltate.
//
// Știind ca avem la dispoziție un buget , decideți dacă se pot face asfaltări care să respecte cerințele fără a depăși bugetul  și afișați un mesaj corespunzător Da/Nu; în caz afirmativ, să se afișeze o listă cu străzile care trebuie asfaltate.
// Alg. Folosit: KRUSKAL

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct muchie {
    int x, y, cost;
    bool obligatoriu;
};

vector<muchie>listaMuchii; // nod1, nod2, cost, muchie obligatorie?
vector<muchie> straziFinale;
set<pair<int, int>> muchiiObligatorii;
int tata[100001], height[1000001];

bool comp(muchie a, muchie b) {
    if (a.obligatoriu != b.obligatoriu) { // daca o muchie e obligatorie si cealalta nu atunci cea obligatorie are prioritate
        return a.obligatoriu > b.obligatoriu;
    }
    return a.cost < b.cost;
}

int gaseste_parinte(int nod) {
    while (nod != tata[nod]) {
        nod = tata[nod];
    }
    return nod;
}

int main() {
    int n, m, k, B;
    int costTotal = 0;
    bool posibil = true;
    cin >> n >> m >> k >> B;
    for (int i = 1; i <= m; i++) {
        int x, y ,c;
        cin >> x >> y >> c;

        if (x > y) swap(x, y);

        listaMuchii.push_back({x, y, c});
    }

    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        muchiiObligatorii.insert({a, b});
    }

    for (auto& muchieCurenta : listaMuchii) {
        int nod1 = muchieCurenta.x;
        int nod2 = muchieCurenta.y;

        if (muchiiObligatorii.count({nod1, nod2}) != 0) {
            muchieCurenta.obligatoriu = true;
        }
    }

    sort(listaMuchii.begin(), listaMuchii.end(), comp);

    // tb initializate nodurile ca fiind componente separate
    for (int i = 1; i <= n; i++) {
        tata[i] = i;
        height[i] = 1;
    }

    for (auto muchie : listaMuchii) {
        int nod1 = muchie.x;
        int nod2 = muchie.y;
        int radacina1 = gaseste_parinte(nod1);
        int radacina2 = gaseste_parinte(nod2);
        if (radacina1 != radacina2) {
            if (height[radacina1] > height[radacina2]) {
                tata[radacina2] = radacina1;
                height[radacina1] += height[radacina2];
            }
            else
                if (height[radacina1] < height[radacina2]) {
                    tata[radacina1] = radacina2;
                    height[radacina2] += height[radacina1];
                }
                else {
                    tata[radacina2] = radacina1;
                    height[radacina1] += 1;
                }

            straziFinale.push_back(muchie);
        }
        else if (muchie.obligatoriu) { // se plateste oricum muchia obligatorie
            costTotal += muchie.cost;
        }
    }

    for (auto muchie : straziFinale) {
        if (costTotal > B) {
            posibil = false;
            break;
        }

        costTotal += muchie.cost;
    }

    if (costTotal <= B && straziFinale.size() == n - 1) {
        cout << "Da\n";
        for (auto muchie : straziFinale) {
            cout << muchie.x << " " << muchie.y << "\n";
        }
    }
    else {
        cout << "Nu";
    }

    return 0;
}
