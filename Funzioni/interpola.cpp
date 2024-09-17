/*
#include <C:\Users\luca\Documents\VS_Code\C\Ord24\Funzioni\interpola.h>

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
    while (!(x >= t[i].x && x <= t[i].x))
    {
        i++;
    }
    // trovato l'intervallo, calcolo l'ordinata
    y = ordinata(t[i].x, t[i].y, t[i + 1].x, t[i + 1].y, x);

    return y;
}

*/