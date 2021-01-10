#include "bullets.h"

bullets::bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;

    img = new QPixmap(direccion_img);
    timer = new QTimer;

    timer->start(30);

    connect(timer, &QTimer::timeout, this, &bullets::Actualizacion);
}

void bullets::Actualizacion()
{
    if (filas == 100) {
        left();
    }
    else if (filas == 0) {
        right();
    }
    else if (filas == 50) {
        up();
    }
    else if (filas == 150) {
        down();
    }
    distancia_max -= 20;
    if (distancia_max == 100) {
        filas = 200;
    }
    else if (distancia_max <= 0) {
        scene()->removeItem(this);
        delete this;
    }
    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);
}

QRectF bullets::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void bullets::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void bullets::up()
{
    setPos(x(),y()-velocidad);
}

void bullets::down()
{
    setPos(x(),y()+velocidad);
}

void bullets::left()
{
    setPos(x()-velocidad,y());
}

void bullets::right()
{
    setPos(x()+velocidad,y());
}

bullets::~bullets()
{
    delete timer;
    delete img;
}
