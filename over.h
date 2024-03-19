#ifndef OVER_H
#define OVER_H

#include <QDialog>

namespace Ui {
class over;
}

class over : public QDialog
{
    Q_OBJECT

public:
    explicit over(QWidget *parent = nullptr);
    ~over();

private slots:
    void on_restartpush_clicked();

private:
    Ui::over *ui;
};

#endif // OVER_H
