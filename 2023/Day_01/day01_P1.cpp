// Bruno Becker Silva 13/04/2024
// Adventure of Code 2023 day 01

#include <fstream>  // ifstream, ofstream
#include <iostream> 
#include <string>   
#include <vector>   
#include <cctype>   // isdigit()

#define DEBUG

using namespace std;

int getNum(string msg) {
  int num = 0;
  vector<int> calibra; 
        
  for (size_t i = 0; i < msg.length(); i++) {
    if (isdigit(msg[i])) {                  // Se o caractere atual for um dígito
      calibra.push_back(msg[i] - '0');      // Add valor numérico ao vetor calibra
      #ifdef DEBUG
      cout << "Pos " << i << ": " << msg[i] - '0' << endl;
      #endif
    }
  }
    num = 10*calibra.front() + calibra.back();
    #ifdef DEBUG
    cout << "retorno: " << num << endl;
    #endif
    return num;
}

int main() {
  ifstream arq;        // Cria input file stream (ifstream)
  int soma = 0;
  string line;
  
  arq.open("inputP1Teste.txt", ios::in); // Abre arquivo

  if (!arq.is_open()) {             // Se houver erro, sai do programa
    cerr << "Erro ao abrir o arquivo!" << endl;
    return 1;
  }

  while (getline(arq, line)) {      // Enquanto houver linhas no arquivo
    #ifdef DEBUG
    cout << "Chamando para a linha: " << line << endl;
    #endif
    soma  += getNum(line);          // Vai pegando as linhas e somando
  }

  cout << soma << endl;

  if (arq.bad()) {
    cerr << "Erro fatal!" << endl;
  }

  arq.close();
  return 0;
}
