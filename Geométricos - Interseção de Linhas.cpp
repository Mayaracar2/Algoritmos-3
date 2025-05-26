#include <iostream>
using namespace std;

struct Ponto {
    int x, y;
};

int orientacao(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool cruzam(Ponto a, Ponto b, Ponto c, Ponto d) {
    int o1 = orientacao(a, b, c);
    int o2 = orientacao(a, b, d);
    int o3 = orientacao(c, d, a);
    int o4 = orientacao(c, d, b);

    // Apenas o caso geral importa (segmentos se cruzam em um ponto interior de ambos)
    return (o1 * o2 < 0) && (o3 * o4 < 0);
}

int main() {
    Ponto a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    if (cruzam(a, b, c, d)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
