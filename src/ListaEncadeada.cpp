#include "ListaEncadeada.h"

ListaEnc* criaListaEnc()
{
	ListaEnc* firstNode = (ListaEnc*)malloc(sizeof(ListaEnc));
	if (firstNode) {
		firstNode->rg = -1;
		firstNode->pProx = NULL;
	}
	else {
		cout << "Failed to create list" << endl;
		return 0;
	}
	
	return firstNode;
}

void inserirNoInicioEnc(ListaEnc* lista, Cliente node)
{
	int C = 0, M = 0;
	clock_t t = clock();

	//ListaEnc* newNode = (ListaEnc*)malloc(sizeof(ListaEnc));
	ListaEnc* newNode = new ListaEnc;	

	newNode->nome = node.nome; M++;
	newNode->rg = node.rg; M++;

	newNode->pProx = lista->pProx; M++;
	lista->pProx = newNode; M++;

	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << node.nome << "\n" << "RG: " << node.rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: 1" << endl;
}

void inserirNoFimEnc(ListaEnc* lista, Cliente node, int op)
{
	int C = 0, M = 0, i = 0;

	clock_t t = clock();

	C++;
	if (lista->pProx != NULL) {
		//ListaEnc* newNode = (ListaEnc*)malloc(sizeof(ListaEnc));
		ListaEnc* newNode = new ListaEnc;
		newNode->nome = node.nome; M++;
		newNode->rg = node.rg; M++;
		newNode->pProx = NULL; M++;

		while (lista->pProx != NULL) {
			lista = lista->pProx; M++;
			i++;
		}
		if (lista->pProx == NULL) {
			lista->pProx = newNode; M++;
			i++;
		}
		C++;
	}
	

	else {
		inserirNoInicioEnc(lista, node);
	}

  t = (clock() - t / (float)CLOCKS_PER_SEC);
	
	if (op == 1) {
		cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << node.nome << "\n" << "RG: " << node.rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: "<< C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << i << endl;
	}
}

void inserirNaPosNEnc(ListaEnc* lista, Cliente node, int pos)
{
	int i = 0, C = 0, M = 0;

	clock_t t = clock();

	//ListaEnc* newNode = (ListaEnc*)malloc(sizeof(ListaEnc));
	ListaEnc* newNode = new ListaEnc; M++;
	newNode->nome = node.nome; M++;
	newNode->rg = node.rg; M++;
	newNode->pProx = NULL; M++;

	if (pos == 0) {
		inserirNoInicioEnc(lista, node);
		return;
	}
	C++;
	if (pos < 1) {
		cout << "Invalid Position!" << endl; C++;
		return;
	}
	C++;

	ListaEnc* aux = lista; M++;

	while (i < pos - 1) {
		lista = lista->pProx; M++;
		i++;
	}
	aux = lista->pProx; M++;
	lista->pProx = newNode; M++;
	newNode->pProx = aux; M++;

	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << node.nome << "\n" << "RG: " << node.rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << pos << endl;
}

void retirarNoInicioEnc(ListaEnc* lista)
{
	string nome = lista->pProx->nome;
	int rg = lista->pProx->rg;

	int M = 0;

	clock_t t = clock();

	ListaEnc* aux = lista->pProx; M++;

	lista->pProx = aux->pProx; M++;
	free(aux);

	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: 1" << endl;
}

void retirarNoFimEnc(ListaEnc* lista)
{
	int M = 0, i = 0;

	clock_t t = clock();

	ListaEnc* aux1 = lista; M++;
	ListaEnc* aux2 = lista; M++;

	while (aux1->pProx != NULL) {
		aux2 = aux1; M++;
		aux1 = aux1->pProx; M++;
		i++;
	}

	string nome = aux2->pProx->nome;
	int rg = aux2->pProx->rg;
 
	aux2->pProx = NULL; M++;
	free(aux1);

	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << i + 1 << endl;
}

void retiraNaPosNEnc(ListaEnc* lista, int pos)
{
	int M = 0, C = 0;

	clock_t t = clock();

	if (pos <= 0) {
		cout << "Invalid position!" << endl;
		return;
	}
	C++;
	if (pos == 1) {
		retirarNoInicioEnc(lista);
		return;
	}
	C++;

	ListaEnc *aux1 = NULL, *aux2 = NULL;

	for (int i = 0; i < pos; i++) {
		if (lista->pProx == NULL) {
			retirarNoFimEnc(lista);
			return;
		}
		C++;
		aux1 = lista; M++;
		lista = lista->pProx; M++;
	}

	aux2 = lista->pProx; M++;

	string nome = lista->nome;
	int rg = lista->rg;

	free(lista);
	aux1->pProx = aux2; M++;


	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: " << C << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << pos << endl;
}
	
void searchForRgEnc(ListaEnc* lista, int rg)
{
	int M = 0, i = 0;

	clock_t t = clock();

	while (lista->rg != rg) {	
		lista = lista->pProx;	M++;
		i++;
	}

	t = (clock() - t / (float)CLOCKS_PER_SEC);

	cout << "\n" << "     Lista Encadeada" << "\n" << "Nome: " << lista->nome << "\n" << "RG: " << rg << "\n" << "Movimentacoes: " << M << "\n" << "Comparacoes: 0" << "\n" << "Tempo de execucao: " << t << "ms" << "\n" << "Posicao: " << i << endl;
}

void mostraListaEnc(ListaEnc* lista)
{
	while (lista->pProx != NULL) {
		cout << "Nome: " << lista->pProx->nome << " RG: " << lista->pProx->rg << endl;
		lista = lista->pProx;
	}
}

void salvaListaEnc(ListaEnc* lista)
{
  ofstream myFile("ClientesEnc.txt");
  if (myFile.is_open())
  {
		while (lista->pProx != NULL) {
			myFile << lista->pProx->nome << " ";
			myFile << lista->pProx->rg << endl;
			
			lista = lista->pProx;
		}
  }
  else {
    cout << "Failed to open file!";
  }
}

void lerListaEnc(ListaEnc* lista)
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

			inserirNoFimEnc(lista, node, 0);
		}

		myfile.close();
	}

	else cout << "Unable to open file";
}
