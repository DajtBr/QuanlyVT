#ifndef _DOHOA_
#define _DOHOA_
#include "mylib.h"
#include "Control.h"
using namespace std;


struct paintBox
{
    int width = 0;
    int height = 0;
    short hightline = 1;
    short posx = 0;
    short posy = 0;
    void setSize(int w, int h)
    {
        width = w;
        height = h;
    }
    void deleteBox()
    {
        posy = posy-height-1;
        gotoxy(posx,posy);
        for (int i=0;i<height+2;i++)
        {
            SetBGColor(0);
            for (int j =0;j<width;j++) cout<<" ";
            gotoxy(posx,posy++);
        }
    }
    void setHightline(short x)
    {
        hightline = x;
    }
    void setPosition(short x, short y)
    {
        posx = x;
        posy = y;
    }
    void paint()
    {
        SetBGColor(0);
        gotoxy(posx,posy++);
        for (int i=0;i<width;i++)
        { 
            cout<<" ";
        }
        for (int i=0;i<height-1;i++)
        {
            gotoxy(posx,posy++);
            for (int j=0;j<width;j++)
            {
                SetBGColor(0);
                if (j==0||j==width-1)
                {
                  
                    cout<<" ";
                }
                else 
                {
                    SetBGColor(hightline);
                    cout<<" ";
                }
            }
        }
        gotoxy(posx,posy++);
        SetBGColor(0);
        for (int i=0;i<width;i++)
        {   
        
            if(i==0||i==width-1) cout<<" "; else cout<<" ";
        }
    }
    void BoxX(int w,int h,short x,short y,short hi)
    {
        setHightline(hi);
        setSize(w,h);
        setPosition(x,y);
    }
};

struct TextLabel
{
    short posx = 0;
    short posy = 0;
    short hightline = 1;
    string text = "";
    void setText(string s)
    {
        text = s;
    }
    void setPosition(short x, short y)
    {
        posx = x;
        posy = y;
    }
    void setHightline(short x)
    {
        hightline = x;
    }
    void Print()
    {
        gotoxy(posx,posy);
        SetBGColor(hightline);
        cout<<text;
    }
    void LabelX(string s,short x, short y, short hi)
    {
        setText(s);
        setPosition(x,y);
        setHightline(hi);
    }
};

void set_cursor(bool visible){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}


struct TableVattu
{
    short posx=0;
    short posy=0;
    short startx = 0;
    short starty=0;
    short Maxtable=0;
    int count = 0;
    short color = 15;
    void setStartPosition(short x, short y)
    {
        startx = x;
        starty = y;

    }
    void setPosition(short x, short y)
    {
        posx = x;
        posy = y;
    }
    void Head()
    {
        SetBGColor(2);
        gotoxy(posx,posy++);cout<<"..........................................................................";
        gotoxy(posx,posy++);cout<<":             :                           :              :               :";
        gotoxy(posx,posy++);cout<<":  Ma vat tu  :        Ten vat tu         : So luong ton :  Don vi tinh  :";
        gotoxy(posx,posy++);cout<<":.............:...........................:..............:...............:";
    }
    void setLineColor(short cl)
    {
        color = cl;
    }
    void LineColor()
    {
        SetBGColor(color);
        cout<<"                                                                          ";
    }
    void RowLine(short x, short y)
    {
        gotoxy(x,y);cout<<":";
        gotoxy(x+14,y); cout<<":";
        gotoxy(x+42,y); cout<<":";
        gotoxy(x+57,y); cout<<":";
        gotoxy(x+73,y); cout<<":";
    }
    void Tail()
    {
        cout<<"..........................................................................";
    }
    void printData(char MVT[10], string tvt, int sl, string dvt)
    {
        gotoxy(posx,posy);
        LineColor();
        RowLine(posx,posy);
        gotoxy(posx,posy+1);
        LineColor();
        RowLine(posx,posy+1);
        gotoxy(posx,posy+2);
        LineColor();
        gotoxy(posx,posy+2);
        Tail();
        RowLine(posx,posy+2);
        gotoxy(posx,++posy);
        gotoxy(posx+3, posy); cout<<MVT;
        gotoxy(posx+17,posy); cout<<tvt;
        gotoxy(posx+46,posy); cout<<sl;
        gotoxy(posx+60,posy); cout<<dvt;
        posy+=2;
        gotoxy(posx,posy);
        if (Maxtable<posy) Maxtable = posy;
    }
    void DeleteAlldata()
    {
        gotoxy(startx,starty+4);
        for (short i = starty+4; i<=Maxtable;i++)
        {
            gotoxy(startx,i);
            setLineColor(0);
            LineColor(); 
        }
        posy=starty+4;
    }
    void DeleteTable()
    {
        gotoxy(startx,starty);
        for (int i = starty;i<=Maxtable;i++)
        {
            gotoxy(startx,i);
            setLineColor(0);
            LineColor();
        }
        posx =startx;
        posy =starty;
    }
};

void HintTable(short posx, short posy,bool isdel)
{
    paintBox box;
    box.BoxX(50,7,posx,posy,1);
    box.paint();
    SetColor(15);
    SetBGColor(1);
    gotoxy(posx+20,posy+1);
    cout<<"DIEU KHIEN";
    gotoxy(posx+2,posy+2);
    cout<<"↑,↓:   LEN XUONG";
    gotoxy(posx+28,posy+2);
    cout<<"←,→: CHUYEN TRANG";
    gotoxy(posx+2,posy+3);
    cout<<"F1:     THEM DU LIEU";
    gotoxy(posx+28,posy+3);
    cout<<"F2:   SUA DU LIEU";
    gotoxy(posx+2,posy+4);
    cout<<"DELETE: XOA DU LIEU";
    gotoxy(posx+2,posy+5);
    cout<<"F:      TIM KIEM";
    gotoxy(posx+2,posy+6);
    cout<<"ESC:    QUAY LAI";
    if (isdel) box.deleteBox();
}


struct TableNhanVien
{
    short posx=0;
    short posy=0;
    short startx = 0;
    short starty=0;
    short Maxtable=0;
    int count = 0;
    short color = 15;
    void setStartPosition(short x, short y)
    {
        startx = x;
        starty = y;

    }
    void setPosition(short x, short y)
    {
        posx = x;
        posy = y;
    }
    void Head()
    {
        SetBGColor(2);
        gotoxy(posx,posy++);cout<<"..............................................................";
        gotoxy(posx,posy++);cout<<":                :                            :              :";
        gotoxy(posx,posy++);cout<<":  Ma Nhan Vien  :        Ten Nhan Vien       :     Phai     :";
        gotoxy(posx,posy++);cout<<":................:............................:..............:";
    }
    void setLineColor(short cl)
    {
        color = cl;
    }
    void LineColor()
    {
        SetBGColor(color);
        cout<<"                                                              ";
    }
    void RowLine(short x, short y)
    {
        gotoxy(x,y);cout<<":";
        gotoxy(x+17,y); cout<<":";
        gotoxy(x+46,y); cout<<":";
        gotoxy(x+61,y); cout<<":";
    }
    void Tail()
    {
        cout<<"..............................................................";
    }
    void printData(char MNV[10], string Ten, string Phai)
    {
        SetColor(0);
        gotoxy(posx,posy);
        LineColor();
        RowLine(posx,posy);
        gotoxy(posx,posy+1);
        LineColor();
        RowLine(posx,posy+1);
        gotoxy(posx,posy+2);
        LineColor();
        gotoxy(posx,posy+2);
        Tail();
        RowLine(posx,posy+2);
        gotoxy(posx,++posy);
        gotoxy(posx+6, posy); cout<<MNV;
        gotoxy(posx+19,posy); cout<<Ten;
        gotoxy(posx+52,posy); cout<<Phai;

        posy+=2;
        gotoxy(posx,posy);
        if (Maxtable<posy) Maxtable = posy;
    }
    void DeleteAlldata()
    {
        gotoxy(startx,starty+4);
        for (short i = starty+4; i<=Maxtable;i++)
        {
            gotoxy(startx,i);
            setLineColor(0);
            LineColor(); 
        }
        posy=starty+4;
    }
    void DeleteTable()
    {
        gotoxy(startx,starty);
        for (int i = starty;i<=Maxtable;i++)
        {
            gotoxy(startx,i);
            setLineColor(0);
            LineColor();
        }
    }
};



#endif