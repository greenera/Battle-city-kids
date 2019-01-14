#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>

namespace Ui {
class Pause;
}

class Pause : public QWidget
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();

private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
