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
<<<<<<< Updated upstream
#define LINHAS
// #define VALID
=======
// #define LINHAS
#define VALORES
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
    arq.open("inputP2.txt", ios::in); // Abre arquivo
=======
    arq.open("input.txt", ios::in); // Abre arquivo
>>>>>>> Stashed changes

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
            cout << "\nLinha " << jaux << " --| " << line << " |--> ";
        #endif
        string number = "";
        vector<char> linhaMatriz;
        for (int i = 0; i < line.length(); i++) {
            char caractere = line[i];
            linhaMatriz.push_back(caractere);
            #ifdef LINHAS
                cout << linhaMatriz[i];
            #endif
            if (isdigit(caractere)){                          //  se for um numero, adiciona a posicao e o caractere
                positions.push_back({i, jaux});
                number = number + caractere;
            }
            if ((!isdigit(caractere) || i == line.length() - 1) && number != ""){         //  se nao for um numero, mas tiver algo nos numeros, preenche os valores de map
                for (const auto& position : positions) {
                    matriz[{position[0], position[1]}] = number;
                    // cout << "Numero adicionado: " << number << endl;
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
<<<<<<< Updated upstream
    int cont = 0;
    for ( int i = 0; i < MatrizAdj.size(); i++) {                // i para cada linha
        for ( int j = 0; j < MatrizAdj[i].size(); j++) {         // j para cada coluna
=======
    
    #ifdef VALORES
        cout << endl;
        cout << endl;
    #endif
    int cont = 0;
    int const numLinhas = MatrizAdj.size();
    for ( int i = 0; i < numLinhas; i++) {                // i para cada linha
        int const numColunas = MatrizAdj[i].size();
        for ( int j = 0; j < numColunas; j++) {         // j para cada coluna
>>>>>>> Stashed changes
            if( isdigit(MatrizAdj[i][j]) ){                      // se é numero
                #ifdef DEBUG
                    cout << " " << MatrizAdj[i][j];
                #endif                
                //--------------------------------------------------------------    .1   .2   .3
                //          VERIFICANDO SE O DIGITO É VALIDO                        .4   ij   .6
                //--------------------------------------------------------------    .7   .8   .9
                // 
                //------------------------------------ LINHA 1 ^ ---------------
                if ( i > 0 && j > 0 ) {         // se for o primeiro da linha e da coluna
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
                if ( i > 0 && j < numColunas - 1 ) { 
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
                if ( j < numColunas - 1 ) { 
                    // cout << ".6";
                    if ( MatrizAdj[i][j+1] != '.' && !isdigit(MatrizAdj[i][j+1]) ){
                        isValid = 1;
                    }
                }
                
                //------------------------------------ LINHA 3 _ ---------------
                if ( i < numLinhas - 1 && j > 0 ) { 
                    // cout << ".7";
                    if ( MatrizAdj[i+1][j-1] != '.' && !isdigit(MatrizAdj[i+1][j-1]) ){
                        isValid = 1;
                    }
                }
                if ( i < numLinhas - 1 ) { 
                    // cout << ".8";
                    if ( MatrizAdj[i+1][j]   != '.' && !isdigit(MatrizAdj[i+1][j]) ){
                        isValid = 1;
                    }
                }
                if ( i < numLinhas - 1 && j < numColunas - 1 ) { 
                    // cout << ".9";
                    if ( MatrizAdj[i+1][j+1] != '.' && !isdigit(MatrizAdj[i+1][j+1]) ){
                        isValid = 1;
                    }
                }
        
                //--------------------------------------------------------------
                //        ADICIONANDO NUMERO COMPLETO A SAÍDA erro possivelmente aqui, se tiver dois repetidos 
                //--------------------------------------------------------------
                
                if ( isValid ){
                    string valor = matriz[{j, i}];
                    int aux_i = 0;
                    int aux_j = 0;
                    
                    int soma = stoi(valor);
                    if (output.empty() || output.back() != valor) {
                        output.push_back(valor);
<<<<<<< Updated upstream
                        #ifdef VALID
                        cout << " V." << valor;
                        #endif
                        somaFinal = somaFinal + soma;
                        cont = 0;
                    }else{
                        if ( cont > 1 ){
                            cout << "\nto aqui" << valor << endl;
                        }
                        #ifdef VALID
                        cout << " #dup." << valor;
=======
                        #ifdef VALORES
                        cout << " +V_" << valor;
                        #endif
                        somaFinal = somaFinal + soma;
                        aux_i = i;
                        aux_j = j;
                        cont = 0;
                    }else{
                        if (cont > 1) { cout << "\nto aqui " << valor << endl;}
                        #ifdef VALORES
                        cout << " #dup_" << valor;
>>>>>>> Stashed changes
                        #endif
                        cont++;
                    }
                }
                isValid = 0;
            }
        }
    }
<<<<<<< Updated upstream
    // cout << "Esperados: 276 958 742 714 612 304 175 346 997 923 256 122 746 76 332 111 204 396 357 438 694 154 859 496 598 810 816 713 802 344 671 388 152 141 73 719 526 830 943 877 67 502" << endl;
    cout << "\nValores validos " << endl;
=======
    cout << "\n\n--------------------------------" << endl;
    // inputP1
    // cout << "Esperados: 467 35 633 617 592 755 664 598 " << endl;
    // inputP2
    // cout << "Esperados: 276 958 742 714 612 304 175 346 997 923 256 122 746 76 332 111 204 396 357 438 694 154 859 496 598 810 816 713 802 344 671 388 152 141 73 719 526 830 943 877 67 502" << endl;
    // inputP3
    // cout << "Esperados: 276 958 742 714 574 833 159 297 612 304 175 890 346 997 923 253 122 746 832 766 432 229 674 415 76 332 111 720 204 396 357 438 694 154 26 422 200 201 859 496 598 810 816 713 802 540 344 671 467 388 152 141 73 719 526 830 943 541 624 781 150 966 877 67 859 502 425 778 142 569 563 57 786 255 638 979 704 181 560 939 194 675 741 681 882 714 741 650 374 542 344 340 799 990 733 811 8 844 660 937 227 775 24 146 983 822 898 611 693 328 254 582 528 359 536 889 9 193 382 450 795 988" << endl;
    cout << "Validos:   ";
>>>>>>> Stashed changes
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }

    cout << "\nSoma Final: " << somaFinal << endl;
    cout << "--------------------------------" << endl;
    
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