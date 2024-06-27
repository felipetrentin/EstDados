#include "graph.hpp"

#define MAXVERTICES 100


Graph::Graph(int numVertices) : numVertices(numVertices){
    adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0)); // Inicializa matriz de adjacência com zeros.
    nodeInfo.resize(numVertices, Vertice(UNKNOWN, 0, 0, "unknown"));   // Inicializa array de informações dos vertices com vertices nulos
}

void Graph::setVertice(int vertice, int posX, int posY, std::string name, int type){
    nodeInfo[vertice] = (Vertice(type, posX, posY, name));
}

// Adiciona uma aresta
void Graph::setEdges(int src, int dest, int weight){
    adjMatrix[src][dest] = weight;
}

// Define informações adicionais para um nó
void Graph::setVeichle(int vertice, Vehicle *dados){
    nodeInfo[vertice].vehicle = dados;
}

// Obtém informações adicionais de um nó
Vehicle *Graph::getVeichle(int vertice){
    return nodeInfo[vertice].vehicle;
}

Vertice *Graph::getVertice(int vertice){
    return &nodeInfo[vertice];
}

int Graph::getWeight(int src, int dest){
    return adjMatrix[src][dest];
}

int Graph::minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < numVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
std::vector<LinkedList> Graph::dijkstra(int src)
{
    std::vector<LinkedList> minPath;
    minPath.resize(numVertices, LinkedList());

    int* dist = malloc(sizeof(int)*numVertices); 
                // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool* sptSet = malloc(sizeof(bool)*numVertices); // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < numVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // u guarda o indice do ultimo vetor de menor tamanho

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < numVertices; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && //não visitamos
                getWeight(u, v) && //tem peso != 0
                dist[u] != INT_MAX && //não é infinito
                dist[u] + getWeight(u, v) < dist[v] &&
                getVeichle(v) == nullptr
                ){ //tem peso menor doq o ja visitado
                    //se ele bate todos esses requisitos, acabamos de achar um caminho mais curto!
                    //salvamos na lista de distâncias como a melhor solução atual
                    dist[v] = dist[u] + getWeight(u, v);
                    //copyLinked(from, to)
                    //copiamos a lista que usamos para chegar em U e adicionamos o proximo passo, V
                    minPath[v].copyLinked(minPath[u]);
                    minPath[v].add(v);
                }
    }
    return minPath;
}