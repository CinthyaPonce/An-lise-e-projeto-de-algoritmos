#include <stdio.h>

void funcao_insertionSort(int array[], int tamanho) {
    int i, j, tmp;
    for (i = 1; i < tamanho; i++) {
		j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                j--;
            }
      }
}

int main(){

	int tamanho, i;
	printf("Digite o tamanho do seu vetor\n");
	scanf("%d", &tamanho);
   	printf("Digite os elementos do vetor\n");
   	int  vetor[tamanho];
   
   	for (i = 0; i < tamanho; i++) { 	
 		scanf ("%d", &vetor[i]);
  	}
    funcao_insertionSort(vetor,tamanho);
    printf("\nEm ordem: ");
    for(i=0; i<tamanho; i++){
    	printf("%d", vetor[i]);
   }
      
   return 0;
}
