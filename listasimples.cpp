#include <iostream>

using namespace std;

class Lista
{
public:
    Lista(int n);
    ~Lista();
    double consulta_fim();
    double consulta_inicio();
    void mova_cursor(int n);
    void add_elemento(int n, double valor);
    void remover_ele(int i);
    double cons_cur();
    bool vazia();
    bool cheia();

private:
    double cursor;
    double inicio;
    double fim;
    double *vet;
    int maxi;

};
Lista::Lista(int n)
{
    inicio=0;
    fim=0;
    maxi= n;
    vet=new double[maxi];

}
Lista::~Lista()
{
    delete (vet);
}
bool Lista::vazia()
{
    return (fim==0);
}
bool Lista::cheia()
{
    return(fim==maxi);
}
double Lista::consulta_fim()
{
    return (fim);
}
double Lista::consulta_inicio()
{
    return (inicio);
}
void Lista::mova_cursor(int n)
{
    if (n<consulta_fim() && n>consulta_inicio())
        cursor = vet[n];
}
void Lista::add_elemento(int n, double valor)
{
    if (n<consulta_fim() && cheia()!=true)
        vet[n]=valor;
        fim++;
}
void Lista::remover_ele(int i)
{
    double aux;
    for (int n=i+1; n<maxi; n++ )
    {
        vet[i]=vet[n];
        n++;
        i++;
    }
    fim--;
}
double Lista::cons_cur()
{
    return(cursor);
}
int main()
{
    Lista l1(5);
    cout << l1.consulta_fim() << endl;
    cout << l1.consulta_inicio() << endl;
    l1.add_elemento(2,25);
    l1.mova_cursor(2);
    cout << l1.cons_cur() << endl;

}
