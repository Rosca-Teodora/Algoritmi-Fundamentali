// Alg lui Kahn
// "elimina" noduri -> scade gradul vecinilor nodului


// // Un grup de studenți pasionați de dezbateri a organizat un turneu regional. Regulile turneului sunt clare: echipele trebuie să participe la meciuri în ordine, iar unele echipe trebuie să joace înaintea altora, conform unui program de priorități.
// //
// // Fiecare echipă este numerotată de la  la , iar programul include o listă de  reguli:
// //
// // Dacă echipa  trebuie să joace înaintea echipei , atunci în program este o regulă
// // Dacă nu există o regulă între două echipe, ele pot juca în orice ordine.
// // Pentru ca turneul să se desfășoare fără probleme:
// //
// // Trebuie să determinăm ordinea completă a meciurilor, astfel încât să respectăm toate regulile date.
// // Dacă există mai multe variante posibile de organizare, alegem varianta care este minim lexicografică (cea în care echipele cu numere mai mici apar cât mai devreme posibil).
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> lista[100001], rezultat;
priority_queue<int> coada;
int d[100001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        d[y]++;
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            coada.push(-i);
        }
    }

    while (!coada.empty()) {
        int nodTop = -coada.top();
        coada.pop();

        rezultat.push_back(nodTop);

        for (auto vecin : lista[nodTop]) {
            d[vecin]--;
            if (d[vecin] == 0) {
                coada.push(-vecin);
            }
        }
    }

    for (auto nod : rezultat) {
        cout << nod << " ";
    }

    return 0;
}

// solutia FARA algoritmul lui kahn:

// #include <iostream>
// #include <bits/stdc++.h>
//
// using namespace std;
//
// vector<int> lista[100001];
// int vizitat[100001];
// stack<int> stiva;
//
// void dfs_sortare_topologica(int nod) {
//     vizitat[nod] = 1;
//
//     for (auto vecin : lista[nod]) {
//         if (vizitat[vecin] == 0) {
//             dfs_sortare_topologica(vecin);
//         }
//     }
//
//     stiva.push(nod);
// }
//
// int main() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) {
//         int x, y;
//         cin >> x >> y;
//
//         lista[x].push_back(y);
//     }
//
//     for (int i = n; i >= 1; i--) {
//         if (vizitat[i] == 0) {
//             dfs_sortare_topologica(i);
//         }
//     }
//
//     while (!stiva.empty()) {
//         int nod = stiva.top();
//         stiva.pop();
//         cout << nod << " ";
//     }
//
//     return 0;
// }