#include "ListaSequencial.h"
#include "ListaEncadeada.h"

int main()
{
  ListaSeq* listaSeq = criaListaSeq();
  ListaEnc* listaEnc = criaListaEnc();

  int option = -1;

  while (option <= -1) {

    cout << endl << "        " << "| Select one of the options below |" << endl << endl
      << "1.  Insert a Node in the beginning of the list" << endl
      << "2.  Insert a Node in the end of the list" << endl
      << "3.  Insert a Node in the position N of the list" << endl
      << "4.  Delete a Node in the beginning of the list" << endl
      << "5.  Delete a Node in the end of the list" << endl
      << "6.  Delete a Node in the position N of the list" << endl
      << "7.  Search a Node with a RG field" << endl
      << "8.  Show the list on screen" << endl
      << "9.  Save the list on file in format Name, RG" << endl
      << "10. Read the list of one file" << endl
      << "0.  EXIT" << endl;
 
    cin >> option;


    Cliente node;

    int pos = -1;

    if (option == 1 || option == 2 || option == 3) {
      string name;
      int RG;

      cout << "Name: ";
      cin >> name;
      cout << "RG: ";
      cin >> RG;
      
      node.nome = name;
      node.rg = RG;
    }

    if (option == 3 || option == 6) {
      cout << "Position: ";
      cin >> pos;
    }

    if (option == 7) { 
      cout << "RG: ";
      cin >> node.rg;
    }
  
    switch (option)
    {
    case 1:
      inserirNoInicioSeq(listaSeq, node);
      inserirNoInicioEnc(listaEnc, node);
      option = -1;
      break;
    case 2:
      inserirNoFimSeq(listaSeq, node, 1);
      inserirNoFimEnc(listaEnc, node, 1);
      option = -1;
      break;
    case 3:
      inserirNaPosNSeq(listaSeq, node, pos);
      inserirNaPosNEnc(listaEnc,  node, pos);
      option = -1;
      break;
    case 4:
      retirarNoInicioSeq(listaSeq);
      retirarNoInicioEnc(listaEnc);
      option = -1;
      break;
    case 5:
      retirarNoFimSeq(listaSeq);
      retirarNoFimEnc(listaEnc);
      option = -1;
      break;
    case 6:
      option = -1;
      retiraNaPosNSeq(listaSeq, pos);
      retiraNaPosNEnc(listaEnc, pos);
      break;
    case 7:
      searchForRgSec(listaSeq, node.rg);
      searchForRgEnc(listaEnc, node.rg);
      option = -1;
      break;
    case 8:
      mostraListaSeq(listaSeq);
      mostraListaEnc(listaEnc);
      option = -1;
      break;
    case 9:
      salvaListaSeq(listaSeq);
      salvaListaEnc(listaEnc);
      option = -1;
      break;
    case 10:
      lerListaSeq(listaSeq);
      lerListaEnc(listaEnc);
      option = -1;
      break;
    case 0:
      return 0;
    }
  }
}

