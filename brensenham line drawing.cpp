#include <iostream>
#include <graphics.h>


void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y,p;

    // Determine the direction of the line
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    
    initwindow(800, 600);

    x = x1;
    y = y1;

    // Plot the starting point
   
    putpixel(x, y, WHITE);
    std::cout << "(" << x << ", " << y << ")\n";

    if (dx > dy) {
        p = 2 * dy - dx;
        while (x != x2) {
            x += sx;
            if (p < 0)
                p += 2 * dy;
            else {
                y += sy;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
            std::cout << "(" << x << ", " << y << ")\n";
        }
    } else {
        p = 2 * dx - dy;
        while (y != y2) {
            y += sy;
            if (p < 0)
                p += 2 * dx;
            else {
                x += sx;
                p += 2 * (dx - dy);
            }
            putpixel(x, y, WHITE);
            std::cout << "(" << x << ", " << y << ")\n";
        }
    }

    delay(10000);
    closegraph();
}
int main() {
    int x1, y1, x2, y2;

    // Coordinates of the endpoints of the line
    std::cout << "Enter the coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    //x1 = 300;
    //y1 = 100;
    //x2 =200;
    //y2 = 500;

    // Draw the line
    drawLine(x1, y1, x2, y2);

    return 0;
}
