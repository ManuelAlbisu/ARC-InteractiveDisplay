#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>

#include <QLineEdit>
#include <QListWidget>

class Console : public QWidget {
    Q_OBJECT

public:
    Console(QWidget *parent = nullptr);
    ~Console();

private slots:
    void consoleInput();
    void executeCommand(const QString &command);

private:
    QLineEdit *m_input;
    QListWidget *m_console;

};

#endif // CONSOLE_H
