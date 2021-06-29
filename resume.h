#ifndef RESUME_H
#define RESUME_H

#include <QDialog>

namespace Ui {
class Resume;
}

class Resume : public QDialog
{
    Q_OBJECT

public:
    explicit Resume(QWidget *parent = nullptr);
    ~Resume();

private:
    Ui::Resume *ui;
};

#endif // RESUME_H
