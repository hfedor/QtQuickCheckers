import QtQuick 2.15
import QtQuick.Window 2.15
import MainWindow1 1.0

Rectangle {
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    
    height: parent.height - 40
    width: height
    color: "#3f2a16"

    function squareColor (column, line)
    {
        if((column + line)%2 == 0 )
        {
            return "#c8c8c8"
        }
        else
        {
            return "#711818"
        }
    }

    function pieceColor (column, line)
    {
        if(line < 3 )
        {
            return "#c8c8c8"
        }
        else
        {
            return "black"
        }
    }

    function pieceVisible (column, line)
    {
        if(line > 2 && line < 5  || (line+column)%2 == 0)
        {
            return false
        }
        else
        {
            return true
        }
    }


    MainWindow1 {
        id: mw
    }

    Grid {
        id: grid
        anchors.centerIn: parent
        height: parent.height - 40
        width: height
        rows: 8
        columns: 8

        Repeater {
            model: [
                {
                    ident: "s18",
                    columnIndex: 0,
                    lineIndex: 7
                    },
                {
                    ident: "s28",
                    columnIndex: 1,
                    lineIndex: 7
                    },
                {
                    ident: "s38",
                    columnIndex: 2,
                    lineIndex: 7
                    },
                {
                    ident: "s48",
                    columnIndex: 3,
                    lineIndex: 7
                    },
                {
                    ident: "s58",
                    columnIndex: 4,
                    lineIndex: 7
                    },
                {
                    ident: "s68",
                    columnIndex: 5,
                    lineIndex: 7
                    },
                {
                    ident: "s78",
                    columnIndex: 6,
                    lineIndex: 7
                    },
                {
                    ident: "s88",
                    columnIndex: 7,
                    lineIndex: 7
                    },
                {
                    ident: "s17",
                    columnIndex: 0,
                    lineIndex: 6
                    },
                {
                    ident: "s27",
                    columnIndex: 1,
                    lineIndex: 6
                    },
                {
                    ident: "s37",
                    columnIndex: 2,
                    lineIndex: 6
                    },
                {
                    ident: "s47",
                    columnIndex: 3,
                    lineIndex: 6
                    },
                {
                    ident: "s57",
                    columnIndex: 4,
                    lineIndex: 6
                    },
                {
                    ident: "s67",
                    columnIndex: 5,
                    lineIndex: 6
                    },
                {
                    ident: "s77",
                    columnIndex: 6,
                    lineIndex: 6
                    },
                {
                    ident: "s87",
                    columnIndex: 7,
                    lineIndex: 6
                    },
                {
                    ident: "s16",
                    columnIndex: 0,
                    lineIndex: 5
                    },
                {
                    ident: "s26",
                    columnIndex: 1,
                    lineIndex: 5
                    },
                {
                    ident: "s36",
                    columnIndex: 2,
                    lineIndex: 5
                    },
                {
                    ident: "s46",
                    columnIndex: 3,
                    lineIndex: 5
                    },
                {
                    ident: "s56",
                    columnIndex: 4,
                    lineIndex: 5
                    },
                {
                    ident: "s66",
                    columnIndex: 5,
                    lineIndex: 5
                    },
                {
                    ident: "s76",
                    columnIndex: 6,
                    lineIndex: 5
                    },
                {
                    ident: "s86",
                    columnIndex: 7,
                    lineIndex: 5
                    },
                {
                    ident: "s15",
                    columnIndex: 0,
                    lineIndex: 4
                    },
                {
                    ident: "s25",
                    columnIndex: 1,
                    lineIndex: 4
                    },
                {
                    ident: "s35",
                    columnIndex: 2,
                    lineIndex: 4
                    },
                {
                    ident: "s45",
                    columnIndex: 3,
                    lineIndex: 4
                    },
                {
                    ident: "s55",
                    columnIndex: 4,
                    lineIndex: 4
                    },
                {
                    ident: "s65",
                    columnIndex: 5,
                    lineIndex: 4
                    },
                {
                    ident: "s75",
                    columnIndex: 6,
                    lineIndex: 4
                    },
                {
                    ident: "s85",
                    columnIndex: 7,
                    lineIndex: 4
                    },
                {
                    ident: "s14",
                    columnIndex: 0,
                    lineIndex: 3
                    },
                {
                    ident: "s24",
                    columnIndex: 1,
                    lineIndex: 3
                    },
                {
                    ident: "s34",
                    columnIndex: 2,
                    lineIndex: 3
                    },
                {
                    ident: "s44",
                    columnIndex: 3,
                    lineIndex: 3
                    },
                {
                    ident: "s54",
                    columnIndex: 4,
                    lineIndex: 3
                    },
                {
                    ident: "s64",
                    columnIndex: 5,
                    lineIndex: 3
                    },
                {
                    ident: "s74",
                    columnIndex: 6,
                    lineIndex: 3
                    },
                {
                    ident: "s84",
                    columnIndex: 7,
                    lineIndex: 3
                    },
                {
                    ident: "s13",
                    columnIndex: 0,
                    lineIndex: 2
                    },
                {
                    ident: "s23",
                    columnIndex: 1,
                    lineIndex: 2
                    },
                {
                    ident: "s33",
                    columnIndex: 2,
                    lineIndex: 2
                    },
                {
                    ident: "s43",
                    columnIndex: 3,
                    lineIndex: 2
                    },
                {
                    ident: "s53",
                    columnIndex: 4,
                    lineIndex: 2
                    },
                {
                    ident: "s63",
                    columnIndex: 5,
                    lineIndex: 2
                    },
                {
                    ident: "s73",
                    columnIndex: 6,
                    lineIndex: 2
                    },
                {
                    ident: "s83",
                    columnIndex: 7,
                    lineIndex: 2
                    },
                {
                    ident: "s12",
                    columnIndex: 0,
                    lineIndex: 1
                    },
                {
                    ident: "s22",
                    columnIndex: 1,
                    lineIndex: 1
                    },
                {
                    ident: "s32",
                    columnIndex: 2,
                    lineIndex: 1
                    },
                {
                    ident: "s42",
                    columnIndex: 3,
                    lineIndex: 1
                    },
                {
                    ident: "s52",
                    columnIndex: 4,
                    lineIndex: 1
                    },
                {
                    ident: "s62",
                    columnIndex: 5,
                    lineIndex: 1
                    },
                {
                    ident: "s72",
                    columnIndex: 6,
                    lineIndex: 1
                    },
                {
                    ident: "s82",
                    columnIndex: 7,
                    lineIndex: 1
                    },
                {
                    ident: "s11",
                    columnIndex: 0,
                    lineIndex: 0
                    },
                {
                    ident: "s21",
                    columnIndex: 1,
                    lineIndex: 0
                    },
                {
                    ident: "s31",
                    columnIndex: 2,
                    lineIndex: 0
                    },
                {
                    ident: "s41",
                    columnIndex: 3,
                    lineIndex: 0
                    },
                {
                    ident: "s51",
                    columnIndex: 4,
                    lineIndex: 0
                    },
                {
                    ident: "s61",
                    columnIndex: 5,
                    lineIndex: 0
                    },
                {
                    ident: "s71",
                    columnIndex: 6,
                    lineIndex: 0
                    },
                {
                    ident: "s81",
                    columnIndex: 7,
                    lineIndex: 0
                    }
            ]
            Square {
                id: sqr
                parent: grid
                color: ma.pressed ? "blue" : squareColor(column,line)

                property int line: modelData.lineIndex
                property int column: modelData.columnIndex

                MouseArea{
                    id: ma
                    anchors.fill: parent
                }

                Piece{
                    id: piece
                    parent: map.pressed ? map : sqr

                    x: map.pressed ? map.mouseX : parent.verticalCenter
                    y: map.pressed ? map.mouseY : parent.horizontalCenter

                    color: map.pressed ? "blue" : pieceColor(parent.column, parent.line)

                    visible: pieceVisible(column,line)

                    MouseArea{
                        id: map
                        anchors.fill: piece
                    }
                }
            }
        }
    }

    /*Repeater
    {
        model:[
            {
                index: 0,
                parent: s12
            },
            {
                index: 1,
                parent: s14
            },
            {
                index: 2,
                parent: s16
            },
            {
                index: 3,
                parent: s18
            },
            {
                index: 4,
                parent: s21
            },
            {
                index: 5,
                parent: s23
            },
            {
                index: 6,
                parent: s25
            },
            {
                index: 7,
                parent: s27
            },
            {
                index: 8,
                parent: s32
            },
            {
                index: 9,
                parent: s34
            },
            {
                index: 10,
                parent: s36
            },
            {
                index: 11,
                parent: s38
            }
        ]

        Piece {
            id: piece
            parent: map.pressed ? map : modelData.parent

            x: map.pressed ? map.mouseX : parent.x
            y: map.pressed ? map.mouseY : parent.y

            color: map.pressed ? "blue" : ( parent.column > 4 ? "white" : "black")

            //color: modelData.pieceColor

            visible: (parent.color == "#c8c8c8") ? false : true

            MouseArea{
                id: map
                anchors.fill: piece
            }
        }
    }*/
}
