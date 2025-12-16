#include <iostream>

int main(){
    struct  Point
    {
        int x;
        int y;
        ~Point(){
            std::cout << "Point is being destroyed naja juk juk" << std::endl;
        }

        int sum(){
            return x+y;
        }
        int diff(){
            return x-y;
        }
        int prod(){
            return x*y;
        }
        int quot(){
            return x/y;
        }
        void fourDirection(int distance){
            std::cout << "up: (" << x << ", " << y + distance << ")" << std::endl;
            std::cout << "down: (" << x << ", " << y - distance << ")" << std::endl;
            std::cout << "left: (" << x - distance << ", " << y << ")" << std::endl;
            std::cout << "right: (" << x + distance << ", " << y << ")" << std::endl;
        }
    };
    Point p1;
    for (int x0 =1; x0 <= 10; x0++){
        int y0 = x0+1;
        p1 = {x0,y0};
    }
    
    std::cout << p1.x << std::endl;
    std::cout << p1.y << std::endl;
    std::cout << "sum:" << p1.sum() << std::endl;
    std::cout << "diff:" << p1.diff() << std::endl;
    std::cout << "Prod:" << p1.prod() << std::endl;
    std::cout << "Quot:" << p1.quot() << std::endl;
    p1.fourDirection(3);
    
    return 0;

}
    