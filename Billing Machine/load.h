#include <windows.h>
void space()//for spacing only
{
    std::cout<<std::endl;
    for(int i=0;i<(168/2)-49;i++)
    {
        std::cout<<" ";
    }
}//using namespace line;
void loading()
{
    Sleep(1000);
    system("cls");
   /* CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X =0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);*/
    Sleep(1000);
    system("color 74");
    int i=0;
    while(i<20)
    {
      std::cout<<std::endl;
      i++;
    }
    std::cout<<"                                                                 Loading";
    for(i=0;i<5;i++)
    {
         Sleep(500);
         std::cout<<".";
    }
    Sleep(500);
    system("cls");
}
void loading_success()
{
    Sleep(1000);
    system("cls");
    //Sleep(2000);
    int i=0;
    while(i<20)
    {
      std::cout<<std::endl;
      i++;
    }
    std::cout<<"                                                                      Login Successfully Completed!!!!!!!";
    /*for(i=0;i<9;i++)
    {
         Sleep(500);
         std::cout<<".";
    }*/
    Sleep(2000);
    system("cls");
}
int disp()
{
    system("color f2");
    int key;
    space();
    std::cout<<"1.To Billing.";
    space();
    std::cout<<"2.To Show Previous Bills.";
    space();
    std::cout<<"3.To Show Latest Bill.";
    space();
    std::cout<<"4.To Delete All Bills.";
    space();
    std::cout<<"0.Exit.";
    space();
    std::cout<<"Press the number between 0 to 4!!";
    std::cout<<std::endl;
    space();
    std::cin>>key;
    space();
    return key;
}
void setting_font()
{
  CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X =0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 40;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
