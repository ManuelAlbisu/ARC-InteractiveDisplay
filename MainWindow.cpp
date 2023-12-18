#include "MainWindow.h"

#include <QDockWidget>
#include <QIcon>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // set window size
    resize(800, 600);

    // populate window
    createActions();
    createCamera();
    createConsole();
    createMenuBar();
    createOptionsMenu();
    createToolBar();
}

MainWindow::~MainWindow() { }

void MainWindow::createActions() {
    m_cutAction = makeAction("Cut", "View cut options...", "test.svg");
    m_drillAction = makeAction("Drill", "View drill options...", "test.svg");
    m_grindAction = makeAction("Grind", "View grind options...", "test.svg");
    m_grabAction = makeAction("Grab", "View grab options...", "test.svg");
    m_vacuumAction = makeAction("Vacuum", "View vacuum options...", "test.svg");
}

void MainWindow::createCamera() {
    m_camera = new Camera();
    // makeDock(m_camera, "Camera", Qt::TopDockWidgetArea);

    // creates camera dock
    QDockWidget *dock = new QDockWidget("Camera");
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // creates the camera layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_camera);

    // sets the layout to the camera widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // adds the camera widget to the dock
    addDockWidget(Qt::TopDockWidgetArea, dock);
}

void MainWindow::createConsole() {
    m_console = new Console();
    // makeDock(m_console, "Command Line", Qt::BottomDockWidgetArea);

    // creates the console dock
    QDockWidget *dock = new QDockWidget("Command Line");
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // creates the console layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_console);

    // sets the layout to the console widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // adds the console widget to the dock
    addDockWidget(Qt::BottomDockWidgetArea, dock);
}

void MainWindow::createMenuBar() {
    // file menu
    m_fileMenu = menuBar()->addMenu("&File");

    // edit menu
    m_editMenu = menuBar()->addMenu("&Edit");

    // selection menu
    m_selectionMenu = menuBar()->addMenu("&Selection");

    // view menu
    m_viewMenu = menuBar()->addMenu("&View");

    // run menu
    m_runMenu = menuBar()->addMenu("&Run");

    // help menu
    m_helpMenu = menuBar()->addMenu("&Help");
}

void MainWindow::createOptionsMenu() {
    m_optionsMenu = new Options();
    makeDock(m_optionsMenu, "Operations Menu", Qt::RightDockWidgetArea);
}

void MainWindow::createProgressBar() { }

void MainWindow::createSideBar() { }

void MainWindow::createStatusBar() { }

void MainWindow::createToolBar() {
    m_toolBar = addToolBar("Operations");
    m_toolBar->addAction(m_cutAction);
    m_toolBar->addAction(m_drillAction);
    m_toolBar->addAction(m_grindAction);
    m_toolBar->addAction(m_grabAction);
    m_toolBar->addAction(m_vacuumAction);
}

QAction *MainWindow::makeAction(const QString &name, const QString &statusTip, const QString &icon) {
    QAction *action = new QAction(name);
    action->setStatusTip(statusTip);
    action->setIcon(QIcon(QString("../ARC-ID/icons/") + icon));

    return action;
}

void MainWindow::makeDock(QWidget *widget, const QString &name, Qt::DockWidgetArea area) {
    QDockWidget *dock = new QDockWidget(name, this);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(widget);
    addDockWidget(area, dock);
    m_viewMenu->addAction(dock->toggleViewAction());
}
