#include <iostream>
#include <list>
#include <climits> // Biblioteca para INT_MAX

using namespace std;

struct no {
    int vadjacente; // Vértice adjacente
    int peso; // Peso da aresta  
};

// Função para criar uma aresta entre dois vértices
void cria_aresta(list<no> adj[], int vorigem, int vadjacente, int peso, int orientado) {    
    no aux;
    aux.vadjacente = vadjacente;
    aux.peso = peso;
    adj[vorigem].push_back(aux);
    
    if (orientado == 0) {
        aux.vadjacente = vorigem;
        adj[vadjacente].push_back(aux);
    }
}

// Função para implementar o algoritmo de Prim
void prim(list<no> adj[], int nVertices, int start) { 
    int distancia[nVertices];
    int pai[nVertices];
    int vorigem, vadjacente, i;
    int destino, weight;
    int custo = 0;
    bool inTree[nVertices];
    list<no>::iterator p;

    // Inicialização dos vetores
    for (vorigem = 0; vorigem < nVertices; vorigem++) {
        inTree[vorigem] = false;
        distancia[vorigem] = INT_MAX;
        pai[vorigem] = -1;
    }

    distancia[start] = 0;
    vadjacente = start;

    while (inTree[vadjacente] == false) {
        inTree[vadjacente] = true;

        for (p = adj[vadjacente].begin(); p != adj[vadjacente].end(); p++) {
            destino = p->vadjacente;
            weight = p->peso;

            if (distancia[destino] > weight && inTree[destino] == false) {
                distancia[destino] = weight;
                pai[destino] = vadjacente;
            }
        }

        // Encontra o próximo vértice com a menor distância
        int dist = INT_MAX;
        for (vorigem = 0; vorigem < nVertices; vorigem++) {
            if (inTree[vorigem] == false && distancia[vorigem] < dist) {
                dist = distancia[vorigem];
                vadjacente = vorigem;
            }
        }
    }

    cout << "Árvore Geradora Mínima:" << endl;
    for (i = 0; i < nVertices; i++) {
        custo += distancia[i];
        if (i != start) {
            cout << pai[i] << " " << i << endl;
        }
    }
    cout << "Custo:" <<" " << custo << endl;

}

int main() {
    int vorigem, vadjacente, peso, nVertices, orientado, s;
    int i;
    list<no> adj[10];
    list<no>::iterator q;

    cin >> nVertices >> orientado >> s;

    cin >> vorigem >> vadjacente >> peso;
    while (vorigem != -1 || vadjacente != -1 || peso != -1) {
        cria_aresta(adj, vorigem, vadjacente, peso, orientado);
        cin >> vorigem >> vadjacente >> peso;
    }

    prim(adj, nVertices, s);

    i = 0;
    while (!adj[i].empty() && i < nVertices) { // Garantir que não ultrapasse os limites
        adj[i].pop_front();
        i++;
    }

    return 0;
}
