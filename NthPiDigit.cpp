/*
P4rasail, 2/16/25
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <cmath>
#include <iomanip>
#include <limits>
#include <thread>
#include <corecrt_math_defines.h>
#include "StringExtra.h"

using namespace std;

const double pi = M_PI;

const string QuitMSG = "quit";

map<string, function<void(vector<string>)>> commands = {
    {"digit", [](vector<string> args) {
        int nAmount = stoi(args.at(1));
        cout << "Pi to " << nAmount << " decimal places: " << fixed << setprecision(nAmount) << pi << "\n";
    }},
    {"bbp", [](vector<string> args) {
        int nAmount = stoi(args.at(1));
        double piStart = 0;
        double Multi = pow(10,9);
        for (int i = 0; i < nAmount; i++) {
            long double dividerAmount = (4.0L / (8 * i + 1)) - (2.0L / (8 * i + 4)) - (1.0L / (8 * i + 5)) - (1.0L / (8 * i + 6));
            piStart += (1.0L / powl(16, i)) * dividerAmount * Multi;
        }
        cout << "Pi Approximation: " << fixed << setprecision(20) << piStart / Multi << "\n";
    }},{
    "side", [ ]( vector<string> args ) {
        int nAmount = stoi( args.at( 1 ) );
        double piStart = 0;
        
        double amountAdd =1/2.0 * tan((pi * 2/nAmount)) * nAmount; 
        piStart += amountAdd;

        cout << "Pi Approximation: " << fixed << setprecision( 20 ) << piStart<< "\n";
        }}
        };


vector<string> SplitString(string input, string delimiter) {
    string output = "";
    int increment = delimiter.size();
    vector<string> words = {};
    int lastInc = 0;

    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i] == delimiter[0]) {
            words.push_back(input.substr(lastInc, i));
            lastInc = i;
        }
    }
    words.push_back(input.substr(lastInc));
    return words;
}

int main() {
    string input = "";
    while (toLowercase(input) != "quit") {
        cout << "This is a pi calculation program\n";
        cout << "Tell me whether you want to: \n";
        cout << "digit: Ask the nth digit of pi\n";
        cout << "side: Ask for approximation of pi using the polygonal method with nth side\n";
        cout << "bbp: Calculating pi by steps using Bailey–Borwein–Plouffe formula \n";
        cout << "quit: Quit the program\n";
        cout << "\n\n\nONLY BBP AND QUIT WORK IN THIS VERSION\n\n\n";
        vector<string> args = {};
        getline(cin, input);
        cout << input << "\n";
        args = SplitString(input, " ");
        if (toLowercase(input) == "quit") break;

        if (args.size() > 0 && commands[toLowercase(args[0])]) {
            commands[toLowercase(args[0])](args);
        }
    }
}