// Bruno Becker Silva 10/05/2024
// Adventure of Code 2023 day 03

#include <fstream>  // ifstream, ofstream
#include <iostream> 
#include <string>   
#include <vector>   
#include <cctype>   // isdigit()

#define DEBUG

using namespace std;

#include <iostream>
#include <string>

std::string extrairNumero(const std::string& str, int i) {
    // Encontrar o índice do início do número
    size_t start_index = 0;
    for (int count = 0; count < i; ++count) {
        start_index = str.find('.', start_index) + 1;
    }

    // Encontrar o índice do fim do número
    size_t end_index = str.find('.', start_index);

    // Extrair o número da string e retorná-lo
    std::string numero = str.substr(start_index, end_index - start_index);
    return numero;
}

string linhaParaString(const vector<vector<char>>& matriz, int linha) {
    string resultado;
    for (char c : matriz[linha]) {
        resultado += c;
    }
    return resultado;
}

// int main() {
//     std::string string_exemplo = "...123..45..89";
//     int i = 10;
//     std::string numero = extrairNumero(string_exemplo, i);
//     std::cout << "Número: " << numero << std::endl;
//     return 0;
// }


int main() {
    ifstream arq;        // Cria input file stream (ifstream)
    string line;
    string numero;
    vector<vector<char>> MatrizAdj;
    vector<int> output;
    vector<int>numeros;
    bool isValid = 0;

    arq.open("InputP1.txt", ios::in); // Abre arquivo

    if (!arq.is_open()) {             // Se houver erro, sai do programa
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
   
    //--------------------------------------------------------------
    //                    CRIANDO A MATRIZ
    //--------------------------------------------------------------

    while (getline(arq, line)) {    // enquanto houver linhas no arquivo
        #ifdef DEBUG
            cout << "\nChamando a linha --| " << line << " |--| ";
        #endif

        vector<char> linhaMatriz;
        for (int i = 0; i < line.length(); i++) {
            char caractere = line[i];
            linhaMatriz.push_back(caractere);
            #ifdef DEBUG
                cout << linhaMatriz[i] << " ";
            #endif
        }
        MatrizAdj.push_back(linhaMatriz);
    }

    //--------------------------------------------------------------
    //                    ACESSANDO A MATRIZ
    //--------------------------------------------------------------
    for ( int i = 0; i < MatrizAdj.size(); i++) {                // i para cada linha
        #ifdef DEBUG
            cout << endl;
        #endif
        for ( int j = 0; j < MatrizAdj[i].size(); j++) {         // j para cada coluna
            if( MatrizAdj[i][j] != '.' && isdigit(MatrizAdj[i][j]) ){
                #ifdef DEBUG
                    cout << " " << MatrizAdj[i][j];
                #endif
                numero += MatrizAdj[i][j];
                numeros.push_back( MatrizAdj[i][j] - '0' );
                numero.clear();
                
                //--------------------------------------------------------------    .1   .2   .3
                //          VERIFICANDO SE O DIGITO É VALIDO                        .4   ij   .6
                //--------------------------------------------------------------    .7   .8   .9
                
                //------------------------------------ LINHA 1 ^ ---------------
                if ( i > 0 && j > 0 ) { 
                    // cout << ".1";
                    if (MatrizAdj[i-1][j-1] != '.' && !isdigit(MatrizAdj[i-1][j-1]) ){
                        isValid = 1;
                    }
                }
                if ( i > 0 ) { 
                    // cout << ".2";
                    if (MatrizAdj[i-1][j]   != '.' && !isdigit(MatrizAdj[i-1][j]) ){
                        isValid = 1;
                    }
                }
                if ( i > 0 && j < MatrizAdj[i].size() - 1 ) { 
                    // cout << ".3";
                    if (MatrizAdj[i-1][j+1] != '.' && !isdigit(MatrizAdj[i-1][j+1]) ){
                        isValid = 1;
                    }
                }

                //------------------------------------ LINHA 2 + ---------------
                if ( j > 0 ) { 
                    // cout << ".4";
                    if ( MatrizAdj[i][j-1] != '.' && !isdigit(MatrizAdj[i][j-1]) ){
                        isValid = 1;
                    }
                }
                if ( j < MatrizAdj[i].size() - 1 ) { 
                    // cout << ".6";
                    if ( MatrizAdj[i][j+1] != '.' && !isdigit(MatrizAdj[i][j+1]) ){
                        isValid = 1;
                    }
                }
                
                //------------------------------------ LINHA 3 _ ---------------
                if ( i < MatrizAdj.size() - 1 && j > 0 ) { 
                    // cout << ".7";
                    if ( MatrizAdj[i+1][j-1] != '.' && !isdigit(MatrizAdj[i+1][j-1]) ){
                        isValid = 1;
                    }
                }
                if ( i < MatrizAdj.size() - 1 ) { 
                    // cout << ".8";
                    if ( MatrizAdj[i+1][j]   != '.' && !isdigit(MatrizAdj[i+1][j]) ){
                        isValid = 1;
                    }
                }
                if ( i < MatrizAdj.size() - 1 && j < MatrizAdj[i].size() - 1 ) { 
                    // cout << ".9";
                    if ( MatrizAdj[i+1][j+1] != '.' && !isdigit(MatrizAdj[i+1][j+1]) ){
                        isValid = 1;
                    }
                }
        
                //--------------------------------------------------------------
                //          ADICIONANDO NUMERO COMPLETO A SAÍDA
                //--------------------------------------------------------------
                
                if ( isValid ){
                    int aux = MatrizAdj[i][j] - '0';
                    string linha_string = linhaParaString(MatrizAdj, i);
                    cout << ".V:" << extrairNumero(linha_string, j) << " ";
                    output.push_back(aux);
                }
                isValid = 0;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }

    if (arq.bad()) {
        cerr << "Erro fatal!" << endl;
    }

    arq.close();
    return 0;
}
