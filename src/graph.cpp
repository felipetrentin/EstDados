#include <stdlib.h>
#include <vector>
#include <string>

#include "graph.hpp"

Graph::Graph(){
    
}

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
void Graph::setVeichle(int vertice, Veichle *dados){
    nodeInfo[vertice].veichle = dados;
}

// Obtém informações adicionais de um nó
Veichle *Graph::getVeichle(int vertice){
    return nodeInfo[vertice].veichle;
}

Vertice *Graph::getVertice(int vertice){
    return &nodeInfo[vertice];
}

int Graph::getWeight(int src, int dest){
    return adjMatrix[src][dest];
}