#ifndef _INPUTDATA_
#define _INPUTDATA_
#include "VatTu.h"
#include "TableData.h"


BSTNode* inputfileVT()
{
    BSTNode * root = NULL;
    ifstream inf;
    inf.open("vattu.txt");
    while (!inf.eof())
    {
        VATTU vt;
        string tmp;
        char dot;
        getline(inf,tmp,',');
        if (tmp[0]==10) tmp.erase(0,1);
        strcpy(vt.MAVT,tmp.c_str());
        getline(inf,vt.TENVT,',');
        inf>>vt.sl;
        inf>>dot;
        getline(inf,vt.DVT,',');
        inf>>vt.check;
        insertBSTNode(root,vt);
    }
    inf.close();
    return root;
}
void updatefileVT()
{
     int j ;
     int outer;
     cout<<"test 3";
}

#endif