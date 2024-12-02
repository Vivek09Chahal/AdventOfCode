#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

bool isSafeReport(const std::vector<int>& report) {
    if (report.size() < 2) return true;
    
    // Check if increasing
    bool isIncreasing = true;
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i - 1];
        if (diff < 1 || diff > 3) {
            isIncreasing = false;
            break;
        }
    }
    
    // Check if decreasing
    bool isDecreasing = true;
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i - 1] - report[i];
        if (diff < 1 || diff > 3) {
            isDecreasing = false;
            break;
        }
    }
    
    return isIncreasing || isDecreasing;
}


bool isStrictlySafe(const std::vector<int>& report) {
    if (report.size() < 2) return true;
    
    // Check if increasing
    bool isIncreasing = true;
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i] - report[i-1];
        if (diff < 1 || diff > 3) {
            isIncreasing = false;
            break;
        }
    }
    
    // Check if decreasing
    bool isDecreasing = true;
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = report[i-1] - report[i];
        if (diff < 1 || diff > 3) {
            isDecreasing = false;
            break;
        }
    }
    
    return isIncreasing || isDecreasing;
}

bool isSafeWithDampener(const std::vector<int>& report) {
    // First check if safe without dampener
    if (isStrictlySafe(report)) return true;
    
    // Try removing each level one at a time
    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> modified = report;
        modified.erase(modified.begin() + i);
        
        if (isStrictlySafe(modified)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    std::ifstream infile("2nd.txt");

    std::string line;
    int safeCount1 = 0;
    int safeCount2 = 0;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::vector<int> report;
        int level;
        while (iss >> level) {
            report.push_back(level);
        }
        if (isSafeReport(report)) {
            ++safeCount1;
        }

        if (isSafeWithDampener(report)) {
            ++safeCount2;
        }
    }

    std::cout << "Number of safe reports: " << safeCount1 << std::endl;
    std::cout << "Number of safe reports: " << safeCount2 << std::endl;
    return 0;
}