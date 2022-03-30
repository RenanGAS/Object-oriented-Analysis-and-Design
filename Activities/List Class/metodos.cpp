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
    qtde = 0;
    inicio = NULL;
    fim = NULL;
    cout << "\nLista criada.\n";
}

Lista::~Lista()
{
    qtde = 0;
    inicio = NULL;
    fim = NULL;
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

void myLista::destruir()
{
    free(this->inicio);
    free(this->fim);
}

bool myLista::anexar(TipoElemento elemento)
{
    No *no = new No(elemento);

    if (vazia())
    {
        inicio = no;
    }
    else
    {
        fim->proximo = no;
        no->anterior = fim;
    }
    
    fim = no;

    qtde++;

    cout << "\nElemento " << elemento << " anexado.\n" ;

    return true;
}

bool myLista::inserir(TipoElemento elemento, int posicao)
{
    if (!posicaoValida(posicao))
    {
        return false;
    }

    No *novo = new No(elemento);

    if (vazia())
    {
        inicio = fim = novo;
        qtde++;
    }
    else if (posicao == qtde)
    {
        anexar(elemento);
    }
    else if (posicao == 0)
    {
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
        qtde++;
    }
    else
    {
        No *aux = enderecoNo(posicao - 1);

        novo->proximo = aux->proximo;
        novo->anterior = aux;
        novo->proximo->anterior = novo;
        aux->proximo = novo;
    }

    cout << "\nElemento " << elemento << " inserido na posição " << posicao << ".\n";

    return true;
}

bool myLista::removerPosicao(int posicao, TipoElemento *endereco)
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

    cout << "\nPosição " << posicao << " removida.\n" ;

    return true;
}

bool myLista::removerElemento(TipoElemento elemento)
{
    int pos = posicao(elemento);
    if (pos == -1)
    {
        return false;
    }

    TipoElemento item;
    removerPosicao(pos, &item);

    cout << "\nElemento " << item << " removido.\n";

    return true;
}

bool myLista::substituir(int posicao, TipoElemento novoElemento)
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

    cout << "\nSubstituição na posição " << posicao << " por " << novoElemento << ".\n";

    return true;
}

int myLista::posicao(TipoElemento elemento)
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

bool myLista::buscar(int posicao, TipoElemento *endereco)
{
    if (!posicaoValida(posicao))
    {
        cout << "\nErro: Dados inválidos.\n";
        return false;
    }

    int i = 0;

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        if (i == posicao)
        {
            *endereco = aux->valor;
            cout << "\nA posição " << i << " contém o elemento " << *endereco << ".\n";
            return true;
        }

        i++;
    }

    return false;
}

int myLista::tamanho()
{
    return qtde;
}

bool myLista::vazia()
{
    return qtde == 0 ? true : false;
}

bool myLista::toString(char *str)
{
    char aux_char[100];

    str[0] = '\0';
    strcat(str, "[");

    for (No *aux = inicio; aux != NULL; aux = aux->proximo)
    {
        sprintf(aux_char, "%d", aux->valor);
        strcat(str, aux_char);

        if (aux->proximo != NULL)
        {
            strcat(str, ", ");
        }
    }

    strcat(str, "]");

    return true;
}