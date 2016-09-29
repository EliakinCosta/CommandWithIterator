#ifndef COMMANDSTACK_H
#define COMMANDSTACK_H

#include <QList>
#include "commanditerator.h"

class ICommand;
class QObject;

class CommandStack
{
public:
    CommandStack();
    virtual ~CommandStack();
    void push(ICommand *command);
    bool undo();
    bool redo();
    CommandIterator<QList<QObject*>> *createIterator(QString className);
private:
    QList<QObject *> *m_commandStack;
    int m_currentIndex;
};

#endif // COMMANDSTACK_H
