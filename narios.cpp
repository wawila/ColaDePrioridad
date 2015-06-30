#include "narios.h"
#include "ui_narios.h"

Narios::Narios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Narios)
{
    ui->setupUi(this);
    ui->Nuevo->setValidator(new QIntValidator());
}

Narios::~Narios()
{
    delete ui;
}

void Narios :: imprimir(Nodo *raiz, QString sp)
{
    if(raiz!=NULL)
    {
        QString s;
        s.append(sp+"->");
        s.append(s.number(raiz->valor));
        ui->listWidget->addItem(s);
        for(unsigned int i=0;i<raiz->hijos.size();i++)
        {
            imprimir(raiz->hijos[i], sp+"    ");
        }
    }
}

Nodo* Narios :: buscar(Nodo* raiz, int num)
{
    if(raiz!=NULL)
    {
        if(raiz->valor == num)
        {
            return raiz;
        }

        for(unsigned int i=0;i<raiz->hijos.size();i++)
        {
            Nodo* temp = buscar(raiz->hijos[i],num);
            if(temp->valor == num)
            {
                return temp;
            }
        }

    }
    return NULL;
}
void Narios :: insertar(Nodo *hijo, Nodo* padre){
    padre->agregarHijo(hijo);
}

void Narios :: eliminar(Nodo *hijo, Nodo* padre){
    padre->eliminarHijo(hijo);
}

void Narios :: agregar(Nodo *nuevo){
    nodos.push_back(nuevo);
}

void Narios :: llenar(){
    ui->ListaPadres->clear();
    ui->ListaHijos->clear();
    for(unsigned int i=0; i<nodos.size(); i++){
        ui->ListaPadres->addItem(QString::number(nodos[i]->valor));
        ui->ListaHijos->addItem(QString::number(nodos[i]->valor));
    }
}

void Narios::on_Agregar_clicked()
{
    Nodo* nuevo = new Nodo(ui->Nuevo->text().toInt());
    agregar(nuevo);
    llenar();
    ui->listWidget->clear();
    if(nodos.size() > 0)
    {
        imprimir(nodos[0], "");
    }
}

void Narios::on_Insertar_clicked()
{
    if((nodos.size() > 0) && (ui->ListaHijos->currentIndex() != ui->ListaPadres->currentIndex()))
    {
        insertar(nodos[ui->ListaHijos->currentIndex()], nodos[ui->ListaPadres->currentIndex()]);
    }

    ui->listWidget->clear();
    if(nodos.size() > 0)
        imprimir(nodos[0], "");
}

void Narios::on_Eliminar_clicked()
{
    if(nodos.size() > 0)
        eliminar(nodos[ui->ListaHijos->currentIndex()], nodos[ui->ListaPadres->currentIndex()]);

    ui->listWidget->clear();
    if(nodos.size() > 0)
        imprimir(nodos[0], "");
}

