#include "MainWindow.h"

#include <QDockWidget>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // set window size
    resize(800, 600);

    // populate window
    createActions();
    createMenuBar();
    createToolBar();

    // create docks
    createCamera();
    createConsole();
    createJoystick();
    //createOptionsMenu();
}

MainWindow::~MainWindow() { }

void MainWindow::createActions() {
    m_cutAction = makeAction("Cut", "View cut options...", "cut.svg");
    m_drillAction = makeAction("Drill", "View drill options...", "drill.svg");
    m_grindAction = makeAction("Grind", "View grind options...", "grind.svg");
    m_grabAction = makeAction("Grab", "View grab options...", "grab.svg");
    m_vacuumAction = makeAction("Vacuum", "View vacuum options...", "vacuum.svg");
}

void MainWindow::createCamera() {
    m_player = new Camera();
    QCamera *camera = m_player->findCamera();
    m_capture = new QMediaCaptureSession();
    m_capture->setCamera(camera);
    m_sink = new QVideoSink();
    m_capture->setVideoOutput(m_sink);
    connect(m_sink, &QVideoSink::videoFrameChanged, m_player, &Camera::frameChanged);
    camera->start();

    setCentralWidget(m_player);
}

void MainWindow::createConsole() {
    m_console = new Console();
    makeDock(m_console->console(), "Command Line", Qt::BottomDockWidgetArea);

    connect(m_console->input(), SIGNAL(returnPressed()), this, SLOT(m_console->consoleInput()));
}

void MainWindow::createJoystick() {
    /* left joystick */
    Joystick *joystick1 = new Joystick();
    QVBoxLayout *layout1 = makeJoystick(joystick1);

    /* right joystick */
    Joystick *joystick2 = new Joystick();
    QVBoxLayout *layout2 = makeJoystick(joystick2);

    /* join layouts */
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addLayout(layout1);
    layout->addStretch();
    layout->addLayout(layout2);
    m_player->setLayout(layout);
}

void MainWindow::createOptionsMenu() {
    m_optionsMenu = new Options();
    makeDock(m_optionsMenu, "Operations Menu", Qt::RightDockWidgetArea);
}

void MainWindow::createMenuBar() {
    m_fileMenu = menuBar()->addMenu("&File");
    m_editMenu = menuBar()->addMenu("&Edit");
    m_selectionMenu = menuBar()->addMenu("&Selection");
    m_viewMenu = menuBar()->addMenu("&View");
    m_runMenu = menuBar()->addMenu("&Run");
    m_helpMenu = menuBar()->addMenu("&Help");
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

/* templates */
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

QVBoxLayout *MainWindow::makeJoystick(Joystick *joystick) {
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addStretch();
    layout->addWidget(joystick);
    layout->addStretch();

    return layout;
}
