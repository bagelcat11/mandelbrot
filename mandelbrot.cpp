#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

struct MandelPoint
{
    double realX;
    double imY;
    // complex<double> mycomplex(0.0, 0.0);
    bool inSet;
};

const int X_WIDTH = 1600;
const int Y_HEIGHT = 1600;                            
const int ITERS = 32;
// MandelPoint topLeft = {-2, 2, false};
// MandelPoint bottomRight = {2, -2, false};

void updatePlot(MandelPoint [X_WIDTH][Y_HEIGHT]);
void printPlot(const MandelPoint [X_WIDTH][Y_HEIGHT]);
void createFile(/*const MandelPoint [X_WIDTH][Y_HEIGHT]*/);

int main()
{
    // MandelPoint *mandelPtr = nullptr;
    // mandelPtr = new MandelPoint[X_WIDTH][Y_HEIGHT];

    // MandelPoint mandelPlot[X_WIDTH][Y_HEIGHT];
    // for (int row = 0; row < X_WIDTH; row++)
    // {
    //     for (int col = 0; col < Y_HEIGHT; col++)
    //     {
    //         mandelPlot[row][col].inSet = false;
    //     }
    // }

    // updatePlot(mandelPlot);
    // printPlot(mandelPlot);

    // mandelPlot[1][2].inSet = true;
    createFile(/*mandelPlot*/);

    // Plotdata x(-1.0, 1.0), y = sin(x);
    // plot(x, y);

    return 0;
}

/****************************************************************************/

void updatePlot(MandelPoint mandelPlot[X_WIDTH][Y_HEIGHT])
{
    double realZ, imZ, realC, imC;
    double scaledX, scaledY;
    
    for (int row = 0; row < X_WIDTH; row++)
    {
        for (int col = 0; col < Y_HEIGHT; col++)
        {
            //TODO: ourgh
        }
    }
}

/****************************************************************************/

void printPlot(const MandelPoint mandelPlot[X_WIDTH][Y_HEIGHT])
{
    for (int row = 0; row < X_WIDTH; row++)
    {
        for (int col = 0; col < Y_HEIGHT; col++)
        {
            if (mandelPlot[row][col].inSet)
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

/****************************************************************************/

void createFile(/*const MandelPoint mandelPlot[X_WIDTH][Y_HEIGHT]*/)
{
    ofstream output("mandelPlot.dat");

    complex<double> topLeft(-2, 2);
    complex<double> bottomRight(2, -2);
    complex<double> c;
    complex<double> z;
    bool inSet;

    output << "#    real(X)     imag(Y)" << endl;
    // for (int row = 0; row < X_WIDTH; row++)
    // {
    //     for (int col = 0; col < Y_HEIGHT; col++)
    //     {
    //         if (mandelPlot[row][col].inSet)
    //             output << mandelPlot[row][col].realX << " " << mandelPlot[row][col].imY << endl;
    //     }
    // }
    //TODO: what format to feed to gnuplot?? do I even need c++

    for (double x = topLeft.real(); x < bottomRight.real(); x += ((bottomRight.real() - topLeft.real()) / X_WIDTH))
    {
        for (double y = topLeft.imag(); y > bottomRight.imag(); y -= ((topLeft.imag() - bottomRight.imag()) / Y_HEIGHT))
        {
            c.real(x);
            c.imag(y);
            z = 0;
            inSet = true;

            for (int i = 1; i <= ITERS; i++)
            {
                z = (z * z) + c;
                if (abs(z) > 2)
                    inSet = false;
            }

            if (inSet)
                output << c.real() << " " << c.imag() << endl;
        }
    }

    output.close();
}