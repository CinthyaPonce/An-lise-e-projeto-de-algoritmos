#include <stdio.h>
#include <stdlib.h>
	
	void mergeSort(int *vetor, int inicio, int meio, int fim){
		int *temp, a1, a2, tamanho, i, j, k;
		int fim_1=0, fim_2=0;
		tamanho=fim-inicio+1;
		
		a1=inicio;
		a2=meio+1;
		temp=(int*)malloc(tamanho*sizeof(int));
		if(temp !=NULL){
			for(i=0; i<tamanho; i++){
				if(!fim_1 && fim_2){
					if(vetor[a1]<vetor[a2]){
						temp[i]=vetor[a1++];
					
					}else{
					temp[i]=vetor[a2++];
					}
					
					if(a1>meio)
						fim_1=1;
					if(a2>fim)
						fim_2=1;
				}else{
					if(!fim_1)
						temp[i]=vetor[a1++];
					else
						temp[i]=vetor[a2++];
				}
		}
		}
		for( j=0, k=inicio; j<tamanho; j++, k++){
			vetor[k]=temp[j];
		}
		free(temp);
		printf("%d%d%d", inicio, meio, fim);
	}
	int main(){	
	int vetor[5]={-1,6,4,9,2};
	mergeSort(vetor, -1, 1, 1);
	return 0;
	}
