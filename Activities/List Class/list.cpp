#include <iostream>
#include <cstring>
using namespace std;

#define TipoElemento int

class Lista
{
    struct No
    {
        TipoElemento valor;
        No *anterior;
        No *proximo;

        No *criar(TipoElemento elem)
        {
            No *novo_no = new No();
            novo_no->valor = elem;
            novo_no->anterior = NULL;
            novo_no->proximo = NULL;

            return novo_no;
        }
    };

    int qtde;
    No *inicio;
    No *fim;

    Lista()
    {
        int qtde = 0;
        No *inicio = NULL;
        No *fim = NULL;
    }

    // Métodos auxiliares

private:
    bool validacao(Lista *l)
    {
        return l != NULL ? true : false;
    }

    // Métodos principais

public:
    Lista *criar()
    {
        Lista *nova_lista = new Lista();

        return nova_lista;
    }

    void destruir(Lista **l);

    bool anexar(Lista *l, TipoElemento elemento)
    {
        if (!l->validacao(l))
        {
            return false;
        }

        No *no = no->criar(elemento);

        if (l->vazia(l))
        {
            l->inicio = no;
        }
        else
        {
            l->fim->proximo = no;
            no->anterior = l->fim;
        }

        l->fim = no;
        qtde++;

        return true;
    }

    bool inserir(Lista *l, TipoElemento elemento, int posicao);
    bool removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
    int removerElemento(Lista *l, TipoElemento elemento);
    bool substituir(Lista *l, int posicao, TipoElemento novoElemento);
    int posicao(Lista *l, TipoElemento elemento);
    bool buscar(Lista *l, int posicao, TipoElemento *endereco);
    int tamanho(Lista *l);

    bool vazia(Lista *l)
    {
        return qtde == 0 ? true : false;
    }
    bool toString(Lista *l, char *str)
    {
        char aux_char[100];

        str[0] = '\0';
        strcat(str, "[");

        for (No *aux = l->inicio; aux != NULL; aux = aux->proximo)
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
};

int main()
{
    Lista *l = l->criar();

    l->anexar(l, 10);
    l->anexar(l, 20);
    l->anexar(l, 30);
    l->anexar(l, 40);
    l->anexar(l, 50);

    char str[100];

    if (l->toString(l, str))
    {
        printf("\n%s\n\n", str);
    }
    else
    {
        printf("\nNão foi possível imprimir a lista.\n\n");
    }

    return 0;
}