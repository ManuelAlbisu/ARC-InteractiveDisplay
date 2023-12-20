#include "Camera.h"

#include <QImage>
#include <QVideoFrame>

Camera::Camera() : m_camera(new QCamera) { startCamera(); }

Camera::~Camera() { }

QWidget *Camera::camera() {
    m_videoLabel = new QLabel();
    m_videoSink = new QVideoSink();

    // connect video sink to frame
    QObject::connect(m_videoSink, &QVideoSink::videoFrameChanged,
                     m_videoLabel, [this](const QVideoFrame &frame) {
        if (!frame.isValid())
            return;

        QImage image = frame.toImage();
        m_videoLabel->setPixmap(QPixmap::fromImage(image));
    });

    m_captureSession.setCamera(m_camera);
    m_captureSession.setVideoSink(m_videoSink);

    // scale camera to fit frame
    m_videoLabel->setMinimumSize(400, 400);
    m_videoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    return m_videoLabel;
}

void Camera::startCamera() { m_camera->start(); }

void Camera::stopCamera() { m_camera->stop(); }
