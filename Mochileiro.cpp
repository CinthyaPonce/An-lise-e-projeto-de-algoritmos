#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int num, capacidade, result=0;
	cout << "Insira o numero de itens:\n";
    cin >> num;
    multimap < float, float, greater <int> > m;    // greater <int> � usado no multimap pra armazenar valores em ordem decrescente
    cout << "\nInsira o peso e valor, separados por espaco:\n";
    float peso, valor;
    for(int i=0; i < num; ++i){
		cin >> peso >> valor;
        m.insert(pair <int,int> (valor/peso, peso));     // valores armazenados como valores m�dios
         }
    cout <<"\nInsira a capacidade da mochila:\n";
    cin >> capacidade;
    multimap <float, float> :: iterator itr;
    for(itr = m.begin(); itr != m.end(); ++itr){
    	int temp = itr -> second;
    	if(temp < capacidade){
        	result += temp* (itr -> first);
            capacidade -= temp;
            }
		else {
	   		result += capacidade*(itr -> first);
            capacidade = 0;
            break;
       }
    }
   cout<<"\n\nO valor maximo possivel e: "<< result << "\n";
 return 0;
 }
