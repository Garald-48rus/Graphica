#include "view_example.h"

View_Example::View_Example()
{
  setRenderHint(QPainter::Antialiasing);//сглаживание форм примитивов
  setCacheMode(QGraphicsView::CacheNone); //не использавать кеширования формы

  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключаю выход сцены за края формы по вертикали
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключаю выход сцены за края формы по горизонтали

  setWindowTitle("Графика урок 1");//название окна

  setFrameStyle(0); //ЧТОБЫ НАША СЦЕНА ПОЛНОСТЬЮ ВЛИВАЛАСЬ В ОКНО
  setSceneRect(0,0,800,800);//размер окна

  setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));//фиксированный размер окна нелбзя изменить
  setFixedSize(800,800);//размер окна

  mScene.setItemIndexMethod(QGraphicsScene::NoIndex);//выключаю индексирование для динамической сцены(если елементы буду подвыжны, анимация)

  setScene(&mScene); //передаю в окно нашу сцену
  ini_view_elements();//вызываю нашу функцию рисования элементов

}
//------------------------------------------------------------------------
void View_Example::ini_view_elements()
 {
  mBtnA.setPos(50,50); //позиция кнопки 1 на сцене
//mBtnA.setGeometry(100,100);//указываю размер кнопки 1
  mBtnA.setImage(":/img/1.png");//передаю путь картинки для кнопки А
  connect(&mBtnA,&Button::btnMouseReleaseEven, this, &View_Example::btn_A_clicked );//связываю сигнал с кнопкой и слотом
  mBtnA.disableMouseMoving();

  mBtnB.setPos(200,50); //позиция кнопки 1 на сцене
//mBtnB.setGeometry(100,100);//указываю размер кнопки 1
  mBtnB.setImage(":/img/2.png");//передаю путь картинки для кнопки B
  connect(&mBtnB,&Button::btnMouseReleaseEven, this, &View_Example::btn_B_clicked );//связываю сигнал с кнопкой и слотом

  mBtnC.setPos(50,200); //позиция кнопки 1 на сцене
//mBtnC.setGeometry(100,100);//указываю размер кнопки 1
  mBtnC.setImage(":/img/3.png");///передаю путь картинки для кнопки C
  connect(&mBtnC,&Button::btnMouseReleaseEven, this, &View_Example::btn_C_clicked );//связываю сигнал с кнопкой и слотом

  mScene.addItem(&mBtnA);//передаю в нашу сцену нашу кнопку 1
  mScene.addItem(&mBtnB);//передаю в нашу сцену нашу кнопку 2
  mScene.addItem(&mBtnC);//передаю в нашу сцену нашу кнопку 1

  }

//------------------------------------------------------
  void View_Example::btn_A_clicked(Qt::MouseButton)
  {
      qWarning() << "Clic button A";
  }
//----------------------------------------------
  void View_Example::btn_B_clicked(Qt::MouseButton)
  {
      qWarning() << "Clic button B";
  }
//-----------------------------------------------
  void View_Example::btn_C_clicked(Qt::MouseButton)
  {
      qWarning() << "Clic button C";
  }
