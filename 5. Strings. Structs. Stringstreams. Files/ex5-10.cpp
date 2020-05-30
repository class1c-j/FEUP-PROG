/*
 
   The area of any polygon, given the coordinates of its vertices and assuming that the vertices are stored
   either clockwise or counter-clockwise, is given by the formula:
   |((x1y2-y1x2)+(x2y3-y2x3) + ..... (xny1-ynx1))/2|, where (xi,yi) are the coordinates of the i-th vertex
   and |...|represents the absolute value.
  
   a) Write a program in C++ that reads the number of vertices of a polygon, as well as the corresponding
   coordinates, and then calculates the area of the polygon. The program must use a struct Point to represent
   a point and a struct Polygon to represent a polygon.
   
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

struct Point {
    double x;
    double y;
    double angle;
};

struct Polygon {
    std::vector<Point> points;
};

bool compare_angle(const Point &p1, const Point &p2) {return p1.angle < p2.angle;}

void readPoint(Point &p) {
    std::cout << "Coordinate x ? ";
    std::cin >> p.x;
    std::cout << "Coordinate y ? ";
    std::cin >> p.y;
    if (p.x == 0 && p.y > 0) p.angle = M_PI/2;
    else if (p.x == 0 && p.y < 0) p.angle = 3*M_PI/2;
    else p.angle = atan(p.y/p.x);
}

double calculateArea(const Polygon &polygon) {
    double sum = 0;
    for (int i = 1; i < polygon.points.size(); i ++) {
        sum += polygon.points.at(i-1).x * polygon.points.at(i).y - polygon.points.at(i-1).y * polygon.points.at(i).x;
    }
    sum += polygon.points.back().x * polygon.points.front().y - polygon.points.back().y * polygon.points.front().x;
    return std::abs(sum / 2);
}

void testA() {
    int vert;
    std::cout << "How many vertices ? ";
    std::cin >> vert;
    Polygon polygon;
    for (int i = 0; i < vert; i ++) {
        Point p = {};
        std::cout << "Point " << i + 1 << std::endl;
        readPoint(p);
        polygon.points.push_back(p);
    }
    std::sort(polygon.points.begin(), polygon.points.end(), compare_angle);
    std::cout << "Area is " << calculateArea(polygon);
}

/*
  
   b) Rewrite the program in "pure C".
  
*/

typedef struct {
    double x;
    double y;
    double angle;
} PointC;

typedef struct {
    PointC *points;
} PolygonC;

void readPointC(PointC &p) {
    std::cout << "Coordinate x ? ";
    std::cin >> p.x;
    std::cout << "Coordinate y ? ";
    std::cin >> p.y;
    if (p.x == 0 && p.y > 0) p.angle = M_PI / 2;
    else if (p.x == 0 && p.y < 0) p.angle = 3 * M_PI / 2;
    else p.angle = atan(p.y / p.x);
}

int compareAnglesC(const void *p1, const void *p2) {
    auto *a = (PointC *) p1;
    auto *b = (PointC *) p2;
    return a->angle - b->angle;
}

double calculateAreaC(PolygonC polygon, int nVerts) {
    double sum = 0;
    for (int i = 1; i < nVerts; i++) {
        sum += polygon.points[i - 1].x * polygon.points[i].y - polygon.points[i - 1].y * polygon.points[i].x;
    }
    sum += polygon.points[nVerts - 1].x * polygon.points[0].y - polygon.points[nVerts - 1].y * polygon.points[0].x;
    return std::abs(sum / 2);
}

void testB() {
    int nVerts;
    PolygonC polygon;
    std::cout << "Number of vertices ? ";
    std::cin >> nVerts;
    polygon.points = (PointC *) malloc(nVerts * sizeof(PointC));
    for (int i = 0; i < nVerts; i++) {
        PointC p = {};
        std::cout << "Point " << i + 1 << std::endl;
        readPointC(p);
        polygon.points[i] = p;
    }
    for (int i = 0; i < nVerts; i++) {
        std::cout << "Points: \n";
        std::cout << polygon.points[i].x << " " << polygon.points[i].y << '\n';
    }
    qsort(polygon.points, nVerts, sizeof(PointC), compareAnglesC);
    std::cout << "Area is " << calculateAreaC(polygon, nVerts);
}




int main() {
    testA();
    testB();
}

