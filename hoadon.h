#ifndef _HOADON_
#define _HOADON_
#include"Struct.h"
#include"CtHoaDon.h"

using namespace std ;

NODEHD* creatHoaDon (HOADON data ) {
        NODEHD* node = new NODEHD ;
        node->hd = data ;
        node->next = NULL ;
        return node ;
}

void insertFirst(ListHD &l,NODEHD* node)
{
    if (l.first==NULL)
    {
        l.first = node;
        l.last = node;
    }
    else
    {
        node->next = l.first;
        l.first = node;
    }
}
#endif