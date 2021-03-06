// This code is my solution to the HackerRank C++ problem found at:
// https://www.hackerrank.com/challenges/virtual-functions/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <numeric>

class Person
{
public:
    int age;
    string name;
    virtual void getdata() {}
    virtual void putdata() {}
};

class Professor : public Person
{
public:
    int publications;
    static int id;
    int cur_id;
    virtual void getdata()
    {
        cin >> name >> age >> publications;
        cur_id = id++;
    }
    virtual void putdata()
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : public Person
{
public:
    vector<int> marks;
    static int id;
    int cur_id;
    virtual void getdata()
    {
        cur_id = id++;
        marks.resize(6);
        cin >> name >> age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
        }
    }
    virtual void putdata()
    {
        cout << name << " " << age << " " << accumulate(marks.begin(), marks.end(), 0) << " " << cur_id << endl;
    }
};
int Professor::id = 1;
int Student::id = 1;

int main()
{

    int n, val;
    cin >> n; // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}