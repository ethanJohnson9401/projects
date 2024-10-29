#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

string find_all_trig_values(double a, double b, double c) {
    // Check if the triangle sides are valid for a right triangle
    if (c <= 0 || a <= 0 || b <= 0 || std::abs(c - std::sqrt(a * a + b * b)) > 1e-6) {
        return "Invalid triangle dimensions.";
    }
    
    double sin_A = a / c;
    double cos_A = b / c;
    double tan_A = a / b;

    double sin_B = b / c;
    double cos_B = a / c;
    double tan_B = b / a;

    std::ostringstream result;
    result << "Trig values for angle opposite side a (theta_A):\n";
    result << "sin(A) = " << sin_A << "\n";
    result << "cos(A) = " << cos_A << "\n";
    result << "tan(A) = " << tan_A << "\n\n";

    result << "Trig values for angle opposite side b (theta_B):\n";
    result << "sin(B) = " << sin_B << "\n";
    result << "cos(B) = " << cos_B << "\n";
    result << "tan(B) = " << tan_B << "\n";

    return result.str();
}

int main() {
    string input;
    while (true) {
        cout << "What are you solving for? (leg or hypotenuse): ";
        cin >> input;
        
        if (input == "hypotenuse") {
            double a, b;
            cout << "Enter leg a: ";
            cin >> a;
            cout << "Enter leg b: ";
            cin >> b;

            double c = sqrt((a * a) + (b * b));
            cout << "The hypotenuse is " << c << endl;
            cout << "The Trig Values of the triangle solved are:\n" << find_all_trig_values(a, b, c) << endl;
            break;

        } else if (input == "leg") {
            double a, c;
            cout << "Enter the leg: ";
            cin >> a;
            cout << "Enter the hypotenuse: ";
            cin >> c;

            double b = sqrt((c * c) - (a * a));
            cout << "The missing leg is " << b << endl;
            cout << "The Trig Values of the triangle solved are:\n" << find_all_trig_values(a, b, c) << endl;
            break;

        } else {
            cout << "Invalid input, please enter 'leg' or 'hypotenuse'.\n";
        }
    }
    return 0;
}
