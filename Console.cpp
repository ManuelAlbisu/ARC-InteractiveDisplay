#include "Console.h"

#include <QDockWidget>
#include <QVBoxLayout>

Console::Console(QWidget *parent) : QWidget(parent) {
    // initializes the console components
    m_console = new QListWidget();
    m_input = new QLineEdit();

    // sets console components to a layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_console);
    layout->addWidget(m_input);

    // sets layout to a widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // sets introduction text
    m_console->addItem("Input command");

    // sends input from text box to command history
    connect(m_input, SIGNAL(returnPressed()), this, SLOT(consoleInput()));
}

Console::~Console() { }

void Console::consoleInput() {
    // reads contents user input and sends to command history
    QString command = m_input->text();
    m_console->addItem(command);

    // executes the contents of the command
    executeCommand(command);

    // Clears input box
    m_input->clear();
}

void Console::executeCommand(const QString &command) {
    static QRegularExpression re("\\s+");
    QStringList list = command.split(re);

    if (command.toLower() == "clear")
        m_console->clear();
}
