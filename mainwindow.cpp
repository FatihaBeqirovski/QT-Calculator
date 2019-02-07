#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>>
#include <QDebug>
#include <QString>
double firstNumber;
bool ifThereIsSecondNum = false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->numBtn0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->numBtn9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->unaryBtn,SIGNAL(released()),this,SLOT(unaryOpPressed()));


    connect(ui->precentBtn,SIGNAL(released()),this,SLOT(unaryOpPressed()));

    connect(ui->equalBtn,SIGNAL(released()),this,SLOT(equalBtnPressed()));
    connect(ui->dotBtn,SIGNAL(released()),this,SLOT(dotBtnPressed()));
    connect(ui->clearBtn,SIGNAL(released()),this,SLOT(clearBtnPressed()));

    connect(ui->addBtn,SIGNAL(released()),this,SLOT(binaryOpPressed()));
    connect(ui->subBtn,SIGNAL(released()),this,SLOT(binaryOpPressed()));
    connect(ui->divideBtn,SIGNAL(released()),this,SLOT(binaryOpPressed()));
    connect(ui->multiplyBtn,SIGNAL(released()),this,SLOT(binaryOpPressed()));

    ui->addBtn->setCheckable(true);
    ui->subBtn->setCheckable(true);
    ui->multiplyBtn->setCheckable(true);
    ui->divideBtn->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){
    QPushButton *button = (QPushButton*) sender();
    QString text;
    double number;
    if ((ui->addBtn->isChecked() || ui->subBtn->isChecked() || ui->multiplyBtn->isChecked() || ui->divideBtn->isChecked()) && (!ifThereIsSecondNum) ){
        number= button->text().toDouble();
        ifThereIsSecondNum=true;
        text = QString::number(number,'g',15);
    }

    else {
        if(ui->label->text().contains('.') && button->text()=="0"){
            text = ui->label->text() + button -> text();
        }
        else{
            number=(ui->label->text() + button->text()).toDouble();
            text= QString:: number(number,'g',15);

        }
    }


    if(text == "1"){
        ui->label->setText("");
    }

    ui->label->setText(text);
}

void MainWindow::dotBtnPressed()
{
    ui -> label->setText(ui->label->text() +".");
}

void MainWindow::unaryOpPressed(){
    QPushButton *button= (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text()=="+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if (button->text()=="%"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::clearBtnPressed()
{
    ui->addBtn->setChecked(false);
    ui->subBtn->setChecked(false);
    ui->multiplyBtn->setChecked(false);
    ui->divideBtn->setChecked(false);
    ifThereIsSecondNum=false;

    ui->label->setText("0");
}

void MainWindow::equalBtnPressed(){

    double number, secondNumber;
    QString newLabel;
    secondNumber= ui->label->text().toDouble();
    if (ui->addBtn->isChecked()){
        number= firstNumber + secondNumber;
        newLabel= QString:: number(number,'g',15);
        ui->label->setText(newLabel);
        ui->addBtn->setChecked(false);
    }
    else if (ui->subBtn->isChecked()){
        number= firstNumber -  secondNumber;
        newLabel= QString:: number(number,'g',15);
        ui->label->setText(newLabel);
        ui->subBtn->setChecked(false);
    }
    else if (ui->multiplyBtn->isChecked()){
        number = firstNumber * secondNumber;
        newLabel= QString:: number(number,'g',15);
        ui->label->setText(newLabel);
        ui->multiplyBtn->setChecked(false);
    }
    else if (ui->divideBtn->isChecked()){
            number = firstNumber / secondNumber;
            newLabel= QString:: number(number,'g',15);
            ui->label->setText(newLabel);
            ui->divideBtn->setChecked(false);

    }

    ifThereIsSecondNum=false;
}
void MainWindow::binaryOpPressed(){
    QPushButton *button= (QPushButton*) sender();
    firstNumber =  ui->label->text().toDouble();
    button->setChecked(true);

}
