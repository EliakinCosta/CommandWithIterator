#ifndef COMMANDITERATOR_H
#define COMMANDITERATOR_H

#include <QObject>
#include <QMetaObject>
#include <QDebug>

class QString;

template<typename typeCollection>
class CommandIterator
{
public:
    CommandIterator(typeCollection historicoDeCommands, QString className):
        m_historicoDeCommands(historicoDeCommands),
        m_className(className),
        m_currentIndex(0)
    {
        m_iterator = m_historicoDeCommands.begin();
    }

    virtual ~CommandIterator()
    {
        delete this->m_next;
    }

    bool hasNext()
    {
        while(m_iterator != m_historicoDeCommands.end())
        {
            if(m_className == QString((*m_iterator)->metaObject()->className()))
            {
                m_next = *m_iterator;
                ++m_iterator;
                return true;
            }
            ++m_iterator;
        }
        return false;
    }

    QObject *next()
    {
        return this->m_next;
    }
private:
    typeCollection m_historicoDeCommands;
    QString m_className;
    typename typeCollection::iterator m_iterator;
    int m_currentIndex;
    QObject *m_next;

};

#endif // COMMANDITERATOR_H
