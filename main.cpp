#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "header.h"

//objects for each class

Drinks dr[10];
Chocolates ch[10];
Chips cp[10];
VendingMachine Vm;
fstream datafile;
Bill bi;
time_t t=time(NULL);
char cardno[17];
char cvv[4];
char amount[13];
int answer;
float balance;

void cart()
{
    dr[0].set_price(50);
    dr[1].set_price(50);
    dr[2].set_price(40);
    dr[3].set_price(50);
    dr[4].set_price(30);
    dr[5].set_price(55);
    dr[6].set_price(40);
    dr[7].set_price(55);
    dr[8].set_price(50);
    dr[9].set_price(55);

    ch[0].set_price(30);
    ch[1].set_price(20);
    ch[2].set_price(30);
    ch[3].set_price(20);
    ch[4].set_price(20);
    ch[5].set_price(35);
    ch[6].set_price(20);
    ch[7].set_price(20);
    ch[8].set_price(30);
    ch[9].set_price(20);

    cp[0].set_price(10);
    cp[1].set_price(20);
    cp[2].set_price(10);
    cp[3].set_price(20);
    cp[4].set_price(20);
    cp[5].set_price(10);
    cp[6].set_price(20);
    cp[7].set_price(20);
    cp[8].set_price(10);
    cp[9].set_price(20);

    dr[0].set_name("7 UP       ");
    dr[1].set_name("Lemonade   ");
    dr[2].set_name("Maaza      ");
    dr[3].set_name("Coca cola  ");
    dr[4].set_name("Pepsi      ");
    dr[5].set_name("Thumbs up  ");
    dr[6].set_name("Limca      ");
    dr[7].set_name("Sprite     ");
    dr[8].set_name("Fanta      ");
    dr[9].set_name("Mirinda    ");

    ch[0].set_name("Kit kat    ");
    ch[1].set_name("Snickers   ");
    ch[2].set_name("Dairy Milk ");
    ch[3].set_name("Bar one    ");
    ch[4].set_name("Munch      ");
    ch[5].set_name("5 star     ");
    ch[6].set_name("Milky bar  ");
    ch[7].set_name("Peak       ");
    ch[8].set_name("Fuse       ");
    ch[9].set_name("Gems       ");

    cp[0].set_name("Terra      ");
    cp[1].set_name("Lays       ");
    cp[2].set_name("Kurkure    ");
    cp[3].set_name("Doritos    ");
    cp[4].set_name("Puff corn  ");
    cp[5].set_name("Cheetos    ");
    cp[6].set_name("Pop chips  ");
    cp[7].set_name("Ruffles    ");
    cp[8].set_name("Pringles   ");
    cp[9].set_name("Tostitos   ");
}




/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = CreateSolidBrush (RGB(204,255,255));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
 szClassName,         /* Classname */
           _T("Vending Machine"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
 NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}



/*  This function is called by the Windows function DispatchMessage()  */
#define ID_LABEL 1
#define ID_CMD1 2
#define ID_CMD2 3
#define ID_CMD3 4
#define ID_CMD4 5
#define ID_CMD5 6
#define ID_CMD6 7
#define ID_CMD7 8
#define ID_CMD8 9
#define ID_CMD9 10
#define ID_CMD10 11
#define ID_CMD11 12
#define ID_CMD12 13
#define ID_CMD13 14
#define ID_CMD14 15
#define ID_CMD15 16
#define ID_CMD16 17
#define ID_CMD17 18
#define ID_CMD18 19
#define ID_CMD19 20
#define ID_CMD20 21
#define ID_CMD21 22
#define ID_CMD22 23
#define ID_CMD23 24
#define ID_CMD24 25
#define ID_CMD25 26
#define ID_CMD26 27
#define ID_CMD27 28
#define ID_CMD28 29
#define ID_CMD29 30
#define ID_CMD30 31
#define ID_EDIT 32
#define ID_CMD31 33
#define ID_CMD32 34
#define ID_CMD33 35
#define ID_CMD34 36
#define ID_CMD35 37
#define ID_CMD36 38

static HWND hwndlb1;
static HWND hwndlb2;
static HWND hwndlb3;
static HWND hwndlb4;
static HWND hwndlb5;
static HWND hwndlb6;
//static HWND hwndlb7;
static HWND hwndcmd1;
static HWND hwndcmd2;
static HWND hwndcmd3;
static HWND hwndcmd4;
static HWND hwndcmd5;
static HWND hwndcmd6;
static HWND hwndcmd7;
static HWND hwndcmd8;
static HWND hwndcmd9;
static HWND hwndcmd10;
static HWND hwndcmd11;
static HWND hwndcmd12;
static HWND hwndcmd13;
static HWND hwndcmd14;
static HWND hwndcmd15;
static HWND hwndcmd16;
static HWND hwndcmd17;
static HWND hwndcmd18;
static HWND hwndcmd19;
static HWND hwndcmd20;
static HWND hwndcmd21;
static HWND hwndcmd22;
static HWND hwndcmd23;
static HWND hwndcmd24;
static HWND hwndcmd25;
static HWND hwndcmd26;
static HWND hwndcmd27;
static HWND hwndcmd28;
static HWND hwndcmd29;
static HWND hwndcmd30;
static HWND hwndcmd31;
static HWND hwndcmd32;
static HWND hwndcmd33;
static HWND hwndcmd34;
static HWND hwndcmd35;
static HWND hwndcmd36;

HWND Textbox;
HWND Textbox1;
HWND Textbox2;

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            hwndlb1=CreateWindow(TEXT("STATIC"),TEXT("   PRODUCTS   "),WS_VISIBLE|WS_CHILD|WS_BORDER,10,10,130,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            hwndlb2=CreateWindow(TEXT("STATIC"),TEXT("      DRINKS  "),WS_VISIBLE|WS_CHILD|WS_BORDER,10,50,130,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            hwndcmd1=CreateWindow(TEXT("BUTTON"),TEXT("7 UP"),WS_VISIBLE|WS_CHILD,50,100,100,30,hwnd,(HMENU) ID_CMD1,NULL,NULL);
            hwndcmd2=CreateWindow(TEXT("BUTTON"),TEXT("LEMONADE"),WS_VISIBLE|WS_CHILD,200,100,100,30,hwnd,(HMENU) ID_CMD2,NULL,NULL);
            hwndcmd3=CreateWindow(TEXT("BUTTON"),TEXT("MAAZA"),WS_VISIBLE|WS_CHILD,400,100,100,30,hwnd,(HMENU) ID_CMD3,NULL,NULL);
            hwndcmd4=CreateWindow(TEXT("BUTTON"),TEXT("COCA COLA"),WS_VISIBLE|WS_CHILD,600,100,100,30,hwnd,(HMENU) ID_CMD4,NULL,NULL);
            hwndcmd5=CreateWindow(TEXT("BUTTON"),TEXT("PEPSI"),WS_VISIBLE|WS_CHILD,800,100,100,30,hwnd,(HMENU) ID_CMD5,NULL,NULL);
            hwndcmd6=CreateWindow(TEXT("BUTTON"),TEXT("THUMBS UP"),WS_VISIBLE|WS_CHILD,50,180,100,30,hwnd,(HMENU) ID_CMD6,NULL,NULL);
            hwndcmd7=CreateWindow(TEXT("BUTTON"),TEXT("LIMCA"),WS_VISIBLE|WS_CHILD,200,180,100,30,hwnd,(HMENU) ID_CMD7,NULL,NULL);
            hwndcmd8=CreateWindow(TEXT("BUTTON"),TEXT("SPRITE"),WS_VISIBLE|WS_CHILD,400,180,100,30,hwnd,(HMENU) ID_CMD8,NULL,NULL);
            hwndcmd9=CreateWindow(TEXT("BUTTON"),TEXT("FANTA"),WS_VISIBLE|WS_CHILD,600,180,100,30,hwnd,(HMENU) ID_CMD9,NULL,NULL);
            hwndcmd10=CreateWindow(TEXT("BUTTON"),TEXT("MIRINDA"),WS_VISIBLE|WS_CHILD,800,180,100,30,hwnd,(HMENU) ID_CMD10,NULL,NULL);
            hwndlb3=CreateWindow(TEXT("STATIC"),TEXT("    CHOCOLATES  "),WS_VISIBLE|WS_CHILD|WS_BORDER,10,250,130,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            hwndcmd11=CreateWindow(TEXT("BUTTON"),TEXT("KIT KAT"),WS_VISIBLE|WS_CHILD,50,300,100,30,hwnd,(HMENU) ID_CMD11,NULL,NULL);
            hwndcmd12=CreateWindow(TEXT("BUTTON"),TEXT("SNICKERS"),WS_VISIBLE|WS_CHILD,200,300,100,30,hwnd,(HMENU) ID_CMD12,NULL,NULL);
            hwndcmd13=CreateWindow(TEXT("BUTTON"),TEXT("DAIRY MILK"),WS_VISIBLE|WS_CHILD,400,300,100,30,hwnd,(HMENU) ID_CMD13,NULL,NULL);
            hwndcmd14=CreateWindow(TEXT("BUTTON"),TEXT("BAR ONE"),WS_VISIBLE|WS_CHILD,600,300,100,30,hwnd,(HMENU) ID_CMD14,NULL,NULL);
            hwndcmd15=CreateWindow(TEXT("BUTTON"),TEXT("MUNCH"),WS_VISIBLE|WS_CHILD,800,300,100,30,hwnd,(HMENU) ID_CMD15,NULL,NULL);
            hwndcmd16=CreateWindow(TEXT("BUTTON"),TEXT("5 STAR"),WS_VISIBLE|WS_CHILD,50,380,100,30,hwnd,(HMENU) ID_CMD16,NULL,NULL);
            hwndcmd17=CreateWindow(TEXT("BUTTON"),TEXT("MILKYBAR"),WS_VISIBLE|WS_CHILD,200,380,100,30,hwnd,(HMENU) ID_CMD17,NULL,NULL);
            hwndcmd18=CreateWindow(TEXT("BUTTON"),TEXT("PEAK"),WS_VISIBLE|WS_CHILD,400,380,100,30,hwnd,(HMENU) ID_CMD18,NULL,NULL);
            hwndcmd19=CreateWindow(TEXT("BUTTON"),TEXT("FUSE"),WS_VISIBLE|WS_CHILD,600,380,100,30,hwnd,(HMENU) ID_CMD19,NULL,NULL);
            hwndcmd20=CreateWindow(TEXT("BUTTON"),TEXT("GEMS"),WS_VISIBLE|WS_CHILD,800,380,100,30,hwnd,(HMENU) ID_CMD20,NULL,NULL);
            hwndlb4=CreateWindow(TEXT("STATIC"),TEXT("       CHIPS  "),WS_VISIBLE|WS_CHILD|WS_BORDER,10,450,130,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            hwndcmd21=CreateWindow(TEXT("BUTTON"),TEXT("TERRA"),WS_VISIBLE|WS_CHILD,50,500,100,30,hwnd,(HMENU) ID_CMD21,NULL,NULL);
            hwndcmd22=CreateWindow(TEXT("BUTTON"),TEXT("LAYS"),WS_VISIBLE|WS_CHILD,200,500,100,30,hwnd,(HMENU) ID_CMD22,NULL,NULL);
            hwndcmd23=CreateWindow(TEXT("BUTTON"),TEXT("KURKURE"),WS_VISIBLE|WS_CHILD,400,500,100,30,hwnd,(HMENU) ID_CMD23,NULL,NULL);
            hwndcmd24=CreateWindow(TEXT("BUTTON"),TEXT("DORITOS"),WS_VISIBLE|WS_CHILD,600,500,100,30,hwnd,(HMENU) ID_CMD24,NULL,NULL);
            hwndcmd25=CreateWindow(TEXT("BUTTON"),TEXT("PUFFCORN"),WS_VISIBLE|WS_CHILD,800,500,100,30,hwnd,(HMENU) ID_CMD25,NULL,NULL);
            hwndcmd26=CreateWindow(TEXT("BUTTON"),TEXT("CHEETOS"),WS_VISIBLE|WS_CHILD,50,580,100,30,hwnd,(HMENU) ID_CMD26,NULL,NULL);
            hwndcmd27=CreateWindow(TEXT("BUTTON"),TEXT("POP CHIPS"),WS_VISIBLE|WS_CHILD,200,580,100,30,hwnd,(HMENU) ID_CMD27,NULL,NULL);
            hwndcmd28=CreateWindow(TEXT("BUTTON"),TEXT("RUFFLES"),WS_VISIBLE|WS_CHILD,400,580,100,30,hwnd,(HMENU) ID_CMD28,NULL,NULL);
            hwndcmd29=CreateWindow(TEXT("BUTTON"),TEXT("PRINGLES"),WS_VISIBLE|WS_CHILD,600,580,100,30,hwnd,(HMENU) ID_CMD29,NULL,NULL);
            hwndcmd30=CreateWindow(TEXT("BUTTON"),TEXT("TOSTITOS"),WS_VISIBLE|WS_CHILD,800,580,100,30,hwnd,(HMENU) ID_CMD30,NULL,NULL);
            hwndlb5=CreateWindow(TEXT("STATIC"),TEXT("  Enter Credit Card no"),WS_VISIBLE|WS_CHILD|WS_BORDER,1050,100,200,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            Textbox=CreateWindow("EDIT","",WS_BORDER|WS_VISIBLE|WS_CHILD,1050,150,200,30,hwnd,NULL,NULL,NULL);
            hwndlb6=CreateWindow(TEXT("STATIC"),TEXT("  Enter cvv no"),WS_VISIBLE|WS_CHILD|WS_BORDER,1050,200,200,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            Textbox1=CreateWindow("EDIT","",WS_BORDER|WS_VISIBLE|WS_CHILD,1050,250,200,30,hwnd,NULL,NULL,NULL);
            hwndcmd31=CreateWindow(TEXT("BUTTON"),TEXT(" ENTER "),WS_VISIBLE|WS_CHILD,1075,300,150,30,hwnd,(HMENU) ID_CMD31,NULL,NULL);
            hwndcmd33=CreateWindow(TEXT("BUTTON"),TEXT("Or"),WS_VISIBLE|WS_CHILD|WS_BORDER,1110,400,80,30,hwnd,(HMENU) ID_CMD33,NULL,NULL);
            //hwndlb7=CreateWindow(TEXT("STATIC"),TEXT("    CASH COLLECTOR"),WS_VISIBLE|WS_CHILD|WS_BORDER,1050,500,200,20,hwnd,(HMENU) ID_LABEL,NULL,NULL);
            Textbox2=CreateWindow("EDIT","",WS_BORDER|WS_VISIBLE|WS_CHILD,1050,550,200,30,hwnd,NULL,NULL,NULL);
            hwndcmd32=CreateWindow(TEXT("BUTTON"),TEXT("ENTER"),WS_VISIBLE|WS_CHILD,1075,600,150,30,hwnd,(HMENU) ID_CMD32,NULL,NULL);
            hwndcmd34=CreateWindow(TEXT("BUTTON"),TEXT("CONFIRM"),WS_VISIBLE|WS_CHILD,500,650,150,30,hwnd,(HMENU) ID_CMD34,NULL,NULL);
            hwndcmd34=CreateWindow(TEXT("BUTTON"),TEXT("EXIT"),WS_VISIBLE|WS_CHILD,50,650,150,30,hwnd,(HMENU) ID_CMD35,NULL,NULL);
            hwndcmd35=CreateWindow(TEXT("BUTTON"),TEXT(" -- PAYMENT --"),WS_VISIBLE|WS_CHILD,1075,10,130,40,hwnd,(HMENU) ID_CMD35,NULL,NULL);
            hwndcmd36=CreateWindow(TEXT("BUTTON"),TEXT(" -- CASH COLLECTOR --"),WS_VISIBLE|WS_CHILD,1050,500,200,35,hwnd,(HMENU) ID_CMD35,NULL,NULL);
            break;
        case WM_COMMAND:
            cart();
            if(LOWORD(wParam)==ID_CMD1)
            {
                try
                {
                        if(dr[0].checkstock())
                        {
                            dr[0].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"7 UP Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"7up stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD2)
            {
                try
                {
                        if(dr[1].checkstock())
                        {
                            dr[1].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Lemonade Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Lemonade stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD3)
            {
                try
                {
                        if(dr[2].checkstock())
                        {
                            dr[2].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Maaza Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Maaza stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD4)
            {
                try
                {
                        if(dr[3].checkstock())
                        {
                            dr[3].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Coca cola Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Coca cola stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD5)
            {
                try
                {
                        if(dr[4].checkstock())
                        {
                            dr[4].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Pepsi Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Pepsi stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD6)
            {
                try
                {
                        if(dr[5].checkstock())
                        {
                            dr[5].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Thumbs up Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Thumbs up stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD7)
            {
                try
                {
                        if(dr[6].checkstock())
                        {
                            dr[6].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Limca Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Limca stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD8)
            {
                try
                {
                        if(dr[7].checkstock())
                        {
                            dr[7].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Sprite Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Sprite stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD9)
            {
                try
                {
                        if(dr[8].checkstock())
                        {
                            dr[8].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Fanta Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Fanta stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD10)
            {
                try
                {
                        if(dr[9].checkstock())
                        {
                            dr[9].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Mirinda Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Mirinda stock over"<<endl;
                    datafile.close();
                }

            }
            else if(LOWORD(wParam)==ID_CMD11)
            {
                try
                {

                        if(ch[0].checkstock())
                        {
                            ch[0].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"KIT KAT Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"KIT KAT stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD12)
            {
                try
                {
                        if(ch[1].checkstock())
                        {
                            ch[1].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Snickers Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Snickers stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD13)
            {
                try
                {
                        if(ch[2].checkstock())
                        {
                            ch[2].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"DAIRY MILK Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"DAIRY MILK stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD14)
            {
                try
                {
                        if(ch[3].checkstock())
                        {
                            ch[3].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"BAR ONE Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"BAR ONE stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD15)
            {
                try
                {
                        if(ch[4].checkstock())
                        {
                            ch[4].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"MUNCH Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"MUNCH stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD16)
            {
                try
                {
                        if(ch[5].checkstock())
                        {
                            ch[5].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"5 STAR Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"5 STAR stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD17)
            {
                try
                {
                        if(ch[6].checkstock())
                        {
                            ch[6].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"MILKYBAR Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"MILKYBAR stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD18)
            {
                try
                {
                        if(ch[7].checkstock())
                        {
                            ch[7].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"PEAK Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"PEAK stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD19)
            {
                try
                {
                        if(ch[8].checkstock())
                        {
                            ch[8].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Fuse Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Fuse stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD20)
            {
                try
                {
                        if(ch[9].checkstock())
                        {
                            ch[9].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"GEMS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"GEMS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD21)
            {
                try
                {
                        if(cp[0].checkstock())
                        {
                            cp[0].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"TERRA Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"TERRA stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD22)
            {
                try
                {
                        if(cp[1].checkstock())
                        {
                            cp[1].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"LAYS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"LAYS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD23)
            {
                try
                {
                        if(cp[2].checkstock())
                        {
                            cp[2].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"KURKURE Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"KURKURE stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD24)
            {
                try
                {
                        if(cp[3].checkstock())
                        {
                            cp[3].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"DORITOS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"DORITOS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD25)
            {
                try
                {
                        if(cp[4].checkstock())
                        {
                            cp[4].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"PUFFCORN Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"PUFFCORN stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD26)
            {
                try
                {
                        if(cp[5].checkstock())
                        {
                            cp[5].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"CHEETOS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"CHEETOS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD27)
            {
                try
                {
                        if(cp[6].checkstock())
                        {
                            cp[6].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"POP CHIPS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"POP CHIPS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD28)
            {
                try
                {
                        if(cp[7].checkstock())
                        {
                            cp[7].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"RUFFLES Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"RUFFLES stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD29)
            {
                try
                {
                        if(cp[8].checkstock())
                        {
                            cp[8].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"Pringles Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Pringles stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD30)
            {
                try
                {
                        if(cp[9].checkstock())
                        {
                            cp[9].purchase();
                        }
                        else
                            throw 10;
                }
                catch(int s)
                {
                    MessageBox(hwnd,"TOSTITOS Not available","Sorry!",MB_OK|MB_ICONINFORMATION);
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"TOSTITOS stock over"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD31)
            {
                GetWindowText(Textbox,&cardno[0],17);
                GetWindowText(Textbox1,&cvv[0],4);
                answer=Vm.T.checkCard(cardno,cvv);
                if(answer==1)
                {
                    MessageBox(hwnd,"Transaction Success","Success",MB_OK|MB_ICONINFORMATION);
                    system("cls");
                    bi.display_bill(dr,ch,cp,0);
                    SetWindowText(Textbox,"");
                    SetWindowText(Textbox1,"");
                    MessageBox(hwnd,"THANKS FOR YOUR PURCHASE!","Thank you",MB_OK|MB_ICONINFORMATION);
                    DestroyWindow(hwnd);
                }
                else if(answer==2)
                {
                    MessageBox(hwnd,"Incorrect pin","Warning",MB_OK|MB_ICONINFORMATION);
                    SetWindowText(Textbox1,"");
                }
                else if(answer==0)
                {
                    MessageBox(hwnd,"Account doesn't exist","Warning",MB_OK|MB_ICONINFORMATION);
                    SetWindowText(Textbox,"");
                    SetWindowText(Textbox1,"");
                }
            }
            else if(LOWORD(wParam)==ID_CMD32)
            {
                GetWindowText(Textbox2,&amount[0],13);
                try
                {
                    if(Vm.C.checkBalance(amount,bi)and Vm.C.get_balance()!=0)
                    {
                        MessageBox(hwnd,"Collect your balance at cash dispenser","Success",MB_OK|MB_ICONINFORMATION);
                        SetWindowText(Textbox2,"");
                        system("cls");
                        bi.display_bill(dr,ch,cp,Vm.C.get_balance());
                        MessageBox(hwnd,"THANKS FOR YOUR PURCHASE!","Thank you",MB_OK|MB_ICONINFORMATION);
                        DestroyWindow(hwnd);
                    }
                    else if(Vm.C.checkBalance(amount,bi)and Vm.C.get_balance()==0)
                    {
                        MessageBox(hwnd,"Your paid amount correctly","Success",MB_OK|MB_ICONINFORMATION);
                        SetWindowText(Textbox2,"");
                        system("cls");
                        bi.display_bill(dr,ch,cp,0);
                        MessageBox(hwnd,"THANKS FOR YOUR PURCHASE!","Thank you",MB_OK|MB_ICONINFORMATION);
                        DestroyWindow(hwnd);
                    }
                    else
                    {
                        throw 10;
                    }
                }
                catch(int no)
                {
                    MessageBox(hwnd,"Balance insufficient in Vending machine\nGo to card payment option","Warning",MB_OK|MB_ICONINFORMATION);
                    SetWindowText(Textbox2,"");
                    datafile.open("Logs.txt",ios::out|ios::app);
                    datafile<<ctime(&t)<<endl;
                    datafile<<"Vending machine balance is insufficient"<<endl;
                    datafile.close();
                }
            }
            else if(LOWORD(wParam)==ID_CMD34)
            {
                system("cls");
                cout<<"YOUR CART:"<<endl;
                bi.Calculate(dr,ch,cp);
                bi.display_bill(dr,ch,cp,0);
                cout<<"Confirm your order(1-Yes/2-No):"<<endl;
                cin>>answer;
                if(answer==1)
                {
                    cout<<"Proceed to pay"<<endl;
                    cout<<"In case of card enter card no and cvv pin"<<endl;
                    cout<<"In case of cash insert cash in cash collector"<<endl;
                }
                else if(answer==2)
                {
                     system("cls");
                     MessageBox(hwnd,"HAVE A NICE DAY!","Thank you",MB_OK|MB_ICONINFORMATION);
                     DestroyWindow(hwnd);
                }
            }
            else if(LOWORD(wParam)==ID_CMD35)
            {
                MessageBox(hwnd,"THANKS FOR YOUR PURCHASE!","Thank you",MB_OK|MB_ICONINFORMATION);
                DestroyWindow(hwnd);
                system("cls");
            }
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
