#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> input(FILE* stdin);

void output(FILE* stdout, const std::vector<int>& answer);

std::vector<int> task_B(const std::vector<int>& array_coefficients_demand);

int main() {
	const std::vector<int> array_coefficients_demand = input(stdin);
	const std::vector<int> answer = task_B(array_coefficients_demand);
	output(stdout, answer);
	return 0;
}