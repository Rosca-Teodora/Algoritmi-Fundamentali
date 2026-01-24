#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("procente.in");

vector<pair<int, double>> lista[10001];
priority_queue<pair<double, int>> pq;
int NEGATIVE_INF = -1e9;
double d[10001];
int tata[10001];


int main()
{
    int n, m, start, end;
    fin >> n >> m >> start >> end;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        double c;
        fin >> x >> y >> c;

        lista[x].push_back({y, c});
        lista[y].push_back({x, c});
    }

    for (int i = 0; i <= n; i++)
    {
        d[i] = 0.0;
        tata[i] = 0;
    }

    d[start] = 1;
    pq.push({1, start});

    while (!pq.empty())
    {
        int nodTop = pq.top().second;
        double procent = pq.top().first;
        pq.pop();

        if (procent < d[nodTop]) // daca deja am gasit un procent mai mare decat cel la care sunt acum
            continue;
        
        for (auto vecin : lista[nodTop])
        {
            int nodVecin = vecin.first;
            double procentVecin = vecin.second;

            // relaxarea muchiei
            if (d[nodVecin] < d[nodTop] * procentVecin)
            {
                d[nodVecin] = d[nodTop] * procentVecin;
                tata[nodVecin] = nodTop;
                pq.push({d[nodVecin], nodVecin});
            }
        }
    }

    cout << d[end];
    
    return 0;
}