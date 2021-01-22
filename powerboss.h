#ifndef POWERBOSS_H
#define POWERBOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include "jefe.h"
#include "math.h"
#include <QGraphicsScene>

class Powerboss :public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;
    float velocidad =36;
    float V0o;
    float filas = 0, columnas = 0,total_columnas;
    int movement;
    float G=5;
    float posx,posy;
    //variables fisicas
    float pi = 3.1416;
    float tiempo = 0, tiempo2 = 0;
    float angle;
    float friccion = 0.3,coeficiente = 0.9;
    float ayudantepos,posiniciox,posinicioy;
    float contador = 0, posxskill,posyskill;
    float Vxo;
    float Vyo;

public:
    explicit Powerboss(QString direccion_img, float ancho_, float alto_, float total_columnas_,float posx_,float posy_,int movement_, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void movimiento1();
    void movimiento2();
    void movimiento3();
    void movimiento4();

signals:

public slots:
    void actualizar();

};

#endif // POWERBOSS_H