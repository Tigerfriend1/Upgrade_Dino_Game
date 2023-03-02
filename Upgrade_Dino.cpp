//Upgrade_Dino

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

//콘솔 창의 크기와 제목을 지정하는 함수
void SetGameScreen()
{
    system("mode con:cols=100 lines=25");
    system("title Upgrade_Dino");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

void DrawYouDied(const int score)
{
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    cout << "===========================";
    GotoXY(x, y + 1);
    cout << "======Y O U   D I E D======";
    GotoXY(x, y + 2);
    cout << "===========================";
    GotoXY(x, y + 5);
    cout << "SCORE : " << score;

    cout << "\n\n\n\n\n\n\n\n\n";
    system("pause");
}


class ChooseDino {
    //공룡을 그리는 함수
public:

    void DrawDino(int dinoY)
    {
        GotoXY(0, dinoY);
        static bool forefoot = true;
        cout << "        $$$$$$$ " << endl;
        cout << "       $$ $$$$$$" << endl;
        cout << "       $$$$$$$$$" << endl;
        cout << "$      $$$      " << endl;
        cout << "$$     $$$$$$$  " << endl;
        cout << "$$$   $$$$$     " << endl;
        cout << " $$  $$$$$$$$$$ " << endl;
        cout << " $$$$$$$$$$$    " << endl;
        cout << "  $$$$$$$$$$    " << endl;
        cout << "    $$$$$$$$    " << endl;
        cout << "     $$$$$$     " << endl;
        if (forefoot)
        {
            cout << "     $    $$$    " << endl;
            cout << "     $$          ";
            forefoot = false;
        }
        else
        {
            printf("     $$$  $     \n");
            printf("          $$    ");
            forefoot = true;
        }

    }

    //나무를 그리는 함수
    void DrawTree(int treeX)
    {
        GotoXY(treeX, TREE_ROOT_Y);
        cout << "$$$$";
        GotoXY(treeX, TREE_ROOT_Y + 1);
        cout << " $$ ";
        GotoXY(treeX, TREE_ROOT_Y + 2);
        cout << " $$ ";
        GotoXY(treeX, TREE_ROOT_Y + 3);
        cout << " $$ ";
        GotoXY(treeX, TREE_ROOT_Y + 4);
        cout << " $$ ";

    }

    void DrawRock(int rockX)
    {
        GotoXY(rockX, ROCK_ROOT_Y);
        cout << "   $$";
        GotoXY(rockX, ROCK_ROOT_Y + 1);
        cout << "  $$$$$ ";
        GotoXY(rockX, ROCK_ROOT_Y + 2);
        cout << " $$$$$$$ ";
        GotoXY(rockX, ROCK_ROOT_Y + 3);
        cout << "  $$$$$ ";
        GotoXY(rockX, ROCK_ROOT_Y + 4);
        cout << "   $$ ";
    }

    // 충돌 했을 때 게임 끝

    bool isCrush_High(const int treeX, const int rockX, const int dinoY)
    {
        //트리의 X가 공룡의 몸체쪽에 있을때,
        //공룡의 높이가 충분하지 않다면 충돌로 처리
        GotoXY(0, 0);


        cout << "treeX : " << treeX << "dinoY : " << dinoY << endl; //충돌 판정의 근거를 표시해줌
        if (treeX <= 8 && treeX >= 4 &&
            dinoY > 8)
        {
            return true;
        }

        if (rockX <= 7 && rockX >= 4 &&
            dinoY > 7)
        {
            return true;
        }
        return false;
    }


};

class ChooseSonic {
    //소닉을 그리는 함수
public:

    void DrawSonic(int sonicY, bool ball)
    {
        GotoXY(0, sonicY);
        if (!ball) {
            cout << " ######       " << endl;
            cout << "   #######    " << endl;
            cout << " #######  ##  " << endl;
            cout << "    ######### " << endl;
            cout << " ##########   " << endl;
            cout << "     ######   " << endl;
            cout << "    ##   ##   " << endl;
            cout << "    ##   ##   " << endl;
        }
        else {
            cout << "    #######   " << endl;
            cout << "  ##########  " << endl;
            cout << " ############ " << endl;
            cout << "   #########  " << endl;
            cout << "     ####     " << endl;

        }
    }

    void DrawTrap(int trapX)
    {
        GotoXY(trapX, TRAP_ROOT_Y);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 1);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 2);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 3);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 4);
        cout << "##";
        GotoXY(trapX, TRAP_ROOT_Y + 5);
        cout << "##";
    }

    void DrawRing(int ringX) {
        GotoXY(ringX, RING_ROOT_Y);
        cout << "  ##  ";
        GotoXY(ringX, RING_ROOT_Y + 1);
        cout << " #  # ";
        GotoXY(ringX, RING_ROOT_Y + 2);
        cout << "  ##  ";

    }

    bool isCrush_High(const int trapX, const int sonicY)
    {
        GotoXY(0, 0);

        cout << "trapX : " << trapX << "sonicY : " << sonicY << endl;
        if (trapX <= 4 && trapX >= 2 &&
            sonicY > 7)
        {
            return true;
        }
        return false;
    }

    bool ringCrush(const int ringX, const int sonicY)
    {
        GotoXY(0, 0);

        cout << "ringX : " << ringX << "sonicY : " << sonicY << endl;
        if (ringX <= 2 && ringX >= 0 &&
            sonicY > 1)
        {
            return true;
        }
        return false;
    }
};



class ChooseMario {
public:
    void DrawMario(int marioY)
    {
        GotoXY(0, marioY);
        static bool leftArm = true;
        cout << "       %%%%%%      " << endl;
        cout << "     %%%%%%%%      " << endl;
        cout << "    %% %%% %%%%%   " << endl;
        cout << "    %% % % %%%     " << endl;
        cout << "   %%% %%% %%%%%   " << endl;
        cout << "   %%%%%%%%%%%%%%  " << endl;

        if (leftArm)
        {
            cout << "    %%%%   %%%%  %%" << endl;
            cout << "   %%%%%%%%%%%%%%  " << endl;
            cout << " %% %%%%%%%%%%%    " << endl;
            cout << "%%  %%%%%%%%%%%    " << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "            %%%    " << endl;
            leftArm = false;
        }
        else
        {
            cout << "%%  %%%%   %%%%    " << endl;
            cout << "  %%%%%%%%%%%%%%%  " << endl;
            cout << "    %%%%%%%%%%%  %%" << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "    %%%            " << endl;
            leftArm = true;
        }


    }

    //버섯을 그리는 함수
    void DrawMushroom(int mushroomX)
    {
        GotoXY(mushroomX, MUSHROOM_ROOT_Y);
        cout << "   %%%%%%   ";
        GotoXY(mushroomX, MUSHROOM_ROOT_Y + 1);
        cout << "  %%%%%%%%  ";
        GotoXY(mushroomX, MUSHROOM_ROOT_Y + 2);
        cout << " %%%%%%%%%% ";
        GotoXY(mushroomX, MUSHROOM_ROOT_Y + 3);
        cout << "   %%%%%%   ";
        GotoXY(mushroomX, MUSHROOM_ROOT_Y + 4);
        cout << "    %%%%    ";

    }

    void DrawBar(int barX)
    {
        GotoXY(barX, BAR_Y);
        cout << "================";
        GotoXY(barX, BAR_Y + 1);
        cout << "================";
    }

    bool isCrush_High(const int mushroomX, const int barX, const int marioY)
    {
        
        GotoXY(0, 0);


        cout << "mushroomX : " << mushroomX << "marioY : " << marioY << "barX : " << barX << endl;
        //이런식으로 적절한 X, Y를 찾습니다.
        if (mushroomX <= 6 && mushroomX >= 4 &&
            marioY > 7)
        {
            return true;
        }
        if (barX <= 6 && barX >= 1 && marioY < 5) {
            return true;
        }
        return false;
    }
};




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

int main() {
    SetGameScreen();


    while (true)        //게임 루프
    {
        //게임 시작시 초기화
        bool isJumping = false;
        bool isRoot = true;
        const int gravity = 3;

        int dinoY = DINO_ROOT_Y;
        int sonicY = SONIC_ROOT_Y;
        int marioY = MARIO_ROOT_Y;
        int mushroomX = MUSHROOM_ROOT_X;
        int treeX = TREE_ROOT_X;
        int rockX = ROCK_ROOT_X;
        int ringX = RING_ROOT_X;
        int trapX = TRAP_ROOT_X;
        int mushroomY = MUSHROOM_ROOT_Y;
        int barX = BAR_X;
        int barY = BAR_Y;

        int score = 0;
        clock_t start, curr;    //점수 변수 초기화
        start = clock();        //시작시간 초기화

        int input_key;
        Selectcharacter();
        input_key = _getch();  //_getch함수는 cin과 달리 입력과 동시에 적용된다.
        switch (input_key) {
        case 49:  // ASCII 코드로 49는 1로 인식한다.
            ChooseDino A;
            while (true)    //한 판에 대한 루프
            {
                // 충돌체크 트리의 x값과 공룡의 y값으로 판단
                if (A.isCrush_High(treeX, rockX, dinoY))
                    break;

                //z키가 눌렸고, 바닥이 아닐때 점프
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                }

                //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
                if (isJumping)
                {
                    dinoY -= gravity;
                }
                else
                {
                    dinoY += gravity;
                }

                //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
                if (dinoY >= DINO_ROOT_Y)
                {
                    dinoY = DINO_ROOT_Y;
                    isRoot = true;
                }

                //나무가 왼쪽으로 (x음수) 가도록하고
                //나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
                treeX -= 2;
                if (treeX <= 0)
                {
                    treeX = TREE_ROOT_X;
                }

                rockX -= 3;
                if (rockX <= 0)
                {
                    rockX = ROCK_ROOT_X;
                }

                //점프의 맨위를 찍으면 점프가 끝난 상황.
                if (dinoY <= 3)
                {
                    isJumping = false;
                }

                A.DrawDino(dinoY);        //draw dino
                A.DrawTree(treeX);        //draw Tree
                A.DrawRock(rockX);

                //(v2.0)
                curr = clock();            //현재시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을떄
                {
                    score++;    //스코어 UP
                    start = clock();    //시작시간 초기화
                }
                Sleep(60);
                system("cls");    //clear

            //점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줌
                GotoXY(22, 0);    //커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
                cout << "Score : " << score << endl;   //점수 출력해줌.
            }
            break;
        case 50: // ASCII코드로 50은 2를 의미
            ChooseSonic B;
            while (true)    //한 판에 대한 루프
            {
                bool jump_check = false;
                //충돌체크 트랩의 x값과 소닉의 y값으로 판단
                if (B.isCrush_High(trapX, sonicY))
                    break;

                if (B.ringCrush(ringX, sonicY))
                {
                    score = score + 10;
                }

                //z키가 눌렸고, 바닥이 아닐때 점프
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                    jump_check = true;
                }

                //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
                if (isJumping)
                {
                    sonicY -= gravity;
                }
                else
                {
                    sonicY += gravity;
                }

                //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
                if (sonicY >= SONIC_ROOT_Y)
                {
                    sonicY = SONIC_ROOT_Y;
                    isRoot = true;
                }

                //트랩이 왼쪽으로 (x음수) 가도록하고
                //트랩의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
                trapX -= 2;
                if (trapX <= 0)
                {
                    trapX = TRAP_ROOT_X;
                }

                ringX -= 1;
                if (ringX <= 0)
                {
                    ringX = RING_ROOT_X;
                }


                //점프의 맨위를 찍으면 점프가 끝난 상황.
                if (sonicY <= 3)
                {
                    isJumping = false;
                }

                B.DrawSonic(sonicY, jump_check);        //draw Sonic
                B.DrawTrap(trapX);
                B.DrawRing(ringX);

                
                curr = clock();            //현재시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을떄
                {
                    score++;    //스코어 UP
                    start = clock();    //시작시간 초기화
                }
                Sleep(60);
                system("cls");    //clear

            //점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줌
                GotoXY(22, 0);    //커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
                cout << "Score : " << score << endl;    //점수 출력해줌.
            }
            break;
        case 51: // ASCII코드로 51은 3을 의미
            ChooseMario C;
            while (true)    //한 판에 대한 루프
            {
                //충돌체크 버섯의 x값,바의 x값과 마리오의 y값으로 판단
                if (C.isCrush_High(mushroomX, barX, marioY))
                    break;


                /*if (C.isCollision_High(barX, marioY)) {
                    break;
                }*/



                //z키가 눌렸고, 바닥이 아닐때 점프
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                }

                //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
                if (isJumping)
                {
                    marioY -= gravity;
                }
                else
                {
                    marioY += gravity;

                }

                //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
                if (marioY >= MARIO_ROOT_Y)
                {
                    marioY = MARIO_ROOT_Y;
                    isRoot = true;
                }

                //버섯이 왼쪽으로 (x음수) 가도록하고
                //버섯의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
                mushroomX -= 3;
                if (mushroomX <= 0)
                {
                    mushroomX = MUSHROOM_ROOT_X;
                }

                if (barX < 20) // bar가 일정 거리이상 가까워지면 속도가 빨라지게 함.
                    barX -= 4;
                else
                    barX -= 2;
                if (barX <= 0)
                {
                    barX = BAR_X;
                }




                //점프의 맨위를 찍으면 점프가 끝난 상황.
                if (marioY <= 3)
                {
                    isJumping = false;
                }

                C.DrawMario(marioY);        //draw mario
                C.DrawMushroom(mushroomX);
                C.DrawBar(barX);

                //(v2.0)
                curr = clock();            //현재시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을떄
                {
                    score++;    //스코어 UP
                    start = clock();    //시작시간 초기화
                }
                Sleep(60);
                system("cls");    //clear

            //점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줌
                GotoXY(22, 0);    //커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
                cout << "Score : " << score << endl;      //점수 출력해줌.
            }
            break;
        }
        //게임 오버 메뉴
        DrawYouDied(score);
    }
    return 0;
}