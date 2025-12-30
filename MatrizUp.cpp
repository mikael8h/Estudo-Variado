#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// classse que possui os elementos da matriz (métodos, funções e estrutura)
class Matriz{

    private: 
        string nome;
        
    public:
        vector<vector<int>> composicao;
        // a matriz possui apenas duas dimensões
        // a matriz já começa sendo uma matriz 2x2 com 0s 
        // caso queira trcar esta composção, basta usar o método Limpa_matriz
        Matriz(){
            this->composicao = {
                {0, 0},
                {0, 0}
            };
        }

        //getters e setters
        void setNome(string nome){
            this-> nome = nome;
        }
        
        string getNome(){
            return this->nome;
        }

        // adiciona um número em alguma posição vazia da matriz
        void setNumero(int numero){
            int linha, coluna;
            cout << "informe a linha em que deseja adicionar o numero: " << endl;
            cin >> linha;
            cout << "informe a coluna: " <<endl;
            cin >> coluna;
            linha--;
            coluna--;
            //condicional que avalia se a linha que está sendo acessada exsite na matriz
            if(this->composicao.size() <= linha || linha < 0){
                cout << "A matriz não possui essa dimenção ainda, adicione um numero valido ou adicione linhas/colunas" << endl;
                for (const auto& linha : composicao){
                    for (const auto& membro : linha){
                        cout << "| " << setw(2) << membro << setw(2) << " |";
                    } cout << endl;
                }
            //condicional que avalia se a coluna que está sendo acessada existe ana matriz 
            } else if (coluna >= composicao[linha].size() || coluna < 0){
                cout <<  "A matriz nao possui estas dimensoes, informe um outro numero ou adicione linhas/colunas" << endl;
                for (const auto& linha : composicao){
                    for (const auto& membro : linha){
                        cout << "| " << setw(2) << membro << setw(2) << " |";
                    } cout << endl;
                }
            } else {
                this->composicao[linha][coluna] = numero;
            }
        }

        //método que adiciona uma linha ao final da matriz
        void Adiciona_linha(){

            int linha, coluna;
            vector<int> linha_nova(composicao[0].size(), 0);
            this->composicao.push_back(linha_nova);
            linha = composicao.size();
            coluna = composicao[0].size();
            cout << "A matriz tem dimensão " << linha <<" X "<< coluna <<endl;
            //imprime na tela a dimensão da matriz
        }

        void Adiciona_coluna(){
            //o que este métofo faz é adicionar um elemento ao final de cada linha
            //os elementos são todos 0, tendo estes que ser alterados posteriormente dpelo método setNumero
            for(int i = 0; i < composicao.size(); i++){
                this->composicao[i].push_back(0);
            }//adiciona 0 ao final de cada linha(uma coluna de 0);

            //irei avaliar a necessidade de criar um método que permita adicionar uma coluna no meio da matriz 
             for (const auto& linha : composicao){
                    for (const auto& membro : linha){
                        cout << "| " << setw(2) << membro << setw(2) << " |";
                    } cout << endl;
            }
        }

        void mostra_matriz(){
            cout << this->nome << endl;
             for (const auto& linha : this->composicao){
                cout << "|";
                    for (const auto& membro : linha){
                        cout << setw(2) << membro << setw(2) << " |";
                    } cout << endl;
            } cout << endl << endl;
        }

        //procedimennto que limpa a matriz 
        void Limpa_matriz(){
            this -> composicao.clear(); 
        }
        /*
        void Alimenta_matriz(){
        
        } */  
};

//métodos que soma as matrizes
//obs: soma de matrizes de tamanhos diferentes é indefinido 
void soma(Matriz& mtr1, Matriz& mtr2, Matriz& resultado){

    resultado.Limpa_matriz();
    resultado.composicao.resize(mtr1.composicao.size(), vector<int> (mtr1.composicao[0].size(), 0 ));

    if (mtr1.composicao.size()!=mtr2.composicao.size()){
        cout << "Erro, as matrizes não tem as mesmas dimensoes" << endl;
        return;
    } else if(mtr1.composicao[0].size()!=mtr2.composicao[0].size()){  
        
            cout << "Erro, as matrizes não tem as mesmas dimensoes" << endl;
        return;
    } else {
        for(int i = 0; i < mtr1.composicao.size() && i < mtr2.composicao.size(); i++) {
            for (int j = 0; j < mtr1.composicao[0].size() && j < mtr2.composicao[0].size(); j++ ){
                resultado.composicao[i][j] = mtr1.composicao[i][j] + mtr2.composicao[i][j];
            }
        }        
    }

    for(const auto& linha : resultado.composicao){
        for(const auto& coluna : linha ){
            cout << "| " <<setw(2) << coluna << setw(2) << " |" ;
        } cout << endl;
    }

}

void subtrai(Matriz& mtr1, Matriz& mtr2, Matriz& resultado){

    resultado.Limpa_matriz();
    resultado.composicao.resize(mtr1.composicao.size(), vector<int>(mtr1.composicao[0].size()));

    if (mtr1.composicao.size()!=mtr2.composicao.size()){
        cout << "Erro, as matrizes não tem as mesmas dimensoes" << endl;
        return;
    } else if(mtr1.composicao[0].size()!=mtr2.composicao[0].size()){  
        
            cout << "Erro, as matrizes não tem as mesmas dimensoes" << endl;
        return;
    } else {
        for(int i = 0; i < mtr1.composicao.size() && i < mtr2.composicao.size(); i++) {
            for (int j = 0; j < mtr1.composicao[0].size() && j < mtr2.composicao[0].size(); j++ ){
                resultado.composicao[i][j] = mtr1.composicao[i][j] - mtr2.composicao[i][j];
            }
        }        
    }

    for(const auto& linha : resultado.composicao){
        for(const auto& coluna : linha ){
            cout << "| " <<setw(2) << coluna << setw(2) << " |" ;
        } cout << endl;
    }

}

void multiplica(Matriz& mtr1, Matriz& mtr2, Matriz& resultado){

    resultado.Limpa_matriz();
    resultado.composicao.resize(mtr1.composicao.size(), vector<int>(mtr2.composicao[0].size(), 0));

    if(mtr1.composicao[0].size() != mtr2.composicao.size()) {
    cout << "Erro: número de colunas de A deve ser igual ao número de linhas de B" << endl;
    return;
    }

    for (int i = 0; i < mtr1.composicao.size() && i < mtr2.composicao.size(); i++){
        for(int j = 0; j < mtr1.composicao[0].size() && j < mtr2.composicao[0].size(); j++){
            for (int k = 0; k < mtr1.composicao[0].size(); k++){
                resultado.composicao[i][j] += mtr1.composicao[i][k] * mtr2.composicao[k][j]; 
            }
        }
    } 

    for(const auto& linha : resultado.composicao){
       cout << "|";
        for(const auto& coluna : linha ){
            cout << setw(3) << coluna << setw(3) << " |" ;
        } cout << endl;
    }
}

//método que chama as operações da classe e manipula as matrizes
void Operacao(Matriz& mtr1, Matriz& mtr2, Matriz& resultado){

    int a, b, c, d;
    char e, f, g, h;

    
     do{ // menu de interação 
        cout << "Voce tem duas matrizes, a primeira matriz e a segunda matriz" << endl;
        cout << "Informe qual operacao deseja realizar: " << endl;
        cout << "digite: " << endl << "1 -> Para visualizar as matrizes." << endl 
        << "2 -> para adicionar ou trocar um numero em uma das posicoes da matriz." << endl
        << "3 -> para adicionar uma linha a uma matriz." << endl
        << "4 -> para adicionar uma coluna a uma matriz." << endl
        << "5 -> para somar as matrizes" << endl
        << "6 -> para multiplicar as matrizes" << endl
        << "7 -> para subtrair as matrizes" << endl 
        << "0 -> para sair." <<endl;
        cin >> a;
        switch(a){
            case 0: 
                
            break;

            case 1:
                cout << "Qual matriz voce deseja ver: " << endl << "1 -> primeira" << endl << "2 -> segunda" << endl;
                cin >> b;
                if(b == 1){mtr1.mostra_matriz();}else if(b == 2){mtr2.mostra_matriz();}else {
                    cout << "numero invalido" << endl;
                } 
            break;

            case 2:
                cout << "Informe qual matriz deseja alterar: " <<  endl << "1 -> primeira " << endl << "2 -> segunda" << endl;
                cin >> b;
                if(b == 1){
                    cout << "Digite o numero que deseja adicionar: " <<endl;
                    cin >> c;
                    mtr1.setNumero(c);
                } else if(b == 2){
                    cout << "Digite o numero que deseja adicionar: " <<endl;
                    cin >> c;
                    mtr2.setNumero(c);
                } else {
                    cout << "Numero invalido" << endl;
                    break;
                } mtr1.mostra_matriz(); mtr2.mostra_matriz();
                break;
            
            case 3: 
                cout << "informe em qual matriz deseja adicionar a linha: " << endl << "1 -> orimeira " << endl << "2 -> segunda " << endl;
                cin >> b;
                if(b == 1) {
                    mtr1.Adiciona_linha();
                } else if (b==2){
                    mtr2.Adiciona_linha();
                } else {
                    cout << "Numero invalido" << endl;
                    break;
                } 
                mtr1.mostra_matriz(); mtr2.mostra_matriz();
                break;
                
            case 4:
                cout << "Informe em qual matriz deseja adicionar a coluna: " << endl << "1 -> primeira " << endl << "2 -> segunda " << endl;
                cin >> b;
                if (b == 1){
                    mtr1.Adiciona_coluna();
                } else if(b == 2){
                    mtr2.Adiciona_coluna();
                } else {
                    cout << "Numero invalido" << endl;
                    break;
                } mtr1.mostra_matriz(); mtr2.mostra_matriz();
                break;
            
            case 5: 
                cout << "O resultado eh: " <<  endl;
                soma(mtr1, mtr2, resultado);
                break;
            
            case 6: 
                cout << "O produto das duas matrizes eh: " << endl;
                multiplica(mtr1, mtr2, resultado);
                break;

            case 7:
                cout << "O resultado eh: " << endl;
                subtrai(mtr1, mtr2, resultado);
                break;

        }

    }while(a != 0);
}

int main(){

    Matriz mtr1, mtr2;
    Matriz resultado;
    

    resultado.setNome("resultado");
    mtr1.setNome("Primeira matriz");
    mtr2.setNome("Segunda matriz");

   Operacao(mtr1, mtr2, resultado);

    return 0;

}