#include <iostream>
#include <string>

class Car {
private:
    std::string name;
    std::string model;
    int year;

public:
    Car(std::string x, std::string y, int z) : name(x), model(y), year(z) {};
    Car(std::string x, std::string y) : Car(x, y, 0) {};
    Car(std::string x) : Car(x,"",0) {};

    std::string Name() {return name;}
    std::string Model() {return model;}
    int Year() {return year;}
};

int main() {
    Car car1("toyota", "corolla", 2022);
    Car car2("honda", "civic");
    Car car3("ford");

    std::cout << "car1: " << car1.Name() << " " << car1.Model() << " " << car1.Year() << std::endl;
    std::cout << "car2: " << car2.Name() << " " << car2.Model() << " " << car2.Year() << std::endl;
    std::cout << "car3: " << car3.Name() << " " << car3.Model() << " " << car3.Year() << std::endl;

    return 0;
}
