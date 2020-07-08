#include <stdio.h>
#include <stdlib.h>
#include "com112_hash.h"

void preencheAluno(struct aluno *al){//
  printf("Digite a matrícula do aluno: ");
  scanf("%d",&al->matricula);

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", al->nome);

  printf("Digite as notas N1 e N2 do aluno: ");
  scanf("%f %f", &al->n1, &al->n2);
}

int menu(){
  int opcao;
  printf("\n-------------------MENU------------------\n");
  printf("|    1. Criar tabela hash               |\n");
  printf("|    2. Liberar tabela hash             |\n");
  printf("|    3. Inserir elemento (sem colisão)  |\n");
  printf("|    4. Consultar elemento (sem colisão)|\n");
  printf("|    5. Sair                            |\n");
  printf("-----------------------------------------\n");
  printf("Opcao:");
  scanf("%d", &opcao);
  return opcao;
}

int main(){
  Hash* ha=NULL;
  int opcao,x, tam,mat;
  struct aluno al;

  do
  {
    opcao = menu();
    switch(opcao)
    {
      case 1:
        printf("Digite o tamanho da tabela:\n");
        scanf("%d", &tam);
        ha = criaHash(tam);
      break;

      case 2:
        liberaHash(ha);
      break;

      case 3:
        preencheAluno(&al);

         x = insereHash_SemColisao(ha, al);
         if(x == 1)
          printf("\nValor inserido com sucesso!");
         else
          printf("\nErro ao inserir o valor");
      break;

      case 4:
        printf("Digite a matrícula do aluno que deseja encontrar: ");
        scanf("%d",&mat);

         x = buscaHash_SemColisao(ha,mat, &al);
         if(x == 1)
          printf("\nMatricula:%d\nNome:%s\nN1:%.2f\nN2:%.2f\n",al.matricula,al.nome,al.n1,al.n2);
         else
          printf("\nA matricula nao foi encontrada");
      break;

      case 5:
      liberaHash(ha);
        printf("\nSaindo...\n");
      break;

      default:
        printf("Digite outro numero");
      break;
    }
  }while(opcao != 5);
}
