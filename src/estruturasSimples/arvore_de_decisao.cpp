typedef char bool;
typedef struct Decisao decisao;
typedef struct Vertice vertice;

struct Decisao {
    char *name; 
    decisao *caseyes;
    decisao *casenot;
    vertice *vertices; // poderá, inclusive, guardar um array de animais (se a operação de inserção for construída de tal modo)
};

struct vertice {
    char *name; // nome do animal
    bool *fields;
};