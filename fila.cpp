#include <iostream>
using namespace std;

class Fila
{
public:
    Fila(int n);
    ~Fila();
    void enfileira(int x);
    void desenfileira();
    double consulta_inicio();
    double consulta_fim();
    bool vazia();
    bool cheia();
    int consulta_tamanho();

private:
    int inicio;
    int fim;
    double *vet;
    int limite;
};
Fila::Fila(int n)
{
    inicio=0;
    fim=-1;
    limite=n;
    vet= new double[limite];
}

bool Fila::vazia()
{
    return(fim<inicio);

}

bool Fila::cheia()
{
    return (fim==limite-1);
}

void Fila::enfileira(int x)
{
    if(cheia()==false)
    {
        fim++;
        vet[fim]=x;

    }
    else
        cout<<"Fila cheia impossivel adicionar elementos\n";
}

double Fila::consulta_fim()
{
    if(vazia()==false)
        return(vet[fim]);
}
double Fila::consulta_inicio()
{
    if(vazia()==false)
        return(vet[inicio]);
}
void Fila::desenfileira()
{
    if (vazia()==false)
    {
        for (int i=0;i<=fim;i++)
        {
            vet[i]=vet[i+1];
            vet[i+1]=NULL;
        }
        fim--;
    }
    else
        cout<<"Fila vazia impossivel retirar elementos\n";
}
int Fila::consulta_tamanho()
{
    return(fim+1);
}
Fila::~Fila()
{
    if (vazia()==false)
    {
        for (int i=0;i<=fim;i++)
        {
            vet[i]=NULL;
        }
    }
    fim=NULL;
}
int main()
{
    Fila f1(5);
    cout<<f1.consulta_fim()<<"    fim <-\n";
    f1.enfileira(25);
    cout<<f1.consulta_fim()<<"\n";
    f1.enfileira(26);
    f1.enfileira(27);
    cout<<f1.consulta_tamanho()<<"       tamanho <- \n";
    cout<<f1.consulta_inicio()<<"       inicio <- \n";
    f1.desenfileira();
    cout<<f1.consulta_inicio()<<"       inicio agr <- \n";
    cout<<f1.consulta_tamanho()<<"      tamanho agr <- \n";
    cout<<f1.consulta_fim()<<"      fim agr<- \n";
    f1.~Fila();
    cout<<f1.consulta_inicio()<<"inicio com destrutor\n";
}
