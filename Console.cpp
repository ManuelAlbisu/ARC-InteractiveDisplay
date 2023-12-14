#include "Console.h"

#include <QDockWidget>
#include <QVBoxLayout>

Console::Console(QWidget *console) : QWidget(console) {
    createConsole();
}

Console::~Console() { }

void Console::createConsole() {
    // initializes the command line
    m_console = new QListWidget();
    m_input = new QLineEdit();

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
