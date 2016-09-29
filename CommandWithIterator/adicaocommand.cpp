#include "adicaocommand.h"
#include <QObject>

AdicaoCommand::AdicaoCommand(float *number, float newNumber,  QObject *parent):
    ICommand(parent),
    m_number(number),
    m_newNumber(newNumber)
{

}

void AdicaoCommand::redo()
{
    *m_number = *m_number + m_newNumber;
}

void AdicaoCommand::undo()
{
    *m_number = *m_number - m_newNumber;
}
