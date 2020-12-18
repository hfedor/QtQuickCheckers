#include "mainwindow.h"

MainWindow::MainWindow(QObject *parent) : QObject(parent)
{
    RenderBoard();
}

void MainWindow::EndGame()
{
    //ui->endLabel->setText("Koniec");
}

void MainWindow::ClickSquare(int column,int line)
{
    Piece* newPickedPiece = game.GetSquarePiece(column, line);
    if(newPickedPiece != NULL)
    {
        if(game.IsThatPieceTurn(newPickedPiece))
            game.SetPickedPiece(newPickedPiece);
    }
    else
    {
        Piece* pickedPiece = game.GetPickedPiece();

        if(pickedPiece != NULL)
        {
            int pickedColumn = pickedPiece->GetColumn();
            int pickedLine = pickedPiece->GetLine();

            if(pickedPiece->IsQueen())
            {
                bool move = true;
                int cdelta = column - pickedColumn;
                int ldelta = line - pickedLine;

                if( cdelta == ldelta || cdelta == -ldelta )
                {
                    if( column >  pickedColumn )
                    {
                        if( line > pickedLine )
                        {
                             for(int i = 1 ; (pickedColumn+i < column && pickedLine+i < line) ; i++)
                             {
                                 Piece* beaten = game.GetSquarePiece(pickedColumn+i,pickedLine+i);
                                 if(beaten != NULL)
                                 {
                                     if(pickedColumn+i < column - 1)
                                     {
                                         move = false;
                                         break;
                                     }
                                     else
                                         game.RemoveSquarePiece(column-1,line-1);
                                 }
                             }
                        }
                        else
                        {
                            for(int i = 1 ; (pickedColumn+i < column && pickedLine-i > line) ; i++)
                            {
                                Piece* beaten = game.GetSquarePiece(pickedColumn+i,pickedLine-i);
                                if(beaten != NULL)
                                {
                                    std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                    if(pickedColumn+i < column - 1)
                                    {
                                        move = false;
                                        break;
                                    }
                                    else
                                        game.RemoveSquarePiece(column-1,line+1);
                                }
                            }
                        }
                    }
                    else
                    {
                        if( line > pickedLine )
                        {
                             for(int i = 1 ; (pickedColumn-i > column && pickedLine+i < line) ; i++)
                             {
                                 Piece* beaten = game.GetSquarePiece(pickedColumn-i,pickedLine+i);
                                 if(beaten != NULL)
                                 {
                                     std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                     if(pickedColumn-i > column + 1)
                                     {
                                         move = false;
                                         break;
                                     }
                                     else
                                         game.RemoveSquarePiece(column+1,line-1);
                                 }
                             }
                        }
                        else
                        {
                            for(int i = 1 ; (pickedColumn-i > column && pickedLine-i > line) ; i++)
                            {
                                Piece* beaten = game.GetSquarePiece(pickedColumn-i,pickedLine-i);
                                if(beaten != NULL)
                                {
                                    std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                    if(pickedColumn-i > column + 1)
                                    {
                                        move = false;
                                        break;
                                    }
                                    else
                                        game.RemoveSquarePiece(column+1,line+1);
                                }
                            }
                        }
                    }
                    if(move)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
            }
            else
            {
                if(game.IsWhiteTurn())
                {
                    if((column == pickedColumn+1 || column == pickedColumn-1) && line == pickedLine+1)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else
                {
                    if((column == pickedColumn+1 || column == pickedColumn-1) && line == pickedLine-1)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }

                if(column == pickedColumn+2 && column >= 2 && line == pickedLine+2 && line >= 2)
                {
                    Piece* beaten = game.GetSquarePiece(column-1,line-1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn+1,pickedLine+1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn-2 && column <= 6  && line == pickedLine-2 && line <= 6)
                {
                    Piece* beaten = game.GetSquarePiece(column+1,line+1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn-1,pickedLine-1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn+2 && column >= 2 && line == pickedLine-2 && line <= 6)
                {
                    Piece* beaten = game.GetSquarePiece(column-1,line+1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn+1,pickedLine-1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn-2 && column <= 6 && line == pickedLine+2 && line >= 2)
                {
                    Piece* beaten = game.GetSquarePiece(column+1,line-1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn-1,pickedLine+1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
            }
        }
    }

    RenderBoard();

    if(game.GetFinish())
        EndGame();
}

void MainWindow::RemoveSquarePiece(int column, int line)
{
    game.RemoveSquarePiece(column,line);
    //squares[column][line]->setIcon(QIcon(""));
}

void MainWindow::RenderBoard()
{
    for(int c = 0; c < 8; c++)
        for(int l = 0; l < 8; l++)
        {
            if((c+l)%2 == 0)
                game.SetSquareColor(c,l,SquareColor::White);
            else
                game.SetSquareColor(c,l,SquareColor::Black);
        }

    Piece* pickedPiece = game.GetPickedPiece();
    if(pickedPiece != NULL)
    {
        ;//squares[pickedPiece->GetColumn()][pickedPiece->GetLine()]->setStyleSheet("background-color: blue");
    }

    for(int c = 0; c < 8; c++)
        for(int l = 0; l < 8; l++)
        {
            ;//squares[c][l]->setIconSize(QSize(37,37));
            Piece* piece = game.GetSquarePiece(c,l);
            if(piece != NULL)
            {
                if(piece->GetColor() == PieceColor::White)
                    SetSquarePieceAsWhite(c,l);
                else
                    SetSquarePieceAsBlack(c,l);
            }
            else
                RemoveSquarePiece(c,l);

        }
}

void MainWindow::SetSquarePieceAsBlack(int column, int line)
{
    game.SetSquarePieceAsBlack(column,line);
    if(game.IsSquarePieceQueen(column, line))
        ;//squares[column][line]->setIcon(QIcon(blackQueenIconPath));
    else
        ;//squares[column][line]->setIcon(QIcon(blackPieceIconPath));
}

void MainWindow::SetSquarePieceAsWhite(int column, int line)
{
    game.SetSquarePieceAsWhite(column,line);
    if(game.IsSquarePieceQueen(column, line))
        ;//squares[column][line]->setIcon(QIcon(whiteQueenIconPath));
    else
        ;//squares[column][line]->setIcon(QIcon(whitePieceIconPath));
}

/*void MainWindow::on_a8_clicked()
{

}*/

void MainWindow::test(int c, int l)
{
    ;//squares[c][l]->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    ;//delete ui;
}


