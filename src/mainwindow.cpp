
#include <QDebug>
#include <QFile>
#include <QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);






    //evitamos que cambie el formulario
    QSize fixedSize(380,155 );
    setMinimumSize(fixedSize);
    setMaximumSize(fixedSize);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);




    Timer = new QTimer();
    Timer2 = new QTimer();
    mEngine = new YahooEngine();

      connect(Timer, SIGNAL(timeout()), this, SLOT(Refrescar())); // temporizaor horario
      connect(Timer2, SIGNAL(timeout()), this, SLOT(slot_Actualizar())); // temporizaor horario

       connect(mEngine, SIGNAL(Finish()), this, SLOT(Exportar())); // temporizaor horario
      QSettings MeteoIni("Meteo.ini", QSettings::IniFormat);

      Timer->start(1000);






       ui->lineCiudad->setText(MeteoIni.value("Ciudad").toString());



 mEngine->update(ui->lineCiudad->text());


Timer2->start(900000);
//Timer2->start(3000);


}

MainWindow::~MainWindow()
{

     QSettings MeteoIni("Meteo.ini", QSettings::IniFormat);
     MeteoIni.setValue("Ciudad",ui->lineCiudad->text());


    delete Timer;
    //delete w_Datos;
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::Refrescar(){

//mEngine->update(ui->lineCiudad->text());

    // ui->labelEstado->setText(mEngine->Estado);
   //  ui->labelTemperatura->setText(mEngine->Temperatura);
   //  ui->labelHumedad->setText(mEngine->Humedad);

    if(mEngine->Temperatura.isEmpty()){
        mEngine->update(ui->lineCiudad->text());
        return;
    }

}

void MainWindow::Conectar(){


 //w_Datos->Actualizar(ui->lineCiudad->text());
  //  qDebug()<<"Conex";
//mEngine->update(ui->lineCiudad->text());
}



void MainWindow::slot_Actualizar(){


mEngine->update(ui->lineCiudad->text());
//Exportar();

}



void MainWindow::Exportar(){



    ui->labelEstado->setText(mEngine->Estado);
    ui->labelTemperatura->setText(mEngine->Temperatura);
    ui->labelHumedad->setText(mEngine->Humedad);




 QString Temperatura2, Temperatura, Humedad,y;


Temperatura=mEngine->Temperatura;
Humedad=mEngine->Humedad;
y = Humedad.right(3);
y = y.left(2);

int fa;
fa=Temperatura.toInt()*9;
fa=fa/5;
fa=fa+32;
fa=fa+1; //desfase del zararadio

Temperatura2=Temperatura2.setNum(fa);


qDebug() <<"faran  " <<Temperatura2;




   /*     QString string = "<HTML>\n"
                      "Location: Sevilla, Spain (Sevilla Airport)<BR />\n"
                      "Condition: Mostly Sunny<BR />\n"
                      "Temperature: 71,6&deg;F/22&deg;C<BR />\n"
                      "Feels Like: 72&deg;F/22&deg;C<BR />\n"
                      "Dew Point: 41&deg;F/5&deg;C<BR />\n"
                       Humedad + "<BR />\n"
                      "Wind: 8,05 km/h<BR />"
                      "Barometer: 762 mm and rising<BR />\n"
                      "Sunrise: 08:37:13<BR />\n"
                      "Sunset: 19:39:27<BR />\n"
                      "<BR />\n"
                      "<TABLE CELLPADDING='0' CELLSPACING='0'><TR><TD ALIGN='right'>Observed:&nbsp;<BR />Downloaded:&nbsp;</TD><TD>21/10/2010 @ 19:30:00<BR />21/10/2010 @ 19:53:30</TD></TR></TABLE>\n"
                      "</HTML>";*/




        QString string = "<HTML>\n"
                       "Location: Sevilla, Spain (Sevilla Airport)<BR />\n"
                       "Condition: Mostly Sunny<BR />\n"
                       "Temperature:"+ Temperatura2 + "&deg;F/3&deg;C<BR />\n"
                       "Feels Like: 72&deg;F/3&deg;C<BR />\n"
                       "Dew Point: 41&deg;F/5&deg;C<BR />\n"
                       "Humidity: " + y + "%" + "<BR />\n"
                       "Wind: 8,05 km/h<BR />"
                       "Barometer: 762 mm and rising<BR />\n"
                       "Sunrise: 08:37:13<BR />\n"
                       "Sunset: 19:39:27<BR />\n"
                       "<BR />\n"
                       "<TABLE CELLPADDING='0' CELLSPACING='0'><TR><TD ALIGN='right'>Observed:&nbsp;<BR />Downloaded:&nbsp;</TD><TD>21/10/2010 @ 19:30:00<BR />21/10/2010 @ 19:53:30</TD></TR></TABLE>\n"
                       "</HTML>";









    QFile file("Currenweather/currenweather.html");

            file.open(QIODevice::WriteOnly);


            QTextStream in(&file);

            in << string ;


             file.close();

            //////////////////////////////////////////////

             QDir dir;
             dir.remove("Currenweather/currenweather.txt");

            file.setFileName("Currenweather/currenweather.txt");
                 file.open(QIODevice::WriteOnly| QIODevice::ReadOnly| QIODevice::Text);



                 QTextStream out(&file);

                 Temperatura = Temperatura.left(2);
                 Humedad=Humedad.right(4);
                 Humedad=Humedad.left(3);

                // Humedad="100";
                 int Hum=Humedad.toInt();
                 Humedad= Humedad.setNum(Hum);


                 qDebug()<<Humedad ;


                 out << Temperatura  <<" " << Humedad;


                file.close();




}












