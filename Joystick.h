#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QWidget>

class Joystick : public QWidget {
    Q_OBJECT

public:
    explicit Joystick(int size = 200, const QColor &color = QColor(255, 255, 255), QWidget *parent = nullptr);
    ~Joystick();
    float radius() const { return 0.5f * m_size - cursor(); }
    QPointF center() const { return 0.5f * QPointF(m_size, m_size); }

signals:
    void updated(float x, float y);

protected:
    /* layout */
    QSize sizeHint() const override { return QSize(m_size, m_size); }
    float cursor() const { return 5; };

    /* mouse */
    void updateMouse(float x, float y);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    /* appearance */
    void paintEvent(QPaintEvent *event) override;
    QColor color(float opacity) const;
    void setPainter(QPainter &painter, float pen, float brush = 0.0f);

private:
    QPointF m_joystick;
    int m_size;
    QColor m_color;
};

#endif // JOYSTICK_H
