#include <iostream>
using namespace std;


class Person {
private:
    std::string name;
    int age;

public:
    Person(const string& n, int a) : name(n), age(a) {}


    string getName() const {
        return name;
    }


    void setName(const string& n) {
        name = n;
    }


    int getAge() const {
        return age;
    }


    void setAge(int a) {
        age = a;
    }


    virtual void displayInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
    }


    virtual ~Person() {
        cout << "Person Destructor" << endl;
    }
};


class Student : public Person {
private:
    string studentId;

public:
    Student(const string& n, int a, const string& id) : Person(n, a), studentId(id) {}

    void displayInfo() const override {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Student ID: " << studentId << endl;
    }


    ~Student() {
        cout << "Student Destructor" << endl;
    }
};


class AbstractShape {
public:
    virtual double area() const = 0;
    virtual ~AbstractShape() {}
};


class Circle : public AbstractShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {

    Person person("Alice", 30);
    Student student("Bob", 20, "S12345");


    person.setName("Carol");
    student.setAge(25);


    person.displayInfo();
    student.displayInfo();


    Person* ptr = &person;
    ptr->displayInfo();

    ptr = &student;
    ptr->displayInfo();


    Circle circle(5.0);
    AbstractShape* shapePtr = &circle;
    cout << "Circle Area: " << shapePtr->area() << endl;

    return 0;
}

