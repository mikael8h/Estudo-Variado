#include <iostream> 
#include <cmath>
#include <iomanip> 

using namespace std;

// procedimento que alimenta as matrizes
void Alimenta_matriz(int matriz[3][3]){ // recebe como parametro a matriz
    int a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cout << "Digite o " << j+1 << "termo da " << i+1 << " linha" << endl; 
            cin >> a;
            matriz[i][j] = a;
        } // adiciona um núero à cada posição da matriz
    }
}

//função que multiplica as matrizes
void Multiplica_matriz(int num[3][3], int num2[3][3], int matrizF[3][3]){
    //recebe as matrizes como parâmetro
    int temp1, temp2;
    //iteração que percorre as linhas(i), colunas(j) e a matriz resultado(k)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                temp1 = num[i][k];
                temp2 = num2[k][j];
                matrizF[i][j] += temp1 * temp2;//matriz que armazena o resultado
            }
        }
    }
}

int main(){
    
    //declarações de variável
    int matrizA[3][3] = {};
    int matrizB[3][3] = {};
    int matrizF[3][3] = {};

    //chamamento das funções
    Alimenta_matriz(matrizA);
    Alimenta_matriz(matrizB);
    Multiplica_matriz(matrizA, matrizB, matrizF);

    //impressão dos resultados
    for(int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cout <<"| " << matrizF[i][j] <<" |";
        } cout << endl;
    } return 0;
}

//Desafio: Fazer um código que suporte matrizes n x n
//Usar arrays dinamicos (vector<int>)
//desenferrujar e aprender mais 
//Que o nome do senhor seja glorificado em todos os lugares

/*algoritmo par multiplicar as matrizes
1. multiplicar o primeiro termo da primeira linha em A pelo primeiro termo da primeira coluna em B 
2. repetir o passo 1 para os termos seguintes na respectiva linha e coluna somando os resultados até não haver mais termos  
3. repetir os passos 1 e 2 para a coluna seguinte até não haver mais colunas 
3. repetir os passos 1, 2 e 3 para as linhas seguintes até não haver mais linhas

*/