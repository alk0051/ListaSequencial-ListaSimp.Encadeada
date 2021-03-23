#pragma once
#include "stdafx.h"
#include "Clientes.h"

// Mudar o valor de max pra cada arquivo que for testado
#define MAX 1000100

typedef struct
{
  Cliente vetor[MAX];
  int nElem;

}ListaSeq;


ListaSeq* criaListaSeq();
void inserirNoInicioSeq(ListaSeq* lista, Cliente cliente);
void inserirNoFimSeq(ListaSeq* lista, Cliente cliente, int op);
void inserirNaPosNSeq(ListaSeq* lista, Cliente cliente, int pos);
void retirarNoInicioSeq(ListaSeq* lista);
void retirarNoFimSeq(ListaSeq* lista);
void retiraNaPosNSeq(ListaSeq* lista, int pos);
void searchForRgSec(ListaSeq* lista, int rg);
void mostraListaSeq(ListaSeq* lista);
void salvaListaSeq(ListaSeq* lista);
void lerListaSeq(ListaSeq* lista);
