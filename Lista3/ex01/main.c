#include <stdio.h>
#include <stdlib.h>

void funcPreencheVetor(int v[], int t)
{
  int i;
  for(i=0;i<t;i++)
  {
    printf("\n Digite um valor inteiro para o %dº valor da lista: ", i+1);
    scanf("%d", &v[i]);
  }
  return;
}

void funcBSB(int v[], int tam)
{
  int i, j, aux;
  int troca=0;
  for(i=0;i<tam;i++)
  {
    j=0;
    troca=0;
    while(j<(tam-i))
    {
      if(v[j]<v[j+1])
      {
        aux=v[j];
        v[j]=v[j+1];
        v[j+1]=aux;
        troca=1;
      }
      j++;
    }
    if(troca==0) return;
  }
  return;
}

void funcImprimeVet(int v[], int tam)
{
  int i;
  for(i=0;i<tam;i++)
  {
    printf(" %d ", v[i]);
  }
  return;
}

int main(void) {
  int *vet, tam=9;
  vet = (int *) malloc(tam * sizeof(int));
  funcPreencheVetor(vet, tam);
  funcBSB(vet, tam);
  funcImprimeVet(vet, tam);
  free(vet);
  return 0;
}
