#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QMediaCaptureSession>
#include <QObject>
#include <QVideoSink>
#include <QWidget>

class Camera : public QWidget {
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void findCamera();
    void frameChanged(const QVideoFrame &frame);
    void playCamera(Camera player);

private:
    QCamera *m_camera;
    QMediaCaptureSession *m_capture;
    QPixmap m_pixmap;
    QVideoSink *m_videoSink;
};

#endif // CAMERA_H
