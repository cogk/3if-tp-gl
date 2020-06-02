#include <string>
#include <vector>

#include "App.h"
#include <math.h>

double distanceGPS(double lat1, double lon1, double lat2, double lon2)
{
    // https://www.movable-type.co.uk/scripts/latlong.html
    const double PI = M_PI;

    // calcul distance entre deux points GPS
    const double R = 6371e3; // rayon de la Terre en mètres

    const double p1 = lat1 * PI / 180; // angles en (radians)
    const double p2 = lat2 * PI / 180;
    const double dp = (lat2 - lat1) * PI / 180;
    const double dl = (lon2 - lon1) * PI / 180;

    const double a = sin(dp / 2) * sin(dp / 2) + cos(p1) * cos(p2) * sin(dl / 2) * sin(dl / 2);
    const double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    const double d = R * c; // distance en mètres

    return d;
}

int main()
{
    // const double rayon = 400e3;    // rayon du cercle en mètres
    const double lat1 = 48.856613; // coordonnées GPS du centre du cercle
    const double lon1 = 2.352222;

    const double lat2 = 45.764042; // coordonnées GPS de l'autre point
    const double lon2 = 4.835659;

    std::cout << distanceGPS(lat1, lon1, lat2, lon2) << std::endl;

    App app;
    return app.MenuPrincipal();
}
