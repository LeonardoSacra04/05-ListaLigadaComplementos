#include <iostream>
using namespace std;

// definicao de tipo
struct NO 
{
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) 
	{
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
			case 1: inicializar();
				break;
			case 2: exibirQuantidadeElementos();
				break;
			case 3: exibirElementos();
				break;
			case 4: buscarElemento();
				break;
			case 5: inserirElemento();
				break;
			case 6: excluirElemento();
				break;
			case 7:
				return;
			default:
				break;
		}
		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) 
	{
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}
	primeiro = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() 
{
	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) 
	{
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (primeiro == NULL) 
	{
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) 
		{
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	int ExisteValor = posicaoElemento(novo->valor);
	if (ExisteValor != NULL)
	{
		cout << "O elemento ja existe" << endl;
		free(novo);
		return;
	};

	if (primeiro == NULL)
	{
		primeiro = novo;
		cout << "O elemento foi adicionado na primeira posicao" << endl;
	}
	else
	{
		while (atual != NULL)
		{
			if (primeiro->valor > novo->valor)
			{
				primeiro = novo;
				primeiro->prox = atual;
				cout << "O elemento foi adicionado na primeira posicao" << endl;
				return;
			}
			else if (atual->valor > novo->valor)
			{
				anterior->prox = novo;
				novo->prox = atual;
				int pos = posicaoElemento(novo->valor); //indica em qual posição o elemento foi inserido de forma mais fácil ao usuário
				cout << "O elemento foi adicionado na posicao " << pos << endl;
				return;
			}
			else if (atual->prox == NULL)
			{
				atual->prox = novo;
				cout << "O elemento foi adicionado na ultima posicao" << endl;
				return;
			}
			anterior = atual;
			atual = atual->prox;
		}
	}
}

void excluirElemento()
{
	//alterações feitas no posicaoElemento para otimização

	if (primeiro == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	int del;
	cout << "Digite o elemento a ser deletado: " << endl;
	cin >> del;
	int delExiste = posicaoElemento(del);

	if (delExiste == NULL)
	{
		cout << "Elemento nao existe" << endl;
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL)
	{
		if (atual->valor == del)
		{
			if (del == primeiro->valor)
			{
				primeiro = atual->prox;
			}
			else
			{
				anterior->prox = atual->prox;
			}
			free(atual);
			cout << "O elemento " << del << " foi deletado com sucesso!" << endl;
			break;
		}
		anterior = atual;
		atual = atual->prox;
	}
}

void buscarElemento()
{
	// alterações feitas no posicaoElemento para otimização

	if (primeiro == NULL)
	{
		cout << "Lista vazia" << endl;
		return;
	}

	NO* aux = primeiro;
	int busca;

	cout << "Digite o elemento a ser encontrado: " << endl;
	cin >> busca;
	int pos = posicaoElemento(busca);

	if (pos == NULL)
	{
		cout << "Elemento nao encontrado" << endl;
		return;
	}
	else
	{
		cout << "Elemento encontrado na posicao " << pos << endl;
	}
}

int posicaoElemento(int numero)
{
	NO* aux = primeiro;
	int contador = 1; // indica a posição de forma mais clara ao usuário

	while (aux != NULL)
	{
		if (aux->valor == numero) // verifica se o elemento existe nessa posição
		{
			return contador;
		}
		else if (aux->valor > numero) // caso o elemento seja menor que o valor da atual posição, ele retorna o valor nulo
		{
			return NULL;
		}
		contador++;
		aux = aux->prox;
	}
	return NULL;
}
