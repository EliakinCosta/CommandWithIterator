#include "commandstack.h"
#include "icommand.h"
#include "commanditerator.h"

#include <QList>
#include <QObject>


CommandStack::CommandStack():m_commandStack(new QList<QObject *>()),
                             m_currentIndex(0)
{

}

CommandStack::~CommandStack()
{
   qDeleteAll(m_commandStack->cbegin(), m_commandStack->cend());
   m_commandStack->clear();
}


void CommandStack::push(ICommand *command)
{

    for(int i=m_currentIndex;i<this->m_commandStack->length();i++)
        this->m_commandStack->removeAt(i);

    m_currentIndex++;
    this->m_commandStack->append(command);
    command->redo();

}

bool CommandStack::undo()
{
    if(this->m_currentIndex==0)
        return false;
    dynamic_cast<ICommand *>(this->m_commandStack->at(this->m_currentIndex-1))->undo();
    this->m_currentIndex--;
    return true;
}

bool CommandStack::redo()
{
    if(this->m_currentIndex==(this->m_commandStack->length()) || this->m_commandStack->isEmpty())
        return false;
    this->m_currentIndex++;
    dynamic_cast<ICommand *>(this->m_commandStack->at(this->m_currentIndex-1))->redo();
    return true;
}

CommandIterator<QList<QObject*>> *CommandStack::createIterator(QString className)
{
    return new CommandIterator< QList <QObject*> >(*m_commandStack, className);
}
