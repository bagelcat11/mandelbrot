#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

const int X_WIDTH = 4096;
const int Y_HEIGHT = 4096;
// const int ITERS = 64;    // 64 for zoomed out
const int ITERS = 128;      // 128 for zoomed in

void createFile();
void createBurningShipFile();

int main()
{
    // createFile();
    createBurningShipFile();

    return 0;
}

/****************************************************************************/

void createFile()
{
    ofstream output("mandelPlot.dat");

    // MAIN
    // complex<double> topLeft(-2, 1.2);
    // complex<double> bottomRight(0.55, -1.2);

    // 5-BULB
    // complex<double> topLeft(-0.66, 0.7);
    // complex<double> bottomRight(-0.4, 0.45);

    // 5-BULB ZOOM
    // complex<double> topLeft(-0.604, 0.668);
    // complex<double> bottomRight(-0.592, 0.658);

    // SEAHORSE VALLEY
    complex<double> topLeft(-0.8, 0.17);
    complex<double> bottomRight(-0.76, 0.13);

    // ELEPHANT VALLEY
    // complex<double> topLeft(0.35, 0.115);
    // complex<double> bottomRight(0.39, 0.075);

    // ANTENNA SATELLITE (really crunchy quality for some reason?)
    // complex<double> topLeft(-1.79, 0.03);
    // complex<double> bottomRight(-0.74, -0.03);

    complex<double> c;
    complex<double> z;
    bool inSet;
    int currentIter;

    output << "#    real(X)     imag(Y)     iters" << endl;

    for (double x = topLeft.real(); x < bottomRight.real(); x += ((bottomRight.real() - topLeft.real()) / X_WIDTH))
    {
        for (double y = topLeft.imag(); y > bottomRight.imag(); y -= ((topLeft.imag() - bottomRight.imag()) / Y_HEIGHT))
        {
            c.real(x);
            c.imag(y);
            z = 0;
            inSet = true;
            currentIter = 1;

            while (inSet && currentIter <= ITERS)
            {
                z = (z * z) + c;
                if (abs(z) > 2)
                    inSet = false;

                currentIter++;
            }

            output << c.real() << " " << c.imag() << " " << currentIter << endl;
        }
    }

    output.close();
}

/****************************************************************************/

void createBurningShipFile()
{
    ofstream output("shipPlot.dat");
    // CALCULATE NORMALLY, THEN REVERSE IN OUTPUT & GNUPLOT

    // MAIN SHIP (top 1/3 cut off for some reason?)
    // complex<double> topLeft(-1.95, 0.75);
    // complex<double> bottomRight(0.7, -1.6); // The y-coords will be swapped in Gnuplot

    // 2ND SHIP
    complex<double> topLeft(-1.8, 0.015);
    complex<double> bottomRight(-1.7, -0.09);

    complex<double> c;
    complex<double> z;
    bool inSet;
    int currentIter;
    int computations = 0;

    output << "#    real(X)     imag(Y)     iters" << endl;

    for (double x = topLeft.real(); x < bottomRight.real(); x += ((bottomRight.real() - topLeft.real()) / X_WIDTH))
    {
        for (double y = topLeft.imag(); y > bottomRight.imag(); y -= ((topLeft.imag() - bottomRight.imag()) / Y_HEIGHT))
        {
            c.real(x);
            c.imag(y);
            z = 0;
            inSet = true;
            currentIter = 1;

            while (inSet && currentIter <= ITERS)
            {
                z.real(abs(z.real()));
                z.imag(abs(z.imag()));
                z = (z * z) + c;

                if (abs(z) > 2)
                    inSet = false;

                currentIter++;
                computations++;
            }

            // Make imaginary output negative to flip fractal for aesthetic purposes
            output << c.real() << " " << -c.imag() << " " << currentIter << endl;
        }
    }

    output.close();
    cout << computations << " computations complete." << endl;
}