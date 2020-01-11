#include "rresultpart.h"

RResultPart::RResultPart(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<RResultPart*>("RResultPart*");

    setValue(0);
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

    m_value = value;
    emit valueChanged(m_value);
}

void RResultPart::setDeleted(bool deleted)
{
    if (m_deleted == deleted)
        return;

    m_deleted = deleted;
    emit deletedChanged(m_deleted);
}
