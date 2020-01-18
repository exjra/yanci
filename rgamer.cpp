#include "rgamer.h"

RGamer::RGamer()
{
    qRegisterMetaType<RGamer*>("RGamer*");
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

void RGamer::addNewResult(int pValue)
{
    QList<QObject*> tList(results());

    RResultPart* tPart = new RResultPart();
    tPart->setValue(pValue);

    tList.append(tPart);

    setResults(tList);
}

int RGamer::getTotalResult()
{
    int tRet = 0;

    for(int t = 0; t<results().length(); t++)
    {
        RResultPart* tPart = (RResultPart*) results().at(t);

        if(!tPart->deleted())
            tRet += tPart->value();
    }

    return tRet;
}

void RGamer::refreshResult()
{
    emit resultsChanged(m_results);
}
