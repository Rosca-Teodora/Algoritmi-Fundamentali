// 
// alg lui prim? 
//      -> ia mereu minimul dintre toate muchiile valabile 
//      -> O(N^2) cu o MATRICE DE ADIACENTA
//      -> O(NlogN + MlogN) cu o LISTA de adiacenta + un MIN HEAP!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lista[100001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        lista[x].push_back(y);
        lista[y].push_back(x);
    }

    

    return 0;
}