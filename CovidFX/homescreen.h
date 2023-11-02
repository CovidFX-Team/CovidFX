#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QDialog>

namespace Ui {
class homescreen;
}

class homescreen : public QDialog
{
    Q_OBJECT

public:
    explicit homescreen(QWidget *parent = nullptr);
    ~homescreen();

private:
    Ui::homescreen *ui;
};

#endif // HOMESCREEN_H
