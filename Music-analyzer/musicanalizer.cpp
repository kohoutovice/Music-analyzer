#include "musicanalizer.h"
#include <QAudioDecoder>
#include <QAudioDeviceInfo>
#include <QDebug>

MusicAnalizer::MusicAnalizer(QObject *parent) : QObject(parent)
{

}

int MusicAnalizer::analyzeSong(QString filename){

}

int MusicAnalizer::getSpeed(QString filename){

    QAudioFormat desiredFormat;
    desiredFormat.setChannelCount(2);
    desiredFormat.setCodec("audio/x-raw");
    desiredFormat.setSampleType(QAudioFormat::UnSignedInt);
    desiredFormat.setSampleRate(44100);
    desiredFormat.setSampleSize(16);

    decoder = new QAudioDecoder(this);
    decoder->setAudioFormat(desiredFormat);
    decoder->setSourceFilename("/home/xmin/Dropbox/Projekty/build-Music-analyzer-Desktop-Debug/Music-analyzer/sugar.mp3");
    connect(decoder, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
    connect(decoder, SIGNAL(positionChanged(qint64)), this, SLOT(updateProgress()));
    decoder->start();

    // Now wait for bufferReady() signal and call decoder->read()
}

void MusicAnalizer::readBuffer(){
    if(!decoder->bufferAvailable())
        return;
    QAudioBuffer buff = decoder->read();
    if(buff.isValid())
        qWarning() << buff.duration();
}

void MusicAnalizer::updateProgress(){
    qint64 position = decoder->position();
    qint64 duration = decoder->duration();
    qWarning() << "Decoding progress: " << position << " " << duration<< "%" << endl;
}
