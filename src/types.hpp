#ifndef TYPES_HPP
#define TYPES_HPP
#include <stdlib.h>
#include <string>
#include <SFML/Graphics/Color.hpp>

struct Vehicle{
    int speed;
    int capacity;
    char typemask;

    float t_way; //vai de 0 até 1 sendo 0=origem e 1=destino
    
};

//Estrutura de uma ocorrencia, com sua respectiva descrição, local e prioridade;
typedef struct Occurrence {
    char description[50];
    int place; //que são os NodeTypes? Ou vamos colocar os endereços mesmo?
    int priority;
}Occurrence;

enum priority_type{ //tá certo declarar assim?
    HIGH = 45,
    MEDIUM = 90,
    LOW = 135, 
    NON = 180,
};

enum NodeType{
    UNKNOWN,
    HOSPITAL,
    POLICE,
    FIREBRIGADE,
    HOUSE,
    APARTMENT,
    OFFICE,
    ROUNDABOUT,
    CROSSING
};

const sf::Color typeColors[] = {
    sf::Color(0x000000FF),
    sf::Color(0xFFFFFFFF),
    sf::Color(0x0000FFFF),
    sf::Color(0xFF0000FF),
    sf::Color(0xCCCC00FF),
    sf::Color(0x775555FF),
    sf::Color(0x111111FF),
    sf::Color(0XFF00FFFF)
};

// Estrutura de um nó na lista de adjacência
struct Vertice {
    Vehicle* vehicle;
    float posX;
    float posY;
    std::string name;

    int type;

    Vertice(int type, float posX, float posY, std::string name) : type(type), posX(posX), posY(posY), name(name), vehicle(nullptr){}
};

#endif