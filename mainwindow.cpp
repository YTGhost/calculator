#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include "charStack.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <QMessageBox>
#include <QClipboard>

using namespace std;

int numberSign = 0;
int optSign = 0;
int computeEnd = 0;
int zeroError = 0;
int numOfLeftBracket = 0;
int rightBracketSign = 0;
int pointSign1 = 0;
int pointSign2 = 0;

sqstack nums;
sqcharstack ops;
QPushButton* pushButton0;
QPushButton* pushButton1;
QPushButton* pushButton2;
QPushButton* pushButton3;
QPushButton* pushButton4;
QPushButton* pushButton5;
QPushButton* pushButton6;
QPushButton* pushButton7;
QPushButton* pushButton8;
QPushButton* pushButton9;
QPushButton* pushButtonPlus;
QPushButton* pushButtonMinus;
QPushButton* pushButtonMul;
QPushButton* pushButtonDiv;
QPushButton* pushButtonEqual;
QPushButton* pushButtonPoint;
QPushButton* pushButtonL;
QPushButton* pushButtonR;
QPushButton* pushButtonBack;
QPushButton* pushButtonClear;
QPushButton* pushButtonPow;
QPushButton* pushButtonSquare;
QPushButton* pushButtonCube;
QPushButton* pushButtonReciprocal;
QPushButton* pushButtonRooting;
QPushButton* pushButtonCubeRoot;
QPushButton* pushButtonLog;
QPushButton* pushButtonLn;
QPushButton* pushButtonPi;
QPushButton* pushButtonE;
QListWidget* listWidget;
QLineEdit* lineEdit1;
QLineEdit* lineEdit2;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitComponent();
    SetStyleSheet();
}

void MainWindow::InitComponent()
{
    pushButton0 = ui->pushButton0;
    pushButton1 = ui->pushButton1;
    pushButton2 = ui->pushButton2;
    pushButton3 = ui->pushButton3;
    pushButton4 = ui->pushButton4;
    pushButton5 = ui->pushButton5;
    pushButton6 = ui->pushButton6;
    pushButton7 = ui->pushButton7;
    pushButton8 = ui->pushButton8;
    pushButton9 = ui->pushButton9;
    pushButtonPlus = ui->pushButtonPlus;
    pushButtonMinus = ui->pushButtonMinus;
    pushButtonMul = ui->pushButtonMul;
    pushButtonDiv = ui->pushButtonDiv;
    pushButtonEqual = ui->pushButtonEqual;
    pushButtonPoint = ui->pushButtonPoint;
    pushButtonL = ui->pushButtonL;
    pushButtonR = ui->pushButtonR;
    pushButtonBack = ui->pushButtonBack;
    pushButtonClear = ui->pushButtonClear;
    pushButtonPow = ui->pushButtonPow;
    pushButtonSquare = ui->pushButtonSquare;
    pushButtonCube = ui->pushButtonCube;
    pushButtonReciprocal = ui->pushButtonReciprocal;
    pushButtonRooting = ui->pushButtonRooting;
    pushButtonCubeRoot = ui->pushButtonCubeRoot;
    pushButtonLog = ui->pushButtonLog;
    pushButtonLn = ui->pushButtonLn;
    pushButtonPi = ui->pushButtonPi;
    pushButtonE = ui->pushButtonE;
    listWidget = ui->listWidget;
    lineEdit1 = ui->lineEdit1;
    lineEdit2 = ui->lineEdit2;
    QMenu* menu = ui->menubar->addMenu("关于");
    QAction* action = menu->addAction("关于作者");
    connect(action, SIGNAL(triggered()), this, SLOT(newSlot()));
}

void MainWindow::SetStyleSheet()
{
    // 数字按钮样式表
    QString StyleSheetNumbers = "QPushButton { color: black; background-color: #FAFAFA; border: none; font: 17pt 'Microsoft YaHei UI'; outline: none;} QPushButton:hover { background-color: #D8D8D8; border-style: solid; border-width: 3px; border-color: #F2F2F2; } QPushButton:pressed { background-color: #A4A4A4; border-style: solid; border-width: 3px; border-color: #E6E6E6; }";
    // 符号按钮样式表
    QString StyleSheetSigns =   "QPushButton { color: black; background-color: #E6E6E6; border: none; font: 19pt 'Microsoft YaHei UI Light'; outline: none; } QPushButton:hover { background-color: #2ECCFA; border-style: solid; border-width: 3px; border-color: #58D3F7; } QPushButton:pressed { background-color: #81DAF5; border-style: solid; border-width: 3px; border-color: #A9E2F3; }";

    // 给数字按钮设置样式表
    pushButton0->setStyleSheet(StyleSheetNumbers);
    pushButton1->setStyleSheet(StyleSheetNumbers);
    pushButton2->setStyleSheet(StyleSheetNumbers);
    pushButton3->setStyleSheet(StyleSheetNumbers);
    pushButton4->setStyleSheet(StyleSheetNumbers);
    pushButton5->setStyleSheet(StyleSheetNumbers);
    pushButton6->setStyleSheet(StyleSheetNumbers);
    pushButton7->setStyleSheet(StyleSheetNumbers);
    pushButton8->setStyleSheet(StyleSheetNumbers);
    pushButton9->setStyleSheet(StyleSheetNumbers);

    // 给符号按钮设置样式表
    pushButtonPlus->setStyleSheet(StyleSheetSigns);
    pushButtonMinus->setStyleSheet(StyleSheetSigns);
    pushButtonMul->setStyleSheet(StyleSheetSigns);
    pushButtonDiv->setStyleSheet(StyleSheetSigns);
    pushButtonEqual->setStyleSheet(StyleSheetSigns);
    pushButtonPoint->setStyleSheet(StyleSheetSigns);
    pushButtonL->setStyleSheet(StyleSheetSigns);
    pushButtonR->setStyleSheet(StyleSheetSigns);
    pushButtonBack->setStyleSheet(StyleSheetSigns);
    pushButtonClear->setStyleSheet(StyleSheetSigns);
    pushButtonPow->setStyleSheet(StyleSheetSigns);
    pushButtonSquare->setStyleSheet(StyleSheetSigns);
    pushButtonCube->setStyleSheet(StyleSheetSigns);
    pushButtonReciprocal->setStyleSheet(StyleSheetSigns);
    pushButtonRooting->setStyleSheet(StyleSheetSigns);
    pushButtonCubeRoot->setStyleSheet(StyleSheetSigns);
    pushButtonLog->setStyleSheet(StyleSheetSigns);
    pushButtonLn->setStyleSheet(StyleSheetSigns);
    pushButtonPi->setStyleSheet(StyleSheetSigns);
    pushButtonE->setStyleSheet(StyleSheetSigns);

    // 给控件设置样式表
    listWidget->setStyleSheet("QListWidget { background-color: #f0f0f0; border: none;}");
    lineEdit1->setStyleSheet("QLineEdit { font : 9pt 'Microsoft YaHei UI Light'; background-color: #f0f0f0; border: none;}");
    lineEdit2->setStyleSheet("QLineEdit { font : 30pt 'Microsoft YaHei UI'; background-color: #f0f0f0; border: none;}");

    // 部分特殊按钮设置显示图标(Unicode)
    pushButtonBack->setText(QString::fromUtf8("\u232B"));
    pushButtonSquare->setText(QString::fromUtf8("x\u00B2"));
    pushButtonCube->setText(QString::fromUtf8("x\u00B3"));
    pushButtonReciprocal->setText(QString::fromUtf8("1/x"));
    pushButtonRooting->setText(QString::fromUtf8("\u221A"));
    pushButtonCubeRoot->setText(QString::fromUtf8("\u221B"));
}

void MainWindow::compute()
{
    double a = pop(&nums);
    double b = pop(&nums);
    char c = popChar(&ops);
    double d;

    if (c == '+')
        d = b + a;
    else if (c == '-')
        d = b - a;
    else if (c == '*')
        d = b * a;
    else if (c == '/')
    {
        if(a == 0)
        {
            zeroError = 1;
            push(&nums, 0);
        }
        d = b / a;
    }
    else{
        d = pow(b, a);
    }
    push(&nums, d);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPoint_clicked()
{
    if(pointSign1)
    {
        return;
    }
    lineEdit2->setText(lineEdit2->text().append("."));
    pointSign1 = 1;
    pointSign2 = 1;
}

void MainWindow::on_pushButton0_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("0"));
}

void MainWindow::on_pushButton1_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("1"));
}

void MainWindow::on_pushButton2_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("2"));
}

void MainWindow::on_pushButton3_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("3"));
}

void MainWindow::on_pushButton4_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("4"));
}

void MainWindow::on_pushButton5_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("5"));
}

void MainWindow::on_pushButton6_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("6"));
}

void MainWindow::on_pushButton7_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("7"));
}

void MainWindow::on_pushButton8_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("8"));
}

void MainWindow::on_pushButton9_clicked()
{
    if(pointSign2) pointSign2 = 0;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
        lineEdit2->clear();
    }
    if(optSign || numberSign == 0)
    {
        optSign = 0;
        numberSign = 1;
        lineEdit2->clear();
    }
    lineEdit2->setText(lineEdit2->text().append("9"));
}

void MainWindow::on_pushButtonPlus_clicked()
{
    if(optSign || pointSign2) return;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }
    if(rightBracketSign)
    {
        lineEdit1->setText(lineEdit1->text().append("+"));
        rightBracketSign = 0;
        optSign = 1;
        return;
    }
    lineEdit1->setText(lineEdit1->text().append(lineEdit2->text() + "+"));
    optSign = 1;

    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonMinus_clicked()
{
    if(optSign || pointSign2) return;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }
    if(rightBracketSign)
    {
        lineEdit1->setText(lineEdit1->text().append("-"));
        rightBracketSign = 0;
        optSign = 1;
        return;
    }
    lineEdit1->setText(lineEdit1->text().append(lineEdit2->text() + "-"));
    optSign = 1;

    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonMul_clicked()
{
    if(optSign || pointSign2) return;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }
    if(rightBracketSign)
    {
        lineEdit1->setText(lineEdit1->text().append("*"));
        rightBracketSign = 0;
        optSign = 1;
        return;
    }
    lineEdit1->setText(lineEdit1->text().append(lineEdit2->text() + "*"));
    optSign = 1;

    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonDiv_clicked()
{
    if(optSign || pointSign2) return;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }
    if(rightBracketSign)
    {
        lineEdit1->setText(lineEdit1->text().append("/"));
        rightBracketSign = 0;
        optSign = 1;
        return;
    }
    lineEdit1->setText(lineEdit1->text().append(lineEdit2->text() + "/"));
    optSign = 1;

    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonEqual_clicked()
{
    if(pointSign2) return;
    if(rightBracketSign == 0)
    {
        // 计算之前先把lineEdit2的数加到lineEdit1;
        lineEdit1->setText(lineEdit1->text().append(lineEdit2->text()));
    }
    string str;
    str = lineEdit1->text().toStdString();
    string left;
    for (int i = 0; i <= str.size(); i++) // 保证左括号比右括号多
        left += '(';
    str = left + str + ')';

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') /* 操作数 */
        {
            int j = i;
            double t = 0;
            while ((str[j] >= '0' && str[j] <= '9') || str[j] == '.')
            {
                j++;
            }
            t = atof(str.substr(i, j-i).c_str());
            i = j - 1;
            push(&nums, t);
        }
        else /* 操作符 */
        {
            char c = str[i];
            if (c == '+' || c == '-')   // 加减的情况
            {
                if(c == '-' && i && !(str[i-1] >= '0' && str[i-1] <= '9' || str[i-1] == ')'))   // 负数情况
                {
                    int j = i + 1, t = 0;
                    while (str[j] >= '0' && str[j] <= '9')
                    {
                        t = t * 10 + str[j] - '0';
                        j++;
                    }
                    i = j - 1;
                    push(&nums, -t);
                }else
                {
                    while(getCharTop(&ops) != '(')  // 不是左括号，可以计算
                        compute();
                    pushChar(&ops, c);
                }
            }else if(c == '*' || c == '/')  // 乘除的情况
            {
                while(getCharTop(&ops) == '*' || getCharTop(&ops) == '/' || getCharTop(&ops) == '^')    // 优先级判断
                    compute();
                pushChar(&ops, c);
            }else if(c == '^')  // 如果是乘方
            {
                while(getCharTop(&ops) == '^')  // 优先级判断
                    compute();
                pushChar(&ops, c);
            }else if(c == ')')
            {
                while(getCharTop(&ops) != '(')
                    compute();
                popChar(&ops);
            }else if(c == '(')
            {
                pushChar(&ops, c);
            }else{
                puts("invalid");
            }
        }
    }
    QString ans = QString::number(getTop(&nums));
    lineEdit2->setText(ans);
    // 标志一次计算结束。
    computeEnd = 1;

    rightBracketSign = 0;

    pointSign1 = 0;
    pointSign2 = 0;

    // 当表达式中出现除数为零的情况时
    if(zeroError)
    {
        zeroError = 0;
        lineEdit2->setText("除数不能为零");
    }

    QListWidgetItem* item = new QListWidgetItem;
    item->setSizeHint(QSize(300,100));
    item->setText(lineEdit1->text() + " = " + lineEdit2->text());
    cout << lineEdit1->text().toStdString() << endl;
    cout << lineEdit2->text().toStdString() << endl;
    item->setTextAlignment(Qt::AlignCenter);
    listWidget->addItem(item);
}

void MainWindow::on_pushButtonL_clicked()
{
    if(rightBracketSign) return;

    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }

    if(optSign)
    {
        optSign = 0;
        lineEdit2->setText("0");
        numberSign = 0;
    }

    lineEdit1->setText(lineEdit1->text().append("("));
    numOfLeftBracket++;
    //    QListWidgetItem *item= new QListWidgetItem;
    //    listWidget->addItem(item);
}

void MainWindow::on_pushButtonR_clicked()
{
    if(numOfLeftBracket == 0) return;
    else{
        numOfLeftBracket--;
        lineEdit1->setText(lineEdit1->text().append(lineEdit2->text()) + ')');
        rightBracketSign = 1;
    }
}

void MainWindow::on_pushButtonClear_clicked()
{
    lineEdit1->clear();
    lineEdit2->setText("0");
    numberSign = 0;
    optSign = 0;
    computeEnd = 0;
    zeroError = 0;
    numOfLeftBracket = 0;
    rightBracketSign = 0;
    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonBack_clicked()
{
    if(lineEdit2->text() == "0") return;
    if(lineEdit2->text().size() == 1)
    {
        lineEdit2->setText("0");
        numberSign = 0;
        return;
    }
    if(lineEdit2->text().right(1) == ".")
    {
        pointSign1 = 0;
        pointSign2 = 0;
    }
    if(lineEdit2->text().at(lineEdit2->text().size() - 2) == ".")
    {
        pointSign2 = 1;
    }
    lineEdit2->setText(lineEdit2->text().left(lineEdit2->text().size() - 1));
}

void MainWindow::on_pushButtonPow_clicked()
{
    if(optSign || pointSign2) return;
    if(computeEnd)
    {
        // 计算开始
        computeEnd = 0;
        lineEdit1->clear();
    }
    if(rightBracketSign)
    {
        lineEdit1->setText(lineEdit1->text().append("^"));
        rightBracketSign = 0;
        optSign = 1;
        return;
    }
    lineEdit1->setText(lineEdit1->text().append(lineEdit2->text() + "^"));
    optSign = 1;

    pointSign1 = 0;
    pointSign2 = 0;
}

void MainWindow::on_pushButtonSquare_clicked()
{
    if(lineEdit2->text().at(lineEdit2->text().size() - 1) == ".")
    {
        return;
    }
    on_pushButtonPow_clicked();
    on_pushButton2_clicked();
}

void MainWindow::on_pushButtonCube_clicked()
{
    if(lineEdit2->text().at(lineEdit2->text().size() - 1) == ".")
    {
        return;
    }
    on_pushButtonPow_clicked();
    on_pushButton3_clicked();
}

void MainWindow::on_pushButtonReciprocal_clicked()
{
    if(lineEdit2->text().at(lineEdit2->text().size() - 1) == ".")
    {
        return;
    }
    int size = lineEdit2->text().size();
    QString text = lineEdit2->text();
    for(int i = 0; i < size; i++)
        on_pushButtonBack_clicked();
    on_pushButton1_clicked();
    on_pushButtonDiv_clicked();
    on_pushButtonL_clicked();
    for(int i = 0; i < size; i++)
    {
        QChar t = text.at(i);
        if(t == '0')    on_pushButton0_clicked();
        else if(t == '1')   on_pushButton1_clicked();
        else if(t == '2')   on_pushButton2_clicked();
        else if(t == '3')   on_pushButton3_clicked();
        else if(t == '4')   on_pushButton4_clicked();
        else if(t == '5')   on_pushButton5_clicked();
        else if(t == '6')   on_pushButton6_clicked();
        else if(t == '7')   on_pushButton7_clicked();
        else if(t == '8')   on_pushButton8_clicked();
        else if(t == '9')   on_pushButton9_clicked();
        else if(t == '.')   on_pushButtonPoint_clicked();
        else if(t == '-')   on_pushButtonMinus_clicked();
    }
    on_pushButtonR_clicked();
}

void MainWindow::on_pushButtonRooting_clicked()
{
    if(lineEdit2->text().at(lineEdit2->text().size() - 1) == ".")
    {
        return;
    }
    if(lineEdit2->text().at(0) == '-')
    {
        computeEnd = 1;
        rightBracketSign = 0;
        pointSign1 = 0;
        pointSign2 = 0;
        lineEdit2->setText("无效输入");
        return;
    }
    on_pushButtonPow_clicked();
    on_pushButtonL_clicked();
    on_pushButton1_clicked();
    on_pushButtonDiv_clicked();
    on_pushButton2_clicked();
    on_pushButtonR_clicked();
}

void MainWindow::on_pushButtonCubeRoot_clicked()
{
    if(lineEdit2->text().at(lineEdit2->text().size() - 1) == ".")
    {
        return;
    }
    on_pushButtonPow_clicked();
    on_pushButtonL_clicked();
    on_pushButton1_clicked();
    on_pushButtonDiv_clicked();
    on_pushButton3_clicked();
    on_pushButtonR_clicked();
}

void MainWindow::on_pushButtonPi_clicked()
{
    int size = lineEdit2->text().size();
    for(int i = 0; i < size; i++)
        on_pushButtonBack_clicked();
    on_pushButton3_clicked();
    on_pushButtonPoint_clicked();
    on_pushButton1_clicked();
    on_pushButton4_clicked();
    on_pushButton1_clicked();
    on_pushButton5_clicked();
    on_pushButton9_clicked();
}

void MainWindow::on_pushButtonE_clicked()
{
    int size = lineEdit2->text().size();
    for(int i = 0; i < size; i++)
        on_pushButtonBack_clicked();
    on_pushButton2_clicked();
    on_pushButtonPoint_clicked();
    on_pushButton7_clicked();
    on_pushButton1_clicked();
    on_pushButton8_clicked();
    on_pushButton2_clicked();
    on_pushButton8_clicked();
}

void MainWindow::on_pushButtonLog_clicked()
{
    double t = atof(lineEdit2->text().toStdString().c_str());
    if(t < 0)
    {
        computeEnd = 1;
        rightBracketSign = 0;
        pointSign1 = 0;
        pointSign2 = 0;
        lineEdit2->setText("无效输入");
        return;
    }else
    {
        t = log10(t);
        QString ans = QString::number(t);
        int Textsize = lineEdit2->text().size();
        int size = ans.size();
        for(int i = 0; i < Textsize; i++)
            on_pushButtonBack_clicked();
        for(int i = 0; i < size; i++)
        {
            QChar t = ans.at(i);
            if(t == '0')    on_pushButton0_clicked();
            else if(t == '1')   on_pushButton1_clicked();
            else if(t == '2')   on_pushButton2_clicked();
            else if(t == '3')   on_pushButton3_clicked();
            else if(t == '4')   on_pushButton4_clicked();
            else if(t == '5')   on_pushButton5_clicked();
            else if(t == '6')   on_pushButton6_clicked();
            else if(t == '7')   on_pushButton7_clicked();
            else if(t == '8')   on_pushButton8_clicked();
            else if(t == '9')   on_pushButton9_clicked();
            else if(t == '.')   on_pushButtonPoint_clicked();
        }
    }
}

void MainWindow::on_pushButtonLn_clicked()
{
    double t = atof(lineEdit2->text().toStdString().c_str());
    if(t < 0)
    {
        computeEnd = 1;
        rightBracketSign = 0;
        pointSign1 = 0;
        pointSign2 = 0;
        lineEdit2->setText("无效输入");
        return;
    }else
    {
        t = log(t);
        QString ans = QString::number(t);
        int Textsize = lineEdit2->text().size();
        int size = ans.size();
        for(int i = 0; i < Textsize; i++)
            on_pushButtonBack_clicked();
        for(int i = 0; i < size; i++)
        {
            QChar t = ans.at(i);
            if(t == '0')    on_pushButton0_clicked();
            else if(t == '1')   on_pushButton1_clicked();
            else if(t == '2')   on_pushButton2_clicked();
            else if(t == '3')   on_pushButton3_clicked();
            else if(t == '4')   on_pushButton4_clicked();
            else if(t == '5')   on_pushButton5_clicked();
            else if(t == '6')   on_pushButton6_clicked();
            else if(t == '7')   on_pushButton7_clicked();
            else if(t == '8')   on_pushButton8_clicked();
            else if(t == '9')   on_pushButton9_clicked();
            else if(t == '.')   on_pushButtonPoint_clicked();
        }
    }
}

void MainWindow::copySeedSlot()
{
    QListWidgetItem* item = listWidget->currentItem();
    // 获取系统剪贴板指针
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->setText(item->text());                          //设置剪贴板内容</span>
}

void MainWindow::deleteSeedSlot()
{
    int ch = QMessageBox::warning(NULL, "Warning",
                                      "你是否要删除这条记录?",
                                      QMessageBox::Yes | QMessageBox::No,
                                      QMessageBox::No);
    if ( ch != QMessageBox::Yes )
        return;

    QListWidgetItem* item = listWidget->currentItem();
    if( item == NULL )
        return;

    int curIndex = listWidget->row(item);
    listWidget->takeItem(curIndex);
    delete item;
}

void MainWindow::newSlot()
{
    int ch = QMessageBox::information(NULL, "关于作者",
                                      "BJTU 18221221 dl",
                                      QMessageBox::Yes);
    if ( ch != QMessageBox::Yes )
        return;
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* curItem = listWidget->itemAt(pos);
    if(curItem == NULL)
        return;
    QMenu* popMenu = new QMenu(this);
    QAction* copySeed = new QAction(tr("Copy"), this);
    QAction* deleteSeed = new QAction(tr("Delete"), this);
    popMenu->addAction(copySeed);
    popMenu->addAction(deleteSeed);
    connect(copySeed, SIGNAL(triggered()), this, SLOT(copySeedSlot()));
    connect(deleteSeed, SIGNAL(triggered()), this, SLOT(deleteSeedSlot()));
    popMenu->exec(QCursor::pos());
    delete popMenu;
    delete deleteSeed;
    delete copySeed;
}




