// Bruno Becker Silva 16/04/2024
// Adventure of Code 2023 day 02

// 12 red, 13 green e 14 blue
// Qual é a soma dos IDs desses jogos?

#include <fstream>  // ifstream, ofstream
#include <iostream> 
#include <string>   
#include <sstream>   
#include <vector>   
#include <cctype>   // isdigit()

// #define DEBUG
#define DEBUG2

using namespace std;

int getID(string linha, int compRed, int compGreen, int compBlue){  // 12 red, 13 green e 14 blue
    int id = 0;
    int red = 0;
    int blue = 0;
    int green = 0;
    char dois_pontos;
    string game, palavra, cor;
    stringstream ss(linha);    
    
    // Extrai a game, o número da linha (ID) e o dois pontos
    ss >> game >> id >> dois_pontos;
    
    while(ss >> palavra){
        if (isdigit(palavra[0])){      // Se for um digito, proxima info sera a cor   
            int valor = stoi(palavra);       // Converte de string para inteiro
            ss >>  cor;                  // salva a cor seguinte

            if(cor[cor.length()-1] == ',' || cor[cor.length()-1] == ';'){   //Se o ultimo caractere for , ou ;
                cor = cor.substr(0, cor.length() - 1);                      //Remove último caractere
            }

            #ifdef DEBUG
            cout << "---- " << valor << " " << cor << "\t\t";
            #endif

            if (cor == "red")   {
                if (red < valor)      red    = valor;   // salva o maior valor da cor
                #ifdef DEBUG
                cout << red << endl;
                #endif
            }
            if (cor == "blue")  {
                if (blue < valor)     blue  = valor;    // salva o maior valor da cor
                #ifdef DEBUG
                cout << blue << endl;
                #endif
            }
            if (cor == "green") {
                if (green < valor)    green = valor;   // salva o maior valor da cor
                #ifdef DEBUG
                cout << green << endl;
                #endif
            }
        }
        
    }
        
    if  ((red > compRed || blue > compBlue || green > compGreen)){
        #ifdef  DEBUG2
        cout << "xxxxxxxxxxxxxxxxxx GAME INVALIDO xxxxxxx RETORNEI ID: " << id << endl;
        cout << "-- Red:   " << red   << "\tCompRed:   " << compRed << endl;
        cout << "-- Green: " << green << "\tCompGreen: " << compGreen << endl;
        cout << "-- Blue:  " << blue  << "\tCompBlue:  " << compBlue << endl;
        cout << endl;
        #endif
        return 0;
    }
    else
        #ifdef  DEBUG2
        cout << "------------------- GAME VALIDO ---------- RETORNEI ID: " << id << endl;
        cout << "-- Red:   " << red   << "\tCompRed:   " << compRed << endl;
        cout << "-- Green: " << green << "\tCompGreen: " << compGreen << endl;
        cout << "-- Blue:  " << blue  << "\tCompBlue:  " << compBlue << endl;
        cout << endl;
        #endif
        return id;
}

int main() {
  ifstream arq;        // Cria input file stream (ifstream)
  int soma = 0;
  string line;
  
  arq.open("input.txt", ios::in); // Abre arquivo

  if (!arq.is_open()) {             // Se houver erro, sai do programa
    cerr << "Erro ao abrir o arquivo!" << endl;
    return 1;
  }

  while (getline(arq, line)) {      // Enquanto houver linhas no arquivo
    #ifdef DEBUG2
    cout << line << endl;
    #endif
    soma  += getID(line, 12, 13, 14);           // Vai pegando as linhas e somando --- 12 red, 13 green e 14 blue
  }

  cout << soma << endl;

  if (arq.bad()) {
    cerr << "Erro fatal!" << endl;
  }

  arq.close();
  return 0;
}
