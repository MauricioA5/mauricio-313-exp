#include <iostream>
#include <cmath> 

struct Point {
    int x, y;

    Point () : x(0), y(0) {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

struct Shape {
    int vertices;
    Point** points;

    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices + 1];
        for (int i = 0; i <= vertices; i++) {
            points[i] = new Point();
        }
    }

    ~Shape () {
        for (int i = 0; i <= vertices; i++) {
            delete points[i];
        }
        delete[] points;
    }

    void addPoints(Point pts[]) {
        
        for (int i = 0; i <= vertices; i++) {
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    double area() { // modified return type seemed unnecessary to return address
        double temp = 0.0;
        for (int i = 0; i < vertices; i++) {
            int lhs = points[i]->x * points[i + 1]->y;
            int rhs = points[i + 1]->x * points[i]->y;
            temp += (lhs - rhs);
        }
        return std::abs(temp) / 2.0;
    }
};

int main () {

    Point tri1, tri2(1,2), tri3(2,0);
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    tri->addPoints(triPts);

    Point quad1(0,0), quad2(0,2), quad3(2,2), quad4(2,0);
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    std::cout << tri->area() << std::endl;
    std::cout << quad->area() << std::endl;

    // deallocate dynamic objects
    delete tri;
    delete quad;

    return 0;
}
