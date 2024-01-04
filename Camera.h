#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QMediaCaptureSession>
#include <QWidget>

class Camera : public QWidget {
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();
    QCamera *findCamera();

public slots:
    void frameChanged(const QVideoFrame &frame);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QCamera *m_camera;
    QMediaCaptureSession *m_capture;
    QPixmap m_pixmap;
};

#endif // CAMERA_H
