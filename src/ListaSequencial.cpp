#include "ListaSequencial.h"
#pragma warning(disable : 4996)

ListaSeq* criaListaSeq()
{
  //ListaSeq* lista = (ListaSeq*) malloc(sizeof(ListaSeq));
  ListaSeq* lista = new ListaSeq;
  if (lista) {
    lista->nElem = 0;
  }
  else {
    cout << "Failed to create list";
    return 0;
  }

  return lista;
}


void inserirNoInicioSeq(ListaSeq* lista, Cliente cliente)
{
  lista->nElem++;
  int i, M = 0;
  clock_t t = clock();


  for (i = lista->nElem; i > 1; i--)
  {
    lista->vetor[i - 1] = lista->vetor[i - 2]; M++;
  }

  lista->vetor[0] = cliente; M++;

  t = (clock() - t / (float)CLOCKS_PER_SEC);

  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << cliente.nome << "\n" <<  "RG: " << cliente.rg << "\n" <<  "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: 1" << endl;
}

void inserirNoFimSeq(ListaSeq* lista, Cliente cliente, int op) 
{
  int i, M = 0, C = 0;
  clock_t t = clock();
  
  C++;

  if (lista->nElem != 0) {
    lista->nElem++;
    for (i = lista->nElem; i >= lista->nElem; i--)
    {
      lista->vetor[i - 1] = lista->vetor[i - 2]; M++;
    }
    lista->vetor[lista->nElem - 1] = cliente; M++;

    t = (clock() - t / (float)CLOCKS_PER_SEC);

    if (op == 1) {
      cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << cliente.nome << "\n" << "RG: " << cliente.rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << lista->nElem << endl;
    }
  }
  else {
    inserirNoInicioSeq(lista, cliente);
  }
}

void inserirNaPosNSeq(ListaSeq* lista, Cliente cliente, int pos)
{
  lista->nElem++;
  int i, M = 0, C = 0;
  clock_t t = clock();

  if (pos > (lista->nElem - 1) || pos < 0) {
    cout << "Posicao invalida" << endl; 
  }
  C++;
  for (i = lista->nElem; i > pos; i--)
  {
    lista->vetor[lista->nElem - 1] = lista->vetor[lista->nElem - 2]; M++;
  }
  lista->vetor[pos - 1] = cliente; M++;

  t = (clock() - t / (float)CLOCKS_PER_SEC);

  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << cliente.nome << "\n" << "RG: " << cliente.rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << pos << endl;
}

void retirarNoInicioSeq(ListaSeq* lista)
{
  string nome = lista->vetor[0].nome;
  int rg = lista->vetor[0].rg;

  int i, M = 0;
  clock_t t = clock();

  for (i = 0; i < lista->nElem - 1; i++)
  {
    lista->vetor[i] = lista->vetor[i + 1]; M++;
  }

  lista->vetor[lista->nElem].rg = NULL; M++;
  lista->nElem--; M++;

  t = (clock() - t / (float)CLOCKS_PER_SEC);

  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: 1" << endl;
}

void retirarNoFimSeq(ListaSeq* lista)
{
  int M = 0;
  clock_t t = clock();

  lista->vetor[lista->nElem].rg = NULL; M++;
  lista->nElem--; M++;
  
  t = (clock() - t / (float)CLOCKS_PER_SEC);

  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << lista->vetor[lista->nElem].nome << "\n" << "RG: " << lista->vetor[lista->nElem].rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << lista->nElem + 1 << endl;
}

void retiraNaPosNSeq(ListaSeq* lista, int pos)
{
  string nome = lista->vetor[pos - 1].nome;
  int rg = lista->vetor[pos - 1].rg;

  int i, M = 0, C = 0;

  clock_t t = clock();

  if (pos > (lista->nElem - 1)) {
    cout << "Posicao invalida" << endl; 
  }
  C++;
  for (i = pos - 1; i < lista->nElem; i++)
  {
    lista->vetor[i] = lista->vetor[i + 1]; M++;
  }

  lista->vetor[lista->nElem].rg = NULL; M++;
  lista->nElem--; M++;

  t = (clock() - t / (float)CLOCKS_PER_SEC);

  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << pos << endl;
}

void searchForRgSec(ListaSeq* lista, int rg)
{
  int i = 0, M = 0, C = 0;
  //Cliente* node = (Cliente*)malloc(sizeof(Cliente));
  Cliente* node = new Cliente;

  clock_t t = clock(); 

  while (node->rg != rg) {
    *node = lista->vetor[i]; M++;
    i++;
  }

  t = (clock() - t / (float)CLOCKS_PER_SEC);
  
  cout << "\n" << "     Lista Sequencial" << "\n" << "Nome: " << node->nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << i << endl;
}

void mostraListaSeq(ListaSeq* lista)
{
  int i;

  for (i = 0; i < lista->nElem; i++)
  {
    cout << "Nome: " << lista->vetor[i].nome << " RG: " << lista->vetor[i].rg  << endl;
  }
}

void salvaListaSeq(ListaSeq* lista)
{
  ofstream myFile("ClientesSeq.txt");
  if (myFile.is_open())
  {
    for (int i = 0; i < lista->nElem; i++)
    {
      myFile << lista->vetor[i].nome << " ";
      myFile << lista->vetor[i].rg << endl;
    }
  }
  else {
    cout << "Failed to open file!";
  }
}

void lerListaSeq(ListaSeq* lista)
{
  string line;
  // Colocar aqui o nome do arquivo que sera testado
  ifstream myfile("NomeRG1M.txt");

  Cliente node;

  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      int indexRG = line.find(",");
      int tam = line.length();

      string rgString = line.substr(indexRG + 1, tam);
      string nameString = line.substr(0, indexRG);

      int rg = stoi(rgString);
      node.nome = nameString;
      node.rg = rg;

      inserirNoFimSeq(lista, node, 0);
    }

    myfile.close();
  }

  else cout << "Unable to open file";
}

