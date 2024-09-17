#include <iostream>


typedef struct {
    float x;
    float y;
} tDataPoint;

const int fsr_nPoints = 9;

tDataPoint fsr[fsr_nPoints] = {
    {10 , 900},
    {20 , 700},
    {30 , 500},
    {40 , 410},
    {50 , 350},
    {60 , 320},
    {70 , 300},
    {80 , 280},
    {90 , 250}
};

float interpola(tDataPoint t[], int n, float x);
float ordinata(float x1, float y1, float x2, float y2, float x);

using namespace std;

int main()
{
    // punto fuori a sinistra
    float xl = 5;
    float yl;
    yl = interpola(fsr, fsr_nPoints, xl);

    cout << "ascissa x = " << xl << "  ordinata y = " << yl << endl;

    // punto fuori a destra
    float xr = 105;
    float yr;
    yr = interpola(fsr, fsr_nPoints, xr);

    cout << "ascissa x = " << xr << "  ordinata y = " << yr << endl;

    // punto nel primo intervallo
    float xp = 15;
    float yp;
    yp = interpola(fsr, fsr_nPoints, xp);

    cout << "ascissa x = " << xp << "  ordinata y = " << yp << endl;
}


//-----------------

// dati i due estremi del segmento, trova l'ordinata y del punto con ascissa x
float ordinata(float x1, float y1, float x2, float y2, float x)
{
    float y;
    // test per evitare divisione per 0
    if (x1 == x2)
    {
        return 0.0;
    }

    // calcola la pendenza
    float m = (y2 - y1) / (x2 - x1);

    // e l'ordinata del punto intermedio
    y = y1 + m * (x - x1);

    return y;
}

// dato l'array t di tipo tDataPoint con n punti della poligonale 2D
// e data l'ascissa x del punto, restituisce l'ordinata y corrispondente
//
// Nota: se x < x_min, restituisce la y del primo punto della tabella
//       se x > x_max, restituisce la y dell'ultimo punto della tabella
float interpola(tDataPoint t[], int n, float x)
{
    float y = 0.0;
    // escludo i valori di x fuori tabella
    if (x < t[0].x)
    {
        y = t[0].y;
        return y;
    }
    if (x > t[n - 1].x)
    {
        y = t[n - 1].y;
        return y;
    }

    // cerco l'intervallo che contiene x
    int i = 0;
    while (!(x >= t[i].x && x <= t[i+1].x))
    {
        i++;
    }
    // trovato l'intervallo (vedi la variabile i), calcolo l'ordinata
    y = ordinata(t[i].x, t[i].y, t[i + 1].x, t[i + 1].y, x);

    return y;
}
