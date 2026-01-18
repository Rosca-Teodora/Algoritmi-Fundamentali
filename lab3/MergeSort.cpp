
// merge sort facut special cu ideea de a fi folosit in algoritmul Kruskal

#include <iostream>

using namespace std;
typedef tuple<int, int, int> Edge;

void merge(Edge arr[], int st, int mij, int dr) {
    int n1 = mij - st + 1;
    int n2 = dr - mij;

    // array-uri temporare
    Edge* L = new Edge[n1];
    Edge* R = new Edge[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[st + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mij + 1 + j];

    int i = 0, j = 0, k = st;

    // merge bazat pe COST (get<2>)
    while (i < n1 && j < n2) {
        if (get<2>(L[i]) <= get<2>(R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiaza celelalte elemente
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Edge arr[], int st, int dr) {
    if (st < dr) {
        int mij = st + (dr - st) / 2;

        mergeSort(arr, st, mij);      // sortare prima jumatate
        mergeSort(arr, mij + 1, dr);  // sortare a doua jumatate
        merge(arr, st, mij, dr);      // merge intre cele doua 
    }
}

int main()
{
    return 0;
}