#ifndef MUSICANALIZER_H
#define MUSICANALIZER_H

#include <QObject>

class MusicAnalizer : public QObject
{
    Q_OBJECT
public:
    explicit MusicAnalizer(QObject *parent = 0);

    typedef struct songDataAnalyzed{
        int speed;
        int rate;
    }songDataAnalyzed_t;
    int analyzeSong(QString filename);
    int getSpeed(QString filename);
public slots:

signals:

public slots:
};

#endif // MUSICANALIZER_H
