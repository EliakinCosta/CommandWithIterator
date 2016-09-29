#ifndef MULTIPLICACAOCOMMAND_H
#define MULTIPLICACAOCOMMAND_H

#include "icommand.h"

class QObject;

class MultiplicacaoCommand: public ICommand
{
    Q_OBJECT
public:
    MultiplicacaoCommand(float *number, float newNumber, QObject *parent=0);
    virtual ~MultiplicacaoCommand(){}
    virtual void redo();
    virtual void undo();
private:
    float *m_number;
    float m_newNumber;
};

#endif // MULTIPLICACAOCOMMAND_H
