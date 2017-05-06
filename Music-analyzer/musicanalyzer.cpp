#include "musicanalyzer.h"
#include <QAudioDecoder>
#include <QAudioDeviceInfo>
#include <QDebug>
#include <iostream>
#include <QDir>
#include <limits>

using namespace std;

MusicAnalyzer::MusicAnalyzer(QObject *parent, QString filename) : QObject(parent), filename(filename)
{
    decodedSong = new QList<int>;
}

MusicAnalyzer::~MusicAnalyzer(){
    delete decodedSong;
    delete decoder;
}

void MusicAnalyzer::run(){
    QAudioFormat desiredFormat;
    desiredFormat.setChannelCount(2);
    desiredFormat.setCodec("audio/x-raw");
    desiredFormat.setSampleType(QAudioFormat::SignedInt);
    desiredFormat.setSampleRate(48000);
    desiredFormat.setSampleSize(16);

    decoder = new QAudioDecoder(this);
    decoder->setAudioFormat(desiredFormat);
    QDir dir;
    decoder->setSourceFilename(dir.absoluteFilePath(filename)); //TODO throw exceptinon on empty filename
    connect(decoder, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
    connect(decoder, SIGNAL(positionChanged(qint64)), this, SLOT(updateProgress()));
    decoder->start();
}

void MusicAnalyzer::readBuffer(){
    if(!decoder->bufferAvailable())
        return;
    QAudioBuffer buff = decoder->read();
    short  *data = buff.data<short>();
    if(buff.isValid()){
        for(int i = 0;i < buff.frameCount();i++){
            cout << data[i] << endl;
            decodedSong->append(data[i]);
        }
    }
}

void MusicAnalyzer::updateProgress(){
    qint64 position = decoder->position();
    qint64 duration = decoder->duration();

    if(position >= duration){
        /*cout << "Amplitude() " <<Amplitude() << endl;
        cout << "PeakFrequency() " << PeakFrequency() << endl;
        cout << "AverageValue()" << AverageValue() << endl;
        cout << "PeakCount()" << PeakCount() << endl;
        cout << sizeof(short) << endl;
       */ exit(0);
    }
}

int MusicAnalyzer::PeakFrequency(){
    return PeakCount() / 100; //TODO replace 100 with duration
}

int MusicAnalyzer::LowerPeakFrequency(){

}

int MusicAnalyzer:: PeakCount(){
    enum states { NO_PEAK,PEAK };
    int state = NO_PEAK;
    int amp = Amplitude();
    int minPeakValue = amp - amp/10;
    int lastPeakTime = 0;
    QList<int> delays;
    for(int i = 0; i < decodedSong->size();i++){
        switch (state) {
        case NO_PEAK:
            if(decodedSong->at(i) > minPeakValue){
                state = PEAK;
                delays << i - lastPeakTime;
                lastPeakTime = i;
            }
            break;
        case PEAK:
            if(decodedSong->at(i) < minPeakValue)
                state = NO_PEAK;
        default:
            break;
        }
    }
    return delays.size();
}

int MusicAnalyzer::Amplitude(){
    int max = 0;
    for (int i = 0; i < decodedSong->size(); ++i) {
        if (decodedSong->at(i) > max) {
            max = decodedSong->at(i);
        }
    }
    return max;
}

int MusicAnalyzer::AverageValue(){
    double avg;
    qWarning() << decodedSong->size();
    for (int i = 0; i < decodedSong->size(); ++i) {
        avg += decodedSong->at(i) / decodedSong->size();
    }
    return avg;
}
