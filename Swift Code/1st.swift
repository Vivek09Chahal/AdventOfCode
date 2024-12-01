import Foundation

func part1(leftList: [Int], rightList: [Int]) -> Int {
    var totalDistance = 0
    for i in 0..<leftList.count {
        totalDistance += abs(leftList[i] - rightList[i])
    }
    return totalDistance
}

func part2(leftList: [Int], rightList: [Int]) -> Int {
    var countMap: [Int: Int] = [:]
    for num in rightList {
        countMap[num, default: 0] += 1
    }

    // Calculate the similarity score
    var similarityScore = 0
    for num in leftList {
        if let count = countMap[num] {
            similarityScore += num * count
        }
    }
    return similarityScore
}

func main() {
    let filePath = "1st.txt"
    var leftList: [Int] = []
    var rightList: [Int] = []

    // Read pairs from the file and populate the lists
    if let fileContent = try? String(contentsOfFile: "1st.txt", encoding: .utf8) {
        let lines = fileContent.split(separator: "\n")
        for line in lines {
            let numbers = line.split(separator: " ").compactMap { Int($0) }
            if numbers.count == 2 {
                leftList.append(numbers[0])
                rightList.append(numbers[1])
            }
        }
    }

    // Sort both lists
    leftList.sort()
    rightList.sort()

    let answer1 = part1(leftList: leftList, rightList: rightList)
    print("Total Distance: \(answer1)")

    let answer2 = part2(leftList: leftList, rightList: rightList)
    print("Similarity Score: \(answer2)")
}

main()
