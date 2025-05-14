// Copyright (c) 2024 Jayden Smith All rights reserved.
// Created By: Jayden Smith
// Date: May 12, 2025
// This code is a calculator

#include <iostream>
#include <string>
#include <cmath>

float CalcProcess(float num1, std::string symbol, float num2) {
    // Define variables
    float answer;

    // Checks for all cases with symbols
        if (symbol == "+") {
            answer = num1 + num2;
        } else if (symbol == "-") {
            answer = num1 - num2;
        } else if (symbol == "*") {
            answer = num1 * num2;
        } else if (symbol == "/") {
            answer = num1 / num2;
        } else if (symbol == "%") {
            answer = fmod(num1, num2);
        }
        return (answer);
}

int main() {
    // Define the variables
    std::string user_num1;
    std::string user_num2;
    std::string user_symbol;
    float num1_float;
    float num2_float;
    float answer;

    // Get user input
    std::cout << "What is your first number? ";
    std::cin >> user_num1;
    std::cout << "What is your second number (+, -, *, /, %)?";
    std::cin >> user_symbol;

    // Checks if the user symbol is a valid one
    if (user_symbol != "+" && user_symbol != "-"
        && user_symbol != "*" && user_symbol != "/" && user_symbol != "%") {
        std::cout << "Please enter a valid symbol!\n";

    // If not code contiunes asking for the second number
    } else {
        std::cout << "What is your second number?";
        std::cin >> user_num2;
        // Converts the numbers to floats
        try {
            num1_float = stof(user_num1);
            try {
                num2_float = stof(user_num2);

                // Make sure that it is not a modulo or division by 0
                if ((num2_float == 0) && (user_symbol == "%" || "/")) {
                        std::cout << "You cannot have 0 as" <<
                        " the second number of division or modulo!\n";
                    } else {
                        // Call function
                        answer = CalcProcess(
                            num1_float, user_symbol, num2_float);

                        // Displays answer
                        std::cout << num1_float  << user_symbol
                        <<  num2_float << " = " << answer;
                    }
            // if num 1 or 2 werent floats this happens
            } catch (std::invalid_argument) {
                std::cout << user_num2 << " is not a valid float!\n";
            }
        } catch (std::invalid_argument) {
            std::cout << user_num1 << " is not a valid float!\n";
        }
    }
}
