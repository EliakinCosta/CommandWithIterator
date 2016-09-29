#ifndef ADICAOCOMMAND_H
#define ADICAOCOMMAND_H

class QObject;

#include "icommand.h"

class AdicaoCommand: public ICommand
{
    Q_OBJECT
public:
    AdicaoCommand(float *document, float newNumber, QObject *parent=0);
    virtual ~AdicaoCommand(){}
    virtual void redo();
    virtual void undo();
private:
    float *m_number;
    float m_newNumber;
};

#endif // ADICAOCOMMAND_H
