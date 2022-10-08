#include "sparrvio.h"
#include "src/s21_SmartCalc.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <string.h>

//#include <QtWidgets/QWidget>
//#include <QSplineSeries>
//#include <QtCharts>
//#include <QChartView>
//#include <QMainWindow>
//#include <QtCharts/QValueAxis>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SmartCalc_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    sparrvio w;
    w.show();
    return a.exec();
}
