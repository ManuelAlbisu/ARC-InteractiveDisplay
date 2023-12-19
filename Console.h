#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>

#include <QLineEdit>
#include <QListWidget>

class Console {
public:
    Console();
    ~Console();
    QWidget *console();

private slots:
    void consoleInput();
    void executeCommand(const QString &command);
    void init();

private:
    QLineEdit *m_input;
    QListWidget *m_console;
};

#endif // CONSOLE_H
