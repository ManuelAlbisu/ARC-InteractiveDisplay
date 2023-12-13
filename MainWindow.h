#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAction>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* graphical elements */
    void createActions();
    void createCommandLine();
    void createMenuBar();
    //void createOptionsMenu();
    void createProgressBar();
    void createSideBar();
    void createStatusBar();
    void createToolBar();

    /* actions */
    QAction *m_cutAction;
    QAction *m_drillAction;
    QAction *m_grindAction;
    QAction *m_grabAction;
    QAction *m_vacuumAction;

    /* command line */
    void commandLineInput();
    void executeCommand(const QString &command);
    QLineEdit *m_input;
    QListWidget *m_commandLine;

    /* menu bar */
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_selectionMenu;
    QMenu *m_viewMenu;
    QMenu *m_runMenu;
    QMenu *m_helpMenu;

    /* tool bar */
    QToolBar *m_toolBar;

    /* tool dock */
};

#endif // MAINWINDOW_H
