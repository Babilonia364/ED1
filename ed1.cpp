#include <iostream>

using namespace std;

//Criando um no

class No
{
		int num;
		No *prox;
	public:
		//Construtor
		No(int num)
		{
			this->num=num;
			this->prox=NULL;
		}
		
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

//Criando a Lista

class Lista
{
		No* cabeca;
		No* cauda;
	public:
		//Construtores, default e outros
		Lista()
		{
			cabeca=NULL;
			cauda=NULL;
		}
		
		Lista(int num)
		{
			cabeca=new No(num);
			cauda=cabeca;
		}
		
		Lista(No* a)
		{
			cabeca=a;
			cauda=cabeca;
		}
		
		//Funcoes
		bool vazia() {return (cabeca==NULL);}
		
		void mostrar()
		{
			No* b = cabeca;
			
			cout << "\nImprimindo elementos da lista\n";
			
			if(vazia())
				cout << "Lista vazia\n";
			else
			{
				while(b!=NULL)
				{
					cout << "elementos: " << b->getNum() << endl;
					b = b->getProx();
				}
				cout << endl;
			}
		}
		
		//Funcao que insere pares a direita e impares a esquerda
		
		int inserir(int n)
		{
			No* b = cauda;
			No* c = new No(n);
			
			if(n%2)
			{
				c->setProx(cabeca);
				cabeca=c;
				return 1;
			}else
			{
				b->setProx(c);
				cauda=c;
				return 1;
			}
			return 0;
		}
		//Caso a funcao retorne 1, sucesso, caso retorne 0, deu erro
		//Fim da questao 1
		
		//Funcoes para calcular a maior quantidade entre pares e impares de uma lista
		
		void quantidade1()
		{
			int par=0;
			int impar=0;
			
			quantidade2(cabeca, &par, &impar);
			
			if(par>impar)
				cout << "Existem mais pares\n";
			else if(par<impar)
				cout << "Existem mais impares\n";
			else
				cout << "Quantidades iguais\n";
		}
		
		int quantidade2(No* a, int* par, int* impar)
		{
			if(a==NULL)
				return 0;
			else if(a!=NULL && (a->getNum()%2))
			{
				*impar=*impar+1;
				quantidade2(a->getProx(), par, impar);
			}else if(a!=NULL && (a->getNum()%2)==0)
			{
				*par=*par+1;
				quantidade2(a->getProx(), par, impar);
			}
			return 0;
		}
		
		//Fim da questao 2
		
		//Fazer uma funcao para verificar se uma lista de inteiros qualquer e funcao de fib
		
		int fib()
		{
			No* b=cabeca;
			int num1, num2, count=0;
			
			while(b!=NULL)
			{
				if(count>=2 && (b->getNum()!=(num1+num2)))
				{
					cout<<"Nao organizados como fib\n";
					goto EXIT;
				}
				if(count%2)
					num1=b->getNum();
				else
					num2=b->getNum();
				count++;
				b=b->getProx();
			}
			cout<<"Organizados como fib\n";
			EXIT:
			return 1;
		}
		
		//Fim da questao 3
		
		//Funcao recursiva para contar os elementos de uma lista
		
		int contar2(No* a)
		{
			if(a==NULL)
				return 0;
			else
				return (1+contar2(a->getProx()));
		}
		
		void contar1()
		{
			cout << "tamanho da lista: " << contar2(cabeca) << endl;
		}
		
		//Fim da questao 5
		
		//Funcao para verificar se a lista de L inteiros está em ordem crescente
		int ordenada()
		{
			No* b = cabeca;
			int num;
			
			do
			{
				num=b->getNum();
				b=b->getProx();
				if(b!=NULL && num>b->getNum())
				{
					cout << "Nao esta em orde crescente\n";
					return 0;
				}
			}
			while(b!=NULL);
			
			cout << "Esta ordenada em ordem crescente\n";
			return 1;
		}
		
		//Fim da questao 6
};

int main()
{
	Lista teste;
	Lista teste2 (8);
	
	teste.mostrar();
	teste2.mostrar();
	teste2.inserir(5);
	teste2.inserir(3);
	teste2.mostrar();
	teste2.ordenada();
	
	return 0;
}