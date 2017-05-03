#include <QCoreApplication>
#include <musicanalizer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MusicAnalizer m;
    m.getSpeed("sugar.mp3");
    return a.exec();
}
