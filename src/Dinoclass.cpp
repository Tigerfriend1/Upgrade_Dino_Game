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

