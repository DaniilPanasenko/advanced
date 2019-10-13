#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> reading_demand_coefficients(std::istream& input = std::cin);

void writing_workers_indices(const std::vector<int>& workers_indices, std::ostream& output = std::cout);

std::vector<int> searching_video_partipants(const std::vector<int>& demand_coefficients);

int main() {
    const std::vector<int> demand_coefficients = reading_demand_coefficients();
    const std::vector<int> workers_indices = searching_video_partipants(demand_coefficients);
    writing_workers_indices(workers_indices);
    return 0;
}