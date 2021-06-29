#include "notepad.h"
#include "ui_notepad.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QFontDialog>
#include"resume.h"
Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("Tanmay's Notepad");

    this->setCentralWidget(ui->textEdit);
    connect(ui->actionNew ,&QAction::triggered,this,&Notepad::newDocument);
    connect(ui->actionOpen ,&QAction::triggered, this, &Notepad::open);
    connect(ui->actionSave , &QAction::triggered , this , &Notepad::save);
    connect(ui->actionCopy , &QAction::triggered , this , &Notepad::copy);
    connect(ui->actionPaste, &QAction::triggered , this , &Notepad::paste);
    connect(ui->actionCut , &QAction::triggered , this , &Notepad::cut);
    connect(ui->actionUnderline , &QAction::triggered , this , &Notepad::setFontUnderline);
    connect(ui->actionBold , &QAction::triggered , this , &Notepad::setFontBold);
    connect(ui->actionItalic , &QAction::triggered , this , &Notepad::setFontItalic);
    connect(ui-> actionAbout, &QAction::triggered , this , &Notepad::openResume);
    connect(ui->actionFont , &QAction::triggered , this , &Notepad::changeFont);
    connect(ui->actionSuperScript , &QAction::triggered , this , &Notepad::superScript);
    connect(ui->actionSubScript , &QAction::triggered , this , &Notepad::subScript);
    connect(ui->actionUndo , &QAction::triggered , this , &Notepad::undo);
    connect(ui->actionRedo , &QAction::triggered , this , &Notepad::redo);



}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());

}

void Notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this , "Open the file");
    QFile file(fileName);
    currentFile = fileName;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this , "Warning" , "Cannot Open File");
        return ;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();


}

void Notepad::save()
{
    QString fileName;
    if(currentFile.isEmpty()){
        fileName = QFileDialog::getSaveFileName(this , "Save");
    }
    else{
        fileName = currentFile;
    }
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this , "Warning" , "Cannot Save File");

    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();



}

void Notepad::saveAs()
{
    QString fileName;

        fileName = QFileDialog::getSaveFileName(this , "SaveAs");

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this , "Warning" , "Cannot Save File");

    }
    currentFile= fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void Notepad::copy()
{
 #if QT_CONFIG(clipboard)
    ui->textEdit->copy();
 #endif
}

void Notepad::cut()
{
#if QT_CONFIG(clipboard)
   ui->textEdit->cut();
#endif
}

void Notepad::paste()
{
#if QT_CONFIG(clipboard)
   ui->textEdit->paste();
#endif
}

void Notepad::undo()
{
    ui->textEdit->undo();

}

void Notepad::redo()
{
    ui->textEdit->redo();

}

void Notepad::superScript()
{
    QString selected_text = ui->textEdit->textCursor().selectedText();
    ui->textEdit->textCursor().removeSelectedText();
    ui->textEdit->insertHtml(QString("<sup>%1</sup>").arg(selected_text));
}

void Notepad::subScript()
{
    QString selected_text = ui->textEdit->textCursor().selectedText();
    ui->textEdit->textCursor().removeSelectedText();
    ui->textEdit->insertHtml(QString("<sub>%1</sub>").arg(selected_text));
}


void Notepad::setFontBold()
{
    ui->textEdit->setFontWeight(QFont::Bold);

}

void Notepad::changeFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected , this);
    if(fontSelected){
        ui->textEdit-> setFont(font);
    }

}

void Notepad::setFontUnderline()
{
ui->textEdit->setFontUnderline(true);
}

void Notepad::setFontItalic()
{
    ui->textEdit->setFontItalic(true);

}

void Notepad::openResume()
{
Resume r;
r.setModal(true);
r.exec();

}


