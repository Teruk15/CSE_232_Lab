#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main () {
    double start_dis_in_kilo = 37.33 * 149598000;
    double start_dis_in_mile = 37.33 * 92955800;
    double speed_kilo = 14.33;
    double speed_mile = 8.90;
    int days;

    //Ask for input
    cout << "How many days has been past?" << endl;
    cin >> days;

    //Calculate distance
    int days_in_sec = days * 86400;
    double distance_kilo = days_in_sec * speed_kilo + start_dis_in_kilo;
    double distance_mile = days_in_sec * speed_mile + start_dis_in_mile;
    cout << fixed << setprecision(2) << "Distance in kilometer is " << distance_kilo << endl;
    cout << fixed << setprecision(2) << "Distance in mile is " << distance_mile << endl;

    //Caluculate rountrip
    double distance_meter = distance_kilo * 1000;
    double travel_sec = distance_meter / 299792458;
    double travel_hour = travel_sec / 3600;
    double round_trip = travel_hour * 2;
    cout << fixed << setprecision(2) << "Round Trip in hour is " << round_trip << endl;;
}
