#include "rresultpart.h"

#include <QDebug>

RResultPart::RResultPart(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<RResultPart*>("RResultPart*");

    mIsFirstSet = true;
    m_initialValue = 0;

    setDeleted(false);
    setChanged(false);
}

RResultPart::RResultPart(int pInitial, QObject *parent) : QObject(parent)
{
    qRegisterMetaType<RResultPart*>("RResultPart*");

    mIsFirstSet = false;
    m_initialValue = pInitial;
    emit initialValueChanged(m_initialValue);

    setDeleted(false);
    setChanged(false);
}

int RResultPart::value() const
{
    return m_value;
}

void RResultPart::setValue(int value)
{
    if (m_value == value)
        return;

    if(mIsFirstSet)
    {
        mIsFirstSet = false;

        m_initialValue = value;
        emit initialValueChanged(m_initialValue);
    }

    m_value = value;
    emit valueChanged(m_value);

    qDebug() << m_initialValue << m_value;
}

void RResultPart::setDeleted(bool deleted)
{
    if (m_deleted == deleted)
        return;

    m_deleted = deleted;
    emit deletedChanged(m_deleted);
}
