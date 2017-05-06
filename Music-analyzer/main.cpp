#include <QCoreApplication>
#include <musicanalyzer.h>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MusicAnalyzer m(NULL,"komorniA440hz.mp3");
    m.run();
    return a.exec();
}
