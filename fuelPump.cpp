#include <iostream>
#include <cstdlib>
using namespace std;
class fueltank
{
    int level;

public:
    fueltank()
    {

        level = rand() % 101;
    }
    int getFuelLevel()
    {
        return level;
    }
};

class fuelrobot
{
    int position;
    int dir;

public:
    fuelrobot()
    {

        position = rand() % 10;
        int k = rand() % 2;
        if (k == 0)
            dir = 'l';
        else
            dir = 'r';
    }

public:
    int getCurrentIndex()
    {
        return position;
    }
    int isFacingRight()
    {
        if (dir == 'r')
            return 1;
        else
            return 0;
    }
    void changeDirection()
    {
        if (dir == 'l')
            dir = 'r';
        else
            dir = 'l';
    }
    void moveForward(int pos)
    {

        if (dir == 'r')
            position = position + pos;
        else
            position = position - pos;
    }
};
class fueldepot
{

    fueltank tanks[10];
    fuelrobot filler;

public:
    fueldepot() {}
    void output()
    {
        cout << "\nrobot position   " << filler.getCurrentIndex();
        cout << "\n fuel level";
        for (int i = 0; i < 10; i++)
        {
            cout << tanks[i].getFuelLevel() << "  ";
        }
    }
    int nextTankToFill(int threshold)
    {
        int m = 0;
        int min = 101;
        for (int i = 0; i < 10; i++)
        {
            if (tanks[i].getFuelLevel() < min)
            {
                min = tanks[i].getFuelLevel();
                m = i;
            }
        }
        // cout<<"\n"<<min;
        if (min > threshold)
        {

            return filler.getCurrentIndex();
        }
        else
            return m;
    }
    void moveToLoc(int loc)
    {
        int x;
        if (filler.getCurrentIndex() > loc)
        {
            x = filler.getCurrentIndex() - loc;
        }
        else
        {
            x = loc - filler.getCurrentIndex();
        }

        if (loc > filler.getCurrentIndex() && filler.isFacingRight() == 1)
        {

            filler.moveForward(x);
        }
        else if (loc < filler.getCurrentIndex() && filler.isFacingRight() == 1)
        {
            filler.changeDirection();
            filler.moveForward(x);
        }
        else if (loc < filler.getCurrentIndex() && filler.isFacingRight() == 0)
        {
            filler.moveForward(x);
        }
        else if (loc > filler.getCurrentIndex() && filler.isFacingRight() == 0)
        {
            filler.changeDirection();
            filler.moveForward(x);
        }
        cout<<"\n"<<filler.getCurrentIndex()<<"    ";
    }
};

int main()
{
    fueldepot f;
    f.output();
    cout << "\n";
    f.moveToLoc(2);
    cout << f.nextTankToFill(40);
}
