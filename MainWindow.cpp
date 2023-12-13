#include "MainWindow.h"
//#include "CommandLine.h"

#include <QDockWidget>
#include <QIcon>
#include <QSize>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(800, 600);

    createActions();
    createMenuBar();
    createToolBar();
    createCommandLine();
}

MainWindow::~MainWindow() { }

void MainWindow::createActions() {
    // cut action
    m_cutAction = new QAction("Cut");
    m_cutAction->setStatusTip("View cut options...");
    m_cutAction->setIcon(QIcon(":/icons/test.svg"));

    // drill action
    m_drillAction = new QAction("Drill");
    m_drillAction->setStatusTip("View drill options...");
    m_drillAction->setIcon(QIcon(":/icons/test.svg"));

    // grind action
    m_grindAction = new QAction("Grind");
    m_grindAction->setStatusTip("View grind options...");
    m_grindAction->setIcon(QIcon(":/icons/test.svg"));

    // grab action
    m_grabAction = new QAction("Grab");
    m_grabAction->setStatusTip("View grab options...");
    m_grabAction->setIcon(QIcon(":/icons/test.svg"));

    // vacuum action
    m_vacuumAction = new QAction("Vacuum");
    m_vacuumAction->setStatusTip("View vacuum options...");
    m_vacuumAction->setIcon(QIcon(":/icons/test.svg"));
}

void MainWindow::createCommandLine() {
    // initializes the command line
    m_commandLine = new QListWidget();
    m_input = new QLineEdit();

    // creates the command line dock
    QDockWidget *dock = new QDockWidget("Command Line", this);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea
                          | Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // creates the command line layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_commandLine);
    layout->addWidget(m_input);

    // sets the layout to the command line widget
    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    // adds the command line widget to the dock
    dock->setWidget(widget);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    m_viewMenu->addAction(dock->toggleViewAction());

    // sets starting text
    m_commandLine->addItem("Input command");

    // sends input to command line
    connect(m_input, SIGNAL(returnPressed()), this, SLOT(commandLineInput()));
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

void MainWindow::createOptionsMenu() { }

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

void MainWindow::commandLineInput() {
    // sends command to command line then clears input box
    QString command = m_input->text();
    m_commandLine->addItem(command);
    executeCommand(command);
    m_input->clear();
}

void MainWindow::executeCommand(const QString &command) {
    static QRegularExpression re("\\s+");
    QStringList list = command.split(re);

    if (command.toLower() == "clear")
        m_commandLine->clear();
}
