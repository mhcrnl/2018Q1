#include "kdeapp.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

kdeapp::kdeapp()
{
    QLabel* label = new QLabel( this );
    label->setText( "Hello World!" );
    setCentralWidget( label );
    QAction* action = new QAction(this);
    action->setText( "Quit" );
    connect(action, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( action );
}

kdeapp::~kdeapp()
{}

#include "kdeapp.moc"
