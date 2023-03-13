#include <iostream>
#include <string>

class car{
public:
    int price;
    int power;
    };

class dog{
public:
    int age;
    int mass;
};

using namespace std;

int main()
{

car car1;
car1.price=10000;
car1.power=120;

car car2;
car2.price=20000;
car2.power=150;

dog dog1;
dog1.age =10;
dog1.mass=20;

dog dog2;
dog2.age =3;
dog2.mass=8;
    return 0;
}
