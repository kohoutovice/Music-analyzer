#ifndef MUSICANALIZER_H
#define MUSICANALIZER_H

#include <QObject>
#include <QAudioDecoder>
class MusicAnalizer : public QObject
{
    Q_OBJECT
public:
    explicit MusicAnalizer(QObject *parent = 0);

    typedef struct songDataAnalyzed{
        int speed;
        int rate;
    }songDataAnalyzed_t;
public slots:
    int analyzeSong(QString filename);
    int getSpeed(QString filename);
    void readBuffer();

signals:

private:
     QAudioDecoder *decoder;

};

#endif // MUSICANALIZER_H
