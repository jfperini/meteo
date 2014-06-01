#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QSettings>
#include "engine/yahooeng.h"



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

     QTimer *Timer;  // Temporizador para el fader
     QTimer *Timer2;  // Temporizador para el fader

     YahooEngine *mEngine;
     Weather mCurrentWeather;

  //  void Exportar();

private slots:

void Refrescar();
void Conectar();
void slot_Actualizar();
void Exportar();

};

#endif // MAINWINDOW_H
