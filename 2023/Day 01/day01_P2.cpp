// Bruno Becker Silva 13/04/2024
// Adventure of Code 2023 day 01

#include <fstream>  // ifstream ofstream
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // stringstream

// #define DEBUG
// #define DEBUGLINHA

using namespace std;

int getNum(string msg) {
  int num = 0;
  vector<int> calibra; 
  std::stringstream ss;
        
  for (size_t i = 0; i < msg.length(); i++) {   // for passa por todos caracteres da string
    if (isdigit(msg[i])) {              // Se o caractere atual for um dígito
      calibra.push_back(msg[i] - '0');  // Adiciona o valor numérico ao vetor calibra
      #ifdef DEBUG
      cout << "achei na pos " << i << " --------- salvei: " << msg[i] - '0' << endl;
      #endif
    } 

    for(int len = msg.length() - i; len > 0; len--) { // Varia o comprimento da substring a partir de i
      int pos = i;
      #ifdef DEBUG
      cout << "2xxx msg de " << pos << " a " << i << ": " << msg.substr(pos,len) << endl;
      #endif
      // Verifica se a stringstream contém uma palavra numérica e a converte em número
      if (msg.substr(pos,len) == "one")   {
        calibra.push_back(1);
        #ifdef DEBUG
          cout << "----------------------- salvei 1" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "two")   {
        calibra.push_back(2);
        #ifdef DEBUG
          cout << "----------------------- salvei 2" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "three") {
        calibra.push_back(3);
        #ifdef DEBUG
          cout << "----------------------- salvei 3" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "four")  {
        calibra.push_back(4);
        #ifdef DEBUG
          cout << "----------------------- salvei 4" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "five")  {
        calibra.push_back(5);
        #ifdef DEBUG
          cout << "----------------------- salvei 5" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "six")   {
        calibra.push_back(6);
        #ifdef DEBUG
          cout << "----------------------- salvei 6" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "seven") {
        calibra.push_back(7);
        #ifdef DEBUG
          cout << "----------------------- salvei 7" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "eight") {
        calibra.push_back(8);
        #ifdef DEBUG
          cout << "----------------------- salvei 8" << endl;
        #endif
      }
      if (msg.substr(pos,len) == "nine")  {
        calibra.push_back(9);
        #ifdef DEBUG
          cout << "----------------------- salvei 9" << endl;
        #endif
      }
    }
  }
    num = 10*calibra.front() + calibra.back();
    #ifdef  DEBUGLINHA
    cout << msg << "\t\t\t--> " << num << endl;
    #endif
    return num;
}

int main() {
  ifstream arq; // Cria input file stream (ifstream)
  int soma = 0;
  string line;
  
  arq.open("input.txt", ios::in); // Abre arquivo

  if (!arq.is_open()) { // Se houver erro, sai do programa
    cerr << "Erro ao abrir o arquivo!" << endl;
    return 1;
  }

  while (getline(arq, line)) { // Enquanto houver linhas no arquivo
    #ifdef DEBUG
    cout << " chamando para a linha: " << line << endl;
    #endif
    soma  += getNum(line);
  }

  cout << soma << endl;

  if (arq.bad()) {
    cerr << "Erro fatal!" << endl;
  }

  arq.close();
  return 0;
}





  // if (msg.find("one")   != std::string::npos) { cout << " 1 pos: "   << msg.find("one")   ;   }
  // if (msg.find("two")   != std::string::npos) { cout << " 2 pos: "   << msg.find("two")   ;   }
  // if (msg.find("three") != std::string::npos) { cout << " 3 pos: " << msg.find("three") ;   }
  // if (msg.find("four")  != std::string::npos) { cout << " 4 pos: "  << msg.find("four")  ;   }
  // if (msg.find("five")  != std::string::npos) { cout << " 5 pos: "  << msg.find("five")  ;   }
  // if (msg.find("six")   != std::string::npos) { cout << " 6 pos: "   << msg.find("six")   ;   }
  // if (msg.find("seven") != std::string::npos) { cout << " 7 pos: " << msg.find("seven") ;   }
  // if (msg.find("eight") != std::string::npos) { cout << " 8 pos: " << msg.find("eight") ;   }
  // if (msg.find("nine")  != std::string::npos) { cout << " 9 pos: "  << msg.find("nine")  ;   }
  