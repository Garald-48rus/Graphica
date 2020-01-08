#include "button.h"


#include <QDebug>

Button::Button()
{

setAcceptHoverEvents(true);//разрешаю оброботку движение курсора

setAcceptedMouseButtons(Qt::LeftButton);//включаю только левую кнопку миши
}
//---------------------------------------------------
  QRectF Button::boundingRect() const
  {
      return  QRectF(0,0, mWidth, mHeigth);
  }

  //------------------------------------------------------

  void Button::paint (QPainter *painter,
                      const QStyleOptionGraphicsItem */*option*/,
                      QWidget */*wifget*/)
  {

      if (mHoper.getHoper())//если курсор на объекте меняю очертание на красный
      {
          painter->setPen(QColor("red"));

      }
      QList<QGraphicsItem*> l = scene()->items();//получаю список всех елементов на сцене
      //пробегаю по списку елементов
      foreach (QGraphicsItem *item ,l) {

          if(item == this) continue;//если елемент вызывает самого себя

          if(collidesWithItem(item))//проверяю объекты на стокновение
          {
              painter->setBrush(QBrush(Qt::green));//если объекты столкнулись закрашиваю
              item->update();//обновляю елемент
          }
      }


      painter -> drawPixmap(0, 0, mWidth, mHeigth, mPixmap);//ресую картинку на кнопке

      painter -> drawRoundedRect(0, 0, mWidth, mHeigth, 5, 5);//ресую кнопку

  }

  //----------------------------------------------------------
  void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *)
  {
      //qWarning() << "Enter";
      mHoper.setHoper(1);//если курсор на оъекте передаю флагу 1 и ставлю его в true
       QGraphicsItem::update();//вызываю функцию изминения вида объекта для обозначения попадания курсора
  }
  //---------------------------------------------
  void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
  {
       //qWarning() << "Leave";
       mHoper.setHoper(0);//если курсор  не на оъекте передаю флагу 0 и ставлю его в False
        QGraphicsItem::update();//вызываю функцию изминения вида объекта для обозначения ухода курсора
  }
//----------------------------------------------------
  void Button::mousePressEvent(QGraphicsSceneMouseEvent *aEvent)
  {
      mIsMoving = false; //как только нажали кнопку мыши на обекте флаг движения усьанавливается в false
      mStartPos = aEvent->pos();//при нажатии кнопки мыши передаю в переменную координаты позиции мышки с кнопкой
    //qWarning() << "Press" << mStartPos;
  }
//------------------------------------------------------------
  void Button::mouseMoveEvent(QGraphicsSceneMouseEvent *aEvent)
  {
  if( mIsMovable)//если передвижение объекта включено
 {
    int distance = ((aEvent->pos()-mStartPos)).manhattanLength();//вычисляю на сколько был сдвинут объект
    if(distance > QApplication::startDragDistance())//если объект сдвинут больше чем системные требования (более 8 пикселей)
    {
        QPointF nf = mapToScene(aEvent->pos()-mStartPos);//переводим координаты на кнопке в координаты не сцене

        if(nf.x()<0 || nf.y()<0) return; // если координаты вне сцены выходим
        if(nf.x()>800 || nf.y()>800) return;// если координаты вне сцены выходим

        mIsMoving = true;//если объект переместился флаг устанавливаю в true
        this->setPos(nf);//иначе устанавливаю навые координаты нашей кнопке
    }

}
   //qWarning() << "Move";

  }
  //------------------------------------------------------------

  void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent)
  {
      if(!mIsMoving)//если после отпуска кнопки миши не было движения
      {
      emit btnMouseReleaseEven(aEvent->button());//возбуждаю сигнал
      }
   //qWarning() << "Relase";
  }


//--------------------------------------------------------
void Button::setImage(QString aPach)
{
  mPixmap.load(aPach);//записываю в переменную картинку по ее пути
  //подстраиваю размер кнопки под картинку
  mWidth   = mPixmap.width();
  mHeigth = mPixmap.height();
}

//-------------------------------------------
  void Button::setGeometry(int aWidth, int aHeigth)
  {
      mWidth   = aWidth;
      mHeigth = aHeigth;

  }
  //------------------------------------------------

  void Button::enableMouseMoving()
  {
     mIsMovable = true;
  }
  //---------------------------------------------

  void Button::disableMouseMoving()
  {
       mIsMovable = false;
  }





