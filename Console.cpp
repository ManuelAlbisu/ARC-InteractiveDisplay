#include "Console.h"

#include <QDockWidget>
#include <QVBoxLayout>

Console::Console(MainWindow *child) : MainWindow(child) { }

Console::~Console() { }

void Console::createConsole() {
    // initializes the command line
    m_console = new QListWidget();
    m_input = new QLineEdit();

    // creates the command line dock
    QDockWidget *dock = new QDockWidget("Command Line", this);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // creates the command line layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_console);
    layout->addWidget(m_input);

    // sets the layout to the command line widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // adds the command line widget to the dock
    dock->setWidget(widget);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    m_viewMenu->addAction(dock->toggleViewAction());

    // sets starting text
    m_console->addItem("Input command");

    // sends input to command line
    connect(m_input, SIGNAL(returnPressed()), this, SLOT(consoleInput()));
}

void Console::consoleInput() {
    // sends command to command line then clears input box
    QString command = m_input->text();
    m_console->addItem(command);
    executeCommand(command);
    m_input->clear();
}

void Console::executeCommand(const QString &command) {
    static QRegularExpression re("\\s+");
    QStringList list = command.split(re);

    if (command.toLower() == "clear")
        m_console->clear();
}
