#include <iostream>
#include <limits>
using namespace std;

int main ()
{
    int N;
    cin >> N;

    int x[100], y[100];

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int ux, uy;
    cin >> ux >> uy;

    int melhorX, melhorY;
    int menorDist = numeric_limits<int>::max();

    for (int i = 0; i < N; i++) {
        int dx = x[i] - ux;
        int dy = y[i] - uy;
        int dist = dx * dx + dy * dy;

        if (dist < menorDist ||
            (dist == menorDist && x[i] < melhorX) ||
            (dist == menorDist && x[i] == melhorX && y[i] < melhorY)) {
            menorDist = dist;
            melhorX = x[i];
            melhorY = y[i];
        }
    }

    cout << melhorX << " " << melhorY << endl;

    return 0;
}
