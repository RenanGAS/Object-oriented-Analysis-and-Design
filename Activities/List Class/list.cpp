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

public:

  Lista()
  {
    int qtde = 0;
    No *inicio = NULL;
    No *fim = NULL;
  }

  ~Lista()
  {
    int qtde = 0;
    No *inicio = NULL;
    No *fim = NULL;
    printf("\nLista destruída.\n");
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
    return pos > qtde || pos < 0 ? false : true;
  }

  bool posicaoPreenchida(int pos)
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

  No *enderecoNo(int pos)
  {
    No *aux = inicio;
    for (int cont = 0; cont < pos; cont++)
    {
      aux = aux->proximo;
    }
    return aux;
  }

  // Métodos principais

public:

  Lista *criar()
  {
    Lista *nova_lista = new Lista();

    if (!validacao(nova_lista))
    {
      printf("\nErro: Não foi possível criar a Lista.\n");
      return NULL;
    }

    printf("\nLista criada.\n");

    return nova_lista;
  }

  void destruir(Lista *l)
  {
    delete l;
  }

  bool anexar(Lista *l, TipoElemento elemento)
  {
    if (!validacao(l))
    {
      return false;
    }

    No *no = no->criar(elemento);

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

    printf("\nElemento %d anexado.\n", elemento);

    return true;
  }

  bool inserir(Lista *l, TipoElemento elemento, int posicao)
  {
    if (!validacao(l))
    {
      return false;
    }

    if (!posicaoValida(posicao))
    {
      return false;
    }

    No *novo = novo->criar(elemento);
    if (vazia())
    {
      inicio = fim = novo;
      qtde++;
    }
    else if (posicao == qtde)
    {
      anexar(l, elemento);
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

    printf("\nElemento %d inserido na posição %d.\n", elemento, posicao);

    return true;
  }

  bool removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
  {
    if (!validacao(l))
    {
      return false;
    }

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

  bool removerElemento(Lista *l, TipoElemento elemento)
  {
    if (!validacao(l))
    {
      return false;
    }

    int pos = posicao(l, elemento);
    if (pos == -1)
    {
      return false;
    }

    TipoElemento item;
    removerPosicao(l, pos, &item);

    printf("\nElemento %d removido.\n", item);

    return true;
  }

  bool substituir(Lista *l, int posicao, TipoElemento novoElemento)
  {
    if (!posicaoPreenchida(posicao))
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

  int posicao(Lista *l, TipoElemento elemento)
  {
    if (!validacao(l))
    {
      return -1;
    }

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

  bool buscar(Lista *l, int posicao, TipoElemento *endereco)
  {
    if (!validacao(l) || !posicaoValida(posicao))
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

  int tamanho(Lista *l)
  {
    if (!validacao(l))
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
    if (!validacao(l))
    {
      return false;
    }

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
  l->inserir(l, 35, 3);

  int elem = 30;
  int pos = l->posicao(l, elem);
  if (pos != -1)
  {
    printf("\nElemento %d na posição %d.\n", elem, pos);
  }
  else
  {
    printf("\nErro: Elemento não encontrado.\n");
  }

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

  l->removerPosicao(l, 1, &elem);

  if (l->toString(l, str))
  {
    printf("\nLista = %s\n", str);
  }
  else
  {
    printf("\nErro: Não foi possível imprimir a lista.\n");
  }

  l->removerElemento(l, 10);

  if (l->toString(l, str))
  {
    printf("\nLista = %s\n", str);
  }
  else
  {
    printf("\nErro: Não foi possível imprimir a lista.\n");
  }

  l->buscar(l, 2, &elem);

  l->destruir(l);

  return 0;
}