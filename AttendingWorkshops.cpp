// This code is my solution to the HackerRank C++ problem found at:
// https://www.hackerrank.com/challenges/attending-workshops

#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops
{
    int n;
    vector<Workshop> workshops;
};

// Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *aw = new Available_Workshops;
    aw->n = n;
    for (int i = 0; i < n; i++)
    {
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        aw->workshops.push_back(w);
    }
    return aw;
}
int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    std::sort(ptr->workshops.begin(), ptr->workshops.end(), [](const Workshop &w1, const Workshop &w2)
              { return w1.end_time < w2.end_time; });
    int current_time = 0;
    int attended_workshops = 0;
    for (const auto &workshop : ptr->workshops)
    {
        if (workshop.start_time >= current_time)
        {
            attended_workshops++;
            current_time = workshop.end_time;
        }
    }
    return attended_workshops;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
