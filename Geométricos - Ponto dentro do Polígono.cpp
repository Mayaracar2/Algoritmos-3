#include <iostream>

using namespace std;

int main() 
{
    int N;
    
    cin >> N;

    int x[100], y[100];
    
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    int px, py;
    
    cin >> px >> py;

    bool dentro = false;

    // Percorre as arestas do polígono (pares de pontos consecutivos)
    for (int i = 0; i < N; i++) {
        int j = (i + N - 1) % N; // pega o vértice anterior (com rotação)
        
        bool cond1 = (y[i] > py) != (y[j] > py); // verifica se py está entre y[i] e y[j]

        if (cond1) {
            double xinters = x[i] + (double)(py - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
            if (px < xinters) {
                dentro = !dentro;
            }
        }
    }

    if (dentro) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}
