#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets/QtWidgets>
#include <QtCore/qmath.h>
#include <QtCore/qrandom.h>
#include <QtCore/qstate.h>

class Button : public QGraphicsWidget
{
    Q_OBJECT
public:
    Button(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

signals:
    void pressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;

private:
    QPixmap _pix;
};

#endif // BUTTON_H
