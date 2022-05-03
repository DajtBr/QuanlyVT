#ifndef _TABLEDATA_
#define _TABLEDATA_
#include "VatTu.h"
#include "DoHoaCoBan.h"
#include "Control.h"
#include "inputUser.h"
using namespace std;
const short POSX = 120;
const short POSY = 0;
int countVT(BSTNode* root)
{
    int count =0;
    BSTNode* p=root;
    BSTNode* Stack[500];
    int sp=-1;
    while (p!=NULL)
    {
        count++;
        if (p->right!=NULL) Stack[++sp] = p->right;
        if (p->left!=NULL) p=p->left;
        else
        if (sp==-1) break;
        else p= Stack[sp--];
    }
    return count;
}
void Save_Data_VT_to_arr(BSTNode* Stackinput[], BSTNode* root)
{
    BSTNode* Stack[500];
    int sp=-1;
    int n = -1;
    BSTNode* p=root;
    while (p!=NULL)
    {
            Stackinput[++n]=p;
            if (p->right!=NULL) 
            Stack[++sp]=p->right;
            if (p->left!=NULL)
            p=p->left;
            else if (sp==-1) break;
            else p=Stack[sp--];
    }
}
int Number_of_VT_in_Stack(BSTNode* Stackinput[],char mvt[10],int n)
{
    int count = 0;
    for (int i=0;i<n;i++)
    {
        if (strcmp(mvt,Stackinput[i]->vt.MAVT)!=0) count++;
        else break;
    }
    return count;
}
void printTableVT(BSTNode *&root)
{
    BSTNode* Stackinput[500];
    BSTNode* StackSelection[500];
    int st=-1;
    BSTNode* p = root;
    if (p==NULL)
    { 
        SetBGColor(0);
        gotoxy(POSX-8,POSY);cout<<"        ";
        return;
    }
    
    Save_Data_VT_to_arr(Stackinput,root);
    int ivt = 0;
    BSTNode* tmp;
    int curpage = 0;
    bool check = true;
    bool insertorfind = false;
    int curnode = 0;
    do
    {
        HintTable(POSX,POSY+29,false);
        SetColor(0);
        SetBGColor(15);
        int Total = countVT(root);
        int PageLimit = 7;
        int Pagenum = Total/PageLimit;
        if (Total%PageLimit!=0) Pagenum++;
        if (curpage+1>Pagenum) curpage--;
        SetColor(1);
        SetBGColor(0);
        TableVattu tb;
        SetColor(0);
        tb.setPosition(POSX,POSY);
        tb.setStartPosition(POSX,POSY);
        tb.Head();
        
    int here = 0;
    char k;
    int i = 0;
    bool loop =true;
    if (insertorfind)
    {
        insertorfind = false;
        curpage = curnode/PageLimit;
        ivt = curpage*PageLimit;
        here = curnode%PageLimit;
        i = here;
    }
    st = -1;
    for (int i=0;i<PageLimit;i++)
    {
        if (ivt==Total) break;
        StackSelection[++st]=Stackinput[ivt];
        tmp = StackSelection[st];
        tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
        ivt++;
    }
    tb.setPosition(POSX,POSY+4+here*3);
    gotoxy(POSX,POSY+4+here*3);
    tmp= StackSelection[here];
    gotoxy(POSX-8,POSY);
    cout<<"PAGE "<<curpage+1<<"/"<<Pagenum;
    tb.setLineColor(1);
    SetColor(15);
    tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
    while (loop)
    {
        k=getch();
        if (k==-32)
        {
            k=getch();
            switch (k)
            {
                case UP:
                    {
                        if (i>0)
                        {
                            tb.posy-=3;
                            gotoxy(POSX,tb.posy);
                            tb.setLineColor(15);
                            SetColor(0);
                            tmp = StackSelection[i];
                            tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
                            gotoxy(POSX,tb.posy-=6);
                            tb.setLineColor(1);
                            SetColor(15);
                            tmp = StackSelection[--i];
                            tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
                        }
                        break;
                    }
                case DOWN:
                    {
                        if (i<st)
                        {
                            tb.posy-=3;
                            tb.setLineColor(15);
                            SetColor(0);
                            tmp = StackSelection[i];
                            tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
                            tb.setLineColor(1);
                            SetColor(15);
                            tmp =StackSelection[++i];
                            tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
                        }
                        break;
                    }
                case RIGHT:
                    {
                        if (curpage+1<Pagenum)
                        { 
                            curpage++;
                            tb.DeleteAlldata();
                            loop =false;
                        }
                        break;
                    }
                case LEFT:
                    {
                        if (curpage!=0)
                        {
                            if(ivt<Total)  ivt=ivt - PageLimit*(curpage+1);
                            else
                            {
                                ivt = Total-PageLimit-st-1;
                            }
                            curpage--;
                            tb.DeleteAlldata();
                            loop =false;
                        }
                        break;
                    }
                case DEL:
                    {
                       HintTable(POSX,POSY+29,true);
                        if (Query("BAN CO CHAC MUON XOA?",50,9))
                        {
                            tb.DeleteTable();
                            deleteBSTNode(root,tmp->vt.MAVT);
                        }
                        loop =false;
                        if (st==0) ivt=Total-PageLimit-st-1;
                        else ivt=ivt-st-1;
                        Save_Data_VT_to_arr(Stackinput,root);
                        break;
                    }
            }
        }
        if (k==0)
        {
            k = getch();
            if (k==F2)
            {
                HintTable(POSX,POSY+29,true);
                set_cursor(true);
                SetBGColor(0);
                SetColor(15);
                fixVATTU(StackSelection[i],SUAVT(StackSelection[i]));
                tb.posy-=3;
                gotoxy(tb.posx,tb.posy);
                tmp =StackSelection[i];
                tb.setLineColor(1);
                tb.LineColor();        
                tb.printData(tmp->vt.MAVT,tmp->vt.TENVT,tmp->vt.sl,tmp->vt.DVT);
                set_cursor(false);
                HintTable(POSX,POSY+29,false);
            }
            if (k==F1)
            {
                HintTable(POSX,POSY+29,true);
                set_cursor(true);
                SetBGColor(0);
                SetColor(15);
                VATTU vt =ThemVT(root);
                if (!vt.check)
                {
                    insertBSTNode(root,vt);
                    Save_Data_VT_to_arr(Stackinput,root);
                    curnode = Number_of_VT_in_Stack(Stackinput,vt.MAVT,Total+1);
                    tb.DeleteTable();
                    insertorfind = true;
                    loop = false;
                }
                set_cursor(false);
                HintTable(POSX,POSY+29,false);
            }
        }

        if (k==ESC)
        {
             tb.DeleteTable();
             gotoxy(POSX-8,POSY);
             cout<<"        ";
             check =false;
             HintTable(POSX,POSY+29,true);
             break;
        }
        if (k==F||k==f)
        {
            HintTable(POSX,POSY+29,true);
            insertorfind =true;
            char mvt[10];
            string s = TimVT(root);
            if (!s.empty())
            {
                strcpy(mvt,s.c_str());
                curnode = Number_of_VT_in_Stack(Stackinput,mvt,Total);
                tb.DeleteTable();
                loop = false;
            }
            else
            {
                 insertorfind = false;
                HintTable(POSX,POSY+29,false);
            }
        }
    }

    } while (check);
}

#endif