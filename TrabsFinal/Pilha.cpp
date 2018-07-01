#include <iostream>

using namespace std;

class No
{
	//Conteudo inteiro
	int num;
	//Nó apontando para o próximo da lista
	No *prox;
	
	public:
		//Construtores
		//Construtor inteiro
		No(int num)
		{
			this->num=num;
			prox=NULL;
		}
		
		//Métodos
		//Método para retorno de conteúdo da pilha
		int getNum()
		{
			return num;
		}
		
		//Retornar o próximo nó
		No* getProx()
		{
			return prox;
		}
		
		//Seta o próximo nó
		void setProx(No* prox)
		{
			this->prox=prox;
		}
};

class Pilha
{
	No* topo;
	
	public:
		//Construtores
		//Construtor vazio
		Pilha()
		{
			topo=NULL;
		}
		
		//Construtor inteiro
		Pilha(int num)
		{
			topo = new No(num);
		}
		
		//Métodos
		//Retorna o elemento do topo da pilha
		No* topPilha()
		{
			return topo;
		}
		
		//Remove o elemento do topo da pilha
		void popPilha()
		{
			No* deletado = topo;
			
			topo=topo->getProx();
			deletado->setProx(NULL);
			deletado=NULL;
		}
		
		//Adiciona o elemento ao topo da pilha
		void pushPilha(int num)
		{
			No* adicionado = new No(num);
			
			adicionado->setProx(topo);
			topo = adicionado;
		}
		
		//Verifica se a pilha está vazia
		void isEmpty()
		{
			if(topo==NULL)
				cout<<"Esta vazia\n";
			else
				cout<<"Contem elementos\n";
		}
		
		//Verifica se um número habita a pilha, 1 se ele está nela, e 0 se não
		int pilhaSearch(int num)
		{
			Pilha aux;
			while(topo!=NULL)
			{
				if(topo->getNum()==num)
				{
					while(aux.topPilha()!=NULL)
					{
						pushPilha(aux.topo->getNum());
						aux.popPilha();
					}
					return 1;
				}
				aux.pushPilha(topo->getNum());
				popPilha();
			}
			
			while(aux.topPilha()!=NULL)
			{
				pushPilha(aux.topo->getNum());
				aux.popPilha();
			}
			return 0;
		}
};

int main()
{
	Pilha p1(1);
	p1.pushPilha(2);
	if(p1.pilhaSearch(3))
		cout<<"Numero ta aqui\n";
	else
		cout<<"Numero n ta aqui\n";
}
