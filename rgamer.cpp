#include "rgamer.h"

RGamer::RGamer()
{
    qRegisterMetaType<RGamer*>("RGamer*");

    QList<QObject*> tList;

    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(100);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(200);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(300);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(400);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(500);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(600);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(700);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(800);

        tList.append(tPart);
    }
    {
        RResultPart* tPart = new RResultPart();
        tPart->setValue(900);

        tList.append(tPart);
    }

    setResults(tList);
}

void RGamer::clearNewNumberList()
{
    mNewNumbers.clear();
    m_newNumbers.clear();

    setNewNumbers(QStringList());
}

void RGamer::addToNewNumberList(int pVal)
{
    mNewNumbers.append(pVal);

    QStringList tList(m_newNumbers);
    tList.append(QString::number(pVal));
    setNewNumbers(tList);
}

int RGamer::calculateNewNumbers()
{
    int tRet = 0;

    for(int t = 0; t<mNewNumbers.length(); t++)
        tRet += mNewNumbers.at(t);

    return tRet;
}

void RGamer::removeFromNewNumberList(int pIndex)
{
    if(pIndex >= 0 && pIndex < m_newNumbers.length())
    {
        QStringList tList(m_newNumbers);
        tList.removeAt(pIndex);
        mNewNumbers.removeAt(pIndex);
        setNewNumbers(tList);
    }
}
