#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonPoint_clicked();

    void on_pushButton0_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButtonPlus_clicked();

    void on_pushButtonMinus_clicked();

    void on_pushButtonMul_clicked();

    void on_pushButtonDiv_clicked();

    void on_pushButtonEqual_clicked();

    void on_pushButtonL_clicked();

    void on_pushButtonR_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonBack_clicked();

    void on_pushButtonPow_clicked();

    void on_pushButtonSquare_clicked();

    void on_pushButtonCube_clicked();

    void on_pushButtonReciprocal_clicked();

    void on_pushButtonRooting_clicked();

    void on_pushButtonCubeRoot_clicked();

    void on_pushButtonPi_clicked();

    void on_pushButtonE_clicked();

    void on_pushButtonLog_clicked();

    void on_pushButtonLn_clicked();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void copySeedSlot();

    void deleteSeedSlot();

    void newSlot();

private:
    Ui::MainWindow *ui;
    void SetStyleSheet();
    void InitComponent();
    void compute();
};
#endif // MAINWINDOW_H
