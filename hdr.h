#ifndef HDR_H
#define HDR_H

#include <QMainWindow>
#include <QMovie>
#include <string>
#include <fstream>

namespace Ui {
    class hdr;
}

class hdr : public QMainWindow
{
    Q_OBJECT

public:
    explicit hdr(QWidget *parent = 0);
    ~hdr();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::hdr *ui;
};

#endif // HDR_H


