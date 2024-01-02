#include "Camera.h"

#include <algorithm>

#include <QMediaDevices>
#include <QPainter>

Camera::Camera(QWidget *parent) : QWidget(parent) { camera(); }

Camera::~Camera() { }

void Camera::camera() {
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();

    for(const QCameraDevice &cameraDevice : cameras)
        qDebug() << cameraDevice.description() << Qt::endl;

    if(cameras.empty()) {
        m_camera = nullptr;
        m_capture = nullptr;
    }

    m_camera = new QCamera(cameras.first());
    m_capture = new QMediaCaptureSession();
    m_capture->setCamera(m_camera);

    m_sink = new QVideoSink();
    m_capture->setVideoOutput(m_sink);

    connect(m_sink, &QVideoSink::videoFrameChanged, this, &Camera::frameChanged);

    m_camera->start();
}

void Camera::drawImage(QPainter &painter, const QRect &frame, const QPixmap &image) {
    float ratio = std::min((float)frame.width() / image.width(),
                      (float)frame.height() / image.height());
    int x = (frame.width() - image.width() * ratio) / 2;
    int y = (frame.height() - image.height() * ratio) / 2;

    painter.drawPixmap(x, y, image.width() * ratio, image.height() * ratio, image);
}

void Camera::frameChanged(const QVideoFrame &frame) {
    if(!frame.isValid())
        return;

    m_pixmap.convertFromImage(frame.toImage());
    update();
}

void Camera::paintEvent(QPaintEvent *event) {
    if(m_pixmap.isNull())
        return;

    QPainter painter(this);
    drawImage(painter, rect(), m_pixmap);
}
