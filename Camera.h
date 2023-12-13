#ifndef CAMERA_H
#define CAMERA_H

#include "MainWindow.h"

#include <QWidget>

class Camera : public MainWindow {
    Q_OBJECT

public:
    Camera(MainWindow *parent = nullptr);
    ~Camera();

private slots:

private:

};

#endif // CAMERA_H
