#include <iostream>

using namespace std;

class No
{
	int num;
	char letra;
	No *prox;

	public:
		//Construtores
		//Vazio
		No()
		{
			num=0;
			letra=0;
			prox=NULL;
		}

		//Recebe inteiro como argumento
		No(int num)
		{
			this->num=num;
			letra=0;
			prox=NULL;
		}

		//Recebe char como argumento
		No(char letra)
		{
			num=0;
			this->letra=letra;
			prox=NULL;
		}

		//Recebe ambos como argumento
		No(int num, char letra)
		{
			this->num=num;
			this->letra=letra;
			prox=NULL;
		}

		//Métodos
		//gets e setters
		int getNum()
		{
			return num;
		}

		void setNum(int num)
		{
			this->num=num;
		}

		char getLetra()
		{
			return letra;
		}

		void setLetra(char letra)
		{
			this->letra=letra;
		}

		No* getProx()
		{
			return prox;
		}

		void setProx(No* prox)
		{
			this->prox=prox;
		}
};

class Pilha
{
	int tam;

	No* cauda;

	public:
		//Construtores
		//Pilha vazia
		Pilha()
		{
			cauda=NULL;
			tam=0;
		}

		//Recebe int como argumento
		Pilha(int num)
		{
			cauda=new No(num);
			tam=1;
		}

		//Recebe char como argumento
		Pilha(char letra)
		{
			cauda=new No(letra);
			tam=1;
		}

		//Recebe Nozinho como argumento
		Pilha(No* novo)
		{
			cauda=novo;
			tam=1;
		}

		//Métodos
		//Retorna o topo da lista
		No* getCauda()
		{
			return cauda;
		}

		//Retorna o tamanho
		int getSize()
		{
			return tam;
		}

		//Adiciona um elemento na pilha
		//Adicionando inteiro
		void pushPilha(int num)
		{
			No* aux;

			aux = cauda;
			cauda = new No(num);
			cauda->setProx(aux);
			tam++;
		}

		//Adicionando char
		void pushPilha(char letra)
		{
			No* aux;

			aux = cauda;
			cauda = new No(letra);
			cauda->setProx(aux);
			tam++;
		}

		//Adicionando ambos
		void pushPilha(int num, char letra)
		{
			No* aux;

			aux = cauda;
			cauda = new No(num, letra);
			cauda->setProx(aux);
			tam++;
		}

		//Adicionando Nozinho
		void pushPilha(No* novo)
		{
			No* aux;

			aux = cauda;
			cauda = novo;
			cauda->setProx(aux);
			tam++;
		}

		//Retirando elemento da pilha
		void popPilha()
		{
			No* aux;

			aux = cauda;
			cauda = cauda->getProx();
			aux->setProx(NULL);
			aux=NULL;
			tam--;
		}

		//Mostrar elementos da pilha
		void mostrarPilha()
		{
			Pilha aux;

			cout << "Imprimindo Elementos:\n";

			while((cauda!=NULL)&&(cauda->getNum()!=num))
			{
				cout << cauda->getNum() << endl;
				aux.pushPilha(cauda);
				popPilha();
			}
		}

		//Buscando elemento da pilha
		//Q2- Retorna a posição da pilha
		int topPilha(int num)
		{
			int pos=0;
			Pilha aux;

			while((cauda!=NULL)&&(cauda->getNum()!=num))
			{
				aux.pushPilha(cauda);
				popPilha();
				pos++;
			}

			if(cauda==NULL)
			{
				while(aux.getCauda()!=NULL)
				{
					pushPilha(aux.getCauda());
					aux.popPilha();
				}
			cout << "elemento nao encontrado\n";
			return -1;
			}else
			{
				while(aux.getCauda()!=NULL)
				{
					pushPilha(aux.getCauda());
					aux.popPilha();
				}
			cout << "elemento encontrado\n";
			return pos;
			}

		}
};

//Funcoes
//Q1 - Funcao que alterna pilhas em ordem crescente
Pilha alternar(Pilha p1, Pilha p2)
{
	Pilha p3;

	while((p1.getCauda()!=NULL) && (p2.getCauda()!=NULL))
	{
		if(p1.getCauda()->getNum()<p2.getCauda()->getNum())
		{
			p3.pushPilha(p1.getCauda()->getNum());
			p1.popPilha();
		}else
		{
			p3.pushPilha(p2.getCauda()->getNum());
			p2.popPilha();
		}
	}

	return p3;
}

int main()
{
	return 0;
}
