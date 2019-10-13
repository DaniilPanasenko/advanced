#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> array_input(int num) {   }

void output(std::vector<int> answer) {   }

std::vector<int> task_B(int num, std::vector<int> arr) {   }

int main() {
	int num;
	std::cin >> num;
	std::vector<int> arr = array_input(num);
	std::vector<int> answer = task_B(num, arr);
	output(answer);
	return 0;
}