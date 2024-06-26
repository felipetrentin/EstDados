#include <stdlib.h>
#include <vector>
#include <string>

#include "graph.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVERTICES 100

void dijkstra(int vertices,int origin,int dest,int *costs, bool vazio)
{ int i,v,    /* variáveis auxiliares */
      ant[MAXVERTICES],   /* vetor dos antecessores */
      z[MAXVERTICES];     /* vértices para os quais se conhece o caminho mínimo */
  double min, /* variável auxiliar */
       dist[MAXVERTICES]; /* vetor com os custos dos caminhos */

/* OBS: O usuário enxerga os vértices como rotulados de 1 a "vértices",  */
/* mas o programa armazena as informações usando os elementos 0 dos */
/* dos vetores. Dessa formar é preciso subtrair 1 de "origem" e "destino" */
/* ao mapeá-los nos vetores. */

  /* Inicialização */

  for (i=0;i<vertices;i++) {
    if (custos[(origem-1)*vertices+i]!=-1) {
      ant[i]=origem-1; 
      dist[i]=custos[(origem-1)*vertices+i];
    }
    else {
      ant[i]=-1;
      dist[i]=HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1]=1;
  dist[origem-1]=0;

  /* Laço principal */

  do {

    /* Encontrando o vértice que deve entrar em z */

    min=HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {min=dist[i];v=i;}

    /* Calculando as distâncias dos novos vizinhos de z */

    if (min!=HUGE_VAL && v!=destino-1) {
      z[v]=1;
      for (i=0;i<vertices;i++)
        if (!z[i]) {
          if (custos[v*vertices+i]!=-1 && dist[v]+custos[v*vertices+i]<dist[i])
            { dist[i]=dist[v]+custos[v*vertices+i];ant[i]=v; }
        }
    }
  } while (v!=destino-1 && min!=HUGE_VAL);

  /* Imprimindo o resultado  */

  if (min==HUGE_VAL)
    printf("\nNo digrafo dado não existe caminho entre os vértices %d e %d !!\n",origem,destino);
  else {
    printf("\nO caminho de custo mínimo entre os vértices %d e %d  é (na ordem reversa):\n",
           origem,destino);
    i=destino;
    printf("%d",i);
    i=ant[i-1];
    while (i!=-1) {
      printf("<-%d",i+1);
      i=ant[i];
    }
    printf("\nO custo deste caminho é: %d\n",(int) dist[destino-1]);
  }
  
} /* dijsktra */