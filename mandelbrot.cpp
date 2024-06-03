#include <iostream>

const int X_WIDTH = 32;
const int Y_HEIGHT = 32;

using namespace std;

void updatePlot(bool [X_WIDTH][Y_HEIGHT]);
void printPlot(const bool [X_WIDTH][Y_HEIGHT]);


int main()
{
    bool plot[X_WIDTH][Y_HEIGHT];
    for (int row = 0; row < X_WIDTH; row++)
    {
        for (int col = 0; col < Y_HEIGHT; col++)
        {
            plot[row][col] = false;
        }
    }

    printPlot(plot);

    return 0;
}

/****************************************************************************/

void printPlot(const bool plot[X_WIDTH][Y_HEIGHT])
{
    for (int row = 0; row < X_WIDTH; row++)
    {
        for (int col = 0; col < Y_HEIGHT; col++)
        {
            if (plot[row][col])
                // in set
                cout << "▓▓";
            else
                // outside set
                cout << "░░";
        }
        cout << endl;
    }
    cout << endl;
}