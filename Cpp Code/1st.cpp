#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

int part1(std::vector<int> &leftList, std::vector<int> &rightList)
{
    int totalDistance = 0;
    for (size_t i = 0; i < leftList.size(); ++i)
    {
        totalDistance += std::abs(leftList[i] - rightList[i]);
    }

    return totalDistance;
}

int part2(std::vector<int> &leftList, std::vector<int> &rightList)
{
    std::map<int, int> countMap;
    for (int num : rightList)
    {
        countMap[num]++;
    }

    // Calculate the similarity score
    int similarityScore = 0;
    for (int num : leftList)
    {
        similarityScore += num * countMap[num];
    }
    return similarityScore;
}

int main()
{
    std::ifstream infile("1st.txt");
    std::vector<int> leftList, rightList;
    int left, right;

    // Read pairs from the file and populate the lists
    while (infile >> left >> right)
    {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    // Sort both lists
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int answer1 = part1(leftList, rightList);
    std::cout << "Total Distance: " << answer1 << std::endl;

    int answer2 = part2(leftList, rightList);
    std::cout << "Similarity Score: " << answer2 << std::endl;

    return 0;
}
