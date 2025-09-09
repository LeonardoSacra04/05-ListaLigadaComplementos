#include <iostream>
using namespace std;

// definição de tipo
struct NO 
{
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;
NO* ant = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
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
	ultimo = NULL;
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
	else 
	{
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

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* ExisteValor = posicaoElemento(novo->valor);
	if (ExisteValor != NULL)
	{
		cout << "O elemento ja existe" << endl;
		return;
	};

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
		ultimo->prox = NULL;
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;
	}
}

void excluirElemento()
{
	NO* atual = primeiro;
	NO* ant = NULL;
	int del;

	if (primeiro == NULL)
	{
		cout << "Sem elementos na lista" << endl;
		return;
	}

	cout << "Qual elemento vai ser deletado" << endl;
	cin >> del;
	NO* buscar = posicaoElemento(del);

	if (buscar == NULL)
	{
		cout << "Elemento nao existe na lista" << endl;
	}
	else
	{
		while (buscar != NULL)
		{
			if (del == atual->valor)
			{
				if (del == primeiro->valor)
				{
					primeiro = atual->prox;
				}
				else if (del == ultimo->valor)
				{
					ant->prox = NULL;
					ultimo = ant;

				}
				else
				{
					ant->prox = atual->prox;
				}
				free(atual);
				cout << "O elemento " << del << " foi deletado" << endl;
				break;
			}
			
			ant = atual;
			atual = atual->prox;
		}
	}
}

void buscarElemento()
{

}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) 
	{
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
