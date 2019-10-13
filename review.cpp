#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> input(std::istream& input = std::cin);

void output(const std::vector<int>& numbers_of_workers_in_video, std::ostream& output = std::cout);

std::vector<int> main_algorithm(const std::vector<int>& demand_coefficients);

int main() {
    const std::vector<int> demand_coefficients = input();
    const std::vector<int> worker_numbers_in_video = main_algorithm(demand_coefficients);
    output(worker_numbers_in_video);
    return 0;
}