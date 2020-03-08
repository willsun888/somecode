#include <iostream>
using namespace std;
class Point3D
{
public:
    Point3D(){}

    Point3D(int x, int y, int z):
        _x(x), _y(y), _z(z) {}

    virtual void foo() {
        cout << "my foo" << endl;
    }

    void bar() {
        cout << "my bar" << endl;
    }

    // static data member
    static Point3D staticP3d;

    // nonstatic data members
    int _x;
    int _y;
    int _z;
};
Point3D Point3D::staticP3d;
int main()
{
    Point3D p3d(3, 4, 5);
    Point3D *pp = &p3d;

    // pp指向已开辟的内存空间，所以如下打印具体的p3d对象中_x的地址
    cout << &pp->_x << endl;

    // int Point3D::* 表示指向Point3D成员变量的指针
    // &Point3D::_x取的是Point3D内存布局中_x的偏移配置, 因为没开辟内存，不可能是具体内存地址
    int Point3D::* p_m_x = &Point3D::_x;
    int Point3D::* p_m_y = &Point3D::_y;
    int Point3D::* p_m_z = &Point3D::_z;

    // 三个打印都是1，按照正常情况，应该是"0，4，8"
    // 但是：
    //  1. 成员变量的指针不能是0，因为这样p_m_x无法跟"int Point3D::* tmp = 0"中的tmp区分了
    //     所以编译器都会将成员变量的偏移位置都加上1
    //  2. 按照1的说法，应该三个打印是"1，5，9"才对。但是有的编译器做了优化，默认都会返回1
    cout << p_m_x << endl;
    cout << p_m_y << endl;
    cout << p_m_z << endl;

    // 因为p_m_x是成员变量x的指针，所以*p_m_x就是
    cout << pp->*p_m_x << endl;
    cout << pp->*p_m_y << endl;
    cout << pp->*p_m_z << endl;

    // staticP3d是静态成员变量，它是独立于Point3D的内存布局
    cout << &Point3D::staticP3d << endl;
    cout << &Point3D::bar << endl;
    return 0;
}
