#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include<QGraphicsScene>

#include "value.h"

#include <QDebug>
#include <QPixmap>


//для работы с сигналами все классs работаюшие с сигналами должны наследоваться от QObject
class Button :public QObject, public QGraphicsItem
{
    //для работы с сигналами все классs работаюшие с сигналами должны такой макросс в начале класса
    Q_OBJECT
public:
    Button();
    QRectF boundingRect() const override;//перекрываю  функцтю  указывает часть екрана которую нужно перересовывать
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *wifget) override;//перекрываю функцию отресовка елементов

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;//перекрываю функцию события нажатия кнопки миши
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;//перекрываю функцию события движенния  мыши
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;//перекрываю функцию события отжатия кнопки миши

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;//перекрываю функцию которая при наводе курсора на объект дает знать об этом
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;//перекрываю функцию которая при уходе курсора с объекта дает знать об этом

    void setGeometry(int, int); //функция задает размеры кнопки

    void setImage(QString);//функция добовления картинки на кнопку
    //создаю сигналы

    void enableMouseMoving();//функция включения возможностм передвигаить объект
    void disableMouseMoving();//функция выключения возможностм передвигаить объект

signals:
    void btnMouseReleaseEven(Qt::MouseButton);//сигнал нажатия кнопки миши

private:
    int mWidth{0};//ширина перересованной площади
    int mHeigth{0};//высота перересованной площади

    bool mIsMoving{false};//влаг проверки двинулся объек или нет
    bool mIsMovable{true};//включения и выключения возможностм передвигаить объект


   Value mHoper;//флаг курсора

   QPointF mStartPos;//переменная стартовой позиции кнопки

   QPixmap mPixmap;//переменная хранящая картинку(буфер)

};

#endif // BUTTON_H
