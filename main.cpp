#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACEBAR 32
#define RESTART 114
#define QUIT 113


int tX, tY, space;
bool spacebar;
bool winORnot;
bool quit;

char gameboard[10][12];
char finishedboard[10][12];
char startboard[10][12];

int levelXY[20];
int levelSpace[10];

bool lvl1 = false;
bool lvl2 = false;
bool lvl3 = false;
bool lvl4 = false;
bool lvl5 = false;
bool lvl6 = false;
bool lvl7 = false;
bool lvl8 = false;
bool lvl9 = false;
bool lvl10 = false;

void refresh(int y);
void refreshXY(int Y, int X);
void screenCl(int cl);
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
class settingsClass//VISKAS VEIKIA
{
private:                   //VISKAS VEIKIA
    void color()
    {
        int co = 1;
        bool colorpower = true;

        screenCl(4);

        cout << "     COLOR OF SYMBOLS:\n";
        cout << " Blue\n";
        cout << " Green\n";
        cout << " Red\n";
        cout << " White\n";
        cout << " Back to the settings\n";

        while (colorpower)
        {
            refresh(co);

            switch (getch())
            {
            case KEY_UP:
                if (co == 1)
                {
                    co = 5;
                    break;
                }
                else
                {
                    co--;
                    break;
                }
            case KEY_DOWN:
                if (co == 5)
                {
                    co = 1;
                    break;
                }
                else
                {
                    co++;
                    break;
                }
            case SPACEBAR:
                switch (co)
                {
                case 1:
                    system ( "color 03" );
                    break;
                case 2:
                    system ( "color 02" );
                    break;
                case 3:
                    system ( "color 04" );
                    break;
                case 4:
                    system ( "color 07" );
                    break;
                case 5:
                    colorpower = false;
                    break;
                default:
                    break;
                }

            default:
                break;
            }
        }
        screenCl(6);
    }

private:                   //VISKAS VEIKIA
    void sound()
    {
        screenCl(4);
        cout << "ERROR\n";
        cout << "There are no sounds in this game.\n";
        system("pause");
        screenCl(4);
    }

public:                    //VISKAS VEIKIA
    void settings()
    {
        bool setpower = true;
        int s = 1;

        screenCl(4);

        while (setpower)
        {

            screenCl(4);
            cout << "     SETTINGS:\n";
            cout << " Color of symbols\n";
            cout << " Sound\n";
            cout << " Back to the meniu\n";

            refresh(s);

            switch (getch())
            {
            case KEY_UP:
                if (s == 1)
                {
                    s = 3;
                    break;
                }
                else
                {
                    s--;
                    break;
                }
            case KEY_DOWN:
                if (s == 3)
                {
                    s = 1;
                    break;
                }
                else
                {
                    s++;
                    break;
                }
            case SPACEBAR:
                switch (s)
                {
                case 1:
                    color();
                    break;
                case 2:
                    sound();
                    break;
                case 3:
                    setpower = false;
                    break;
                }
            default:
                break;
            }
        }
    }
};

class playClass
{
private: void arrayPrint()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                cout << gameboard[i][j];
            }
            cout << endl;
        }
    }

private: void levelRead(string file)
    {
        ifstream f1;
        f1.open(file.c_str());

        f1 >> tX >> tY >> space;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                f1 >> gameboard[i][j];
                startboard[i][j] = gameboard[i][j];
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                f1 >> finishedboard[i][j];
            }
        }
        f1.close();
    }

private: void levelPrint()
    {
        screenCl(5);
        cout << "     LEVELS" << endl;
        if (lvl1 == true)
            cout << " Level 1 - cleared" << endl;
        else cout << " Level 1" << endl;
        if (lvl2 == true)
            cout << " Level 2 - cleared" << endl;
        else cout << " Level 2" << endl;
        if (lvl3 == true)
            cout << " Level 3 - cleared" << endl;
        else cout << " Level 3" << endl;
        if (lvl4 == true)
            cout << " Level 4 - cleared" << endl;
        else cout << " Level 4" << endl;
        if (lvl5 == true)
            cout << " Level 5 - cleared" << endl;
        else cout << " Level 5" << endl;
        if (lvl6 == true)
            cout << " Level 6 - cleared" << endl;
        else cout << " Level 6" << endl;
        if (lvl7 == true)
            cout << " Level 7 - cleared" << endl;
        else cout << " Level 7" << endl;
        if (lvl8 == true)
            cout << " Level 8 - cleared" << endl;
        else cout << " Level 8" << endl;
        if (lvl9 == true)
            cout << " Level 9 - cleared" << endl;
        else cout << " Level 9" << endl;
        if (lvl10 == true)
            cout << " Level 10 - cleared" << endl;
        else cout << " Level 10" << endl;
        cout << " Back to the Play meniu";

    }

private: bool movement(int& y, int& x)
    {
        switch (getch())
        {
        case KEY_UP:
            if (gameboard[y - 1][x] == '#' || gameboard[y - 1][x] == 'x')
            {
                break;
                return true;
            }
            else
            {
                if (spacebar == false)
                {
                    refreshXY(y, x); cout << "x";
                    gameboard[y][x] = 'x';
                }
                else
                {
                    refreshXY(y, x); cout << ".";
                    gameboard[y][x] = '.';
                }
                refreshXY(y - 1, x); cout << "o";
                gameboard[--y][x] = 'o';

                spacebar = false;
                break;
                return true;
            }
        case KEY_DOWN:
            if (gameboard[y + 1][x] == '#' || gameboard[y + 1][x] == 'x')
            {
                break;
                return true;
            }
            else
            {
                if (spacebar == false)
                {
                    refreshXY(y, x); cout << "x";
                    gameboard[y][x] = 'x';
                }
                else
                {
                    refreshXY(y, x); cout << ".";
                    gameboard[y][x] = '.';
                }
                refreshXY(y + 1, x); cout << "o";
                gameboard[++y][x] = 'o';

                spacebar = false;
                break;
                return true;
            }
        case KEY_LEFT:
            if (gameboard[y][x - 1] == '#' || gameboard[y][x - 1] == 'x')
            {
                break;
                return true;
            }
            else
            {
                if (spacebar == false)
                {
                    refreshXY(y, x); cout << "x";
                    gameboard[y][x] = 'x';
                }
                else
                {
                    refreshXY(y, x); cout << ".";
                    gameboard[y][x] = '.';
                }
                refreshXY(y, x - 1); cout << "o";
                gameboard[y][--x] = 'o';

                spacebar = false;
                break;
                return true;

            }
        case KEY_RIGHT:
            if (gameboard[y][x + 1] == '#' || gameboard[y][x + 1] == 'x')
            {
                break;
                return true;
            }
            else
            {
                if (spacebar == false)
                {
                    refreshXY(y, x); cout << "x";
                    gameboard[y][x] = 'x';
                }
                else
                {
                    refreshXY(y, x); cout << ".";
                    gameboard[y][x] = '.';
                }
                refreshXY(y, x + 1); cout << "o";
                gameboard[y][++x] = 'o';

                spacebar = false;
                break;
                return true;
            }
        case SPACEBAR:
            if (space > 0)
            {
                space--;
                spacebar = true;

                refreshXY(12, 0);
                cout << "                                                    ";
                refreshXY(12, 0);
                cout << "You have " << space << " spaces";
                return true;
            }
            else
            {
                refreshXY(12, 0);
                cout << "                                                    ";
                refreshXY(12, 0);
                cout << "You have no spaces";
                return true;
            }
            break;
        case RESTART:
            return false;
            break;
        case QUIT:
            quit = false;
            return false;
            break;
        default:
            return true;
            break;
        }
    }

private: bool checkIFwin()
    {
        bool win = true;

        for (int i = 0; i < 10 && win; i++)
        {
            for (int j = 0; j < 12 && win; j++)
            {
                if (gameboard[i][j] == finishedboard[i][j])
                    continue;
                else
                    win = false;
            }
        }
        return win;
    }

private: bool checkIFstuck(int y, int x)
    {
        if (gameboard[y + 1][x] == 'x' || gameboard[y + 1][x] == '#')
        {
            if (gameboard[y - 1][x] == 'x' || gameboard[y - 1][x] == '#')
            {
                if (gameboard[y][x + 1] == 'x' || gameboard[y][x + 1] == '#')
                {
                    if (gameboard[y][x - 1] == 'x' || gameboard[y][x - 1] == '#')
                    {
                        return true;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }

private: bool levelPlay(int number, int x, int y, string level, bool& lvl)
    {
        bool power = true;
        bool gamepower;
        char yesNO;
        char play;

        quit = true;

        levelSpace[number] = space;
        levelXY[x] = tX;
        levelXY[y] = tY;

        while (power && quit)
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    gameboard[i][j] = startboard[i][j];
                }
            }
            tX = levelXY[x];
            tY = levelXY[y];
            space = levelSpace[number];

            gamepower = true;

            screenCl(12);
            arrayPrint();
            refreshXY(12, 0);
            if (levelSpace[number] == 0)
                cout << "You have no spaces";
            else
                cout << "You have " << levelSpace[number] << " spaces";

            while (gamepower && movement(tY, tX) && quit)
            {
                if (checkIFwin() == true)
                {
                    power = false;
                    gamepower = false;
                    lvl = true;
                    Sleep(500);

                    screenCl(14);
                    cout << "     CONGRATULATIONS\n\n";
                    Sleep(500);
                    cout << "You passed the " << level << " level!\n\n";
                    Sleep(500);
                    if (level == "last")
                    {
                        system("pause");
                        screenCl(5);
                        levelPrint();
                        return false;

                    }
                    else
                    {
wrongWin:
                        cout << "Would you like to play next level? (y/n) ";
                        cin >> yesNO;
                        screenCl(5);
                    }
                    if (yesNO == 'y')
                    {
                        power = false;
                        gamepower = false;
                        return true;
                    }
                    else if (yesNO == 'n')
                    {
                        power = false;
                        gamepower = false;
                        levelPrint();
                        return false;
                    }
                    else
                    {
                        screenCl(3);
                        cout << endl << " Wrong option. You can only quit by pressing 'n'\n";
                        cout << "or continue playing next level by pressing 'y' \n\n";
                        system("pause");
                        screenCl(6);
                        cout << endl;
                        goto wrongWin;
                    }

                }
                else if (checkIFstuck(tY, tX) == true)
                {
                    Sleep(500);
wrongAnswer:
                    screenCl(13);
                    cout << "     YOU FAILED\n\n";
                    Sleep(500);
                    cout << " Would you like to continue playing this level? (y/n) ";
                    Sleep(500);
                    cin >> play;

                    if (play == 'y')
                    {
                        gamepower = false;
                    }
                    else if (play == 'n')
                    {
                        gamepower = false;
                        power = false;

                        screenCl(3);
                        levelPrint();
                        return false;
                    }
                    else
                    {
                        screenCl(3);
                        cout << endl << " Wrong option. You can only quit by pressing 'n'\n";
                        cout << "or continue playing this level by pressing 'y' \n\n";
                        system("pause");
                        goto wrongAnswer;

                    }

                }
            }
        }
        if (quit == false)
        {
            screenCl(15);
            levelPrint();
        }
    }
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
private: void Levels() //--------------------------------------------------------// NOT BUILT YET
    {
        bool levelPower = true;
        int l = 1;
        int winORnot;

        levelPrint();

        while (levelPower)
        {
            levelPower = true;

            refresh(l);

            switch (getch())
            {
            case KEY_UP:
                if (l == 1)
                {
                    l = 11;
                    break;
                }
                else
                {
                    l--;
                    break;
                }
            case KEY_DOWN:
                if (l == 11)
                {
                    l = 1;
                    break;
                }
                else
                {
                    l++;
                    break;
                }
            case SPACEBAR:
                switch (l)
                {
                case 1:
                    levelRead("level1.txt");
                    if (levelPlay(0, 0, 1, "first", lvl1) == false)
                        break;
                case 2:
                    levelRead("level2.txt");
                    if (levelPlay(1, 2, 3, "second", lvl2) == false)
                        break;
                case 3:
                    levelRead("level3.txt");
                    if (levelPlay(2, 4, 5, "third", lvl3) == false)
                        break;
                case 4:
                    levelRead("level4.txt");
                    if (levelPlay(3, 6, 7, "fourth", lvl4) == false)
                        break;
                case 5:
                    levelRead("level5.txt");
                    if (levelPlay(4, 8, 9, "fifth", lvl5) == false)
                        break;
                case 6:
                    levelRead("level6.txt");
                    if (levelPlay(5, 10, 11, "sixth", lvl6) == false)
                        break;
                case 7:
                    levelRead("level7.txt");
                    if (levelPlay(6, 12, 13, "seventh", lvl7) == false)
                        break;
                case 8:
                    levelRead("level8.txt");
                    if (levelPlay(7, 14, 15, "eighth", lvl8) == false)
                        break;
                case 9:
                    levelRead("level9.txt");
                    if (levelPlay(8, 16, 17, "ninth", lvl9) == false)
                        break;
                case 10:
                    levelRead("level10.txt");
                    if (levelPlay(9, 18, 19, "last", lvl10) == false);
                    break;

                case 11:
                    levelPower = false;
                    screenCl(12);
                    break;


                }
            }
        }
    }

private: void Tutorial()
    {
        screenCl(4);
        cout << "     TUTORIAL\n" << endl;
        cout << "By moving symbol  'o'  with your arrow keys\n";
        cout << "you will have to fill all the spaces that are\n";
        cout << "marked with symbol  '.'.  \n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(7);
        cout << endl;

        cout << "Once you move, you will leave symbol  'x'  behind you.\n";
        cout << "You can't step on this field anymore.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(5);
        cout << endl;

        cout << "Fields, marked with symbol  '#'  are the walls.\n";
        cout << "It is not possible to go through them.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(5);
        cout << endl;

        cout << "The only way to pass the level is to fill\n";
        cout << "all the  '.'  fields and end up standing on a\n";
        cout << "'@' symbol.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(6);
        cout << endl;

        cout << "When you hit level 6, you will be able to use spaces.\n";
        cout << "It means that after you press 'space'\n";
        cout << "You won't leave 'x' symbol behind you.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(6);
        cout << endl;

        cout << "After you fail to pass the level,\n";
        cout << "you will be able to restart it or quit it\n";
        cout << "by typing in 'y' or 'n'.\n";
        cout << "Afterwards press enter to confirm your choice.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(7);
        cout << endl;

        cout << "If you can't pass the level or\n";
        cout << "if you know you won't pass it after certain move\n";
        cout << "you can always press 'r' to restart the level\n";
        cout << "or 'q' to quit it.\n" << endl;
        Sleep(1000);
        system("pause");
        screenCl(7);
        cout << endl;

        cout << "Now you will try out a tutorial level.\n" << endl;
        Sleep(500);
        system("pause");
        screenCl(4);

        int startX, startY;
        int spacess;
        bool tutorialPower;
        bool win = false;

        levelRead("tutorial.txt");

        spacess = space;
        startX = tX;
        startY = tY;

        while (win == false)
        {
            tutorialPower = true;

            tX = startX;
            tY = startY;
            space = spacess;

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    gameboard[i][j] = startboard[i][j];
                }
            }

            arrayPrint();
            cout << endl << endl << "You have 1 space";
            while (tutorialPower)
            {
                movement(tY, tX);
                if (checkIFwin() == true)
                {
                    tutorialPower = false;
                    win = true;

                    screenCl(15);
                    cout << " Congratulations!!!\n\n";
                    cout << "You passed the tutorial!\n\n";
                    Sleep(500);
                    cout << "Now you can head towards level 1!\n\n";
                    Sleep(500);
                    system("pause");
                }
                else if (checkIFstuck(tY, tX) == true)
                {
                    tutorialPower = false;
                    Sleep(500);
                    screenCl(15);
                    cout << " You failed.\n\n";
                    Sleep(500);
                    cout << "Remember that you have to end up on a '@' symbol.\n\n";
                    Sleep(500);
                    cout << "Also there is one space in this level you have to use.\n\n";
                    Sleep(500);
                    cout << "And don't forget to fill all the '.'.\n\n";
                    Sleep(500);
                    cout << "Try again\n" << endl;
                    system("pause");
                }

            }
            screenCl(11);
        }
    }

public: void playSettings()
    {
        bool playPower = true;
        int p = 1;

        while (playPower == true)
        {
            screenCl(4);
            cout << "     PLAY SETTINGS\n";
            cout << " Levels\n";
            cout << " Tutorial\n";
            cout << " Back to the main meniu";

            refresh(p);

            switch (getch())
            {
            case KEY_UP:
                if (p == 1)
                {
                    p = 3;
                    break;
                }
                else
                {
                    p--;
                    break;
                }
            case KEY_DOWN:
                if (p == 3)
                {
                    p = 1;
                    break;
                }
                else
                {
                    p++;
                    break;
                }
            case SPACEBAR:
                switch (p)
                {
                case 1:
                    Levels();
                    break;
                case 2:
                    Tutorial();
                    break;
                case 3:
                    playPower = false;
                    break;
                }
            }
        }
    }
};


int main()
{
    system("cls");
    cout << "     Welcome to The game\n\n";
    cout << " Move '_' with arrow keys then\n";
    cout << " select something by pressing 'space'.\n";
    cout << "\n\n Have fun!\n ";
    system("pause");
    screenCl(8);

    bool power = true;
    int y = 1;

    while (power)
    {
        screenCl(4);
        cout << "     Meniu:\n";
        cout << " Play\n";
        cout << " Settings\n";
        cout << " Exit\n";

        refresh(y);

        switch (getch())
        {
        case KEY_UP:
            if (y == 1)
            {
                y = 3;
                break;
            }
            else
            {
                y--;
                break;
            }
        case KEY_DOWN:
            if (y == 3)
            {
                y = 1;
                break;
            }
            else
            {
                y++;
                break;
            }
        case SPACEBAR:
            switch (y)
            {
            case 1:
                playClass playobject;
                playobject.playSettings();
                break;
            case 2:
                settingsClass setobject;
                setobject.settings();
                break;
            case 3:
                power = false;
                break;
            }

        default:
            break;
            refresh(y);
        }
    }

    system ( "color 07" );
}


void refresh(int y)
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = y;
    SetConsoleCursorPosition(hOut, Position);
}

void refreshXY(int Y, int X)
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = X;
    Position.Y = Y;
    SetConsoleCursorPosition(hOut, Position);
}

void screenCl(int cl)
{
    refresh(0);
    for (int i = 0; i < cl; i++)
    {
        cout << "                                                            " << endl; //60 spaces
    }
    refresh(0);
}
