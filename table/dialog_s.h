#ifndef DIALOG_S_H
#define DIALOG_S_H

#include <QDialog>

namespace Ui {
    class Dialog_s;
}

class Dialog_s : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_s(QWidget *parent = 0);
    ~Dialog_s();

private:
    Ui::Dialog_s *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_S_H
