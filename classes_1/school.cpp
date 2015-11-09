// author: Mustafa Atik <muatik@gmail.com> No. 2015719018
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    unsigned int id;
    string name;
public:
    Person()
    {
        id = 0;
    }
    void display()
    {
        cout << "id: " << id << ", name: " << name << endl;
    }
    void set(unsigned int id)
    {
        this->id = id;
    }
    void set(unsigned int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    unsigned int getId()
    {
        return id;
    }
    ~Person()
    {

    }
};


class Teacher: public Person
{
private:
    string classes[2];
public:
    static unsigned short MAX_CLASS;

    bool teachClass(string className)
    {
        for (int i=0; i < MAX_CLASS; i++)
        {
            if (classes[i] == "") {
                classes[i] = className;
                return true;
            }
        }
        return false;
    }

    // overriding
    void display()
    {
        Person::display();
        cout << "teaches:" << endl;
        for (int i = 0; i < MAX_CLASS; ++i)
        {
            cout << i+1 << ".course is " << classes[i] << endl;
        }
    }

};
unsigned short Teacher::MAX_CLASS = 2;

class Student: public Person
{
private:
    string classes[2];
public:
    static unsigned short MAX_CLASS;

    bool takeClass(string className)
    {
        for (int i=0; i < MAX_CLASS; i++)
        {
            if (classes[i] == "") {
                classes[i] = className;
                return true;
            }
        }
        return false;
    }

    // overriding
    void display()
    {
        Person::display();
        cout << "takes:" << endl;
        for (int i = 0; i < MAX_CLASS; ++i)
        {
            cout << i+1 << ".course is " << classes[i] << endl;
        }
    }

};
unsigned short Student::MAX_CLASS = 2;

class School
{
private:
    string name;
    std::vector<Student*> students;
    std::vector<Teacher*> teachers;
public:
    static unsigned short MAX_STUDENT;
    static unsigned short MAX_TEACHER;
    School(string name)
    {
        this->name = name;
    }

    void registerStudent(Student student)
    {
        students.push_back(&student);
    }
    void hireTeacher(Teacher teacher)
    {
        teachers.push_back(&teacher);
    }
    void display()
    {
        cout << "STUDENTS IN THE SCHOOL" << endl;
        for (int i = 0; i < MAX_STUDENT; ++i)
        {
            students[i]->display();
        }
        cout << "TEACHERS IN THE SCHOOL" << endl;
        for (int i = 0; i <MAX_STUDENT; ++i)
        {
            teachers[i]->display();
        }
    }

    bool exists(Person p)
    {
        for (int i = 0; i < MAX_STUDENT; ++i)
        {
            if (students[i]->getId() == p.getId())
                return true;
        }
        for (int i = 0; i < MAX_TEACHER; ++i)
        {
            if (teachers[i]->getId() == p.getId())
                return true;
        }
        return false;
    }
    ~School(){};
};
unsigned short School::MAX_STUDENT = 2;
unsigned short School::MAX_TEACHER = 2;

int main()
{
    Student s1;
    s1.set(123, "Mustafa");
    s1.takeClass("math1");
    s1.takeClass("math2");
    s1.takeClass("math3");

    Student s2;
    s2.set(634, "Ali");
    s2.takeClass("bio1");
    s2.takeClass("bio2");
    s2.takeClass("bio3");

    Teacher t1;
    t1.set(954, "John");
    t1.teachClass("math1");
    t1.teachClass("math2");
    t1.teachClass("bio1");

    Teacher t2;
    t2.set(890, "George");
    t2.teachClass("math1");
    t2.teachClass("math2");
    t2.teachClass("bio1");

    School univ("BOUN");
    univ.registerStudent(s1);
    univ.registerStudent(s2);
    univ.hireTeacher(t1);
    univ.hireTeacher(t2);
    univ.display();

    if (univ.exists(t2)) {
        cout << t2.getName() << " is in the school";
    }

    // STUDENTS IN THE SCHOOL
    // id: 123, name: Mustafa
    // takes:
    // 1.course is math1
    // 2.course is math2
    // id: 634, name: Ali
    // takes:
    // 1.course is bio1
    // 2.course is bio2
    // TEACHERS IN THE SCHOOL
    // id: 954, name: John
    // teaches:
    // 1.course is math1
    // 2.course is math2
    // id: 890, name: George
    // teaches:
    // 1.course is math1
    // 2.course is math2
    // George is in the school

}