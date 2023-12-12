#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    /* basic functionality */
    void createButtons();
    void createCommandDock();
    void createCommandLine();
    void createMenuBar();
    void createProgressBar();
    void createSideBar();
    void createStatusBar();
    void createToolBar();
    void createToolDock();

    /* command line */
    void commandLine();
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
    QToolBar *m_cutToolBar;
    QToolBar *m_drillToolBar;
    QToolBar *m_grindToolBar;
    QToolBar *m_grabToolBar;
    QToolBar *m_vacuumToolBar;

    /* tool dock */
};

#endif // MAINWINDOW_H
