#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
//testando melhor

int main(){
  using namespace std;

  char jogo[3][3];
  int i, j, linha, coluna, jogador = 1, ganhou = 0, jogadas, opcao, numero_teste = 0;
  i = 0;
  j = 0;
  // teste
  do{
    jogador = 1;
    ganhou = 0;
    jogadas = 0;

    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        jogo[i][j] = ' ';
      }
    }
    do{
      // imprimir o jogo
      cout << "          0    1    2\n";
      cout << endl;
      for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
          if (j == 0)
            cout << "\t";
          cout << "   " << jogo[i][j];
          if (j < 2)
            cout << "|";
          if (j == 2)
            cout << " " << i;
        }
        if (i < 2)
          cout << "\n\t--------------\n";
      }
      // ler coordenadas
      do{
        cout << "\nJogador: Digite a linha e a coluna que deseja jogar: ";
        cin >> linha >> coluna;
        system("cls");
      }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

      // salvar coodernadas
      if (jogador == 1){
        jogo[linha][coluna] = 'O';
        jogador++;
      }
      else{
        jogo[linha][coluna] = 'X';
        jogador = 1;
      }
      jogadas++;
      // alguem ganhou por linha
      if (jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
          jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
          jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
        cout << "Parabens! O jogador 1 venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
          jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
          jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
        cout << "Parabens! O jogador 2 venceu!";
        ganhou = 1;
      }
      // alguem ganhou por coluna
      if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
          jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
          jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
        cout << "Parabens! O jogador 1 venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
          jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
          jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
        cout << "Parabens! O jogador 2 venceu!";
        ganhou = 1;
      }
      // alguem ganhou na diagonal principal
      if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
        cout << "\nParabens! o jogador 1 venceu!";
        ganhou = 1;
      }
      if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
        cout << "\nParabens! O jogador 2 venceu!";
        ganhou = 1;
      }
      // alguem ganhou na diagonal principal
      if (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
        cout << "\nParabens! O jogador 1 venceu!";
        ganhou = 1;
      }
      if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
        cout << "\nParabens! O jogador 2 venceu!";
        ganhou = 1;
      }
    } while (ganhou == 0 && jogadas < 9);
    if (ganhou == 0)
      cout << "\nO jogo finalizou sem ganhador!";
    cout << "\nDigite 1 para jogar novamente: ";
    cin >> opcao;

  } while (opcao == 1);
  return 0;
}
