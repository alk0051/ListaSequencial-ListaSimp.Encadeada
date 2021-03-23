#pragma once
#include "stdafx.h"
#include "ListaSequencial.h"
#include "Clientes.h"

struct ListaEnc {
  string nome;

  int rg;
  ListaEnc* pProx;
};

typedef struct ListaEnc ListaEnc;


ListaEnc* criaListaEnc();
void inserirNoInicioEnc(ListaEnc* lista, Cliente node);
void inserirNoFimEnc(ListaEnc* lista, Cliente node, int op);
void inserirNaPosNEnc(ListaEnc* lista, Cliente node, int pos);
void retirarNoInicioEnc(ListaEnc* lista);
void retirarNoFimEnc(ListaEnc* lista);
void retiraNaPosNEnc(ListaEnc* lista, int pos);
void searchForRgEnc(ListaEnc* lista, int rg);
void mostraListaEnc(ListaEnc* lista);
void salvaListaEnc(ListaEnc* lista);
void lerListaEnc(ListaEnc* lista);