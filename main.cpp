#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

const double E_CONSTANT = exp(1);  // Defining the constant e
const double LOG_10 = log(10.0);   // Natural Logarithm of 10, used for base conversion

double ln_series(double y, int terms = 10000000); // calculates natural logarithm using series formula

int main() {
    string try_again;    // variable to control if the user wants to repeat calculations
    string x_input;      // stores user input for x
    string base_input;   // stores user input for logarithm base
    double x, b, ln_b, log_base_b; // variables for storing numerical values and results

    cout << " ------ Logarithmic Calculator ------\n" << endl;

    do {
        // asks for base first
        while (true) {
            cout << "What is the base, b? Recall that log_b(a): ";
            cin >> base_input;
            if (base_input == "e") {
                b = E_CONSTANT;
                break;
            } else {
                b = stod(base_input);
                if (b <= 0 || b == 1) {
                    cout << "Your base must be positive, b cannot equal to one" << endl;
                } else {
                    break;
                }
            }
        }

        // asking for the value of a
        while (true) {
            cout << "What is the input, a? Recall that log_" << base_input << "(a): ";
            cin >> x_input;
            if (x_input == "e") {
                x = E_CONSTANT;
                break;
            } else {
                x = stod(x_input);
                if (x <= 0) {
                    cout << "Domain error, a must be positive, a > 0." << endl;
                } else {
                    break;
                }
            }
        }

        cout << fixed << setprecision(8);

        // normalizes x from values between 1 and 10 for accurate calculations
        int powerOfTen = 0;
        double y = x;
        if (y >= 10) {
            while (y >= 10) {
                y /= 10;
                powerOfTen++;
            }
        } else if (y < 1) {
            while (y < 1) {
                y *= 10;
                powerOfTen--;
            }
        }

        // calculate natural logarithm using the series formula
        double ln_y = ln_series(y);
        double ln_x = ln_y + powerOfTen * LOG_10;

        // output result with fixed precision
        if (b == E_CONSTANT) {
            cout << "The natural logarithm ln(" << x_input << ") is approximately " << ln_x << endl;
        } else {
            ln_b = log(b); // calculates natural log of the base
            log_base_b = ln_x / ln_b; // base conversion formula
            cout << "The logarithm base " << b << " of " << x_input << " is approximately " << log_base_b << endl;
        }

        cout << "\n--------------------------------------------------\n";
        cout << "\nWould you like to try another calculation? (Y/N): ";
        cin >> try_again;
        cout << "\n--------------------------------------------------\n\n";

        if (try_again == "n" || try_again == "N") {
            cout << "\n ------ Exiting the program. Thank you for using the calculator! ------\n" << endl;
            break; // exits loop if user chooses no
        }
    } while (try_again == "y" || try_again == "Y");

    return 0;
}

double ln_series(double y, int terms) {
    // Compute ln(y) using the series
    double numerator = y - 1;
    double denominator = y + 1;
    double sum = 0;  // initializes sum of the series
    double term = 0; // variable to store the current term of the series
    double z = numerator / denominator;

    for (int m = 1; m <= terms; m++) {
        term = pow(z, 2 * m - 1) / (2 * m - 1); // calculates each term
        sum += term; // add the term to the sum
    }

    return 2 * sum; // multiply by 2 to get final result
}
