// Bruno Becker Silva 10/05/2024
// Adventure of Code 2023 day 03

#include <fstream>  // ifstream, ofstream
#include <iostream> 
#include <string>   
#include <vector>   
#include <cctype>   // isdigit()
#include <map>

#define DEBUG

using namespace std;

int main() {
    ifstream arq;        // Cria input file stream (ifstream)
    string line;
    string numero;
    vector<vector<char>> MatrizAdj;
    vector<vector<int>> positions;
    vector<int> output;
    vector<int>numeros;
    bool isValid = 0;
    std::map <std::pair<int, int>, char> simb2;
    std::map <std::pair<int, int>, std::string> matriz;
    int size_line = 0;

    arq.open("InputP1.txt", ios::in); // Abre arquivo

    if (!arq.is_open()) {             // Se houver erro, sai do programa
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
   
    //--------------------------------------------------------------
    //                    CRIANDO A MATRIZ
    //--------------------------------------------------------------
    int jaux = 0;
    while (getline(arq, line)) {    // enquanto houver linhas no arquivo
        #ifdef DEBUG
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
    size_line = line.size();

    //--------------------------------------------------------------
    //              PRINTANDO A MAPA E simbolo
    //--------------------------------------------------------------

    cout << "\nMatrix:" << endl;
    for (const auto& pair : matriz) {
        cout << pair.first.first << ", " << pair.first.second << ": " << pair.second << endl;
    }

    cout << "\nsimbolo:" << endl;
    for (const auto& pair : simb2) {
        cout << pair.first.first << ", " << pair.first.second << ": " << pair.second << endl;
    }

    

    for (auto& pair : matriz) {
        int i = pair.first.first; // Obter a primeira coordenada do par
        int j = pair.first.second; // Obter a segunda coordenada do par
        string num = pair.second; // Obter o caractere associado ao par
        
        #ifdef DEBUG
            cout << " " << num;
        #endif
        // numero += num;
        // numero.clear();
        
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
            // string linha_string = linhaParaString(MatrizAdj, i);
            // cout << ".V:" << extrairNumero(linha_string, j) << " ";
            output.push_back(aux);
        }
        isValid = 0;
    }




    //--------------------------------------------------------------
    //                    ACESSANDO A MATRIZ
    //--------------------------------------------------------------
    for ( int i = 0; i < MatrizAdj.size(); i++) {                // i para cada linha
        #ifdef DEBUG
            cout << endl;
        #endif
        for ( int j = 0; j < MatrizAdj[i].size(); j++) {         // j para cada coluna
            if( isdigit(MatrizAdj[i][j]) ){                      // se é numero
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
                    // string linha_string = linhaParaString(MatrizAdj, i);
                    // cout << ".V:" << extrairNumero(linha_string, j) << " ";
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

/*
python
input = """467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598.."""

numbers = ['1','2','3','4','5','6','7','8','9','0']

def near(x, y):
  return [
      [x -1, y -1], [x, y - 1], [x + 1, y - 1],
      [x -1, y   ],             [x + 1, y    ],
      [x -1, y +1], [x, y + 1], [x + 1, y + 1]
    ]

def is_number_str(number_str):
    return number_str in numbers
    
def is_symbol(c):
    return c not in numbers and c != '.'
    
def vector_get_number_positions_and_symbol_positions(input):
    lines = input.split("\n")
    vector_number_and_positions = {}
    vector_symbol_positions = []
    number = ''
    vector_current_number_positions = []
    for y, line in enumerate(lines):
        for x, c in enumerate(line):
            if is_number_str(c):
                vector_current_number_positions .append([x,y])
                number = number + c
            if  not is_number_str(c) and number != '':
                vector_number_and_positions[int(number)] = vector_current_number_positions
                number = ''
                vector_current_number_positions  = []
            if is_symbol(c):
                vector_symbol_positions.append([x,y])
    return vector_number_and_positions, vector_symbol_positions

def get_symbols_surrounding_zone(vector_symbol_positions):
    surrounding_zone = []
    for position in vector_symbol_positions:
        x, y = position
        surrounding_zone = surrounding_zone + near(x, y)
    return surrounding_zone

def get_numbers_with_symbols_in_surroundings(vector_number_and_positions, symbols_surrounding_zone):
    numbers_with_symbols_near = []
    for number, positions in vector_number_and_positions.items():
        any_symbol_near = False
        for position in positions:
            if position in symbols_surrounding_zone:
                any_symbol_near = True
        if any_symbol_near:
            numbers_with_symbols_near .append(number)
    return numbers_with_symbols_near

if __name__ == "__main__":
    vector_number_and_positions, vector_symbol_positions = vector_get_number_positions_and_symbol_positions(input)
    surrounding_zone = get_symbols_surrounding_zone(vector_symbol_positions)
    numbers_with_symbols_near = get_numbers_with_symbols_in_surroundings(vector_number_and_positions, surrounding_zone)
    sum = sum(numbers_with_symbols_near)
    print(sum)

*/




/*
python
input = """
467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..""" 

# se divide na nova linha para ter uma matriz
lines = input.split("\n")

# numeros e as posicoes da matriz que ocupam
map = {}
# simbolos e as posicoes da matriz que ocupam
simbolo = {}

# numero atual pra montar os numeros ao invez de mostrar so um por casa
number = ''
# as posicoes que o numero atual ocupa, pra gente preencher depois
positions = []
# o que sao os numeros, tem jeito melhor de fazer isso... mas ta bueno vai assim
numbers = ['1','2','3','4','5','6','7','8','9','0']

# pra cada linha
for i, line in enumerate(lines):
    # pra cada caractere
    for j, c in enumerate(line):
        # se for um numero, adiciona a posicao e o caractere
        if c in numbers:
            positions.append([i,j])
            number = number + c 

        # se nao for um numero, mas tiver algo nos numeros, preenche os valores
        # de map
        if c not in numbers and number != '':
            for position in positions:
                map[str(position)] = number
            number = ''
            positions = []

        # se for um symbol, poe em simbolo
        if c not in numbers and c != '.':
            simbolo[str([i,j])] = c


print(simbolo)
print(map)

#o que tem em volta da posicao x,y
def near(j, i):
    return [
     [j -1, i -1], [j, i - 1] , [j + 1, i - 1],
     [j -1, i]               ,  [j + 1, i],
     [j -1, i +1], [j, i + 1],  [j +1, i +1]] 


# quais zonas estao ao arredor de um symbol
zone = []
for key, operation in simbolo.items():
    i, j = eval(key)
    zone = zone + near(i, j)

print(zone)

# aqui pode dar bug, mas sao todos os numeros que tem symbol em volta
# se tiver mais de um numero igual pode dar ruim por cause do set que torna
# unico os valores...
uniques = [] 

for key, value in map.items():
    key_list = eval(key)
    # se a chave ta na zona de arredores de algum symbol, poe na lista
    if key_list in zone:
        uniques.append(int(value))


# pra cada numero unique soma
sum = 0
for u in set(uniques):
*/