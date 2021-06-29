#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private:
    Ui::Notepad *ui;
    QString currentFile;



private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void superScript();
    void openResume();
    void subScript();
    void setFontBold();
    void changeFont();
    void setFontUnderline();
    void setFontItalic();

};
#endif // NOTEPAD_H
