#include "subtracaocommand.h"

SubtracaoCommand::SubtracaoCommand(float *number, float newNumber, QObject *parent):
    ICommand(parent),
    m_number(number),
    m_newNumber(newNumber)
{

}

void SubtracaoCommand::redo()
{
    *m_number = *m_number - m_newNumber;
}

void SubtracaoCommand::undo()
{
    *m_number = *m_number + m_newNumber;
}
