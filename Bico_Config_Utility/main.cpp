#include "mainwindow.h"
#include <QApplication>
#include <QDir>

#define AMOLED "/ex_stylesheet/AMOLED.qss"
#define AQUA "/ex_stylesheet/Aqua.qss"
#define CONSOLEDARK "/ex_stylesheet/ConsoleDark.qss"        // This good
#define ELEGANTDARK "/ex_stylesheet/ElegantDark.qss"
#define MATERIALDARK "/ex_stylesheet/MateialDark.qss"       // This OK
#define UBUNTU "/ex_stylesheet/Ubuntu.qss"                  // This good
#define QDRAKSHEET "/ex_stylesheet/QDarkStyleSheet.qss"     // This so good (Qt's theme)
#define DARKSTYLE "/ex_stylesheet/darkstyle.qss"
#define DIFFNES "/ex_stylesheet/Diffnes.qss"
#define COMBINEAR "/ex_stylesheet/Combinear.qss"
#define DARKEUM "/ex_stylesheet/Darkeum.qss"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load an application style
    QFile styleFile(QDir::currentPath() + UBUNTU);
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    MainWindow w;
    w.show();

    return a.exec();
}
