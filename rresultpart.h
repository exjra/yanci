#ifndef RRESULTPART_H
#define RRESULTPART_H

#include <QObject>

class RResultPart : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool deleted READ deleted WRITE setDeleted NOTIFY deletedChanged)
    Q_PROPERTY(bool changed READ changed WRITE setChanged NOTIFY changedChanged)
    Q_PROPERTY(int initialValue READ initialValue NOTIFY initialValueChanged)

public:
    explicit RResultPart(QObject *parent = nullptr);
    explicit RResultPart(int pInitial, QObject *parent = nullptr);

    int value() const;

    bool deleted() const
    {
        return m_deleted;
    }

    bool changed() const
    {
        return m_changed;
    }

    int initialValue() const
    {
        return m_initialValue;
    }

public slots:
    void setValue(int value);

    void setDeleted(bool deleted);

    void setChanged(bool changed)
    {
        if (m_changed == changed)
            return;

        m_changed = changed;
        emit changedChanged(m_changed);
    }

private:
    int m_value;

    bool m_deleted;

    bool m_changed;

    int m_initialValue;

    bool mIsFirstSet;

signals:
    void valueChanged(int value);
    void deletedChanged(bool deleted);
    void changedChanged(bool changed);
    void initialValueChanged(int initialValue);
};

Q_DECLARE_METATYPE(RResultPart*);

#endif // RRESULTPART_H
