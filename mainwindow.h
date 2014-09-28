#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QWebFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void submit();
    void populateJavaScriptWindowObject();
    void ubmit();
     void hello2(char *c_str, char *c_str1);

     void hello(QString sname, QString semail, QString sphone, QString swebsite, QString scomp_name, QString scomp_desc, QString slicense, QString sapp_name, QString sapp_desc);


};

#endif // MAINWINDOW_H
