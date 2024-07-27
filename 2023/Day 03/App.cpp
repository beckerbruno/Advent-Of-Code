// Bruno Becker Silva 10/05/2024
// Adventure of Code 2023 day 03

#include <fstream>  // ifstream, ofstream
#include <iostream> 
#include <string>   
#include <vector>   
#include <cctype>   // isdigit()
#include <map>
#include <sstream> // Para std::istringstream   

// #define DEBUG
#define LINHAS

using namespace std;

int main() {
    ifstream arq;        // Cria input file stream (ifstream)
    string line;
    vector<vector<char>> MatrizAdj;
    vector<vector<int>> positions;
    vector<string> output;
    bool isValid = 0;
    int somaFinal = 0;
    std::map <std::pair<int, int>, char> simb2;
    std::map <std::pair<int, int>, std::string> matriz;

    arq.open("Input.txt", ios::in); // Abre arquivo

    if (!arq.is_open()) {             // Se houver erro, sai do programa
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
   
    //--------------------------------------------------------------
    //                    CRIANDO A MATRIZ
    //--------------------------------------------------------------
    int jaux = 0;
    while (getline(arq, line)) {    // enquanto houver linhas no arquivo
        #ifdef LINHAS
            cout << "\nChamando a linha " << jaux << " --| " << line << " |--| ";
        #endif
        string number = "";
        vector<char> linhaMatriz;
        for (int i = 0; i < line.length(); i++) {
            char caractere = line[i];
            linhaMatriz.push_back(caractere);
            #ifdef DEBUG
                cout << linhaMatriz[i] << " ";
            #endif
            if (isdigit(caractere)){                          //  se for um numero, adiciona a posicao e o caractere
                positions.push_back({i, jaux});
                number = number + caractere;
            }
            if (!isdigit(caractere) && number != ""){         //  se nao for um numero, mas tiver algo nos numeros, preenche os valores de map
                for (const auto& position : positions) {
                    matriz[{position[0], position[1]}] = number;
                }
                number.clear();
                positions.clear();
            }
            if (!isdigit(caractere) && caractere != '.'){     // se for um symbol, poe em simbolo
                simb2[{i, jaux}] = caractere;
            }
        }
        MatrizAdj.push_back(linhaMatriz);
        jaux ++;
    }

    //--------------------------------------------------------------
    //              PRINTANDO A MAPA E simbolo
    //--------------------------------------------------------------

    // cout << "\nMatriz:" << endl;
    // for (const auto& pair : matriz) {
    //     cout << pair.first.first << ", " << pair.first.second << ": " << pair.second << endl;
    // }

    // cout << "\nsimbolo:" << endl;
    // for (const auto& pair : simb2) {
    //     cout << pair.first.first << ", " << pair.first.second << ": " << pair.second << endl;
    // }

    //--------------------------------------------------------------
    //                    ACESSANDO A MATRIZ
    //--------------------------------------------------------------
    for ( int i = 0; i < MatrizAdj.size(); i++) {                // i para cada linha
        #ifdef LINHAS
            cout << endl;
        #endif
        for ( int j = 0; j < MatrizAdj[i].size(); j++) {         // j para cada coluna
            if( isdigit(MatrizAdj[i][j]) ){                      // se é numero
                #ifdef DEBUG
                    // cout << " " << MatrizAdj[i][j];
                #endif                
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
                    string valor = matriz[{j, i}];
                    int soma = stoi(valor);
                    if (output.empty() || output.back() != valor) {
                        output.push_back(valor);
                        cout << " V." << valor;
                        somaFinal = somaFinal + soma;
                    }else{
                        cout << " #dup." << valor;
                    }
                }
                isValid = 0;
            }
        }
    }
    cout << "Esperados: 276 958 742 714 612 304 175 346 997 923 256 122 746 76 332 111 204 396 357 438 694 154 859 496 598 810 816 713 802 344 671 388 152 141 73 719 526 830 943 877 67 502" << endl;
    cout << "\nValores validos " << endl;
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }

    cout << "\nSoma Final: " << somaFinal << endl;
    
    if (arq.bad()) {
        cerr << "Erro fatal!" << endl;
    }

    arq.close();
    return 0;
}

/*
def get_number_with_positions(lines):
    number_with_positions = []
    number = ""
    current_number_positions = []
    for y, line in enumerate(lines):
        for x, c in enumerate(line):
            if c.isdigit():
                current_number_positions.append([x, y])
                number = number + c
            if not c.isdigit() and number != "":
                number_with_positions.append([int(number), current_number_positions])
                number = ""
                current_number_positions = []
    return number_with_positions


def get_symbols_surroundings(lines):
    return [
        p
        for y, line in enumerate(lines)
        for x, c in enumerate(line)
        if not c.isdigit() and c != "."
        for p in near(x, y)
    ]


def get_numbers_with_symbols_in_surroundings(
    number_with_positions, symbols_surroundings
):
    return [
        n
        for n, ps in number_with_positions
        if any([p in symbols_surroundings for p in ps])
    ]


def part1(input):
    lines = input.split("\n")
    number_with_positions = get_number_with_positions(lines)
    symbols_surroundings = get_symbols_surroundings(lines)
    numbers_with_symbols_near = get_numbers_with_symbols_in_surroundings(
        number_with_positions, symbols_surroundings
    )
    return sum(numbers_with_symbols_near)


if _name_ == "_main_":
    print(part1(EXAMPLE_INPUT))
*/