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
    QLineEdit *input();

private slots:
    void consoleInput();
    void executeCommand(const QString &command);

private:
    QLineEdit *m_input;
    QListWidget *m_console;
};

#endif // CONSOLE_H
