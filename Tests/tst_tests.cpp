#include <QString>
#include <QtTest>

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests();

private Q_SLOTS:
    void speed();
};

Tests::Tests()
{
}

void Tests::speed()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Tests)

#include "tst_tests.moc"
