#include <iostream>

using namespace std;

int main()
{
    double w, h;
    cin >> w;
    cin >> h;
    double bmi = w / (h * h);
    cout << bmi << endl;
    return 0;
}