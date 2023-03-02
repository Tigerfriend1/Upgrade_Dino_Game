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

//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetGameScreen()
{
    system("mode con:cols=100 lines=25");
    system("title Upgrade_Dino");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
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
    //������ �׸��� �Լ�
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

    //������ �׸��� �Լ�
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

    // �浹 ���� �� ���� ��

    bool isCrush_High(const int treeX, const int rockX, const int dinoY)
    {
        //Ʈ���� X�� ������ ��ü�ʿ� ������,
        //������ ���̰� ������� �ʴٸ� �浹�� ó��
        GotoXY(0, 0);


        cout << "treeX : " << treeX << "dinoY : " << dinoY << endl; //�浹 ������ �ٰŸ� ǥ������
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
    //�Ҵ��� �׸��� �Լ�
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

    //������ �׸��� �Լ�
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
        //�̷������� ������ X, Y�� ã���ϴ�.
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


    while (true)        //���� ����
    {
        //���� ���۽� �ʱ�ȭ
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
        clock_t start, curr;    //���� ���� �ʱ�ȭ
        start = clock();        //���۽ð� �ʱ�ȭ

        int input_key;
        Selectcharacter();
        input_key = _getch();  //_getch�Լ��� cin�� �޸� �Է°� ���ÿ� ����ȴ�.
        switch (input_key) {
        case 49:  // ASCII �ڵ�� 49�� 1�� �ν��Ѵ�.
            ChooseDino A;
            while (true)    //�� �ǿ� ���� ����
            {
                // �浹üũ Ʈ���� x���� ������ y������ �Ǵ�
                if (A.isCrush_High(treeX, rockX, dinoY))
                    break;

                //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                }

                //�������̶�� Y�� ����, ������ �������� Y�� ����.
                if (isJumping)
                {
                    dinoY -= gravity;
                }
                else
                {
                    dinoY += gravity;
                }

                //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
                if (dinoY >= DINO_ROOT_Y)
                {
                    dinoY = DINO_ROOT_Y;
                    isRoot = true;
                }

                //������ �������� (x����) �������ϰ�
                //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
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

                //������ ������ ������ ������ ���� ��Ȳ.
                if (dinoY <= 3)
                {
                    isJumping = false;
                }

                A.DrawDino(dinoY);        //draw dino
                A.DrawTree(treeX);        //draw Tree
                A.DrawRock(rockX);

                //(v2.0)
                curr = clock();            //����ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
                {
                    score++;    //���ھ� UP
                    start = clock();    //���۽ð� �ʱ�ȭ
                }
                Sleep(60);
                system("cls");    //clear

            //��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ����
                GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
                cout << "Score : " << score << endl;   //���� �������.
            }
            break;
        case 50: // ASCII�ڵ�� 50�� 2�� �ǹ�
            ChooseSonic B;
            while (true)    //�� �ǿ� ���� ����
            {
                bool jump_check = false;
                //�浹üũ Ʈ���� x���� �Ҵ��� y������ �Ǵ�
                if (B.isCrush_High(trapX, sonicY))
                    break;

                if (B.ringCrush(ringX, sonicY))
                {
                    score = score + 10;
                }

                //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                    jump_check = true;
                }

                //�������̶�� Y�� ����, ������ �������� Y�� ����.
                if (isJumping)
                {
                    sonicY -= gravity;
                }
                else
                {
                    sonicY += gravity;
                }

                //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
                if (sonicY >= SONIC_ROOT_Y)
                {
                    sonicY = SONIC_ROOT_Y;
                    isRoot = true;
                }

                //Ʈ���� �������� (x����) �������ϰ�
                //Ʈ���� ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
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


                //������ ������ ������ ������ ���� ��Ȳ.
                if (sonicY <= 3)
                {
                    isJumping = false;
                }

                B.DrawSonic(sonicY, jump_check);        //draw Sonic
                B.DrawTrap(trapX);
                B.DrawRing(ringX);

                
                curr = clock();            //����ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
                {
                    score++;    //���ھ� UP
                    start = clock();    //���۽ð� �ʱ�ȭ
                }
                Sleep(60);
                system("cls");    //clear

            //��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ����
                GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
                cout << "Score : " << score << endl;    //���� �������.
            }
            break;
        case 51: // ASCII�ڵ�� 51�� 3�� �ǹ�
            ChooseMario C;
            while (true)    //�� �ǿ� ���� ����
            {
                //�浹üũ ������ x��,���� x���� �������� y������ �Ǵ�
                if (C.isCrush_High(mushroomX, barX, marioY))
                    break;


                /*if (C.isCollision_High(barX, marioY)) {
                    break;
                }*/



                //zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                }

                //�������̶�� Y�� ����, ������ �������� Y�� ����.
                if (isJumping)
                {
                    marioY -= gravity;
                }
                else
                {
                    marioY += gravity;

                }

                //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
                if (marioY >= MARIO_ROOT_Y)
                {
                    marioY = MARIO_ROOT_Y;
                    isRoot = true;
                }

                //������ �������� (x����) �������ϰ�
                //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
                mushroomX -= 3;
                if (mushroomX <= 0)
                {
                    mushroomX = MUSHROOM_ROOT_X;
                }

                if (barX < 20) // bar�� ���� �Ÿ��̻� ��������� �ӵ��� �������� ��.
                    barX -= 4;
                else
                    barX -= 2;
                if (barX <= 0)
                {
                    barX = BAR_X;
                }




                //������ ������ ������ ������ ���� ��Ȳ.
                if (marioY <= 3)
                {
                    isJumping = false;
                }

                C.DrawMario(marioY);        //draw mario
                C.DrawMushroom(mushroomX);
                C.DrawBar(barX);

                //(v2.0)
                curr = clock();            //����ð� �޾ƿ���
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����
                {
                    score++;    //���ھ� UP
                    start = clock();    //���۽ð� �ʱ�ȭ
                }
                Sleep(60);
                system("cls");    //clear

            //��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ++ ����
                GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
                cout << "Score : " << score << endl;      //���� �������.
            }
            break;
        }
        //���� ���� �޴�
        DrawYouDied(score);
    }
    return 0;
}