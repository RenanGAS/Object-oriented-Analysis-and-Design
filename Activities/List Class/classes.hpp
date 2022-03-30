#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#define TipoElemento int

class No
{
public:
    TipoElemento valor;
    No *anterior;
    No *proximo;

    No(TipoElemento elem);
};

class Lista
{
protected:
    int qtde;
    No *inicio;
    No *fim;

    bool posicaoValida(int pos);

    bool posicaoPreenchida(int pos);

    No *enderecoNo(int pos);

public:
    Lista();
    ~Lista();
    void virtual destruir() = 0;
    bool virtual anexar(TipoElemento elemento) = 0;
    bool virtual inserir(TipoElemento elemento, int posicao) = 0;
    bool virtual removerPosicao(int posicao, TipoElemento *endereco) = 0;
    bool virtual removerElemento(TipoElemento elemento) = 0;
    bool virtual substituir(int posicao, TipoElemento novoElemento) = 0;
    int virtual posicao(TipoElemento elemento) = 0;
    bool virtual buscar(int posicao, TipoElemento *endereco) = 0;
    int virtual tamanho() = 0;
    bool virtual vazia() = 0;
    bool virtual toString(char *str) = 0;
};

class myLista : public Lista
{
public:
    void destruir();
    bool anexar(TipoElemento elemento);
    bool inserir(TipoElemento elemento, int posicao);
    bool removerPosicao(int posicao, TipoElemento *endereco);
    bool removerElemento(TipoElemento elemento);
    bool substituir(int posicao, TipoElemento novoElemento);
    int posicao(TipoElemento elemento);
    bool buscar(int posicao, TipoElemento *endereco);
    int tamanho();
    bool vazia();
    bool toString(char *str);
};

#endif
