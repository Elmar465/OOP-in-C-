
#include <iostream>
using std::string;

//* Creating abstract class
class AbstractEmployee
{
    virtual void AskForPromotion() = 0; //* That means whoever sign this contract here to impelement this method
};

class Employee : AbstractEmployee //* to call abstract class
{

    //*Encapsulation method
private:
    string Company;
    int Age;
    //* TO acces exact data in child class we must protected acces modifier
protected:
    string Name;
    //! private:  //* This means explicit way  to say everything will be private
    //* protected: //* This also will not let us use data in main
public: //* This will let us use data
    //* Encapsulation getter and setter methods
    void setName(string name)
    {
        Name = name; //* setter
    }
    string getName()
    {
        return Name; //* getter
    }
    void setCompany(string company)
    {
        Company = company; //*setter
    }
    string getCompany()
    {

        return Company; //* getter
    }
    void setAge(int age)
    {
        if (age >= 18)
        {
            Age = age; // * setter
        }
    }
    int getAge()
    {
        return Age; //*getter
    }
    void IntroduceYourSelf()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    //* Creating constructor

    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion()
    {
        if (Age > 30)
        {
            std::cout << Name << " got promoted! " << std::endl;
        }
        else
        {
            std::cout << Name << " sorry NO promotion for you!" << std::endl;
        }
    }
    virtual void Work() //* making this virtual and calling in pointer it will change for each child classes and it will tell child class same functions if you have same functions but different types and words change it.
    {
        std::cout << Name << " is checking email, task backlock, performing tasks..." << std::endl;
    };
};
//* Training in inheritance class
class Developer : public Employee //* making this public just because to acces all the functions and methods in  main class
{                                 //* in this clas Developer class became a child which means subclass or derived class,
                                  //* and class Employee became base class or main class ,super class, parent class also we can call it
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favprog) : Employee(name, company, age) //* We must call main class attributes in child class and call main constructor and put attributes
    {
        FavProgrammingLanguage = favprog;
    }
    void FixBug()
    {
        std::cout << Name << " fix the bugs using " << FavProgrammingLanguage << std::endl;
    }
    //*Polymorphism example
    void Work()
    {
        std::cout << Name << " is writing code  in " << FavProgrammingLanguage << std::endl;
    };
};

class Teacher : public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
        std::cout << Name << " is preparing " << Subject << " lesosn " << std::endl;
    }
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work()
    {
        std::cout << Name << " is teaching  " << Subject << std::endl;
    };
};
int main()
{ //*The most common use of polymorphism is when a
  //* parent clas reference is used to refer to a child class object
    Employee employee1 = Employee("Elmar", "Penningar Investemnt", 31);
    Employee employee2 = Employee("Fedya", "Penningar Investent", 27);
    //*Testing Inheritance
    Developer developer1 = Developer("Elmar", "Penningar Investemnt", 31, "Java");
    Teacher teacher1 = Teacher("Fedya", "Penningar"
                                        "Investent",
                               27, "History");
    Employee *e1 = &developer1;
    Employee *e2 = &teacher1;

    e1->Work();
    e2->Work();
    // developer1.FixBug();
    // developer1.AskForPromotion();
    // teacher1.PrepareLesson();
    // employee1.Work();
    // developer1.Work();
    // teacher1.Work();

    //*Testing abstraction
    // employee1.AskForPromotion();
    // employee1.setAge(28);
    // std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

    //* This was the example of default constructors
    // employee1.Name = "Elmar";
    // employee1.Company = "Penningar investment";
    // employee1.Age = 28;
    // employee1.IntroduceYourSelf();

    // Employee employee2;
    // employee2.Name = "Fedya";
    // employee2.Company = "Penningar investment";
    // employee2.Age = 27;
    // employee2.IntroduceYourSelf();

    return 0;
}