#include <QString>
#include <QtTest>
#include "musicanalyzer.h"

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests();

private Q_SLOTS:
    void speed();
    void peakFrequencyTest();
};

Tests::Tests()
{
}

void Tests::speed()
{
    MusicAnalyzer m;
}

void Tests::peakFrequencyTest(){

}

QTEST_APPLESS_MAIN(Tests)

#include "tst_tests.moc"
