#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> input();

void output(const std::vector<int> answer);

std::vector<int> task_B(const int input_array_size, const std::vector<int> input_array);

int main() {
	const std::vector<int> input_array = input();
	const std::vector<int> answer = task_B(input_array.size(), input_array);
	output(answer);
	return 0;
}