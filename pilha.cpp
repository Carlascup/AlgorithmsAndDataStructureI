#include <iostream>

using namespace std;

class Pilha_vet
{
public:
    Pilha_vet(int i);
    ~Pilha_vet();
    void empilha(double n);
    void desempilha();
    double consulta_tamanho();
    bool vazia();
    double consulta_topo();
    bool cheia();
private:
    int topo;
    double *vet;
    int maxi;
};

Pilha_vet::Pilha_vet(int i)
{
    topo=-1;
    maxi=i;
    vet=new double[maxi];
}

bool Pilha_vet::cheia()
{
    return(topo==maxi);
}
bool Pilha_vet::vazia()
{
    return (topo==-1);
}

double Pilha_vet::consulta_tamanho()
{
    return (topo+1);
}

double Pilha_vet::consulta_topo()
{
    if (vazia()==false)
        return(vet[topo]);
}

void Pilha_vet::empilha(double n)
{
    if (topo<maxi)
    {
        topo ++;
        vet[topo]=n;
    }
}

Pilha_vet::~Pilha_vet()
{
    for (int i =0; i<topo;i++)
    {
        vet[i]=NULL;
        topo--;

    }
}

void Pilha_vet::desempilha()
{
    if (vazia()==false)
    {
        vet[topo]=NULL;
        topo--;
    }
}

int main()
{
   Pilha_vet p1(5);
   p1.empilha(85);
   cout<<p1.consulta_topo()<<"        "<<p1.consulta_tamanho()<<endl;
   p1.empilha(25);
   p1.empilha(56);
   cout<<p1.consulta_topo()<< "         "<<p1.consulta_tamanho()<<endl;
   p1.desempilha();
   cout<<p1.consulta_topo()<<"        "<<p1.consulta_tamanho()<<endl;
   p1.~Pilha_vet();
   cout<<p1.consulta_topo()<<endl;
}
