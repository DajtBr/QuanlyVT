#include "VatTu.h"
#include "inputData.h"
#include "MenuSelec.h"
#include "TableData.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    set_cursor(false);
    BSTNode* root;
    while (true)
    {
        SetBGColor(0);
        SetColor(15);
        int choose = Menuselec1();
        switch (choose)
        {
            case 1:
                root = inputfileVT();
                printTableVT(root);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                {
                    int tchoose = MenuThongke();
                    switch (tchoose)
                    {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                    }
                }
            case 5:
                break;
        }
        if (choose==5) break;
    }
    
}
       
