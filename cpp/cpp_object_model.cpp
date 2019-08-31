#include <stdio.h>
#include <iostream>
using namespace std;
class Point2D
{
public:
    Point2D(int x, int y) {
        _x = x;
        _y = y;
    }
    virtual void foo() {
        cout << "my foo" << endl;
    }
    virtual void bar() {
        cout << "my bar" << endl;
    }
private:
    int _x;
    int _y;
};
typedef void (*Func)();
typedef unsigned long DWORD;
#define DWORD_SIZE (sizeof(DWORD))
int main()
{
    Point2D p2d(1, 2);
    Point2D *p = &p2d;
    cout << "Point2D object size:" << sizeof(Point2D) << ", vtable(8B)+int(4B)+int(4B)" << endl;
    DWORD vptr_val = *(DWORD*)p;
    DWORD* vptr = (DWORD*)(vptr_val);
    cout << "vtable.addr:" << vptr << endl;
    DWORD* p_foo = (DWORD*)(*vptr);
    cout << "Point2D::foo addr:" << p_foo << endl;
    ((Func)p_foo)();
    DWORD* p_bar = p_foo+DWORD_SIZE;
    cout << "Point2D::bar addr:" << p_bar << endl;
    ((Func)(p_bar))();
    int *p_x = (int*)((char*)p+DWORD_SIZE);
    int *p_y = (int*)((char*)p+sizeof(int));
    cout << "p2d addr:" << p << endl;
    cout << "p_x addr:" << p_x << endl;
    cout << "p_y addr:" << p_y << endl;
    cout << "p.x:" << *p_x << endl;
    cout << "p.y:" << *p_y << endl;
    return 0;
}
