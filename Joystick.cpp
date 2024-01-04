#include "Joystick.h"

#include <cmath>

#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPen>

Joystick::Joystick(int size, const QColor &color, QWidget *parent)
    : QWidget(parent), m_size(size), m_color(color), m_joystick(0, 0) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

Joystick::~Joystick() { }

/* helper functions */
float angle(const QPointF &p) {
    return atan2(p.y(), p.x());
}

float length(const QPointF &p) {
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

void drawCircle(QPainter &painter, float x, float y, float radius) {
    painter.drawEllipse(QRectF(x - radius, y - radius, 2 * radius, 2 * radius));
}

void drawLine(QPainter &painter, float x1, float y1, float x2, float y2) {
    painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
}

/* joystick */
void Joystick::updateMouse(float x, float y) {
    QPointF mouse = QPointF(x, y);

    if(m_joystick == mouse)
        return;

    qDebug() << "Joystick: " << x << ", " << y;
    m_joystick = mouse;
    update();
    emit updated(m_joystick.x(), -m_joystick.y());
}

QColor Joystick::color(float opacity) const {
    return QColor(m_color.red(), m_color.green(), m_color.blue(), opacity * 255);
}

void Joystick::setPainter(QPainter &painter, float pen, float brush) {
    QPen p(color(pen));
    p.setCosmetic(true);
    painter.setPen(p);
    painter.setBrush(color(brush));
}

void Joystick::paintEvent(QPaintEvent */*event*/) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    /* scale -1 to 1 */
    painter.translate(center());
    painter.scale(radius(), radius());

    /* draw dials */
    setPainter(painter, 0.4f, 0.4f);
    drawCircle(painter, 0.0f, 0.0f, 1.0f);      // background
    drawCircle(painter, 0.0f, 0.0f, 0.2f);      // aim
    drawLine(painter, -1.0f, 0.0f, 1.0f, 0.0f); // x-axis
    drawLine(painter, 0.0f, -1.0f, 0.0f, 1.0f); // y-axis
    drawCircle(painter, m_joystick.x(), m_joystick.y(), 2 * cursor() / radius()); // cursor
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
    qDebug() << "Mouse press: " << event->pos().x() << ", " << event-pos().y();
}

void Joystick::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Mouse release: " << event->pos().x() << ", " << event->pos().y();
    updateMouse(0, 0);
}
