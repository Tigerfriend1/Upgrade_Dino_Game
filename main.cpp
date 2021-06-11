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
        }
        //���� ���� �޴�
        DrawYouDied(score);
    }
    return 0;
}