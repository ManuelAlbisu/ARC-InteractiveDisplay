#ifndef CONSOLE_H
#define CONSOLE_H

#include "MainWindow.h"

#include <QWidget>

#include <QLineEdit>
#include <QListWidget>

class Console : public MainWindow {
    Q_OBJECT

public:
    Console(MainWindow *child = nullptr);
    ~Console();

private slots:
    void consoleInput();
    void executeCommand(const QString &command);

private:
    void createConsole();

    QLineEdit *m_input;
    QListWidget *m_console;

};

#endif // CONSOLE_H
