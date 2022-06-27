#include <iostream>

class Shape {
   public:
    Shape() { std::cout << "Shape: init\n"; }
    ~Shape() { std::cout << "Shape: delete\n"; }
    virtual double area() = 0;
};

class Rectangle : public Shape {
   public:
    Rectangle(double w, double h) {
        std::cout << "Rectangle: init\n";
        width = w;
        height = h;
    }
    ~Rectangle() { std::cout << "Rectangle: delete\n"; }

    double area() override { return width * height; }

   private:
    double width;
    double height;
};

class Circle : public Shape {
   public:
    Circle(double ra) {
        std::cout << "Circle: init\n";
        r = ra;
    }
    ~Circle() { std::cout << "Circle: delete\n"; }

    const double pi = 3.1415926;
    double area() override { return pi * r * r; }

   private:
    double r;
};

class Square : public Rectangle {
   public:
    Square(double u) : Rectangle(u, u) { std::cout << "Square: init\n"; }
    ~Square() { std::cout << "Square: delete\n"; }
};

int main() {
    Rectangle rect(10, 20);
    Circle cir(5);
    Square squ(3);

    std::cout << "rectangle area: " << rect.area() << std::endl;
    std::cout << "circle area: " << cir.area() << std::endl;
    std::cout << "square area: " << squ.area() << std::endl;

    return 0;
}

/* 
Shape: init             // 首先创建Shape基类,再创建Rectangle对象rect
Rectangle: init
Shape: init             // 首先创建Shape基类,Circle对象cir
Circle: init
Shape: init             // 依次创建Shape, Rectangle基类,再创建Square对象squ
Rectangle: init
Square: init
rectangle area: 200     // 调用rect.area()
circle area: 78.5398    // 调用cir.area()
square area: 9          // 调用squ.area()
Square: delete          // squ对象析构,依次调用Square,Rectangle和Shape的析构函数
Rectangle: delete
Shape: delete
Circle: delete          // cir对象析构
Shape: delete
Rectangle: delete       // rect对象析构
Shape: delete 
*/


