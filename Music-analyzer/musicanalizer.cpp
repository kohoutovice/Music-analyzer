#include "musicanalizer.h"
#include <QAudioDecoder>
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
    desiredFormat.setSampleRate(48000);
    desiredFormat.setSampleSize(16);

    decoder = new QAudioDecoder(this);
    decoder->setAudioFormat(desiredFormat);
    decoder->setSourceFilename(filename);

    connect(decoder, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
    decoder->start();

    // Now wait for bufferReady() signal and call decoder->read()
}

void MusicAnalizer::readBuffer(){
    QAudioBuffer buff = decoder->read();
    qDebug() << buff.data();
}
