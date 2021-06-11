#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <iostream>

#define DINO_ROOT_Y 12
#define TREE_ROOT_Y 20
#define TREE_ROOT_X 45
#define ROCK_ROOT_X 45
#define ROCK_ROOT_Y 20

#define SONIC_ROOT_Y 16
#define TRAP_ROOT_Y 17
#define TRAP_ROOT_X 45
#define RING_ROOT_X 45
#define RING_ROOT_Y 5

#define MARIO_ROOT_Y 16
#define MUSHROOM_ROOT_X 45
#define MUSHROOM_ROOT_Y 19
#define BAR_X 45
#define BAR_Y 4

using namespace std;


void Selectcharacter()
{
    system("cls");
    int x = 15;
    int y = 3;
    GotoXY(x + 8, y);
    cout << "choose character";
    GotoXY(x - 3, y + 2);
    cout << "================================================================" << endl;
    cout << "                                                                       %%%%%%%         " << endl;
    cout << "                                     $$$$$$$                          %  %  %%       " << endl;
    cout << "                                    $$ $$$$$$                        %% % % %%%%%    " << endl;
    cout << "                                    $$$$$$$$$                        %%%%%%%%%%      " << endl;
    cout << "                             $      $$$          ######             %%%%%%%%%%%%%    " << endl;
    cout << "                             $$     $$$$$$$        #######          %%%%%%%%%%%%%%   " << endl;
    cout << "                             $$$   $$$$$         #######  ##         %%%%   %%%%  %% " << endl;
    cout << "                              $$  $$$$$$$$$$        #########       %%%%%%%%%%%%%%   " << endl;
    cout << "                              $$$$$$$$$$$        ##########       %% %%%%%%%%%%%     " << endl;
    cout << "                               $$$$$$$$$$            ######      %%  %%%%%%%%%%%     " << endl;
    cout << "                                 $$$$$$$$           ##   ##          %%%%%%%%%%%     " << endl;
    cout << "                                  $$$$$$            ##   ##          %%%     %%%     " << endl;
    cout << "                                                                                     " << endl;
    cout << "                            1. Dino : easy      2. Sonic : nomal    3. Mario! : HARD!    " << endl;
    GotoXY(x - 3, y + 17);
    cout << "=================================================================";
    GotoXY(x, y + 5);

}
