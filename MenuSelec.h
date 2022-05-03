#ifndef _MENU_
#define _MENU_
#include "DoHoaCoBan.h"
#include "control.h"
const int POSXmn = 0;
const int POSYmn = 0;
using namespace std;

void VATTUmn(bool isdel, short hi)
{
    paintBox box;
    TextLabel label;
    box.BoxX(30,4,POSXmn,POSYmn,hi);
    box.paint();
    label.LabelX("VAT TU",POSXmn+10,POSYmn+2,hi);
    label.Print();
    if (isdel) box.deleteBox();
}
void NHANVIENmn(bool isdel, short hi)
{
    paintBox box;
    TextLabel label;
    box.BoxX(30,4,POSXmn,POSYmn+6,hi);
    box.paint();
    label.LabelX("NHAN VIEN",POSXmn+10,POSYmn+8,hi);
    label.Print();
    if (isdel) box.deleteBox();
}
void HOADONmn(bool isdel, short hi)
{
    paintBox box;
    TextLabel label;
    box.BoxX(30,4,POSXmn,POSYmn+12,hi);
    box.paint();
    label.LabelX("HOA DON",POSXmn+10,POSYmn+14,hi);
    label.Print();
    if (isdel) box.deleteBox();
}
void THONGKEmn(bool isdel, short hi)
{
    paintBox box;
    TextLabel label;
    box.BoxX(30,4,POSXmn,POSYmn+18,hi);
    box.paint();
    label.LabelX("THONG KE",POSXmn+10,POSYmn+20,hi);
    label.Print();
    if (isdel) box.deleteBox();
}
void THOATmn(bool isdel, short hi)
{
    paintBox box;
    TextLabel label;
    box.BoxX(30,4,POSXmn,POSYmn+24,hi);
    box.paint();
    label.LabelX("THOAT",POSXmn+10,POSYmn+26,hi);
    label.Print();
    if (isdel) box.deleteBox();
}
void Normalmenulect1(int x)
{
    if (x==1)
    {
        VATTUmn(true,14);
        VATTUmn(false,14);
    }
    if (x==2)
    {
        NHANVIENmn(true,14);
        NHANVIENmn(false,14);
    }
    if (x==3)
    {
        HOADONmn(true,14);
        HOADONmn(false,14);
    }
    if (x==4)
    {
        THONGKEmn(true,14);
        THONGKEmn(false,14);
    }
    if (x==5)
    {
        THOATmn(true,14);
        THOATmn(false,14);
    }
}
void Hightlinemenuselec1(int x)
{
    if (x==1)
    {
        VATTUmn(true,1);
        VATTUmn(false,1);
    }
    if (x==2)
    {
        NHANVIENmn(true,1);
        NHANVIENmn(false,1);
    }
    if (x==3)
    {
        HOADONmn(true,1);
        HOADONmn(false,1);
    }
    if (x==4)
    {
        THONGKEmn(true,1);
        THONGKEmn(false,1);
    }
    if (x==5)
    {
        THOATmn(true,1);
        THOATmn(false,1);
    }
}
int Menuselec1()
{
    SetColor(0);
    int ischoose=1;
    bool loop= true;
    SetColor(15);
    Hightlinemenuselec1(1);
    SetColor(0);
    Normalmenulect1(2);
    Normalmenulect1(3);
    Normalmenulect1(4);
    Normalmenulect1(5);
    while (loop)
    {
        char k =getch();
        if (k==-32)
        {
            k =getch();
            switch (k)
            {
                case UP:
                    {
                        if (ischoose>1)
                        {
                            SetColor(0);
                            Normalmenulect1(ischoose);
                            ischoose--;
                            SetColor(15);
                            Hightlinemenuselec1(ischoose);
                         }
                        break;
                    }
                case DOWN:
                    {
                         if (ischoose<5)
                         {
                            SetColor(0);
                            Normalmenulect1(ischoose);
                            ischoose++;
                            SetColor(15);
                            Hightlinemenuselec1(ischoose);
                         }
                         break;
                    }
            } 
        }
        if (k==ENTER) break;
    }
    return ischoose;
}

int MenuThongke()
{
    short posx = 50;
    short posy = 2;
    int ischoose = 0;
    string S[5];
    S[0] = "                   DS VAT TU TON KHO                 ";
    S[1] = "                    DS NHAN VIEN                     ";
    S[2] = "       THONG KE HOA DON TRONG KHOANG THOI GIAN       ";
    S[3] = " 10 VAT TU DOANG THU CAO NHAT TRONG KHOANG THOI GIAN ";
    S[4] = "            THONG KE DOANG THU THEO NAM              ";
    paintBox box;
    TextLabel lb;
    box.BoxX(60,15,posx,posy,1);
    box.paint();
    SetColor(15);
    lb.LabelX(S[0],posx+4,posy+3,2);
    lb.Print();
    SetColor(0);
    lb.LabelX(S[1],posx+4,posy+5,14);
    lb.Print();
    lb.LabelX(S[2],posx+4,posy+7,14);
    lb.Print();
    lb.LabelX(S[3],posx+4,posy+9,14);
    lb.Print();
    lb.LabelX(S[4],posx+4,posy+11,14);
    lb.Print();
    posy+=3;
    while (true)
    {
        char k =getch();
        if (k==-32)
        {
            k = getch();
            switch (k)
            {
                case UP:
                {
                    if (ischoose>0)
                    {
                        SetColor(0);
                        lb.LabelX(S[ischoose--],posx+4,posy,14);
                        lb.Print();
                        posy-=2;
                        SetColor(15);
                        lb.LabelX(S[ischoose],posx+4,posy,2);
                        lb.Print();
                    }
                    break;
                }
                case DOWN:
                {
                    if (ischoose<4)
                    {
                        SetColor(0);
                        lb.LabelX(S[ischoose++],posx+4,posy,14);
                        lb.Print();
                        posy+=2;
                        SetColor(15);
                        lb.LabelX(S[ischoose],posx+4,posy,2);
                        lb.Print();
                    }
                    break;
                }
            }
        }
        if (k==ENTER)
        {
            box.deleteBox();
            return ++ischoose;
        }
        if (k==ESC)
        {
            box.deleteBox();
            return 0;
        }
    }
    return 0;
}

#endif