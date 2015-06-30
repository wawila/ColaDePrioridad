#ifndef NARIOS_H
#define NARIOS_H
#include <iostream>
#include <vector>
#include <QDialog>

using namespace std;

class Nodo
{
public:
    int valor;
    vector<Nodo*> hijos;

    Nodo(int valor)
    {
        this->valor = valor;
        hijos.clear();
    }

    void agregarHijo(Nodo* hijo)
    {
        hijos.push_back(hijo);
    }

    void eliminarHijo(Nodo* hijo)
    {
        for(vector<Nodo*>:: iterator h = hijos.begin(); h!= hijos.end(); h++)
        {
               if((*h)->valor == hijo->valor)
                   hijos.erase(h);
        }
    }
};

namespace Ui {
class Narios;
}

class Narios : public QDialog
{
    Q_OBJECT

public:
    explicit Narios(QWidget *parent = 0);
    ~Narios();
    vector<Nodo*>nodos;
    void imprimir(Nodo* raiz, QString sp);
    void insertar(Nodo* hijo, Nodo* padre);
    void eliminar(Nodo* hijo, Nodo* padre );
    void agregar(Nodo* nuevo);
    Nodo* buscar(Nodo* raiz, int num);
    void llenar();
private slots:
    void on_Agregar_clicked();

    void on_Insertar_clicked();

    void on_Eliminar_clicked();

private:
    Ui::Narios *ui;
};

#endif // NARIOS_H
