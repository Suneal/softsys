#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebElement>
#include <QWebFrame>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QMessageBox>
#include <string>
#include <QProcess>
#include <QDir>

QString sapp_name;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  //  QWidget::showMaximised();
    QMainWindow::showMaximized();
    QMainWindow::showFullScreen();

    ui->setupUi(this);

  //  ui->centralWidget->isMaximized();
   // ui->webView->isMaximized();
  //  ui->webView->setUrl(QUrl("qrc:/new/prefix1/softsys/html/index.html"));
    ui->webView->setUrl(QUrl("qrc:/new/prefix1/softsys/html/index.html"));
      connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()) ,this, SLOT(populateJavaScriptWindowObject()));
  // connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()) ,this, SLOT(populateJavaScriptWindowObject()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::populateJavaScriptWindowObject()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("formExtractor", this);

}

void MainWindow::submit()
{
    QWebFrame *frame = ui->webView->page()->mainFrame();

       QWebElement qname = frame->findFirstElement("#name");
       QWebElement qemail = frame->findFirstElement("#email");
       QWebElement qphone = frame->findFirstElement("#phone");
       QWebElement qwebsite = frame->findFirstElement("#website");
       QWebElement qcomp_name = frame->findFirstElement("#comp_name");
       QWebElement qcomp_desc = frame->findFirstElement("#comp_description");
        QWebElement qlicense = frame->findFirstElement("#license");
       QWebElement qapp_name = frame->findFirstElement("#app_name");
       QWebElement qapp_desc = frame->findFirstElement("#description");


       QString sname = qname.evaluateJavaScript("this.value").toString();
       //char *c_str1 = sname.toString().data();

       QString semail = qemail.evaluateJavaScript("this.value").toString();
      // char *c_str2 = semail.toLocal8Bit().data();

       QString sphone = qphone.evaluateJavaScript("this.value").toString();
      // char *c_str3 = sphone.toLatin1().data();

       QString swebsite = qwebsite.evaluateJavaScript("this.value").toString();
     //  char *c_str4 = swebsite.toLatin1().data();

       QString scomp_name = qcomp_name.evaluateJavaScript("this.value").toString();
      // char *c_str5 = scomp_name.toLocal8Bit().data();

       QString scomp_desc = qcomp_desc.evaluateJavaScript("this.value").toString();
     //  char *c_str6 = scomp_desc.toLocal8Bit().data();
          QString slicense = qlicense.evaluateJavaScript("this.value").toString();

       sapp_name = qapp_name.evaluateJavaScript("this.value").toString();
//       char *c_str7 = sapp_name.toLocal8Bit().data();

       QString sapp_desc = qapp_desc.evaluateJavaScript("this.value").toString();
  //     char *c_str8 = sapp_desc.toLocal8Bit().data();


           hello(sname, semail, sphone, swebsite, scomp_name, scomp_desc, slicense, sapp_name, sapp_desc);
           ui->webView->setUrl(QUrl("qrc:/new/prefix2/gaesql/index.html"));
         //  ui->fisrtname_2->setText(lastName.evaluateJavaScript("this.value").toString());

     //     ui->fisrtname->setText(firstName.evaluateJavaScript("this.value").toString());
       //ui->fisrtname_2->setText(lastName.evaluateJavaScript("this.value").toString());

//         ui->webView->
         //        ui->webView->setUrl(QUrl("qrc:/new/prefix1/gaesql/index.html"));
           //      ui->fisrtname_2->setText(lastName.evaluateJavaScript("this.value").toString());
        //      connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()) ,this, SLOT(populateJavaScriptWindowObject()));
          //    QWebFrame *frame = ui->webView->page()->mainFrame();



}
void MainWindow::hello(QString sname, QString semail, QString sphone, QString swebsite, QString scomp_name, QString scomp_desc, QString slicense, QString sapp_name, QString sapp_desc)
{

  QString fileName= QCoreApplication::applicationDirPath() + "/ABOUT";
  QString fileName1= QCoreApplication::applicationDirPath() + "/LICENSE";


//  QString fileName1 =  QDir::homePath();
//  QString fileName2 =  QCoreApplication::applicationFilePath();

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
                return;
        }
        QTextStream out(&file);

        QString msc = "This app has been developed by ";
        char *c_string1 = msc.toLocal8Bit().data();
        out << c_string1;


        char *name1 = sname.toUtf8().data();
        out << name1;
        out << "\n";

        QString further = "Further details:\n ";
        char *c_string2 = further.toLocal8Bit().data();
        out<<c_string2;
        out<< "App Name: ";
        char *app_name = sapp_name.toUtf8().data();
        out << app_name;
        out << "\n";
        out<< "App Description: ";
        char *app_desc = sapp_desc.toUtf8().data();
        out << app_desc;
        out << "\n";
        out<< "Email: ";
        char *email= semail.toUtf8().data();
        out << email;
        out << "\n";
        out<< "Website: ";
        char *website = swebsite.toUtf8().data();
        out << website;
        out << "\n";

        out<< "Company: ";
        char *comp_name = scomp_name.toUtf8().data();
        out << comp_name;
        out << "\n";

        out<< "Company Description: ";
        char *comp_desc = scomp_desc.toUtf8().data();
        out << comp_desc;
        out << "\n";
        file.close();

    }


    if (fileName1.isEmpty())
        return;
    else {
        QFile file(fileName1);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
                return;
        }
        QTextStream out(&file);

        QString msc = "License: ";
        char *c_string1 = msc.toLocal8Bit().data();
        out << c_string1;


        char *license = slicense.toUtf8().data();
        out << license;
        out << "\n";

        file.close();

    }




    QProcess process;
  //  QProcess gzip;
   // QString c = "softsys.py";
 //      process.start("python", QStringList() << "/Users/user/QTProjects/SoftSys/web2py/"+ c);
//        python web2py.py -a 'your password' -i 127.0.0.1 -p 8000
   // mkdir applications/appname
  //  cd applications/appname
  //  tar zxvf ../../welcome.w2p







    process.start("python" , QStringList() << QCoreApplication::applicationDirPath()+ "/web2py/create.py"<< QCoreApplication::applicationDirPath()+ "/web2py" << sapp_name );









    // process.start("mkdir" , QStringList() << "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name );



           // process.waitForFinished(-1);
          //  process.start("cp" , QStringList() << "/Users/user/QTProjects/SoftSys/web2py/welcome.w2p" << "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name +"/");
          //  process.start("mkdir" , QStringList() <<  sapp_name );
        //    process.pid();
           // process.start("cd", QStringList()<< "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name + "/");
      //      process.waitForFinished(10000);
    //        process.start("tar" , QStringList() << "zxvf"<< "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name + "/welcome.w2p");

  //           process.waitForFinished();
   //         process.start("tar" , QStringList() << "zxvf"<< "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name+ "welcome.w2p" );
//This can be used to run without the starting interface
//    process.start("python", QStringList() << "/Users/user/QTProjects/SoftSys/web2py/softsys.py" << "-a" << "password" << "-i" << "127.0.0.1" << "-p" << "8080");

  //  process.start("open -a iTunes", QStringList());
//    process.start('echo haha');
  process.waitForFinished(-1);
process.close();
  // forever until finished


}

void MainWindow::ubmit()
{
    QWebFrame *frame = ui->webView->page()->mainFrame();
//
  //     QWebElement firstName = frame->findFirstElement("#firstname");

    //   ui->fisrtname->setText(firstName.evaluateJavaScript("this.value").toString());
       QWebElement xmlparsed = frame->findFirstElement("#xmlparsed");
       QString xml = xmlparsed.evaluateJavaScript("this.value").toString();
        char *c_str = xml.toLocal8Bit().data();
          QWebElement sqlparsed = frame->findFirstElement("#sqlparsed");
        QString sql = sqlparsed.evaluateJavaScript("this.value").toString();
         char *c_str1 = sql.toLocal8Bit().data();
        hello2(c_str, c_str1);

     //  ui->fisrtname_2->setText(lastName.evaluateJavaScript("this.value").toString());

//         ui->webView->
         //        ui->webView->setUrl(QUrl("file:///Users/user/Desktop/sunilss/gaesql/index.html"));
           //      ui->fisrtname_2->setText(lastName.evaluateJavaScript("this.value").toString());


}


void MainWindow::hello2(char *c_str, char *c_str1)
{
    // Define Original Path
    QString fileName = QCoreApplication::applicationDirPath() + "/extended.xml";

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
                return;
        }

        QString msc = "this is awesome";

        file.write(c_str);
//        file.write(c_str1);

        file.close();

    }
    QString fileName1 = QCoreApplication::applicationDirPath() + "/db.py";

    if (fileName1.isEmpty())
        return;
    else {
        QFile file(fileName1);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
                return;
        }
        file.write(c_str1);

        file.close();

    }
    this->close();
    QProcess process;
    process.start("cp", QStringList() << QCoreApplication::applicationDirPath() +"/ABOUT" << QCoreApplication::applicationDirPath()+ "/web2py/applications/" + sapp_name+ "/");
    process.waitForFinished(-1);

    process.start("cp", QStringList() << QCoreApplication::applicationDirPath() +"/LICENSE" << QCoreApplication::applicationDirPath()+ "/web2py/applications/" + sapp_name+ "/");
    process.waitForFinished(-1);

     process.start("cp", QStringList() << QCoreApplication::applicationDirPath() +"/db.py" << QCoreApplication::applicationDirPath() + "/web2py/applications/" + sapp_name+ "/models/");
       process.waitForFinished(-1);
       process.start("python", QStringList() <<QCoreApplication::applicationDirPath()+"/automation.py"<< QCoreApplication::applicationDirPath() );
        process.waitForFinished(-1);
       process.start("cp", QStringList() <<QCoreApplication::applicationDirPath()+"/default.py" << QCoreApplication::applicationDirPath()+"/web2py/applications/"+sapp_name+"/controllers/");
 process.waitForFinished(-1);
       process.start("python", QStringList() << QCoreApplication::applicationDirPath() + "/web2py/softsys.py");

 //    process.start("cp" , QStringList() << "/Users/user/QTProjects/SoftSys/web2py/welcome.w2p" << "/Users/user/QTProjects/SoftSys/web2py/applications/" + sapp_name +"/");

        process.waitForFinished(-1);




     //  this->close();
/*
    QProcess process;
//  QProcess gzip;
QString c = "softsys.py";
//      process.start("python", QStringList() << "/Users/user/QTProjects/SoftSys/web2py/"+ c);
//        python web2py.py -a 'your password' -i 127.0.0.1 -p 8000
process.start("python", QStringList() << "/Users/user/QTProjects/SoftSys/web2py/softsys.py" << "-a" << "password" << "-i" << "127.0.0.1" << "-p" << "8000");

//  process.start("open -a iTunes", QStringList());
//    process.start('echo haha');
process.waitForFinished(-1);
// forever until finished
*/

}


