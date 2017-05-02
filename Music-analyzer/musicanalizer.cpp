#include "musicanalizer.h"
#include <QAudioDecoder>


MusicAnalizer::MusicAnalizer(QObject *parent) : QObject(parent)
{

}

int MusicAnalizer::analyzeSong(QString filename){

}

int MusicAnalizer::getSpeed(QString filename){
    averageValue = 0;
    maxPeak = 0;
    minPeak = 0;

}
