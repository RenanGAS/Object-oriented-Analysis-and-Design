#include <iostream>
#include <cstring>
#include "classes.hpp"
using namespace std;


No::No(TipoElemento elem)
{
    valor = elem;
    anterior = NULL;
    proximo = NULL;
}

Lista::Lista()
{
    int qtde = 0;
    No *inicio = NULL;
    No *fim = NULL;
    cout << "\nLista criada.\n";
}

Lista::~Lista()
{
    int qtde = 0;
    No *inicio = NULL;
    No *fim = NULL;
    cout << "\nLista destruída.\n";
}

// Métodos secundários

bool Lista::posicaoValida(int pos)
{
    return pos > qtde || pos < 0 ? false : true;
}

bool Lista::posicaoPreenchida(int pos)
{
    if (pos < 0)
    {
        return false;
    }

    if (pos >= qtde)
    {
        return false;
    }

    return true;
}

No *Lista::enderecoNo(int pos)
{
    No *aux = inicio;
    for (int cont = 0; cont < pos; cont++)
    {
        aux = aux->proximo;
    }
    return aux;
}

// Métodos principais

void Lista::destruir()
{
    delete this;
}

bool Lista::anexar(TipoElemento elemento)
{
    No no(elemento);

    if (vazia())
    {
        inicio = &no;
        printf("\na\n");
    }
    else
    {
        fim->proximo = &no;
        (&no)->anterior = fim;
        printf("\n%d\n", fim->valor);
    }
    printf("\n%d\n", inicio->valor);
    fim = &no;

    qtde++;

    printf("\nElemento %d anexado.\n", elemento);

    return true;
}

bool Lista::inserir(TipoElemento elemento, int posicao)
{
    if (!posicaoValida(posicao))
    {
        return false;
    }

    No novo(elemento);

    if (vazia())
    {
        inicio = fim = &novo;
        qtde++;
    }
    else if (posicao == qtde)
    {
        anexar(elemento);
    }
    else if (posicao == 0)
    {
        (&novo)->proximo = inicio;
        inicio->anterior = &novo;
        inicio = &novo;
        qtde++;
    }
    else
    {
        No *aux = enderecoNo(posicao - 1);

        (&novo)->proximo = aux->proximo;
        (&novo)->anterior = aux;
        (&novo)->proximo->anterior = (&novo);
        aux->proximo = (&novo);
    }

    printf("\nElemento %d inserido na posição %d.\n", elemento, posicao);

    return true;
}

bool Lista::removerPosicao(int posicao, TipoElemento *endereco)
{
    if (vazia())
    {
        return false;
    }

    if (!posicaoPreenchida(posicao))
    {
        return false;
    }

    No *aux;

    if (qtde == 1)
    {
        aux = inicio;
        inicio = fim = NULL;
    }
    else if (posicao == 0)
    {
        aux = inicio;
        inicio = inicio->proximo;
        inicio->anterior = NULL;
        aux->proximo = NULL;
    }
    else if (posicao == qtde - 1)
    {
        aux = fim;
        fim = fim->anterior;
        fim->proximo = NULL;
        aux->anterior = NULL;
    }
    else
    {
        aux = enderecoNo(posicao);
        aux->proximo->anterior = aux->anterior;
        aux->anterior->proximo = aux->proximo;
        aux->proximo = NULL;
        aux->anterior = NULL;
    }

    *endereco = aux->valor;
    delete aux;
    qtde--;

    printf("\nPosição %d removida.\n", posicao);

    return true;
}

bool Lista::removerElemento(TipoElemento elemento)
{
    int pos = posicao(elemento);
    if (pos == -1)
    {
        return false;
    }

    TipoElemento item;
    removerPosicao(pos, &item);

    printf("\nElemento %d removido.\n", item);

    return true;
}

bool Lista::substituir(int posicao, TipoElemento novoElemento)
{
    if (!posicaoPreenchida(posicao))
    {
        return false;
    }

    int i = 0;

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        if (i == posicao)
        {
            aux->valor = novoElemento;
        }

        i++;
    }

    printf("\nSubstituição na posição %d por %d.\n", posicao, novoElemento);

    return true;
}

int Lista::posicao(TipoElemento elemento)
{
    int i = 0;

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        if (aux->valor == elemento)
        {
            return i;
        }

        i++;
    }

    return -1;
}

bool Lista::buscar(int posicao, TipoElemento *endereco)
{
    if (!posicaoValida(posicao))
    {
        printf("\nErro: Dados inválidos.\n");
        return false;
    }

    int i = 0;

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        if (i == posicao)
        {
            *endereco = aux->valor;
            printf("\nA posição %d contém o elemento %d.\n", i, *endereco);
            return true;
        }

        i++;
    }

    return false;
}

int Lista::tamanho()
{
    return qtde;
}

bool Lista::vazia()
{
    return qtde == 0 ? true : false;
}

bool Lista::toString(char *str)
{
    char aux_char[100];

    str[0] = '\0';
    strcat(str, "[");
    printf("\nqtde: %d\n", qtde);
    printf("\ninicio: %d\n", inicio->valor);

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        sprintf(aux_char, "%d", aux->valor);
        strcat(str, aux_char);

        if (aux->proximo != NULL)
        {
            strcat(str, ", ");
        }
    }
    printf("\nC\n");
    strcat(str, "]");

    return true;
}