#include <iostream>
#include <math.h>

using namespace std;

class No
{
	int coef;
	int exp;
	No* prox;
	
	public:
		No(int coef)
		{
			this->coef=coef;
		}
		
		int getCoef()
		{
			return coef;
		}
		
		int getExp()
		{
			return exp;
		}
		
		No* getProx()
		{
			return prox;
		}
		
		void setExp(int exp)
		{
			this->exp=exp;
		}
		
		void setProx(No* prox)
		{
			this->prox=prox;
		}
};

class Lista
{
	No* cabeca;
	No* cauda;
	
	public:
		Lista()
		{
			cabeca=NULL;
			cauda=NULL;
		}
		
		Lista(int coef)
		{
			cabeca=new No(coef);
			cauda=cabeca;
		}
		
		//Func
		void calcular(int x)
		{
			No* b=cabeca;
			int count=0, result=0;
			
			while(b!=NULL || count<=x)
			{
				result=result+(pow(b->getCoef(), count));
				b=b->getProx();
				count++;
			}
			cout << "\nresultado: " << result << endl;
		}
		
		//Inserir
		int inserir(int coef)
		{
			No* b = new No(coef);
			cauda->setProx(b);
			cauda=b;
		}
};

int main()
{
	Lista teste(2);
	teste.inserir(3);
	teste.inserir(4);
	teste.calcular(2);
	return 0;
}