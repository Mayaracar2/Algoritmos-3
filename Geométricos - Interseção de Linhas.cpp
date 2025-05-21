#include <iostream>
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - y1 * x2;
}

bool entre(int a, int b, int c) {
    return min(a, b) <= c && c <= max(a, b);
}

bool segmentosSeCruzam(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int d1 = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    int d2 = cross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
    int d3 = cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
    int d4 = cross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);

    // Caso geral: sinais opostos → cruzam
    if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0)) {
        return true;
    }

    // Casos de toque ou sobreposição (colinear)
    if (d1 == 0 && entre(x1, x2, x3) && entre(y1, y2, y3)) return true;
    if (d2 == 0 && entre(x1, x2, x4) && entre(y1, y2, y4)) return true;
    if (d3 == 0 && entre(x3, x4, x1) && entre(y3, y4, y1)) return true;
    if (d4 == 0 && entre(x3, x4, x2) && entre(y3, y4, y2)) return true;

    return false;
}

int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if (segmentosSeCruzam(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
