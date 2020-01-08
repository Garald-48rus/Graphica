#ifndef VIEW_EXAMPLE_H
#define VIEW_EXAMPLE_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include"button.h"

class View_Example : public QGraphicsView
{
public:
    View_Example();

private:
    void ini_view_elements();//функция создания элементов

    Button mBtnA;//создаю кнопку 1
    Button mBtnB;//создаю кнопк 2
    Button mBtnC;//создаю кнопку 3


    QGraphicsScene mScene;//создаю сцену
    //создаю слоты
private slots:

      void btn_A_clicked(Qt::MouseButton);//КЛИКАЮ КНОПКУ А
      void btn_B_clicked(Qt::MouseButton);//КЛИКАЮ КНОПКУ B
      void btn_C_clicked(Qt::MouseButton);//КЛИКАЮ КНОПКУ C

};

#endif // VIEW_EXAMPLE_H
