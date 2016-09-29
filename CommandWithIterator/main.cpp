#include <QCoreApplication>
#include <QTextStream>

#include "adicaocommand.h"
#include "subtracaocommand.h"
#include "multiplicacaocommand.h"
#include "divisaocommand.h"
#include "commandstack.h"
#include "commanditerator.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CommandStack cmd;
    float number = 0;
    float tmp = 0;

    cmd.push(new AdicaoCommand(&number, tmp));
    cmd.push(new MultiplicacaoCommand(&number, tmp));
    cmd.push(new SubtracaoCommand(&number, tmp));
    cmd.push(new AdicaoCommand(&number, tmp));

    CommandIterator<QList<QObject*>> *iterator = cmd.createIterator(QStringLiteral("MultiplicacaoCommand"));

    while(iterator->hasNext())
    {
        cout << iterator->next()->metaObject()->className() << endl;
    }

    delete iterator;
}
