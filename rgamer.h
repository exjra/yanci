#ifndef RGAMER_H
#define RGAMER_H

#include <QObject>

#include "rresultpart.h"

class RGamer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<QObject*> results READ results WRITE setResults NOTIFY resultsChanged)
    Q_PROPERTY(QStringList newNumbers READ newNumbers WRITE setNewNumbers NOTIFY newNumbersChanged)

public:
    RGamer();
    QString name() const
    {
        return m_name;
    }

    QList<QObject*> results() const
    {
        return m_results;
    }

    QStringList newNumbers() const
    {
        return m_newNumbers;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }

    void setResults(QList<QObject*> results)
    {
        if (m_results == results)
            return;

        m_results = results;
        emit resultsChanged(m_results);
    }

    void clearNewNumberList();
    void addToNewNumberList(int pVal);
    int calculateNewNumbers();
    void removeFromNewNumberList(int pIndex);

    void setNewNumbers(QStringList newNumbers)
    {
        if (m_newNumbers == newNumbers)
            return;

        m_newNumbers = newNumbers;
        emit newNumbersChanged(m_newNumbers);
    }

private:
    QString m_name;
    QList<QObject*> m_results;
    QList<int> mNewNumbers;

    QStringList m_newNumbers;

signals:
    void nameChanged(QString name);
    void resultsChanged(QList<QObject*> results);
    void newNumbersChanged(QStringList newNumbers);
};

Q_DECLARE_METATYPE(RGamer*);

#endif // RGAMER_H
