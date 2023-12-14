#include "Camera.h"

#include <QImage>
#include <QVideoFrame>

Camera::Camera(QWidget *camera) : QWidget(camera), m_camera(new QCamera) {
    m_videoLabel = new QLabel();
    m_videoSink = new QVideoSink();

    QObject::connect(m_videoSink, &QVideoSink::videoFrameChanged, m_videoLabel, [this](const QVideoFrame &frame) {
        if (!frame.isValid()) return;

        QImage image = frame.toImage();
        m_videoLabel->setPixmap(QPixmap::fromImage(image));
    });

    m_captureSession.setCamera(m_camera);
    m_captureSession.setVideoSink(m_videoSink);

    // scale camera to fit frame
    m_videoLabel->setMinimumSize(400, 400);
    m_videoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // start camera module
    m_camera->start();
}

Camera::~Camera() {
    // free memory when done with camera
    m_camera->stop();
    delete m_camera;
    delete m_videoSink;
    delete m_videoLabel;
}
