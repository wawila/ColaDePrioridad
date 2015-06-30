#include "practica_monticulos.h"
#include "ui_practica_monticulos.h"

Practica_Monticulos::Practica_Monticulos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Practica_Monticulos)
{
    ui->setupUi(this);
    inicio = NULL;
    ui->dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
}

void Practica_Monticulos::insertar(Dato *nuevo)
{
    if(!inicio)
    {
        inicio = nuevo;
        return;
    }

    if(inicio->fecha > nuevo->fecha)
    {
        nuevo->ant = inicio;
        inicio = nuevo;
        return;
    }

    Dato * temp = inicio;
    while(temp->ant && temp->ant->fecha <= nuevo->fecha)
        temp = temp->ant;

    nuevo->ant = temp->ant;
    temp->ant = nuevo;
    temp = temp->ant->ant;
}

QDateTime Practica_Monticulos::consultarPrimerDato()
{
    if(inicio)
    {
        cout<<inicio->tarea.toStdString()<<" - "<<inicio->fecha.toString().toStdString()<<endl;
        return inicio->fecha;
    }
}

void Practica_Monticulos::extraerInsertar(QDateTime fecha)
{
    if(inicio)
    {
        Dato * tem = inicio;
        tem->fecha = fecha;
        inicio = inicio->ant;
        insertar(tem);
    }
    imprimir();
}

void Practica_Monticulos::extraer()
{
    QString a;
    a.append(inicio->tarea + " - " + inicio->fecha.toString());
    ui->label_2->setText(a);
    inicio = inicio->ant;
    imprimir();
}

void Practica_Monticulos::imprimir()
{
    Dato * temp = inicio;
     ui->listWidget->clear();
     QString s;
    while(temp)
    {
        s.clear();
        s.append(temp->tarea + " - " + temp->fecha.toString());
        ui->listWidget->addItem(s);
        cout<<temp->tarea.toStdString()<<" - "<<temp->fecha.toString().toStdString()<<endl;
        temp = temp->ant;

    }
}

void Practica_Monticulos::cambiar(QString nom, QDateTime dt)
{
    if(inicio)
        {
        if(nom == inicio->tarea)
        {
            extraerInsertar(dt);
            return;
        }

        Dato * temp = inicio;
        while(temp->tarea != nom)
            temp = temp->ant;

         temp = temp->ant;

        Dato * nuevo = new Dato(nom, dt);
         insertar(nuevo);
     }
    imprimir();

}

Practica_Monticulos::~Practica_Monticulos()
{
    delete ui;
}

void Practica_Monticulos::on_pushButton_clicked()
{
    QString nom  = ui->lineNombre->text();
    QDateTime fecha = ui->dateTimeEdit->dateTime();

    Dato * nu = new Dato(nom, fecha);
    insertar(nu);

    imprimir();
}

void Practica_Monticulos::on_pushButton_5_clicked()
{
    extraerInsertar(ui->dateTimeEdit->dateTime());
    imprimir();
}

void Practica_Monticulos::on_pushButton_4_clicked()
{
    ui->label->clear();
    if(inicio)
        ui->label->setText(consultarPrimerDato().toString("dd/MM/yy h:mm AP"));
}

void Practica_Monticulos::on_pushButton_2_clicked()
{
    if(ui->lineNombre->text() != "")
        cambiar(ui->lineNombre->text(), ui->dateTimeEdit->dateTime());
}

void Practica_Monticulos::on_pushButton_3_clicked()
{
    if(inicio)
        extraer();
}
