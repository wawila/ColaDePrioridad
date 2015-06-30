#ifndef PRACTICA_MONTICULOS_H
#define PRACTICA_MONTICULOS_H

#include <QDialog>
#include <QDateTime>
#include <iostream>

using namespace std;

class Dato
{
public:
    QDateTime fecha;
    QString tarea;
    Dato * ant;
    Dato(QString t)
    {
        tarea = t;
        QDateTime dt;
        fecha = dt.currentDateTime();
        ant = NULL;
    }

    Dato(QString t, QDateTime dt)
    {
        tarea = t;
        fecha = dt;
        ant = NULL;
    }
};

namespace Ui {
class Practica_Monticulos;
}

class Practica_Monticulos : public QDialog
{
    Q_OBJECT

public:
    explicit Practica_Monticulos(QWidget *parent = 0);
    ~Practica_Monticulos();

    Dato * inicio;
    void insertar(Dato * nuevo);
    QDateTime consultarPrimerDato();
    void extraerInsertar(QDateTime fecha);
    void extraer();
    void imprimir();
    void cambiar(QString nom, QDateTime dt);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Practica_Monticulos *ui;
};

#endif // PRACTICA_MONTICULOS_H
