#ifndef SUBTRACAOCOMMAND_H
#define SUBTRACAOCOMMAND_H

#include "icommand.h"

class QObject;

class SubtracaoCommand : public ICommand
{
    Q_OBJECT
public:
    SubtracaoCommand(float *document, float newNumber, QObject *parent=0);
    virtual ~SubtracaoCommand(){}
    virtual void redo();
    virtual void undo();
private:
    float *m_number;
    float m_newNumber;
};

#endif // SUBTRACAOCOMMAND_H
