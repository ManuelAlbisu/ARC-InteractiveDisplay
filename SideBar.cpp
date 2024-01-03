#include "SideBar.h"

#include <QDebug>
#include <QEvent>
#include <QPainter>
#include <QPaintEvent>

#define actionHeight 90

SideBar::SideBar(QWidget *parent)
    : QWidget(parent), m_checkedAction(NULL), m_overAction(NULL) {
    setMouseTracking(true);
}

SideBar::~SideBar() { }

void SideBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    /* set font */
    QFont fontText(painter.font());
    fontText.setFamily("Helvetica Neue");
    painter.setFont(fontText);

    /* set color for box */
    int yAction = 0;
    painter.fillRect(rect(), QColor(100, 100, 100));

    for(auto action : m_actions) {
        QRect actionRect(0, yAction, event->rect().width(), actionHeight);

        /* set color on hover or checked */
        if(action->isChecked())
            painter.fillRect(actionRect, QColor(35, 35, 35));

        if(action == m_overAction)
            painter.fillRect(actionRect, QColor(150, 150, 150));

        /* set position for text */
        painter.setPen(QColor(255, 255, 255));
        QSize size = painter.fontMetrics().size(Qt::TextSingleLine, action->text());
        QRect actionTextRect(QPoint(actionRect.width() / 2 - size.width() / 2,
                                    actionRect.bottom() - size.height() - 5), size);
        painter.drawText(actionTextRect, Qt::AlignCenter, action->text());

        /* set position for icon */
        QRect actionIconRect(0, yAction + 10, actionRect.width(),
                             actionRect.height() - 2 * actionTextRect.height() - 10);
        QIcon actionIcon(action->icon());
        actionIcon.paint(&painter, actionIconRect);

        yAction += actionRect.height();
    }
}

QSize SideBar::minimumSizeHint() const {
    return actionHeight * QSize(1, m_actions.size());
}

void SideBar::addAction(QAction *action) {
    m_actions.push_back(action);
    action->setCheckable(true);
    update();
}

QAction *SideBar::addAction(const QString &text, const QIcon &icon) {
    QAction *action = new QAction(icon, text, this);
    action->setCheckable(true);
    m_actions.push_back(action);
    update();

    return action;
}

void SideBar::mousePressEvent(QMouseEvent *event) {
    QAction *tempAction = actionAt(event->pos());

    if(tempAction == NULL || tempAction->isChecked())
        return;

    qDebug() << "clicked";

    if(m_checkedAction)
        m_checkedAction->setChecked(false);

    if(m_overAction == tempAction)
        m_overAction = NULL;

    m_overAction = tempAction;
    tempAction->setChecked(true);
    update();
    QWidget::mousePressEvent(event);
}

void SideBar::mouseMoveEvent(QMouseEvent *event) {
    QAction *tempAction = actionAt(event->pos());

    if(tempAction == NULL) {
        m_overAction = NULL;
        update();

        return;
    }

    if(tempAction->isChecked() || m_overAction == tempAction)
        return;

    m_overAction = tempAction;
    update();
    QWidget::mouseMoveEvent(event);
}

void SideBar::leaveEvent(QEvent *event) {
    m_overAction = NULL;
    update();
    QWidget::leaveEvent(event);
}
QAction *SideBar::actionAt(const QPoint &at) {
    int yAction = 0;

    for(auto action : m_actions) {
        QRect actionRect(0, yAction, rect().width(), actionHeight);

        if(actionRect.contains(at))
            return action;

        yAction += actionRect.height();
    }

    return NULL;
}

#undef actionHeight
