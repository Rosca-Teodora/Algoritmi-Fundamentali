// A fost odata un camionas care se afla intr-un basm. In lumea basmului existau N sate, numerotate de la 1 la N si M drumuri bidirectionale de legatura intre ele. Cum nici macar in basme drumurile nu sunt construite cum trebuie, fiecare din cele M drumuri au o rezistenta gi. Basmul nostru este insa un basm modern, iar PIZZA este unul dintre elementele de baza ale acestuia. Camionasul nostru are o greutate G si se afla initial, in satul 1. Acesta are misiunea de a transporta PIZZA din satul 1, catre satul N. Fiind foarte de treaba, camionasul se gandeste ca nu ar fi indicat sa mearga pe drumuri care au rezistenta mai mica strict decat greutatea sa, pentru ca aceste drumuri s-ar strica. Totusi, cum livrarea de PIZZA este menirea sa pe lume, acesta se intreaba care este numarul minim de drumuri a caror rezistenta trebuie marita, astfel incat el sa poata transporta PIZZA din satul 1 in satul N, fara sa fie nevoit sa mearga pe drumuri cu rezistenta strict mai mica decat greutatea sa.

// Cum camionasul nostru nu este tocmai un expert in teoria grafurilor, s-a gandit ca tocmai voi il puteti ajuta, furnizandu-i raspunsul la aceasta intrebare.
// Date de intrare

// Fişierul de intrare camionas.in contine pe prima linie trei numere naturale, N M G, avand semnificatia din enunt. Pe urmatoarele M linii se vor gasi perechi de cate trei numere naturale, x y g, semnificand existenta unui drum intre satele x si y, de rezistenta g.

// OBS: problema asta este una de COST MINIM!!
// insa NU SE REZOLVA CU DIJKSTRA fiindca costul este doar intre 0 (nu modific rezistenta) si 1 (modific rezistenta)!!!
// asadar poate fi mult mai simpla de rezolvat!!!


// cum fuctioneaza tuple-ul btw: 
// get<0>(rezistenta);
// n-am nevoie de el doar cand incercam sa rezolv problema incercasem cu un d-asta si gen n-am nevoie so... cool

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, int>> lista[50001]; // pastrez si rezistenta muchiei in pair, pe locul second

// DOUBLE ENDED QUEUE -> cand verifica cum tb relatia 
deque<int> coada;


int distanta[50001]; // greutatea pana la n
int nr_schimbari; // cate muchii tb schimbate

int INF = 2147483647; // pusesem 1e23 initial dar... "warning: overflow in conversion from ‘double’ to ‘int’ changes value from ‘9.9999999999999992e+22’ to ‘2147483647’ [-Woverflow]""

// input
int n, m, g;

void bfs()
{
    for (int i = 1; i <= n; i++)
        distanta[i] = INF;
    
    distanta[1] = 0;
    coada.push_front(1);

    while (!coada.empty())
    {
        int nodTop = coada.front();
        coada.pop_front();

        for (auto vecin : lista[nodTop])
        {
            int cost = (vecin.second <= g) ? 0 : 1; // cand se indeplineste (camionasul poate livra pizza pe acolo yay) costul e 0, altfel 1 

            // relaxarea muchiei similar cu Dijkstra!
            if (distanta[vecin.first] > distanta[nodTop] + cost) 
            {
                distanta[vecin.first] = distanta[nodTop] + cost; // va fi generat in distanta[n] costul MINIM (nr minim de modificari) necesare!

                if (!cost)
                {
                    coada.push_front(vecin.first);
                }
                else 
                {
                    coada.push_back(vecin.first);
                }
            }
        }
    }
    
}

int main()
{
    cin >> n >> m >> g;

    
    for (int i = 1; i <= m; i++)
    {
        int x, y, gC;
        cin >> x >> y >> gC;

        lista[x].push_back({y, gC});
        lista[y].push_back({x, gC});
        
    }

    bfs();

    cout << distanta[n];

    return 0;
}