#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Camera.h"
#include "Console.h"
#include "Joystick.h"
#include "Options.h"
#include "SideBar.h"

#include <QMainWindow>

#include <QAction>
#include <QBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QVideoSink>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QMenu *m_viewMenu;

private:
    /* graphical elements */
    void createActions();
    void createCamera();
    void createCameraButtons();
    void createConsole();
    void createJoystick();
    void createMenuBar();
    void createOptionsMenu();
    void createProgressBar();
    void createSideBar();
    void createStatusBar();
    void createToolBar();

    /* widget templates */
    QAction *makeAction(const QString &name, const QString &statusTip, const QString &icon);
    void makeDock(QWidget *widget, const QString &name, Qt::DockWidgetArea area);
    QVBoxLayout *makeJoystick(Joystick *joystick);

    /* actions */
    QAction *m_cutAction;
    QAction *m_drillAction;
    QAction *m_grindAction;
    QAction *m_grabAction;
    QAction *m_vacuumAction;

    /* camera */
    QMediaCaptureSession *m_capture;
    Camera *m_player;
    QVideoSink *m_sink;

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
};

#endif // MAINWINDOW_H
