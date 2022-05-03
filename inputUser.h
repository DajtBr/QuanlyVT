#include "VatTu.h"
#include "DoHoaCoBan.h"


using namespace std ;

void BacksapaceData(int x,int y)
{
    gotoxy(x-1,y);
    cout<<" ";
    gotoxy(x-1,y);
}
bool checkDataNumber ( char c ) {
      if (c>=48&&c<=57) return true;
      return false;
}
bool checkDataString ( char &c) {
      if ((c>=48&&c<=57)||(c>=97&&c<=122)||(c>=65&&c<=90)||(c==32))
      {
            if (c>=97) c-=32;
            return true;
      }
      return false;
}

bool Query(string s,short posx ,short posy)
{
    paintBox box;
    TextLabel lb,lbY,lbN;
    set_cursor(false);
    bool check = true;
    SetBGColor(0);
    box.BoxX(50,7,posx,posy,1);
    SetColor(15);
    lb.LabelX(s,posx+6,posy+2,1);
    box.paint();
    lb.Print();
    lbY.LabelX(" XAC NHAN ",posx+5,posy+4,2);
    lbY.Print();
    lbN.LabelX("   HUY    ",posx+32,posy+4,0);
    lbN.Print();
    while (true)
    {
        char k =getch();
        if (k==-32)
        {
            k=getch();
            if (k==RIGHT&&check)
            {
                lbY.setHightline(0);
                lbY.Print();
                lbN.setHightline(2);
                lbN.Print();
                check=false;
            }
            if (k==LEFT&&!check)
            {
                lbN.setHightline(0);
                lbN.Print();
                lbY.setHightline(2);
                lbY.Print();
                check=true;
            }
        }
        if (k==ENTER)
        {
            box.deleteBox();
            return check;
        }
    }
    return true;
}

void Alertmgs(string s, short posx, short posy)
{
      set_cursor(false);
      paintBox box;
      TextLabel lb;
      box.BoxX(50,7,posx,posy,1);
      box.paint();
      gotoxy(posx+2,posy+2);
      SetBGColor(1);
      cout<<s;
      lb.LabelX("NHAN ENTER",posx+19,posy+5,2);
      lb.Print();
      while (true)
      {
            char k =getch();
            if (k==ENTER)
            {
                  box.deleteBox();
                  break;
            }
      }
}

VATTU SUAVT(BSTNode* root)
{
      short posxbox=50;
      short posybox=2;
      VATTU vt;
      paintBox box;
      TextLabel lb;
      string S[3];
      S[0] = root->vt.TENVT;
      S[1] = to_string(root->vt.sl);
      S[2] = root->vt.DVT;
      vt.TENVT = root->vt.TENVT;
      vt.sl = root->vt.sl;
      vt.DVT = root->vt.DVT;
      box.BoxX(50,25,posxbox,posybox,1);
      box.paint();
      SetBGColor(1);
      gotoxy(posxbox+2,posybox+21); cout<<"↑,↓: LEN,XUONG";
      gotoxy(posxbox+2,posybox+22); cout<<"ESC: HUY";
      gotoxy(posxbox+2,posybox+23); cout<<"ENTER: XAC NHAN SUA VAT TU";
      lb.LabelX("SUA VAT TU",posxbox+20,posybox+2,1);
      lb.Print();
      lb.LabelX("MA VAT TU:",posxbox+4,posybox+5,1);
      lb.Print();
      lb.LabelX("                      ",posxbox+19,posybox+5,3);
      lb.Print();
      gotoxy(posxbox+21,posybox+5);cout<<root->vt.MAVT;
      lb.LabelX("TEN VAT TU:",posxbox+4,posybox+9,1);
      lb.Print();
      lb.LabelX("                      ",posybox+19,posybox+9,0);
      lb.Print();
      gotoxy(posxbox+21,posybox+9);cout<<S[0];
      lb.LabelX("SO LUONG TON:",posxbox+4,posybox+13,1);
      lb.Print();
      lb.LabelX("                      ",posxbox+19,posybox+13,0);
      lb.Print();
      gotoxy(posxbox+21,posybox+13);cout<<S[1];
      lb.LabelX("DON VI TINH:",posxbox+4,posybox+17,1);
      lb.Print();
      lb.LabelX("                      ",posxbox+19,posybox+17,0);
      lb.Print();
      gotoxy(posxbox+21,posybox+17);cout<<S[2];
      short posx = posxbox+19;
      short posy = posybox+9;
      int cur = 0;
      lb.LabelX("                      ",posx,posy,0);
      lb.Print();
      gotoxy(posx+2,posy);cout<<S[cur];
      while (true)
      {
            char k =getch();
            if (k==-32)
            {
                  k=getch();
                 
                  switch (k)
                  {
                        case UP:
                        {
                              if (posy>posybox+9&&!S[cur].empty())
                              {
                                    lb.LabelX("                      ",posx,posy,0);
                                    lb.Print();
                                    gotoxy(posx+2,posy);cout<<S[cur];
                                    posy-=4;
                                    gotoxy(posx+2,posy);cout<<S[--cur];

                              }
                              break;
                        }
                        case DOWN:
                        {
                              if (posy<posybox+17&&!S[cur].empty())
                              {
                                    lb.LabelX("                      ",posx,posy,0);
                                    lb.Print();
                                    gotoxy(posx+2,posy);cout<<S[cur];
                                    posy+=4;
                                    gotoxy(posx+2,posy);cout<<S[++cur];
                              }
                              break;
                        }
                  }
            }
            else if (k==BACKSPACE&&!S[cur].empty())
            {
                  gotoxy(posx+S[cur].length()+2,posy);
                  BacksapaceData(posx+S[cur].length()+2,posy);
                  S[cur].pop_back();
            }
            else if ((cur==0||cur==2)&&checkDataString(k))
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        S[cur].push_back(k);
                        cout<<k;
                  }
            else if (cur==1&checkDataNumber(k))
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        S[cur].push_back(k);
                        cout<<k;
                  }
            if (k==ESC) 
            {
                  if (Query("BAN CO CHAC MUON HUY ?",50,28))
                  {
                        box.deleteBox();
                        break;
                  }
                  else 
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                  }
            }
            if (k==ENTER)
            {
                  if (Query("KIEM TRA DU LIEU NHAP CUA BAN ?",50,28))
                  {
                        if (!S[0].empty()&&!S[1].empty()&&!S[2].empty())
                        {
                              box.deleteBox();
                              vt.TENVT = S[0];
                              vt.sl = stoi(S[1]);
                              vt.DVT = S[2];
                              return vt;
                        }
                        else
                        {
                              //Alert box
                              Alertmgs("BAN KHONG DUOC DE TRONG DU LIEU ?",50,28);
                              gotoxy(posx+S[cur].length()+2,posy);
                              set_cursor(true);
                        }
                  }
                  else
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        set_cursor(true);
                  }
            }
      }
      return vt;
}

VATTU ThemVT(BSTNode* root)
{
      short posxbox=50;
      short posybox=2;
      VATTU vt;
      paintBox box;
      TextLabel lb;
      string S[4];
      char c[10];
      S[0]="";
      S[1]="";
      S[2]="";
      S[3]="";
      vt.check = false;
      box.BoxX(50,25,posxbox,posybox,1);
      box.paint();
      SetBGColor(1);
      gotoxy(posxbox+2,posybox+21); cout<<"↑,↓:   LEN,XUONG";
      gotoxy(posxbox+2,posybox+22); cout<<"ESC:   HUY";
      gotoxy(posxbox+2,posybox+23); cout<<"ENTER: XAC NHAN THEM VAT TU";
      lb.LabelX("THEM VAT TU",posxbox+20,posybox+2,1);
      lb.Print();
      lb.LabelX("MA VAT TU:",posxbox+4,posybox+5,1);
      lb.Print();
      lb.LabelX("                          ",posxbox+19,posybox+5,0);
      lb.Print();
      lb.LabelX("TEN VAT TU:",posxbox+4,posybox+9,1);
      lb.Print();
      lb.LabelX("                          ",posxbox+19,posybox+9,0);
      lb.Print();
      lb.LabelX("SO LUONG TON:",posxbox+4,posybox+13,1);
      lb.Print();
      lb.LabelX("                          ",posxbox+19,posybox+13,0);
      lb.Print();
      lb.LabelX("DON VI TINH:",posxbox+4,posybox+17,1);
      lb.Print();
      lb.LabelX("                          ",posxbox+19,posybox+17,0);
      lb.Print();
      short posx = posxbox+19;
      short posy = posybox+5;
      int cur = 0;
      lb.LabelX("                          ",posx,posy,0);
      lb.Print();
      gotoxy(posx+2,posy);
      while (true)
      {
            char k = getch();
            strcpy(c,S[0].c_str());
            if (cur == 0&&!S[0].empty()&&findVATTU(root,c)!=NULL)
            {
                  Alertmgs("DA TON TAI VAT TU CO MA NAY",50,28);
                  set_cursor(true);
                  S[0].clear();
                  gotoxy(posx+2,posy);cout<<"                          ";
                  gotoxy(posx+2,posy);
                  continue;
            }
            if (k==-32)
            {
                  k = getch();
                 switch (k)
                  {
                        case UP:
                        {
                              if (posy>posybox+5)
                              {
                                    lb.LabelX("                          ",posx,posy,0);
                                    lb.Print();
                                    gotoxy(posx+2,posy);cout<<S[cur];
                                    posy-=4;
                                    gotoxy(posx+2,posy);cout<<S[--cur];

                              }
                              break;
                        }
                        case DOWN:
                        {
                              if (posy<posybox+17&&!S[cur].empty())
                              {
                                    lb.LabelX("                          ",posx,posy,0);
                                    lb.Print();
                                    gotoxy(posx+2,posy);cout<<S[cur];
                                    posy+=4;
                                    gotoxy(posx+2,posy);cout<<S[++cur];
                              }
                              break;
                        }
                  }
            }
            else if (k==BACKSPACE&&!S[cur].empty())
            {
                  gotoxy(posx+S[cur].length()+2,posy);
                  BacksapaceData(posx+S[cur].length()+2,posy);
                  S[cur].pop_back();
            }
            else if (cur==0&&checkDataString(k)&&S[0].length()<10)
            {
                  gotoxy(posx+S[cur].length()+2,posy);
                  S[cur].push_back(k);
                  cout<<k;
            }
            else if ((cur==1||cur==3)&&checkDataString(k))
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        S[cur].push_back(k);
                        cout<<k;
                  }
            else if (cur==2&checkDataNumber(k))
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        S[cur].push_back(k);
                        cout<<k;
                  }
            if (k==ESC) 
            {
                  if (Query("BAN CO CHAC MUON HUY ?",50,28))
                  {
                        vt.check = true;
                        box.deleteBox();
                        break;
                  }
                  else  gotoxy(posx+S[cur].length()+2,posy);

            }
             if (k==ENTER)
            {
                  if (Query("KIEM TRA THONG TIN NHAP CUA BAN ?",50,28))
                  {
                        if (!S[0].empty()&&!S[1].empty()&&!S[2].empty()&&!S[3].empty())
                        {
                              box.deleteBox();
                              strcpy(vt.MAVT,S[0].c_str());
                              vt.TENVT = S[1];
                              vt.sl = stoi(S[2]);
                              vt.DVT = S[3];
                              return vt;
                        }
                        else  
                        {
                              //Alert box
                              Alertmgs("BAN KHONG DUOC DE TRONG DE LIEU ",50,28);
                              gotoxy(posx+S[cur].length()+2,posy);
                              set_cursor(true);
                        }
                  }
                  else
                  {
                        gotoxy(posx+S[cur].length()+2,posy);
                        set_cursor(true);
                  }
            }
      }
      return vt;
}

string TimVT(BSTNode* root)
{
      string s;
      char mvt[10];
      paintBox box;
      TextLabel lb;
      box.BoxX(66,5,50,5,1);
      SetColor(15);
      lb.LabelX("MA VAT TU: ",52,7,1);
      box.paint();
      lb.Print();
      lb.LabelX("                        ",65,7,0);
      lb.Print();
      SetColor(0);
      lb.LabelX(" TIM KIEM ",91,7,15);
      lb.Print();
      lb.LabelX(" THOAT ",105,7,15);
      lb.Print();
      short cur = 0;
      lb.LabelX("                        ",65,7,0);
      lb.Print();
      gotoxy(67,7);
      set_cursor(true);
      while (true)
      {
            char k = getch();
            if (k==-32)
            {
                  k = getch();
                  if (k==LEFT&&cur==1)
                  {
                        set_cursor(true);
                        SetColor(0);
                        lb.LabelX(" TIM KIEM ",91,7,15);
                        lb.Print();
                        lb.LabelX("                        ",65,7,0);
                        lb.Print();
                        SetColor(15);
                        gotoxy(68,7);cout<<s;
                        cur=0;
                  }
                  if (k==LEFT&&cur==2)
                  {
                        SetColor(0);
                        lb.LabelX(" THOAT ",105,7,15);
                        lb.Print();
                        SetColor(15);
                        lb.LabelX(" TIM KIEM ",91,7,2);
                        lb.Print();
                        cur=1;
                  }
                  if (k==RIGHT&&cur==1)
                  {
                        SetColor(0);
                        lb.LabelX(" TIM KIEM ",91,7,15);
                        lb.Print();
                        SetColor(15);
                        lb.LabelX(" THOAT ",105,7,2);
                        lb.Print();
                        cur=2;
                  }
                  if (k==RIGHT&&cur==0)
                  {
                        set_cursor(false);
                        SetColor(15);
                        lb.LabelX(" TIM KIEM ",91,7,2);
                        lb.Print();
                        cur = 1;
                  }
            }
            else
            if (cur==0&&checkDataString(k)&&s.length()<10)
            {
                  SetColor(15);
                  s.push_back(k);
                  gotoxy(67+s.length(),7);
                  cout<<k;
            }
            else
            if (k==BACKSPACE&&!s.empty())
            {
                  gotoxy(67+s.length()+1,7);
                  BacksapaceData(67+s.length()+1,7);
                  s.pop_back();
            }
            else
            if (cur==1&&k==ENTER)
            {
                  strcpy(mvt,s.c_str());
                  if (findVATTU(root,mvt)!=NULL)
                  {     
                        box.deleteBox();
                        return s;
                  }
                  Alertmgs("KHONG TIM DUOC VAT TU",50,11);
                  gotoxy(67+s.length()+1,6);
                  continue;
            }
            else
            if (cur==2&&k==ENTER)
            {
                  if (Query("BAN CO MUON THOAT ?",50,11))
                  {
                        s.clear();
                        box.deleteBox();
                        return s;
                  }
            }
      }
      s.clear();
      return s;
}