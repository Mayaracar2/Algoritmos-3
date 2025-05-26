#include <iostream>
#include <cmath>
using namespace std;

struct ponto {
    int x, y;
};

// Função para calcular a distância ao quadrado entre dois pontos
int dist2(ponto a, ponto b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    int n;
    cin >> n;

    ponto vetorA[100]; // até 100 pontos como diz o enunciado
    for (int i = 0; i < n; i++) {
        cin >> vetorA[i].x >> vetorA[i].y;
    }

    ponto u;
    cin >> u.x >> u.y;

    ponto maisProx = vetorA[0];
    int menorDist = dist2(u, vetorA[0]);

    for (int i = 1; i < n; i++) {
        int d = dist2(u, vetorA[i]);

        if (d < menorDist || 
            (d == menorDist && vetorA[i].x < maisProx.x) || 
            (d == menorDist && vetorA[i].x == maisProx.x && vetorA[i].y < maisProx.y)) {
            menorDist = d;
            maisProx = vetorA[i];
        }
    }

    cout << maisProx.x << " " << maisProx.y << endl;

    return 0;
}
