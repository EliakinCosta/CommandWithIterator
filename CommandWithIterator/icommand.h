#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <QObject>

class ICommand: public QObject
{
    Q_OBJECT
public:
    ICommand(QObject *parent=0);
    virtual ~ICommand(){}
    virtual void redo() = 0;
    virtual void undo() = 0;
};
#endif // ICOMMAND_H
