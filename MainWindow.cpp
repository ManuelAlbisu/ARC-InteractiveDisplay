#include "MainWindow.h"

#include <QDockWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(800, 600);

    createMenuBar();
    createToolBar();
}

MainWindow::~MainWindow() { }

/* creates the buttons */
void MainWindow::createButtons() { }

/* creates command line dock */
void MainWindow::createCommandDock() {
    // creates command line dock
    QDockWidget *dock = new QDockWidget("Command Line", this);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // Adds console to vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_commandLine);
    layout->addWidget(m_input);

    // Sets layout to a widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // Adds console widget to dock
    dock->setWidget(widget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    m_viewMenu->addAction(dock->toggleViewAction());
}

/* creates the command line box */
void MainWindow::createCommandLine() { }

/* creates menu bar */
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

/* creates progress bar */
void MainWindow::createProgressBar() { }

/* creates side bar */
void MainWindow::createSideBar() { }

/* creates status bar */
void MainWindow::createStatusBar() { }

/* creates tool bar */
void MainWindow::createToolBar() {
    // cut tool bar
    m_cutToolBar = addToolBar("Cut");

    // drill tool bar
    m_drillToolBar = addToolBar("Drill");

    // grind tool bar
    m_grindToolBar = addToolBar("Grind");

    // grab tool bar
    m_grabToolBar = addToolBar("Grab");

    // vacuum tool bar
    m_vacuumToolBar = addToolBar("Vacuum");
}

/* creates tool dock */
void MainWindow::createToolDock() { }

/* handles the command line input */
void MainWindow::commandLine() {
    // creates command line
    m_commandLine = new QListWidget();
    m_input = new QLineEdit();

    // prompts user for help at application start
    m_commandLine->addItem("Type 'list' for available commands.");
}
