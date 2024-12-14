#include <iostream>

using namespace std;

class Shape {
};

class Circle : public Shape {

};

class Triangle : public Shape {

};

class Square : public Shape {
};

// Overloaded draw functions for each shape type
void draw(const Circle* circle) {
    circle->printShapeInfo();
}

void draw(const Triangle* triangle) {
    triangle->printShapeInfo();
}

void draw(const Square* square) {
    square->printShapeInfo();
}

int main() {
    // Dynamically allocated arrays of pointers for each shape, each holding 2 objects
    Circle* circles[2] = { new Circle(3.0), new Circle(5.0) };
    Triangle* triangles[2] = { new Triangle(3.0, 4.0, 5.0), new Triangle(6.0, 8.0, 10.0) };
    Square* squares[2] = { new Square(4.0), new Square(7.0) };

    // Print shape info for each object in circles array
    for (int i = 0; i < 2; ++i) {
        draw(circles[i]);
    }

    // Print shape info for each object in triangles array
    for (int i = 0; i < 2; ++i) {
        draw(triangles[i]);
    }

    // Print shape info for each object in squares array
    for (int i = 0; i < 2; ++i) {
        draw(squares[i]);
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete circles[i];
        delete triangles[i];
        delete squares[i];
    }

    return 0;
}
