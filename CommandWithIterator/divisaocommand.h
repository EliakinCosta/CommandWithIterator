#ifndef DIVISAOCOMMAND_H
#define DIVISAOCOMMAND_H

#include "icommand.h"

class QObject;

class DivisaoCommand: public ICommand
{
    Q_OBJECT
public:
    DivisaoCommand(float *document, float newNumber, QObject *parent=0);
    virtual ~DivisaoCommand(){}
    virtual void redo();
    virtual void undo();
private:
    float *m_number;
    float m_newNumber;
};

#endif // DIVISAOCOMMAND_H
