#ifndef _NHANVIEN_
#define _NHANVIEN_
#include"Struct.h"

using namespace std ;


void insertNhanVien (NHANVIEN nv, ds_NHANVIEN &listnv ) {
         listnv.ds[listnv.count] = new NHANVIEN;
         strncpy(listnv.ds[listnv.count]->MANV, nv.MANV, sizeof(nv.MANV)) ;
         listnv.ds[listnv.count]->HO = nv.HO ;
         listnv.ds[listnv.count]->TEN = nv.TEN ;
         listnv.ds[listnv.count]->PHAI = nv.PHAI ;
         listnv.count++ ;
}

void deleteNhanVien (ds_NHANVIEN &listnv , char id[10]) {
       int temp = listnv.count ;
       for(int i = 0 ; i < temp ; i++) {
           if (strcmp(listnv.ds[i]->MANV,id) == 0 ) {
               for(int j = i ; j < temp-1 ; j++) {
                    listnv.ds[j] = listnv.ds[j+1] ;
               }
               delete listnv.ds[temp] ;
               listnv.count-- ;
               break;
           }
       }
}

void fixNhanVien(NHANVIEN nv, ds_NHANVIEN &listnv, int pos)
{
    listnv.ds[pos]->HO = nv.HO;
    listnv.ds[pos]->TEN = nv.TEN;
    listnv.ds[pos]->PHAI = nv.PHAI;
}
#endif