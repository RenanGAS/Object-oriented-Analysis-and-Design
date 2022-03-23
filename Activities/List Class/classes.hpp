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
private:

    int qtde;
    No *inicio;
    No *fim;

    bool posicaoValida(int pos);

    bool posicaoPreenchida(int pos);

    No *enderecoNo(int pos);

public:

    Lista();
    ~Lista();
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
