#ifndef DIRECTION
#define DIRECTION

#include <QString>

namespace Direction {
    static const int dontMove = 0;
    static const int up = 1;
    static const int left = 2;
    static const int back = 3;
    static const int right = 4;
}

namespace CameraDirection {
    static const QString up = "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200";
    static const QString left = "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200";
    static const QString down = "/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200";
    static const QString right = "/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200";
}

#endif // DIRECTION
