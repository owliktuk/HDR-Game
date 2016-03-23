#include "hdr.h"
#include "ui_hdr.h"
#include "cmath"
#include "fstream"
#include <iostream>

using std::cout;

QString command;

//wywołanie gnójplota
void gnuplot(QString gnucommand)
{
  system(qPrintable(gnucommand));
}

hdr::hdr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hdr)
{
    ui->setupUi(this);
}

hdr::~hdr()
{
    delete ui;
}

void hdr::on_pushButton_clicked()
{
    ui->textBrowser->clear();

    //macierz zysków z czystych strategii
    double Payoff[3][3]={ui->doubleSpinBox->value(), ui->doubleSpinBox_7->value(), ui->doubleSpinBox_8->value(),
                         ui->doubleSpinBox_2->value(), ui->doubleSpinBox_3->value(), ui->doubleSpinBox_9->value(),
                         ui->doubleSpinBox_4->value(), ui->doubleSpinBox_5->value(), ui->doubleSpinBox_6->value()};

    //strategie
    double H[3]={1,0,0};
    double D[3]={0,1,0};
    double R[3]={0,0,1};

    //macierz zysków ze strategii
    double Strategy_payoff[3][3];

    memcpy(Strategy_payoff, Payoff, sizeof(Payoff));

    //populacje
    double Population[3]={ui->doubleSpinBox_10->value(), ui->doubleSpinBox_11->value(), ui->doubleSpinBox_12->value()};

    //wektor przystosowań
    double Fitness[3]={0,0,0};
    double Mean_fitness=0;

    //współrzędne
    double x, y;


    command = "gnuplot -p -e \"set terminal gif animate delay 10; set output 'animate.gif'; set pointsize 5; ";
     command+="set nokey; unset xtics; unset ytics; unset border; set label 'H' font 'Helvetica,20' at -0.01,0; set label 'D' font 'Helvetica,20' at 1,0; set label 'R' font 'Helvetica,20' at 0.5,0.88; ";

     for (int line=0; line < 50; line++)
         command += "set label '_' at " + QString::number(double(line)/50) + ",0; ";


     for (int line=0; line < 60; line++)
         command += "set label '/' at " + QString::number(double(line)/120) + "," + QString::number(sqrt(3)*double(line)/120) + "; ";


     for (int line=0; line < 60; line++)
         command += "set label '\\' at " + QString::number(0.5+double(line)/120) + "," + QString::number(-sqrt(3)*(0.5+double(line)/120)+sqrt(3)) + "; ";


     command += " set xrange[0:1]; set yrange[0:0.9]; ";

    for (int krok=0; krok < 500; krok++) {

        Mean_fitness=0;

        //liczenie przystosowań
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                Fitness[i] += Population[j]*Strategy_payoff[i][j];
            }
        }

        //średnie przystosowanie
        for(int j=0; j<3; j++)
        {
            Mean_fitness += Population[j]*Fitness[j];
        }

        //liczenie populacji
        for(int j=0; j<3; j++)
        {
            Population[j]=Population[j]*Fitness[j]/Mean_fitness;
            if (Population[j] < 0)
            {
                ui->textBrowser->insertPlainText("Mniejsze od zera!!! \n");
                Population[j] = 0;
            }
        }

        ui->textBrowser->insertPlainText("H: " + QString::number(Population[0]) + ", D: " + QString::number(Population[1]) + ", R: " + QString::number(Population[2]) + " \n");

        //Współrzędne na wykresie
        x=Population[1]+Population[2]/2;
        y=sqrt(3)*Population[2]/2;



        command += "plot '<echo " + QString::number(x) + " " + QString::number(y) + "'; ";


    }

    command += "\"";
    gnuplot(command);

    QMovie *movie = new QMovie("animate.gif");

    ui->label_3->setMovie(movie);
    movie->start();


}

void hdr::on_pushButton_2_clicked()
{
    ui->doubleSpinBox->setValue(0);
    ui->doubleSpinBox_2->setValue(-1);
    ui->doubleSpinBox_3->setValue(1.5);
    ui->doubleSpinBox_7->setValue(2);
    ui->doubleSpinBox_8->setValue(0);
    ui->doubleSpinBox_9->setValue(0);
    ui->doubleSpinBox_6->setValue(0);
    ui->doubleSpinBox_5->setValue(0);
    ui->doubleSpinBox_4->setValue(0);
    ui->doubleSpinBox_12->setValue(0);
    ui->doubleSpinBox_11->setValue(600);
    ui->doubleSpinBox_10->setValue(0.1);
}

void hdr::on_pushButton_3_clicked()
{
    ui->doubleSpinBox->setValue(-1);
    ui->doubleSpinBox_2->setValue(0);
    ui->doubleSpinBox_3->setValue(1);
    ui->doubleSpinBox_7->setValue(2);
    ui->doubleSpinBox_8->setValue(-1);
    ui->doubleSpinBox_9->setValue(0.9);
    ui->doubleSpinBox_6->setValue(1);
    ui->doubleSpinBox_5->setValue(1.1);
    ui->doubleSpinBox_4->setValue(-1);
    ui->doubleSpinBox_12->setValue(4);
    ui->doubleSpinBox_11->setValue(4);
    ui->doubleSpinBox_10->setValue(2);
}

void hdr::on_pushButton_4_clicked()
{
    ui->doubleSpinBox->setValue(-1);
    ui->doubleSpinBox_2->setValue(0);
    ui->doubleSpinBox_3->setValue(1);
    ui->doubleSpinBox_7->setValue(2);
    ui->doubleSpinBox_8->setValue(2);
    ui->doubleSpinBox_9->setValue(0);
    ui->doubleSpinBox_6->setValue(1);
    ui->doubleSpinBox_5->setValue(2);
    ui->doubleSpinBox_4->setValue(0);
    ui->doubleSpinBox_12->setValue(4);
    ui->doubleSpinBox_11->setValue(4);
    ui->doubleSpinBox_10->setValue(2);
}
