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
float ascissa(float x1, float y1, float x2, float y2, float x);

using namespace std;

int main()
{
    // punto fuori a sinistra
    float yl = 5;
    float xl;
    xl = interpola(fsr, fsr_nPoints, yl);

    cout << "  ordinata y = " << yl << "ascissa x = " << xl << endl;

    // punto fuori a sinistra
    float yr = 905;
    float xr;
    xr = interpola(fsr, fsr_nPoints, yr);

    cout << "ordinata y = " << yr << "  ascissa x = " << xr  << endl;

    // punto nel primo intervallo
    float yp = 800;
    float xp;
    xp = interpola(fsr, fsr_nPoints, yp);

    cout << "ordinata y = " << yp << "  ascissa x = " << xp  << endl;
}


//-----------------

// dati i due estremi del segmento, trova l'ascissa x del punto con ordinata y
float ascissa(float x1, float y1, float x2, float y2, float y)
{
    float x;
    // test per evitare divisione per 0
    if (x1 == x2)
    {
        return 0.0;
    }

    // calcola la pendenza
    float m = (y2 - y1) / (x2 - x1);

    // e l'ascissa del punto intermedio
    x = x1 + (y - y1) / m;

    return x;
}

// dato l'array t di tipo tDataPoint con n punti della poligonale 2D
// e data l'ordinata y del punto, restituisce l'ascissa x corrispondente
//
// Nota: se y < y_min, restituisce la x dell'ultimo punto della tabella
//       se y > y_max, restituisce la x del primo punto della tabella
float interpola(tDataPoint t[], int n, float y)
{
    float x = 0.0;
    // escludo i valori di y fuori tabella
    if (y > t[0].y)
    {
        x = t[0].x;
        return x;
    }
    if (y < t[n - 1].y)
    {
        x = t[n - 1].x;
        return x;
    }

    // cerco l'intervallo che contiene y
    int i = 0;
    while (!(y <= t[i].y && y >= t[i+1].y))
    {
        i++;
    }
    // trovato l'intervallo (vedi la variabile i), calcolo l'ordinata
    x = ascissa(t[i].x, t[i].y, t[i + 1].x, t[i + 1].y, y);

    return x;
}
