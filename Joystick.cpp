#include "Joystick.h"

#include <cmath>

#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPen>

Joystick::Joystick(int size, QWidget *parent)
    : QWidget(parent), m_size(size), m_joystick(0, 0) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

Joystick::~Joystick() { }

float length(const QPointF &p) {
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

float angle(const QPointF &p) {
    return atan2(p.y(), p.x());
}

QColor color(float opacity) {
    return QColor(QColor(255, 255, 255, opacity * 255));
}

void circle(QPainter &painter, float x, float y, float radius, float pen, float brush) {
    QPen p(color(pen));
    p.setCosmetic(true);
    painter.setPen(p);
    painter.setBrush(color(brush));
    painter.drawEllipse(QRectF(x - radius, y - radius, 2 * radius, 2 * radius));
}

void line(QPainter &painter, float x1, float y1, float x2, float y2, float pen) {
    QPen p(color(pen));
    p.setCosmetic(true);
    painter.setPen(p);
    painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
}

void Joystick::updateMouse(float x, float y) {
    QPointF mouse = QPointF(x, y);

    if(m_joystick == mouse)
        return;

    qDebug() << "Joystick: " << x << " , " << y;
    m_joystick = mouse;
    update();
    emit updated(m_joystick.x(), -m_joystick.y());
}

void Joystick::paintEvent(QPaintEvent */*event*/) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // set scale from -1 to 1
    painter.translate(center());
    painter.scale(radius(), radius());

    // draw dials on screen
    circle(painter, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f);  // background
    circle(painter, 0.0f, 0.0f, 0.25f, 0.2f, 0.1f); // aim
    line(painter, -1.0f, 0.0f, 1.0f, 0.0f, 0.2f);   // x-axis
    line(painter, 0.0f, -1.0f, 0.0f, 1.0f, 0.2f);   // y-axis
    circle(painter, m_joystick.x(), m_joystick.y(),
           2 * cursor() / radius(), 0.0f, 0.5f);    // cursor
}

void Joystick::mouseMoveEvent(QMouseEvent *event) {
    auto j = event->pos() - center();
    auto r = length(j);
    auto a = angle(j);
    r = std::min(r, radius()) / radius();
    float x = r * cos(a);
    float y = r * sin(a);

    updateMouse(x, y);
}

void Joystick::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Mouse press: " << event->pos().x() << ", " << event->pos().y();
}

void Joystick::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Mouse release: " << event->pos().x() << ", " << event->pos().y();

    updateMouse(0, 0);
}
