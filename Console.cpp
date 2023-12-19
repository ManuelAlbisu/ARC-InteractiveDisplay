#include "Console.h"

#include <QDockWidget>
#include <QVBoxLayout>

Console::Console() { init(); }

Console::~Console() { }

void Console::init() {
    // sends input from text box to command history
    QObject::connect(m_input, SIGNAL(returnPressed()), nullptr, SLOT(consoleInput()));
}

QWidget *Console::console() {
    // initializes the console components
    m_console = new QListWidget();
    m_input = new QLineEdit();

    // sets introduction text
    m_console->addItem("Input command");

    // sets console components to a layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_console);
    layout->addWidget(m_input);

    // sets layout to a widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    return widget;
}

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
