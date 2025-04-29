#include <iostream>
#include <vector>
using namespace std;

// ANSI escape codes for colors
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"

void printTaskHeader(int taskNumber) {
    cout << COLOR_CYAN << "[ - - - " << COLOR_YELLOW << taskNumber << COLOR_CYAN << " - - - ]" 
         << COLOR_RESET << "\n";
}

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
};

void shapeDemo() {
    printTaskHeader(1);
    vector<Shape*> shapes = {
        new Circle(5),
        new Rectangle(4, 6)
    };
    
    for (auto shape : shapes) {
        cout << "Площадь: " << shape->area() << endl;
        delete shape;
    }
    cout << "\n";
};
//2
class Animal {
    public:
        virtual void sound() const = 0;
        virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Гав!" << endl; }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Мяу!" << endl; }
};

void animalDemo() {
    printTaskHeader(2);
    vector<Animal*> animals = {
        new Dog(),
        new Cat()
    };
    
    for (auto animal : animals) {
        animal->sound();
        delete animal;
    }
    cout << "\n";
};
//3
class Employee {
    public:
        virtual double calculateSalary() const = 0;
        virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
};

void employeeDemo() {
    printTaskHeader(3);
    vector<Employee*> employees = {
        new FullTimeEmployee(5000),
        new PartTimeEmployee(20, 80)
    };
    
    for (auto emp : employees) {
        cout << "Зарплата: " << emp->calculateSalary() << endl;
        delete emp;
    }
    cout << "\n";
};
//4
class Vehicle {
    public:
        virtual void move() const = 0;
        virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void move() const override { cout << "Машина едет" << endl; }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "Велосипед крутит педали" << endl; }
};

void vehicleDemo() {
    printTaskHeader(4);
    vector<Vehicle*> vehicles = {
        new Car(),
        new Bike()
    };
    
    for (auto v : vehicles) {
        v->move();
        delete v;
    }
    cout << "\n";
};
//5
class Account {
    protected:
        double balance;
    public:
        Account(double b) : balance(b) {}
        virtual void withdraw(double amount) = 0;
        virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        if (balance - amount >= 0) balance -= amount;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        cout << "Снято " << amount << endl;
        balance -= amount;
    }
};

void accountDemo() {
    printTaskHeader(5);
    vector<Account*> accounts = {
        new SavingsAccount(1000),
        new CheckingAccount(1000)
    };
    
    for (auto acc : accounts) {
        acc->withdraw(200);
        delete acc;
    }
    cout << "\n";
};
//6
class Media {
    public:
        virtual void play() const = 0;
        virtual ~Media() {}
};

class Audio : public Media {
public:
    void play() const override { cout << "Воспроизводится аудио..." << endl; }
};

class Video : public Media {
public:
    void play() const override { cout << "Воспроизводится видео..." << endl; }
};

void mediaDemo() {
    printTaskHeader(6);
    vector<Media*> media = {
        new Audio(),
        new Video()
    };
    
    for (auto m : media) {
        m->play();
        delete m;
    }
    cout << "\n";
};
//7
class Person {
    public:
        virtual void introduce() const = 0;
        virtual ~Person() {}
};

class Student : public Person {
public:
    void introduce() const override { cout << "Я студент" << endl; }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "Я учитель" << endl; }
};

void personDemo() {
    printTaskHeader(7);
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };
    
    for (auto p : people) {
        p->introduce();
        delete p;
    }
    cout << "\n";
};
//8
class Book {
    public:
        virtual void getInfo() const = 0;
        virtual ~Book() {}
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "Электронная книга" << endl; }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "Печатная книга" << endl; }
};

void bookDemo() {
    printTaskHeader(8);
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };
    
    for (auto b : books) {
        b->getInfo();
        delete b;
    }
    cout << "\n";
};
//9
class Appliance {
    public:
        virtual void turnOn() const = 0;
        virtual ~Appliance() {}
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "Стиральная машина запущена" << endl; }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "Холодильник охлаждает" << endl; }
};

void applianceDemo() {
    printTaskHeader(9);
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };
    
    for (auto a : appliances) {
        a->turnOn();
        delete a;
    }
    cout << "\n";
};
//10
class Game {
    public:
        virtual void play() const = 0;
        virtual ~Game() {}
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Играем в настольную игру" << endl; }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Играем в видеоигру" << endl; }
};

void gameDemo() {
    printTaskHeader(10);
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };
    
    for (auto g : games) {
        g->play();
        delete g;
    }
    cout << "\n";
};

int main() {
    shapeDemo();
    animalDemo();
    employeeDemo();
    vehicleDemo();
    accountDemo();
    mediaDemo();
    personDemo();
    bookDemo();
    applianceDemo();
    gameDemo();
    
    return 0;
}