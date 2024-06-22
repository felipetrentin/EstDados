#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <string>

#include "types.hpp"

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix; // matriz de adjacência entre cada um dos nós
    std::vector<Vertice> nodeInfo; // Array de ponteiros genéricos para armazenar informações adicionais de cada nó

public:
    Graph();
    Graph(int numVertices);
    void setVertice(int vertice, int posX, int posY, std::string name, int type);
    void setEdges(int src, int dest, int weight);
    void setVeichle(int vertice, Vehicle* dados);
    
    Vehicle* getVeichle(int vertice);
    Vertice* getVertice(int vertice);
    int getWeight(int src, int dest);
};

#endif