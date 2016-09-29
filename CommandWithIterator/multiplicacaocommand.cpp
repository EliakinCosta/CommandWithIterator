#include "multiplicacaocommand.h"

MultiplicacaoCommand::MultiplicacaoCommand(float *number, float newNumber, QObject *parent):
    ICommand(parent),
    m_number(number),
    m_newNumber(newNumber)
{

}

void MultiplicacaoCommand::redo()
{
    *m_number = *m_number * m_newNumber;
}

void MultiplicacaoCommand::undo()
{
    *m_number = *m_number / m_newNumber;
}
