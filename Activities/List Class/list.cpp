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
        if (l == NULL)
        {
            printf("\nErro: Lista inválida.\n");
            return false;
        }

        return true;
    }

    bool posicaoValida(int pos)
    {
        return pos >= qtde || pos < 0 ? false : true;
    }

    // Métodos principais

public:
    Lista *criar()
    {
        Lista *nova_lista = new Lista();

        if (!nova_lista->validacao(nova_lista))
        {
            printf("\nErro: Não foi possível criar a Lista.\n");
            return NULL;
        }

        printf("\nLista criada.\n");

        return nova_lista;
    }

    void destruir()
    {
        delete this;
        qtde = 0;
        inicio = NULL;
        fim = NULL;

        printf("\nLista destruída.\n");
    }

    bool anexar(Lista *l, TipoElemento elemento)
    {
        if (!l->validacao(l))
        {
            return false;
        }

        No *no = no->criar(elemento);

        if (l->vazia())
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

        printf("\nElemento %d anexado.\n", elemento);

        return true;
    }

    bool inserir(Lista *l, TipoElemento elemento, int posicao)
    {
        // int i = 0;

        // for (No *aux = l->inicio; aux != NULL; aux = aux->proximo)
        // {
        //     if (i == posicao)
        //     {
        //         aux->valor = elemento;
        //     }

        //     i++;
        // }

        // printf("\nElemento %d foi inserido com sucesso.\n", elemento);

        return true;
    }

    bool removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
    int removerElemento(Lista *l, TipoElemento elemento);

    bool substituir(Lista *l, int posicao, TipoElemento novoElemento)
    {
        if (!l->posicaoValida(posicao))
        {
            return false;
        }

        int i = 0;

        for (No *aux = l->inicio; aux != NULL; aux = aux->proximo)
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

    bool posicao(Lista *l, TipoElemento elemento)
    {
        if (!l->validacao(l))
        {
            return -1;
        }

        int i = 0;

        for (No *aux = l->inicio; aux != NULL; aux = aux->proximo)
        {
            if (aux->valor == elemento)
            {
                printf("\nElemento %d na posição %d.\n", elemento, i);
                return true;
            }

            i++;
        }

        printf("\nErro: Elemento não encontrado.\n");
        return false;
    }

    bool buscar(Lista *l, int posicao, TipoElemento *endereco)
    {
        if (!l->validacao(l) || !l->posicaoValida(posicao))
        {
            printf("\nErro: Dados inválidos.\n");
            return false;
        }

        int i = 0;

        for (No *aux = l->inicio; aux != NULL; aux = aux->proximo)
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

    int tamanho(Lista *l)
    {
        if (!l->validacao(l))
        {
            return -1;
        }

        return qtde;
    }

    bool vazia()
    {
        return qtde == 0 ? true : false;
    }

    bool toString(Lista *l, char *str)
    {
        if (!l->validacao(l))
        {
            return false;
        }

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
    l->substituir(l, 4, 45);

    l->posicao(l, 30);

    char str[100];

    if (l->toString(l, str))
    {
        printf("\nLista = %s\n", str);
    }
    else
    {
        printf("\nErro: Não foi possível imprimir a lista.\n");
    }

    if (l->tamanho(l) == -1)
    {
        printf("\nErro: Lista inválida.\n");
    }
    else
    {
        printf("\nTamanho = %d\n", l->tamanho(l));
    }

    int elem;

    l->buscar(l, 4, &elem);

    l->destruir();

    return 0;
}