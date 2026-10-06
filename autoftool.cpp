//Programmed by MasterDonald (MD)
//Inspired by moyashi mugen's "Automatic %f tool"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

int main() {
    int startY;
    std::string yInput;
    std::cout << "Provide hex address: ";
    if (!(std::cin >> yInput)) {
        std::cerr << "Error: Could not read input." << std::endl;
        return 1;
    }

    try {
        startY = std::stoi(yInput, nullptr, 16);
    } catch (const std::exception&) {
        std::cerr << "Error: Invalid input." << std::endl;
        return 1;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string xInput;
    std::cout << "Provide byte code: ";
    std::getline(std::cin, xInput);

    std::vector<int> xValues;
    std::stringstream ss(xInput);
    std::string tempHex;

    while (ss >> tempHex) {
        try {
            int xDec = std::stoi(tempHex, nullptr, 16);
            xValues.push_back(xDec);
        } catch (const std::exception&) {
            std::cerr << "Warning: Skipping invalid hex entry '" << tempHex << "'." << std::endl;
        }
    }

    if (xValues.empty()) {
        std::cerr << "Error: No valid bytes provided." << std::endl;
        return 1;
    }

    std::ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output.txt file." << std::endl;
        return 1;
    }

    int currentY = startY;

    for (int x : xValues) {
        outFile << "[state ]\n";
        outFile << "type = DisplayToClipboard\n";
        outFile << "trigger1 = 1\n";
        outFile << "text=\"%.*d%n%d\"\n";
        outFile << "params=" << x << ",0," << currentY << "\n";
        outFile << "ignorehitpause=1\n\n";

        currentY += 1;
    }

    outFile.close();

    std::cout << "Success! Decoded " << xValues.size() << " hex values and generated 'output.txt'." << std::endl;

    return 0;
}
