def part1(left_list, right_list):
    total_distance = 0
    for i in range(len(left_list)):
        total_distance += abs(left_list[i] - right_list[i])
    return total_distance

def part2(left_list, right_list):
    count_map = {}
    for num in right_list:
        if num in count_map:
            count_map[num] += 1
        else:
            count_map[num] = 1

    # Calculate the similarity score
    similarity_score = 0
    for num in left_list:
        similarity_score += num * count_map.get(num, 0)
    return similarity_score

def main():
    left_list = []
    right_list = []

    with open("/Users/vivekchahal/developer/AdventOfCode/Python/1st.txt", "r") as infile:
        for line in infile:
            left, right = map(int, line.split())
            left_list.append(left)
            right_list.append(right)

    # Sort both lists
    left_list.sort()
    right_list.sort()

    answer1 = part1(left_list, right_list)
    print("Total Distance:", answer1)

    answer2 = part2(left_list, right_list)
    print("Similarity Score:", answer2)

if __name__ == "__main__":
    main()