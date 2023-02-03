#include <iostream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: setprecision;
using std::fixed;

double Fn(double x){
    double temp = (-6.0 * x*x) + (5.0 * x) + 3;
    return temp;
}

double Integral(double x){
    double temp = (-2.0 * x * x * x) + (5.0 / 2.0 * x * x) + (3.0 * x);
    return temp;
}

double EstimateWithTraps(double a, double b, int n){
    double delta_x;
    delta_x = (b - a) / n;

    double trapezoid;
    double area = 0;
    for (int i = 0; i < n; i++){
        trapezoid = ((Fn(a + delta_x) + Fn(a)) / 2.0) * delta_x; 
        area += trapezoid;
        a += delta_x;
    }

    return area;
}

double Actual_Area(double a, double b){
    double area;
    area = Integral(b) - Integral(a);

    return area;
}



int main(){
    double a,b,tolerance,diff;
    int n;

    cout << "Lower Range:";
    cin >> a;
    cout << endl;
    cout << "Upper Range:";
    cin >> b;
    cout << endl;
    cout << "Tolerance:";
    cin >> tolerance;
    cout << endl;
    cout << "Initial trapezoid count:";
    cin >> n;
    cout << endl;
    
    do {
        diff = Actual_Area(a,b) - EstimateWithTraps(a,b,n);
        cout << fixed << setprecision(4) << "Estimate:" << EstimateWithTraps(a,b,n) <<", Number of Traps:" << n << ", Diff:" << diff << endl;
        n = n * 2;
    }while (tolerance < diff);
}