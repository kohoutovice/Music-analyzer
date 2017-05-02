#ifndef MUSICANALIZER_H
#define MUSICANALIZER_H

#include <QObject>

class MusicAnalizer : public QObject
{
    Q_OBJECT
public:
    explicit MusicAnalizer(QObject *parent = 0);

signals:

public slots:
};

#endif // MUSICANALIZER_H