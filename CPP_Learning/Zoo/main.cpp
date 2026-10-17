#include <iostream>
#include <string>

// создание родительского класса
class Animal {
    std::string name;
    unsigned age;

public:

    void eat() {std::cout << name << " ест.\n";}
    void sleep() {std::cout << name << " спит.\n";}

    std::string nameGetter() {return name;}
    unsigned ageGetter() {return age;}

    void nameSetter(std::string inName) {name = inName;}
    void ageSetter(unsigned inAge) {age = inAge;}

    void showInfo() {
        std::cout << "Имя: " << nameGetter() << std::endl;
        std::cout << "Возраст: " << ageGetter() << std::endl;
    }

    // конструкторы, на случай, если кто-то захочет записать "Просто животное"
    Animal() : name("Unknow"), age(0) {};
    Animal(std::string inName) : name(inName), age(0) {};
    Animal(std::string inName, unsigned inAge) : name(inName), age(inAge) {};
};

class FlyingAnimal : public Animal {
    unsigned maxAltitude;
public:
    void fly() {std::cout << nameGetter() << " летит на высоте до " << maxAltitude << " метров." << std::endl;}

    FlyingAnimal() : maxAltitude(0) {
        nameSetter("Unknow");
        ageSetter(0);
    };
    FlyingAnimal(std::string inName, unsigned inAge, unsigned inMaxAltitude) : maxAltitude(inMaxAltitude) {
        nameSetter(inName);
        ageSetter(inAge);
    };
};

class WalkingAnimal : public Animal {
    unsigned walkingSpeed;
public:
    void walk() {std::cout << nameGetter() << " ходит со скоростью до " << walkingSpeed << " метров в секунду." << std::endl;}

    WalkingAnimal() : walkingSpeed(0) {
        nameSetter("Unknow");
        ageSetter(0);
    };
    WalkingAnimal(std::string inName, unsigned inAge, unsigned walkingSpeed) : walkingSpeed(walkingSpeed) {
        nameSetter(inName);
        ageSetter(inAge);
    };
};

class SwimmingAnimal : public Animal {
    unsigned maxDepth;
public:
    void swim() {std::cout << nameGetter() << " может плавать на глубину до " << maxDepth << " метров." << std::endl;}

    SwimmingAnimal() : maxDepth(0) {
        nameSetter("Unknow");
        ageSetter(0);
    };
    SwimmingAnimal(std::string inName, unsigned inAge, unsigned inMaxDepth) : maxDepth(inMaxDepth) {
        nameSetter(inName);
        ageSetter(inAge);
    };
};

int main()
{
    FlyingAnimal eagle("Eage", 3, 2000);
    WalkingAnimal bear("Bear", 7, 5);
    SwimmingAnimal dolphin("Dolphin", 4, 300);

    eagle.showInfo();
    eagle.eat();
    eagle.sleep();
    eagle.fly();


    bear.showInfo();
    bear.eat();
    bear.sleep();
    bear.walk();


    dolphin.showInfo();
    dolphin.eat();
    dolphin.sleep();
    dolphin.swim();
}