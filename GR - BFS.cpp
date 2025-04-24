#include<iostream> 
#include<list>

using namespace std; 

// Estrutura que representa um nó da lista de adjacência
struct no {
    int v; // Vértice adjacente
    int peso; // Peso da aresta
};

// Função que cria uma aresta no grafo
void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    no aux = {v, p}; // Cria um nó representando a aresta (u -> v) com peso p
    
    adj[u].push_back(aux); // Adiciona essa aresta na lista de adjacência do vértice u
    
    // Se o grafo for não orientado, adicionamos a aresta no sentido contrário (v -> u)
    if (orientado == 0) {
        aux.v = u; // Inverte o vértice de destino
        adj[v].push_back(aux); // Adiciona a aresta na lista de adjacência de v
    }
}
void bfs(list<no> adj[], int nVertices, int s) {
    int u, v;                             //u = vértice corrente, v = vértice adjacente
    int state[nVertices];                // Vetor para armazenar o estado de cada vértice ('u': não visitado, 'd': descoberto, 'p': processado)
    int pai[nVertices];                  // Vetor para armazenar o pai de cada vértice no caminho da busca em largura
    list<int> Q;                         // Lista para armazenar os vértices a serem visitados em largura
    list<no>::iterator p;                // Iterador para percorrer as arestas adjacentes de um vértice

    // Loop para percorrer todas os vertices
    for (u = 0; u < nVertices; u++) {
        if (u != s) {
            state[u] = 'u';              // Define todos os vértices, exceto o vértice de partida, como não visitados
            pai[u] = -1;                 // Define o pai de todos os vértices, exceto o vértice de partida, como -1
        }
    }

    state[s] = 'd';                      // Marca o vértice de partida como descoberto
    pai[s] = -1;                         // Define o pai do vértice de partida como -1
    Q.push_back(s);                      // Adiciona o vértice de partida à lista de vértices a serem visitados

    while (!Q.empty()) {
        u = *Q.begin();                  // Obtém o primeiro vértice da lista
        Q.pop_front();                   // Remove o vértice visitado da lista
        cout << u << endl;               // Imprime o vértice visitado

        for (p = adj[u].begin(); p != adj[u].end(); p++) {
            v = p->v;                                        // Obtém o vértice adjacente

            cout << u << " " << v << endl;                   // Imprime a aresta sendo percorrida

            if (state[v] == 'u') {                           // Verifica se o vértice adjacente não foi visitado
                state[v] = 'd';                              // Marca o vértice adjacente como descoberto
                pai[v] = u;                                  // Define o pai do vértice adjacente como o vértice atual
                Q.push_back(v);                              // Adiciona o vértice adjacente à lista de vértices a serem visitados
            }
        }

        state[u] = 'p';                                      // Marca o vértice atual como processado
    }
}

int main() {
    int nVertices; // Número de vértices e flag para indicar se o grafo é orientado (1) ou não (0)
    int u, p, v; // Variáveis para armazenar entrada de arestas (vértices u, v e peso p)
    int orientado = 0; // Flag para indicar se o grafo é orientado (1) ou não (0)
    list<no>::iterator q; // Iterador para percorrer a lista de adjacência
    int s;
    

    cin >> nVertices >> s; // Lê o número de vértices e se o grafo é orientado
    
    list<no> adj[nVertices]; // Cria um vetor de listas de adjacência para armazenar o grafo
    
    // Trecho de código comentado que originalmente lia um número fixo de arestas
    // for(int i = 0; i < vertices; i++) {
    //     cin >> u >> v >> p;
    //     cria_aresta(adj, u, v, p, orientado);
    // }

    // Lê as arestas do grafo até que seja inserido "-1 -1 -1"
    cin >> u >> v >> p;
    while (u != -1 || v != -1 || p != -1) {
        cria_aresta(adj, u, v, p, 0); // Adiciona a aresta ao grafo
        cin >> u >> v >> p; // Lê a próxima aresta
        
    }

    bfs(adj, nVertices, s); // Chama a função de busca em largura;

    

    return 0; // Encerra o programa
}
