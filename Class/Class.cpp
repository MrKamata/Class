#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Solid
{
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};
class Box :Solid
{
private:
    double width;
    double height;
    double depth;

public:
    Box(double width,   //幅
        double height,  //高さ
        double depth)  //奥行
    {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetVolume()
    {
        return width * height * depth;
    }
    double GetSurface()
    {
        return (width * height + height * depth + depth * width) * 2;
    }


};
class Cylinder :Solid
{
private:
    double radius;
    double height;
public:
    Cylinder(double radius,   //底面の半径
        double height)  //高さ
    {
        this->radius = radius;
        this->height = height;
    }
    double GetVolume()
    {
        return radius * radius * M_PI * height;
    }
    double GetSurface()
    {
        return (radius * radius * M_PI * 2) + (radius * M_PI * height * 2);
    }
};
class Cone :Solid
{
private:
    double radius;
    double height;
public:
    Cone(double radius,   //底面の半径
        double height)  //高さ
    {
        this->radius = radius;
        this->height = height;
    }
    double GetVolume()
    {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface()
    {
        return radius * M_PI * sqrtf(radius * radius + height * height) + radius * radius * M_PI;
    }
};
class Sphere :Solid
{
private:
    double radius;
public:
    Sphere(double radius) //球の半径
    {
        this->radius = radius;
    }
    double GetVolume()
    {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    double GetSurface()
    {
        return radius * radius * M_PI * 4;
    }
};
int main()
{
    Box box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder cylinder{ 5,10 };
    cout << "cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "cylinderの表面積=" << cylinder.GetSurface() << endl;
    Cone cone{ 4,8 };
    cout << "coneの体積=" << cone.GetVolume() << endl;
    cout << "coneの表面積=" << cone.GetSurface() << endl;
    Sphere sphere{ 6 };
    cout << "sphereの体積=" << sphere.GetVolume() << endl;
    cout << "sphereの表面積=" << sphere.GetSurface() << endl;
}