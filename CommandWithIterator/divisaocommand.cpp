#include "divisaocommand.h"

DivisaoCommand::DivisaoCommand(float *number, float newNumber, QObject *parent):
    ICommand(parent),
    m_number(number),
    m_newNumber(newNumber)
{

}

void DivisaoCommand::redo()
{
    *m_number = *m_number / m_newNumber;
}

void DivisaoCommand::undo()
{
    *m_number = *m_number * m_newNumber;
}
