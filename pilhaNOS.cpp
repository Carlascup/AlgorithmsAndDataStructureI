#include <iostream>
using namespace std;
class No
{
public:
    No();
    double consulta_valor();
    No *consulta_proximo();
    void muda_valor(double n);
    void muda_proximo(No* i);
private:
    double valor;
    No*proximo;
};
No::No()
{
    valor=0;
    proximo=0;
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
class Pilha
{
public:
    Pilha();
    ~Pilha();
    bool Vazia();
    void Empilha(double x);
    void Desempilha();
    double consulta_topo();
    int tamanho_da_pilha();
private:
    No *topo;
};
Pilha::Pilha()
{
    topo=0;
}

bool Pilha::Vazia()
{
    return topo==0;
}
double Pilha::consulta_topo()
{
    if(Vazia()==false)
        return (topo->consulta_valor());
}
void Pilha::Empilha(double x)
{
    No *noaux;
    noaux=new No;
    noaux->muda_valor(x);
    noaux->muda_proximo(topo);
    topo=noaux;
    noaux=NULL;

}
void Pilha::Desempilha()
{
    if (Vazia()==false)
    {
        No *aux;
        aux=new No;
        aux=topo;
        topo=NULL;
        topo=aux->consulta_proximo();
        aux=NULL;
    }
}
int Pilha::tamanho_da_pilha()
{
    int n=0;
    No* aux;
    aux= new No;
    aux=topo;
    if (Vazia())
        return (0);
    else
    {
        while (aux!=0)
        {
            n++;
            aux=aux->consulta_proximo();
        }
        aux=NULL;
        return (n);
    }

}
Pilha::~Pilha()
{
    int n;
    n=tamanho_da_pilha();
    for (int i=0;i<=n && Vazia()==false;i++)
    {
        No *aux;
        aux= new No;
        aux= topo->consulta_proximo();
        topo=0;
        delete topo;
        topo=aux;
        n--;
    }
}
int main()
{
Pilha p1;
    p1.Empilha(1);
    p1.Empilha(2);
    p1.Empilha(3);
    p1.Empilha(4);
    p1.Empilha(5);
    p1.Empilha(6);
    p1.Empilha(7);
    p1.Empilha(8);
    p1.Empilha(9);
    p1.Empilha(10);
    cout<<"Pilha inicial - Topo // Ultimo a entrar, primeiro a sair \n";
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    p1.Desempilha();
    cout<<p1.consulta_topo()<<"\n";
    cout<<"^^Primeiro a entrar, ultimo a sair^^\n";
}
