#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class enemigos : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit enemigos(QString direccion_img, float ancho_, float alto_, float total_columnas_,float posx, float posy, QObject *parent = nullptr);
    ~enemigos();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();
    void seguir(float playerx_,float playery_);

    float velocidad = 5;
    float filas = 0, columnas = 0, total_columnas;
    int vida;
private:
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;
    float playerx,playery;

signals:

public slots:
    void Actualizacion();

};

#endif // ENEMIGOS_H