// Student.h

#include <string>
using namespace std;

class Student
{
private:
    string name;
    int IdNumber;
    string major;
    double gpa;
public:
    // constructors
    Student();  // default constructor
    Student(string n, int id, string m, double g);

    //mutators and accessors
    void setName(string n);
    string getName();
    void setIdNumber(int id);
    int  getIdNumber();
    void setMajor(string m);
    string getMajor();
    void setGpa(double g);
    double getGpa();
};
