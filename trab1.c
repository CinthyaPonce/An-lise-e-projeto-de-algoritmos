// Aluna Cinthya Ponce Leon - 11328633

#include <stdio.h>

void funcao_selection_sort (int vetor[],int tamanho_do_vetor) { //funcao selection_sort
  int i, j, minimo, aux;
  
  for (i = 0; i < (tamanho_do_vetor - 1); i++) { 
    minimo = i;
    for (j = i+1; j < tamanho_do_vetor; j++) {
      if (vetor[j] < vetor[minimo]) { //se ainda tiver um numero menor, ele faz a troca do minimo
	minimo = j;
      }
    }
	
	if (i != minimo) { //faz a troca para ordenar 
      aux = vetor[i];
      vetor[i] = vetor[minimo];
      vetor[minimo] = aux;
    }
  }
  
  for (i = 0; i < tamanho_do_vetor; i++) {
    printf ("%d ",vetor[i]); //imprime o velor ja organizado
  }
  printf ("\n");
}

main () {
  int tamanho_do_vetor, i;
  printf("Digite o tamanho do seu vetor\n"); //Define o tamanho do vetor
  scanf ("%d", &tamanho_do_vetor);
  
  int  vetor[tamanho_do_vetor];
  for (i = 0; i < tamanho_do_vetor; i++) { 
  	printf("Digite o numeros desejados");
    scanf ("%d", &vetor[i]);
  }
  
  funcao_selection_sort (vetor, tamanho_do_vetor); 
  return 0;
}
