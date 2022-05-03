#ifndef _STRUCT_ 
#define _STRUCT_
#include"mylib.h"
#define MAX_NHANVIEN 500

using namespace std ;


// Vật Tư
struct VATTU
{
    char MAVT[10] ;
    string TENVT ;
    int sl ;
    string DVT ;
    bool check ;
};
// Cây nhị phân
struct BSTNode
{
    VATTU vt ;
    BSTNode*left ;
    BSTNode*right ;
};
//Hóa Đơn
struct My_Date
{
    int ngay ;
    int thang ;
    int nam ;
};
struct CT_HOADON
{
    string  MAVT ;
    int   Soluong;
    int Dongia;
    float VAT ;
};

struct NODECTHD
{
    CT_HOADON ct_hd;
    NODECTHD* next;
};

struct ListCTHD
{
    NODECTHD* first =  NULL;
    NODECTHD* last = NULL;
};

struct HOADON
{
    char SoHD[20] ;
    My_Date date;
    string Loai ;
    ListCTHD cthd ;
};

struct NODEHD
{
      HOADON hd ;
      NODEHD* next;
};

 struct ListHD
 {
     NODEHD*first = NULL;
     NODEHD*last = NULL ;
 };
 
// Danh sách Hóa đơn
struct DANHSACHHD {
      int count = 0;
      HOADON *hdnv ;
};

// Nhân viên
struct NHANVIEN
{
    char MANV[10] ;
    string HO ;
    string TEN ;
    string PHAI ;
    DANHSACHHD DSHD;
};
struct ds_NHANVIEN
{
    int count = 0;
	NHANVIEN *ds[MAX_NHANVIEN];
};



#endif