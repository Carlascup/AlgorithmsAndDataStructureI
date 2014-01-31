#include <iostream>

using namespace std;

class No
{
public:
    No(double v,No *prox);
    double consulta_valor();
    No *consulta_proximo();
    void muda_valor(double n);
    void muda_proximo(No* i);
private:
    double valor;
    No*proximo;
};
No::No(double v,No *prox)
{
    valor=v;
    proximo=prox;
}
double No::consulta_valor()
{
    return (valor);
}
No *No::consulta_proximo()
{
    return (proximo);
}

void No::muda_valor(double n)
{
    valor = n;
}
void No::muda_proximo(No* i)
{
    proximo= i;
}

class Filano
{
public:
    Filano();
    ~Filano();
    double consulta_inicio();
    double consulta_fim();
    void add_pess(double x);
    void tira_pess();
    int consulta_tamanho();
    bool vazia();
private:
    No *inicio;
    No *fim;
};
Filano::Filano()
{
    inicio=new No(NULL,NULL);
    fim=new No(NULL,NULL);

}
bool Filano::vazia()
{
    if (inicio->consulta_proximo()==NULL && inicio->consulta_valor()==NULL)
        return(true);
    else
        return(false);
}
double Filano::consulta_inicio()
{
    if(vazia()==false)
        return(inicio->consulta_valor());
}
double Filano::consulta_fim()
{
    if(vazia()==false)
        return(fim->consulta_valor());
}
int Filano::consulta_tamanho()
{
    if (vazia()==true)
    {
        return (0);
    }
    else
    {
        int n=1;
        No *aux;
        aux=inicio;
        while(aux->consulta_proximo()!=NULL)
        {
            n++;
            aux=aux->consulta_proximo();
        }
        return n;
    }

}
void Filano::add_pess(double x)
{
    if(vazia()==true)
    {
        fim->muda_valor(x);
        inicio->muda_valor(x);
    }
    else if(consulta_tamanho()==1)
    {
        No *aux;
        aux=new No(x,NULL);
        inicio->muda_proximo(aux);
        fim=aux;
        aux=NULL;
    }
    else
    {
        No *aux;
        aux=new No(x,NULL);
        fim->muda_proximo(aux);
        fim=aux;
        aux=NULL;
    }
}

void Filano::tira_pess()
{
    if(vazia()==true)
    {
        cout<<"sua fila está vazia, impossivel retirar algo\n";
    }
    else if(consulta_tamanho()==1)
    {
        fim=NULL;
        inicio=NULL;
    }
    else
    {
        No *aux;
        aux=inicio->consulta_proximo();
        inicio=NULL;
        inicio=aux;
    }
}
Filano::~Filano()
{
    while(inicio!=NULL)
    {
        No*aux;
        aux=inicio->consulta_proximo();
        inicio=NULL;
        inicio=aux;
        aux=NULL;
    }
}

int main()
{

    Filano f2;
    f2.add_pess(5);
    cout<<"tamanho"<<f2.consulta_tamanho()<<endl;
    f2.add_pess(6);
    cout<<"tamanho"<<f2.consulta_tamanho()<<endl;
    f2.add_pess(7);
    cout<<"tamanho"<<f2.consulta_tamanho()<<endl;
    f2.tira_pess();
    cout<<"tamanho"<<f2.consulta_tamanho()<<endl;
    f2.tira_pess();
    cout<<"tamanho"<<f2.consulta_tamanho()<<endl;
    cout<<f2.consulta_inicio();
}
