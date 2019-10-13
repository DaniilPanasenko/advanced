#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> read_demand_coefficients(std::istream& input = std::cin);

void write_workers_indices(const std::vector<int>& workers_indices, std::ostream& output = std::cout);

std::vector<int> find_maximal_subsequence(const std::vector<int>& demand_coefficients);

int main() {
    const std::vector<int> demand_coefficients = reade_demand_coefficients();
    const std::vector<int> workers_indices = find_maximal_subsequence(demand_coefficients);
    write_workers_indices(workers_indices);
    return 0;
}