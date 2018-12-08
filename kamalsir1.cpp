/*PROBLEM
Write C++ code in object oriented approach for the students.Student can be rewarded from the department if he gets good GPA in a semester and
solved atleast 100 ACM problems in the last year. Department will publish the top 5 students name in their honor board.
As a student of CSE, write OOP code for the project.*/

#include<iostream>
#include<iomanip>
using namespace std;

class Student
{
    public:
        int id;
        string name;
        float cgpa;
        int acmSolve;
        Student(int id, string name, float cgpa, int acmSolve)
        {
            this->id = id;
            this->name = name;
            this->cgpa = cgpa;
            this->acmSolve = acmSolve;
        }

};



int main()
{
    const int stdSize = 8;
    int counter = 0, arr[stdSize];
    Student *temp;

    Student *stdnt[stdSize]=
    {
        new Student(4001,"ABC",3.91,100),
        new Student(4002,"DEF",3.57,120),
        new Student(4003,"PQR",3.41,190),
        new Student(4004,"XYZ",3.52,140),
        new Student(4005,"LMN",3.94,90),
        new Student(4006,"MNO",3.11,110),
        new Student(4007,"STR",3.81,190),
        new Student(4008,"IJK",3.2,290)
    };


    for(int i=0;i < stdSize ;i++)
    {
        for(int j=0;j<stdSize;j++)
        {
            if(stdnt[j]->cgpa < stdnt[j+1]->cgpa)
            {
                *temp=*stdnt[j+1];
                *stdnt[j+1] =*stdnt[j];
                *stdnt[j] = *temp ;
            }
        }
    }


    cout << "TOP 5 STUDENTS IN THE HONOUR BOARD ARE: " << endl << endl;

    cout <<"ID"  << setw(10)  << "NAME"  << setw(10) << "GPA" << setw(30) << "ACM SOLVED (last year)" << endl;
    cout <<"...." << setw(10) << "......."  << setw(10) << "......" << setw(30) << "........................" << endl ;

    for(int i=0;i < stdSize ;i++)
    {
        if(stdnt[i]->acmSolve >= 100)
        {
            cout<<stdnt[i]->id<<setw(10)<<stdnt[i]->name<<setw(10)<<stdnt[i]->cgpa<<setw(10)<<stdnt[i]->acmSolve<<endl;
            counter++;
        }
        if(counter == 5)
        {
            break;
        }
    }
    return 0;
}
