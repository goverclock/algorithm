#include <cmath>
#include <iostream>

class Point {
   public:
    Point() {
        // std::cout << "Point: init\n";
        x = 0;
        y = 0;
    }
    Point(const Point &p) {
        // std::cout << "Point: copy init\n";
        x = p.x;
        y = p.y;
    }
    Point(std::istream& is) {
        // std::cout << "Point: init\n";
        is >> x >> y;
    }
    ~Point() {  }
    double distance(Point p) {
        double dx = posX() - p.posX();
        double dy = posY() - p.posY();
        return sqrt(dx * dx + dy * dy);
    }
    int posX() { return x; }
    int posY() { return y; }

   private:
    int x;
    int y;
};

class Circle {
   public:
    Circle() {
        // std::cout << "Circle: init\n";
        puts("Enter center and range:");
        c = Point(std::cin);
        std::cin >> r;
    }
    ~Circle() {  }

    bool is_collid(Circle& other) {
        double P = c.distance(other.c);
        double Rr = r + other.r;
        return other.r - r < P && other.r + r;
    }

   private:
    Point c;
    int r;
};

int main() {
    Circle a, b;
    puts("Here");
    std::cout << "is collid:\n" << a.is_collid(b) << "\n";

    return 0;
}

/*
Point: init     // 圆形a的私有变量c初始化
Circle: init    // 圆形a调用默认构造函数Circle()
Point: init     // Circle()中调用Point(std::cin),该Point对象是自动的
1 1 1           // 输入圆心坐标和半径
Point: delete   // Circle()返回,之前创建的自动Point对象析构
Point: init     // 从这里直到"Here"是创建圆形b经历的相同过程
Circle: init
Point: init
2 2 2
Point: delete
Here
is collid:
Point: copy init    // a.is_collid(b)中调用了c.distance(other.c),参数通过拷贝构造函数产生
Point: delete       // distance函数完成后参数自动析构
1Circle: delete     // iscollid()返回1,main函数执行至结束,Circle析构
Point: delete       // Circle的成员Point析构
Circle: delete
Point: delete
*/
