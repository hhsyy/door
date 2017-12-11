#ifndef DIALOG_D_H
#define DIALOG_D_H

#include <QDialog>

namespace Ui {
    class Dialog_d;
}

class Dialog_d : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_d(QWidget *parent = 0);
    ~Dialog_d();

private:
    Ui::Dialog_d *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_D_H
