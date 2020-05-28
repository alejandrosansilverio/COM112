#ifndef COM_112SORT_H
#define COM_112SORT_H

void bubble_sort(int vetor[], int n);//método de ordenação bubble sort
void selection_Sort(int vet[],int n);//método de ordenação selection sort
void insertion_sort(int vetor[], int n);//método de ordenação insertion sort
void merge(int *v, int inicio, int meio, int fim,int *comp,int (*mov));//Metodo merge do merge sort
void mergeSort(int *V,int inicio,int fim,int *comp,int *mov);//Metodo merde sort
int particiona(int *v,int inicio,int final,int *comp,int *mov);//particiona o vetor
void quickSort(int *v,int inicio,int fim,int *comp,int *mov);//método de ordenação quick sort


#endif
