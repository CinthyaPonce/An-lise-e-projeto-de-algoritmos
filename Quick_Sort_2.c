#include<stdio.h>
#include <stdlib.h>


void mergeSort(int *vetorDesordenado, int posicaoInicio, int posicaoFim){
   int i,j,k,metadeTamanho,*vetorTemp;
   if (posicaoInicio == posicaoFim) return;
   
   
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   mergeSort( vetorDesordenado, posicaoInicio, metadeTamanho);
   mergeSort( vetorDesordenado, metadeTamanho+1,posicaoFim );


   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));
   
   while(i < metadeTamanho+1 || j  < posicaoFim+1){ 
   
      if (i == metadeTamanho+1){
         vetorTemp[k] = vetorDesordenado[j];
         j++;
         k++;
      } 
      else{
         if (j==posicaoFim+1){ 
            vetorTemp[k] = vetorDesordenado[i];
            i++;
            k++;
         } 
         else{
            if (vetorDesordenado[i] < vetorDesordenado[j]){ 
               vetorTemp[k] = vetorDesordenado[i];
               i++;
               k++;
            } 
            else{ 
              vetorTemp[k] = vetorDesordenado[j];
              j++;
              k++;
            }
         }
      }
      
   }

   for(i = posicaoInicio; i <= posicaoFim; i++){
      vetorDesordenado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
}

int main(){
	
	int vetorDesordenado[5]={-1,6,4,9,2};
	mergeSort(vetorDesordenado, -1, 2);
	
	return 0;
}
