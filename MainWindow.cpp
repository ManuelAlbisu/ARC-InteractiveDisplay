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
    // cut action
    m_cutAction = new QAction("Cut");
    m_cutAction->setStatusTip("View cut options...");
    m_cutAction->setIcon(QIcon("../ARC-ID/icons/test.svg"));

    // drill action
    m_drillAction = new QAction("Drill");
    m_drillAction->setStatusTip("View drill options...");
    m_drillAction->setIcon(QIcon("../ARC-ID/icons/test.svg"));

    // grind action
    m_grindAction = new QAction("Grind");
    m_grindAction->setStatusTip("View grind options...");
    m_grindAction->setIcon(QIcon("../ARC-ID/icons/test.svg"));

    // grab action
    m_grabAction = new QAction("Grab");
    m_grabAction->setStatusTip("View grab options...");
    m_grabAction->setIcon(QIcon("../ARC-ID/icons/test.svg"));

    // vacuum action
    m_vacuumAction = new QAction("Vacuum");
    m_vacuumAction->setStatusTip("View vacuum options...");
    m_vacuumAction->setIcon(QIcon("../ARC-ID/icons/test.svg"));
}

void MainWindow::createCamera() {
    m_camera = new Camera();

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

    // creates the console dock
    QDockWidget *dock = new QDockWidget("Operations Menu");
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // creates the console layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_optionsMenu);

    // sets the layout to the console widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // adds the console widget to the dock
    addDockWidget(Qt::RightDockWidgetArea, dock);
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
