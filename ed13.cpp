#include <iostream>

using namespace std;

//Nozinho

class No
{
	int num;
	char letra;
	No *prox;
	
	public:
		//Construtor
		No(int num)
		{
			this->num=num;
			this->prox=NULL;
		}
		
		No(char letra)
		{
			this->letra=letra;
			this->prox=NULL;
		}
		
		//Métodos
		int getNum()
		{
			return num;
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

//Filinha

class Fila
{
	No* cabeca;
	No* cauda;
	
	int tam;
	
	public:
		//Construtores
		//Fila vazia
		Fila()
		{
			cabeca=NULL;
			cauda=NULL;
			tam=0;
		}
		
		//Passando argumento
		Fila(int num)
		{
			cabeca = new No(num);
			cauda = cabeca;
			tam=1;
		}
		
		//Passando um nozinho
		Fila(No* novo)
		{
			cabeca = novo;
			cauda = cabeca;
			tam=1;
		}
		
		//Metodos
		//Retorna do tamanho da fila
		int getSize()
		{
			return tam;
		}
		
		//Exibe os elementos da fila
		void mostrar()
		{
			No* aux = cabeca;
			
			if(aux==NULL)
			{
				cout << "Lista vazia\n";
			}else
			{
				while(aux!=NULL)
				{
					cout << "Elementos da fila:\n";
					cout << aux->getNum() << endl;
					aux=aux->getProx();
				}
			}
			
		}
		
		//Adiciona char na fila
		void naFila(char letra)
		{
			No* aux1 = 
		}
}

//Listinha

class Pilha
{
	No* cauda;
	
	int tam;
	
	public:
		//Construtores
		//Pilha vazia
		Pilha()
		{
			cauda=NULL;
			tam=0;
		}
		
		//Passando argumento
		Pilha(int num)
		{
			cauda = new No(num);
			tam=1;
		}
		
		//Passando um nozinho
		Pilha(No* novo)
		{
			cauda=novo;
			tam=1;
		}
		
		//Métodos
		//Retorna o comeco da pilha
		No* getCauda()
		{
			return cauda;
		}
		
		//Retorna o tamanho da pilha
		int getSize()
		{
			return tam;
		}
		
		//Exibir elementos da pilha
		void mostrar()
		{
			No* mostrar=cauda;
			
			if(mostrar==NULL)
			{
				cout << "Lista vazia\n";
			}else
			{
				while(mostrar!=NULL)
				{
					cout << "Exibindo elementos:\n";
					cout << mostrar->getNum() << endl;
					mostrar = mostrar->getProx();
				}
			}
		}
		
		//Insere no comeco da pilha, vulgo Push
		//Insere Nozinho
		void PushPilha(No* novo)
		{
			No* aux=cauda;
			
			cauda=novo;
			novo->setProx(aux);
			tam++;
		}
		
		//Insere conteudo
		void PushPilha(int num)
		{
			No* aux1 = new No(num);
			No* aux2 = cauda;
			
			cauda = aux1;
			aux1->setProx(aux2);
			tam++;
		}
		
		//Questoes:
		//Q2 - Metodo que verifica se algo esta na pilha e retorna
		//Done
		int verificaPilha(int item)
		{
			No* aux = cauda;
			int pos=1;
			
			while((aux!=NULL) && (aux->getNum()!=item))
			{
				aux = aux->getProx();
				pos++;
			}
			if(aux==NULL)
			{
				cout << "Num ta na pilha nao parca\n";
				return -1;
			}else
			{
				cout << "Ta na pilha parceiro\n";
				return pos;
			}
		}
};

//Funcoes
//Q1 - Funcao que alterna pilhas em ordem crescente
//NaoDone
Pilha alternar(Pilha p1, Pilha p2)
{
	Pilha p3;
	
	No* aux1=p1.getCauda();
	No* aux2=p2.getCauda();
	
	while((aux1!=NULL) && (aux2!=NULL))
	{
		if(aux1->getNum()<aux2->getNum())
		{
			cout << "aux1: " << aux1 << endl;
			p3.PushPilha(aux1);
			aux1=aux1->getProx();
			cout << "aux1: " << aux1 << endl;
		}else
		{
			p3.PushPilha(aux2);
			aux2=aux2->getProx();
		}
	}
	
	p3.mostrar();
	return p3;
}

//Main

int main()
{
	Pilha p1(3);
	Pilha p2(4);
	Fila f1();
	
	p1.PushPilha(1);
	p2.PushPilha(2);
	
	p1.PushPilha(-1);
	p2.PushPilha(0);
	
	//alternar(p1, p2);
	//cout << p1.verificaPilha(3) << endl;
}