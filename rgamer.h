#ifndef RGAMER_H
#define RGAMER_H

#include <QObject>

#include "rresultpart.h"

class RGamer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<RResultPart*> results READ results WRITE setResults NOTIFY resultsChanged)

public:
    RGamer();
    QString name() const
    {
        return m_name;
    }

    QList<RResultPart*> results() const
    {
        return m_results;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }

    void setResults(QList<RResultPart*> results)
    {
        if (m_results == results)
            return;

        m_results = results;
        emit resultsChanged(m_results);
    }

private:
    QString m_name;


    QList<RResultPart*> m_results;

signals:
void nameChanged(QString name);
void resultsChanged(QList<RResultPart*> results);
};

Q_DECLARE_METATYPE(RGamer*);

#endif // RGAMER_H
