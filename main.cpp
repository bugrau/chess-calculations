#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

const int rows = 8;
const int cols = 8;

int main() {
    std::string array[rows][cols];  // Define an 8x8 array of strings

    std::ifstream inputFile("board1.txt");  // Replace with the actual file path
    if (!inputFile.is_open()) {
        std::cout << "Unable to open the file." << std::endl;
        return 1;
    }

    std::string line;
    for (int i = 0; i < rows; ++i) {
        if (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            for (int j = 0; j < cols; ++j) {
                iss >> array[i][j];
            }
        } else {
            std::cout << "File does not have enough lines." << std::endl;
            break;
        }
    }

    inputFile.close();

    // Print the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    return 0;
}
