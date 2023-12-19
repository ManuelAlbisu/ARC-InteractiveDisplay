#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Camera.h"
#include "Console.h"
#include "Options.h"

#include <QMainWindow>

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    /* initialization */
    void init();

    /* graphical elements */
    void createActions();
    void createCamera();
    void createConsole();
    void createMenuBar();
    void createOptionsMenu();
    void createProgressBar();
    void createSideBar();
    void createStatusBar();
    void createToolBar();

    /* widget templates */
    QAction *makeAction(const QString &name, const QString &statusTip, const QString &icon);
    void makeDock(QWidget *widget, const QString &name, Qt::DockWidgetArea area);

    /* actions */
    QAction *m_cutAction;
    QAction *m_drillAction;
    QAction *m_grindAction;
    QAction *m_grabAction;
    QAction *m_vacuumAction;

    /* camera */
    Camera *m_camera;

    /* console */
    Console *m_console;

    /* menu bar */
    QMenu *m_fileMenu;
    QMenu *m_editMenu;
    QMenu *m_selectionMenu;
    QMenu *m_runMenu;
    QMenu *m_helpMenu;

    /* options menu */
    Options *m_optionsMenu;

    /* tool bar */
    QToolBar *m_toolBar;

protected:
    QMenu *m_viewMenu;

};

#endif // MAINWINDOW_H
