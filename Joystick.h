#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QWidget>

class Joystick : public QWidget {
    Q_OBJECT

public:
    explicit Joystick(int size = 200, QWidget *parent = nullptr);
    ~Joystick();
    float radius() const { return 0.5f * m_size - cursor(); }
    QPointF center() const { return 0.5f * QPointF(m_size, m_size); }

signals:
    void updated(float x, float y);

protected:
    float cursor() const { return 5; }
    void updateMouse(float x, float y);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    QSize sizeHint() const override { return QSize(m_size, m_size); }

private:
    QPointF m_joystick;
    int m_size;
};

#endif // JOYSTICK_H
