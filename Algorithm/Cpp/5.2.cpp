#include <iostream>
#include <cstdlib>

class Point {
   public:
    Point(int u = 0, int v = 0): x(u), y(v) {
        // std::cout << "Point: init\n";
    }
    Point(const Point& p) {
        // std::cout << "Point: copy init\n";
        x = p.x;
        y = p.y;
    }
    Point(std::istream& is) {
        // std::cout << "Point: init\n";
        is >> x >> y;
    }
    ~Point() {
        // std::cout << "Point: delete\n";
    }

    Point& operator++() {
        x++;
        y++;
        return *this;
    }
    Point& operator--() {
        x--;
        y--;
        return *this;
    }
    Point operator++(int) {
        Point ret = *this;
        ++*this;
        return ret;
    }
    Point operator--(int) {
        Point ret = *this;
        --*this;
        return ret;
    }

    void out(const char* s) {
        printf("%s:x=%d, y=%d\n", s, x, y);
    }

   private:
    int x;
    int y;
};

int main() {
    Point p(10, 5);
    p.out("init:p");

    Point t = p++;
    t.out("t");
    p.out("p");

    t = ++p;
    t.out("t");
    p.out("p");

    puts("----------");

    t = p--;
    t.out("t");
    p.out("p");

    t = --p;
    t.out("t");
    p.out("p");

    return 0;
}
