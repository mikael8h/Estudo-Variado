#ifndef MATRIZHUB_H
#define MATRIZHUB_H 

#include <string>
#include <vector>

// classse que possui os elementos da matriz (métodos, funções e estrutura)
class Matriz{

    private: 
        std::string nome;
        
    public:
        std::vector<std::vector<int>> composicao;
        // a matriz possui apenas duas dimensões
        // a matriz já começa sendo uma matriz 2x2 com 0s 
        // caso queira trcar esta composção, basta usar o método Limpa_matriz
        Matriz();

        //getters e setters
        void setNome(std::string nome);
        
        std::string getNome();

        // adiciona um número em alguma posição vazia da matriz
        void setNumero(int numero);

        //método que adiciona uma linha ao final da matriz
        void Adiciona_linha();

            //imprime na tela a dimensão da matriz

        void Adiciona_coluna();
            //o que este métofo faz é adicionar um elemento ao final de cada linha
            //os elementos são todos 0, tendo estes que ser alterados posteriormente dpelo método setNumero
            //adiciona 0 ao final de cada linha(uma coluna de 0);

            //irei avaliar a necessidade de criar um método que permita adicionar uma coluna no meio da matriz 

        void mostra_matriz();

        //procedimennto que limpa a matriz 
        void Limpa_matriz();
        /*
        void Alimenta_matriz(){
        
        } */  
};

//métodos que soma as matrizes
//obs: soma de matrizes de tamanhos diferentes é indefinido 
void soma(Matriz& mtr1, Matriz& mtr2, Matriz& resultado);

void subtrai(Matriz& mtr1, Matriz& mtr2, Matriz& resultado);

void multiplica(Matriz& mtr1, Matriz& mtr2, Matriz& resultado);

//método que chama as operações da classe e manipula as matrizes
void Operacao(Matriz& mtr1, Matriz& mtr2, Matriz& resultado);
#endif