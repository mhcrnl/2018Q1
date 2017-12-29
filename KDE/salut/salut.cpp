#include "salut.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include <KAboutData>

salut::salut()
{
    QLabel* label = new QLabel( this );
    label->setText( "SALUT!" );
    setCentralWidget( label );
    QAction* action = new QAction(this);
    action->setText( "Quit" );
    connect(action, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( action );
}

salut::~salut()
{}

#include "salut.moc"
