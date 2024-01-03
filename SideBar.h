#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QAction>
#include <QWidget>

class SideBar : public QWidget {
    Q_OBJECT

public:
    explicit SideBar(QWidget *parent = nullptr);
    ~SideBar();
    void addAction(QAction *action);
    QAction *addAction(const QString &text, const QIcon &icon = QIcon());
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    QAction *actionAt(const QPoint &at);

private:
    QList<QAction *> m_actions;
    QAction *m_checkedAction;
    QAction *m_overAction;
};

#endif // SIDEBAR_H
