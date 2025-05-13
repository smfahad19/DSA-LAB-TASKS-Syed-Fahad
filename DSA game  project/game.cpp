#include<iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int value;
    Node *up;
    Node *down;
    Node *left;
    Node *right;

    Node()
    {
        value = 0;
        up = down = left = right = NULL;
    }
};

class Board
{
public:
    Node *grid[4][4];
    Board()
    {
        createBoard();
    }

    void createBoard()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                grid[i][j] = new Node();
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i > 0)
                {
                    grid[i][j]->up = grid[i - 1][j];
                }
                if (i < 3)
                {
                    grid[i][j]->down = grid[i + 1][j];
                }
                if (j > 0)
                {
                    grid[i][j]->left = grid[i][j - 1];
                }
                if (j < 3)
                {
                    grid[i][j]->right = grid[i][j + 1];
                }
            }
        }
    }

    void showBoard()
    {
        cout << "\n";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j]->value == 0)
                    cout << ".\t";
                else{
                   
                    cout << grid[i][j]->value << "\t";
                }
            }
            cout << "\n";
        }
    }

    void insertTileAtEmpty()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j]->value == 0)
                {
                    grid[i][j]->value = 2;
                    return;
                }
            }
        }
    }
};

class Game
{
public:
    Board board;
    int score;

    Game()
    {
        score = 0;
        board.insertTileAtEmpty();
        board.insertTileAtEmpty();
    }

    void play()
    {
        char move;
        while (true)
        {
            board.showBoard();
            cout << "Score: " << score << "\n";
            cout << "Enter move (w/a/s/d): ";
            cin >> move;
            system("cls");
            switch (move)
            {
            case 'a':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            case 'w':
                moveUp();
                break;
            case 's':
                moveDown();
                break;
            default:
                continue;
            }
            board.insertTileAtEmpty();
        }
    }

    void moveLeft()
    {
        for (int i = 0; i < 4; i++)
        {
            int temp[4] = {0}, idx = 0;
            for (int j = 0; j < 4; j++)
            {
                if (board.grid[i][j]->value != 0)
                {
                    temp[idx++] = board.grid[i][j]->value;
                }
            }
            for (int j = 0; j < 3; j++)
            {
                if (temp[j] != 0 && temp[j] == temp[j + 1])
                {
                    temp[j] *= 2;
                    score += temp[j];
                    temp[j + 1] = 0;
                }
            }
            int newLine[4] = {0}, newIdx = 0;
            for (int j = 0; j < 4; j++)
            {
                if (temp[j] != 0)
                {
                    newLine[newIdx++] = temp[j];
                }
            }
            for (int j = 0; j < 4; j++)
            {
                board.grid[i][j]->value = newLine[j];
            }
        }
    }

    void moveRight()
    {
        for (int i = 0; i < 4; i++)
        {
            int temp[4] = {0}, idx = 3;
            for (int j = 3; j >= 0; j--)
            {
                if (board.grid[i][j]->value != 0)
                {
                    temp[idx--] = board.grid[i][j]->value;
                }
            }
            for (int j = 3; j > 0; j--)
            {
                if (temp[j] != 0 && temp[j] == temp[j - 1])
                {
                    temp[j] *= 2;
                    score += temp[j];
                    temp[j - 1] = 0;
                }
            }
            int newLine[4] = {0}, newIdx = 3;
            for (int j = 3; j >= 0; j--)
            {
                if (temp[j] != 0)
                {
                    newLine[newIdx--] = temp[j];
                }
            }
            for (int j = 0; j < 4; j++)
            {
                board.grid[i][j]->value = newLine[j];
            }
        }
    }

    void moveUp()
    {
        for (int j = 0; j < 4; j++)
        {
            int temp[4] = {0}, idx = 0;
            for (int i = 0; i < 4; i++)
            {
                if (board.grid[i][j]->value != 0)
                {
                    temp[idx++] = board.grid[i][j]->value;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                if (temp[i] != 0 && temp[i] == temp[i + 1])
                {
                    temp[i] *= 2;
                    score += temp[i];
                    temp[i + 1] = 0;
                }
            }
            int newCol[4] = {0}, newIdx = 0;
            for (int i = 0; i < 4; i++)
            {
                if (temp[i] != 0)
                {
                    newCol[newIdx++] = temp[i];
                }
            }
            for (int i = 0; i < 4; i++)
            {
                board.grid[i][j]->value = newCol[i];
            }
        }
    }

    void moveDown()
    {
        for (int j = 0; j < 4; j++)
        {
            int temp[4] = {0}, idx = 3;
            for (int i = 3; i >= 0; i--)
            {
                if (board.grid[i][j]->value != 0)
                {
                    temp[idx--] = board.grid[i][j]->value;
                }
            }
            for (int i = 3; i > 0; i--)
            {
                if (temp[i] != 0 && temp[i] == temp[i - 1])
                {
                    temp[i] *= 2;
                    score += temp[i];
                    temp[i - 1] = 0;
                }
            }
            int newCol[4] = {0}, newIdx = 3;
            for (int i = 3; i >= 0; i--)
            {
                if (temp[i] != 0)
                {
                    newCol[newIdx--] = temp[i];
                }
            }
            for (int i = 0; i < 4; i++)
            {
                board.grid[i][j]->value = newCol[i];
            }
        }
    }
};

int main()
{
    Game g;
    g.play();
    return 0;
}