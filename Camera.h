#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoSink>
#include <QLabel>

class Camera {
public:
    Camera();
    ~Camera();
    QWidget *camera();

private slots:
    void startCamera();
    void stopCamera();

private:
    QCamera *m_camera;
    QMediaCaptureSession m_captureSession;
    QVideoSink *m_videoSink;
    QLabel *m_videoLabel;
};

#endif // CAMERA_H
