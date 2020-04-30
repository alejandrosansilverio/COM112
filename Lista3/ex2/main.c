#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
  float salario;
  char *nome;
}funcionario;

void funcPreencheVet(funcionario f[], int tam)
{
  int i;
  for(i=0;i<tam;i++)
  {
  f[i].nome = (char*)malloc(sizeof(char));
  printf("\n -----------------------Informações sobre o %dº funcionario-----------------------", i+1);
  printf("\n Digite o nome do trabalhador:");
  scanf(" %[^\n]", f[i].nome);
  fflush(stdin);
  printf("\n Digite o salario do trbalhador:");
  scanf(" %f", &f[i].salario);
  }
  return;
}

void funcImprimeVet(funcionario f[], int tam)
{
  int i;
  for(i=0;i<tam;i++)
  {
    printf("\n -----------------------Trabalhador %d----------------------- \n", i+1);
    printf("\n Nome: %s \n", f[i].nome);
    printf("\n Salário: %f \n", f[i].salario);

  }
  return;
}

void funcBSB(funcionario v[], int tam)
{
  int i, j;
  int troca=0;
  funcionario aux;
  for(i=0;i<tam;i++)
  {
    j=0;
    troca=0;
    while(j<(tam-i))
    {
      if(v[j].salario<v[j+1].salario)
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

void funcOrdemAlfa(funcionario f[], int tam)
{
  int i, j;
  int troca=0;
  funcionario aux;
  for(i=0;i<tam;i++)
  {
    j=0;
    troca=0;
    while(j<(tam-i))
    {
      if(strcmp(f[j].nome, f[j+1].nome)>0)
      {
        aux=f[j];
        f[j]=f[j+1];
        f[j+1]=aux;
        troca=1;
      }
      j++;
    }
    if(troca==0) return;
  }
  return;
}

int main(void) {
funcionario *f;
int i, tam=3;

f = (funcionario *) malloc(tam*sizeof(funcionario));
funcPreencheVet(f, tam);
funcImprimeVet(f, tam);
funcBSB(f, tam);
printf("\n********************Ordem decrescente de salário******************** \n");
funcImprimeVet(f, tam);
funcOrdemAlfa(f, tam);
printf("\n********************Ordem Alfabética******************** \n");
funcImprimeVet(f, tam);
free(f);
return 0;
}
