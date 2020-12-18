#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QObject>
#include <QColor>

class MainWindow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString s11Color READ s11Color NOTIFY s11ColorChanged)
    Q_PROPERTY(QString s12Color READ s12Color NOTIFY s12ColorChanged)
    Q_PROPERTY(QString s13Color READ s13Color NOTIFY s13ColorChanged)
    Q_PROPERTY(QString s14Color READ s14Color NOTIFY s14ColorChanged)

    Q_PROPERTY(QString s11PieceColor READ s11PieceColor NOTIFY  s11PieceColorChanged)

    Q_PROPERTY(bool s11PieceVsibile READ s11PieceVsibile NOTIFY  s11PieceVsibileChanged)

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit MainWindow(QObject *parent = nullptr);
    void ClickSquare(int column,int line);
    void EndGame();
    void RemoveSquarePiece(int column, int line);
    void RenderBoard();
    void SetSquarePieceAsBlack(int column, int line);
    void SetSquarePieceAsWhite(int column, int line);
    ~MainWindow();

    QColor color() const
    {
        return m_color;
    }

    QString s11Color(){return m_s11Color = sqrColor(0,0);}
    QString s12Color(){return m_s12Color = sqrColor(0,1);}
    QString s13Color(){return m_s13Color = sqrColor(0,2);}
    QString s14Color(){return m_s14Color = sqrColor(0,3);}

    QString sqrColor(int c, int l)
    {
        if(game.GetSquareColor(c,l) == SquareColor::White)
        {
            std::cout << "white" << std::endl;
            return "#711818";
        }
        else
            return "#c8c8c8";
    }

    QString s11PieceColor()
    {
        std::cout << "ok" << std::endl;
        if(game.GetSquarePiece(0,7)->GetColor() == PieceColor::White)
        {
            std::cout << "white" << std::endl;
            return "#711818";
        }
        else
            return "#c8c8c8";
    }

    bool s11PieceVsibile()
    {
        return game.GetSquarePiece(0,4) != NULL;
    }

public slots:
    void setColor(QColor color)
    {
        if (m_color == color)
            return;

        m_color = color;
        emit colorChanged(m_color);
    }

signals:
    void colorChanged(QColor color);

    void s11ColorChanged(QString s11Color);
    void s12ColorChanged(QString s12Color);
    void s13ColorChanged(QString s13Color);
    void s14ColorChanged(QString s14Color);

    void s11PieceColorChanged(QString s11PieceColor);

    void s11PieceVsibileChanged(bool s11PieceVsibile);

private slots:
    //void on_a8_clicked();
    void test(int,int);

private:
    //Ui::MainWindow *ui;
    Game game;
    //QPushButton* squares[8][8];
    //QLabel* pieces[8][8];

    QString blackPieceIconPath;
    QString whitePieceIconPath;
    QString blackQueenIconPath;
    QString whiteQueenIconPath;

    //QPixmap whitePiecePixMap;
    //QPixmap blackPiecePixMap;
    QColor m_color;
    QString m_s11Color;
    QString m_s12Color;
    QString m_s13Color;
    QString m_s14Color;
    QString m_s11PieceColor;
    bool m_s11PieceVsibile;
};
#endif // MAINWINDOW_H
