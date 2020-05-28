#include <stdio.h>
#include <time.h>
#include <math.h>
#include "com_112sort.h"
#include "com_112file.h"

void bubble_sort(int vetor[], int n, int *comp, int *mov)
{
    int k, j, aux;
  *comp = 0;
  *mov = 0;
    for (k = n - 1; k > 0; k--)//percorre o vetor de traz pra frente
    {
      (*comp)++;
        for (j = 0; j < k; j++)//percorre o elemento A[j] até A[k] 
        {
            *comp = *comp + 2;//toda vez que houver comparação, a variável será incrementada
            if (vetor[j] > vetor[j + 1])//Caso o proximo numero seja menor que o atual, ambos devem trocar
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                *mov = *mov + 2;//toda vez que houver movimentações, a variável será incrementada
            }
        }
    }
    printf("Bubble Sort realizado com sucesso");
    return;
}

void selection_Sort(int vet[],int n, int *comp, int *mov) 
{ 
    int minIndex;
    int aux;
    *comp = 0;
    *mov = 0;
    for (int i = 0; i < n-1; i++) 
    { 
        minIndex = i; 
        for (int j = i+1; j < n; j++)
        {
          (*comp)++;
          if (vet[j] < vet[minIndex])
            minIndex = j;
        }
        // Troca
        aux = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = aux;
        *mov = *mov + 2;        
    }
    printf("Selection Sort realizado com sucesso");
    return;
}

void insertion_sort(int vetor[], int n, int *comp, int *mov)
{
    int k, j, aux;
    *comp = 0;
    *mov = 0;
    for (k = 1; k <= n - 1; k++)//percorre o vetor
    {
        aux = vetor[k];
        j = k - 1;
        (*comp)++;//numero de comparações
        while (j >= 0 && aux < vetor[j])//compara o próximo vetor com o vetor na posição j
        {
            (*comp)++;
            vetor[j + 1] = vetor[j];
            j--;
            (*mov)++;//numero de movimentações
        }
        vetor[j + 1] = aux;
        (*mov)++;//numero de movimentações
    }
    printf("Insertion Sort realizado com sucesso");
    return;
}

void merge(int *v, int inicio, int meio, int fim,int *comp,int (*mov))
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1=inicio;
    p2=meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    (*comp)++;
    if(temp != NULL)
    {
        for(i=0;i<tamanho;i++)
        {
          (*comp)++;
            if(!fim1 && !fim2)
            {
              (*comp)++;
                if(v[p1] < v[p2])
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];
                if(p1>meio)
                  fim1=1;
                if(p2>fim)
                  fim2=1;
                (*comp) += 2;
            }else
            {
              (*comp)++;
                if(!fim1)
                    temp[i]=v[p1++];
                else
                    temp[i]=v[p2++];
                    
            }    
        }
        for(j=0, k=inicio;j<tamanho;j++, k++){
            v[k] = temp[j];
            (*mov)++;
        }
    }
    free(temp);
    return;
}

void mergeSort(int *V,int inicio,int fim,int *comp,int *mov)
{
  int meio;
  (*comp)++;
  if(inicio<fim){
    meio = floor((inicio+fim)/2);
    mergeSort(V,inicio,meio,comp,mov);
    mergeSort(V,meio+1,fim,comp,mov);
    merge(V,inicio,meio,fim,comp,mov);
  }
  return;
}

int particiona(int *v,int inicio,int final,int *comp,int *mov){
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = final;
  pivo = v[inicio];
  while(esq < dir){
   
    while(v[esq] <= pivo){
      esq++;
      (*comp)++;
    }
    while(v[dir] > pivo){
      dir--;
      (*comp)++;
    }
    (*comp)++;
    if(esq < dir){
      aux = v[esq];
      v[esq] = v[dir];
      v[dir] = aux;
      *mov = *mov + 2;
    }
     (*comp)++;
  }
  v[inicio] = v[dir];
  v[dir] = pivo;
  *mov = *mov + 2;

  return dir;
}

void quickSort(int *v,int inicio,int fim,int *comp,int *mov){
  int pivo;
  (*comp)++;
  if(fim > inicio){
    pivo = particiona(v, inicio, fim,comp,mov);
    quickSort(v,inicio,pivo-1,comp,mov);
    quickSort(v,pivo+1,fim,comp,mov);
  }
}
