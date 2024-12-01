#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ifstream infile("1st.txt");
    std::vector<int> leftList, rightList;
    int left, right;

    // Read pairs from the file and populate the lists
    while (infile >> left >> right) {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    // Sort both lists
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    // Calculate the total distance
    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i) {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    // Output the total distance
    std::cout << "Total Distance: " << totalDistance << std::endl;

    return 0;
}
