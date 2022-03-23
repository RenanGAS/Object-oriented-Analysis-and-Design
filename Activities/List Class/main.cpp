#include <iostream>
#include "classes.hpp"
using namespace std;

int main()
{
    Lista l;

    l.anexar(10);
    l.anexar(20);
    l.anexar(30);
    l.anexar(40);
    l.anexar(50);

    char str[100];

    if (l.toString(str))
    {
        printf("\nLista = %s\n", str);
    }
    else
    {
        printf("\nErro: Não foi possível imprimir a lista.\n");
    }

    l.substituir(4, 45);
    l.inserir(35, 3);

    int elem = 30;
    int pos = l.posicao(elem);
    if (pos != -1)
    {
        printf("\nElemento %d na posição %d.\n", elem, pos);
    }
    else
    {
        printf("\nErro: Elemento não encontrado.\n");
    }

    if (l.toString(str))
    {
        printf("\nLista = %s\n", str);
    }
    else
    {
        printf("\nErro: Não foi possível imprimir a lista.\n");
    }

    if (l.tamanho() == -1)
    {
        printf("\nErro: Lista inválida.\n");
    }
    else
    {
        printf("\nTamanho = %d\n", l.tamanho());
    }

    l.removerPosicao(1, &elem);

    if (l.toString(str))
    {
        printf("\nLista = %s\n", str);
    }
    else
    {
        printf("\nErro: Não foi possível imprimir a lista.\n");
    }

    l.removerElemento(10);

    if (l.toString(str))
    {
        printf("\nLista = %s\n", str);
    }
    else
    {
        printf("\nErro: Não foi possível imprimir a lista.\n");
    }

    l.buscar(2, &elem);

    l.destruir();

    return 0;
}