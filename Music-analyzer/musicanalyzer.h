#ifndef MUSICANALIZER_H
#define MUSICANALIZER_H

#include <QObject>
#include <QAudioDecoder>
#include <QList>
#include <QThread>

class MusicAnalyzer : public QObject
{
    Q_OBJECT
public:
    explicit MusicAnalyzer(QObject *parent = 0,QString filename = "");
    ~MusicAnalyzer();

public slots:
    void run();

signals:
    MusicAnalyzer* finished();
private slots:
    void readBuffer();
    void updateProgress();
    int PeakFrequency();
    int LowerPeakFrequency();
    int Amplitude();
    int AverageValue();
    int PeakCount();
private:
    QList<int> *decodedSong;
    QAudioDecoder *decoder;
    QString filename;
protected:

};

#endif // MUSICANALIZER_H
