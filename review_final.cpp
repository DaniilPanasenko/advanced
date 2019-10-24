#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> read_demand_coefficients(std::istream& input)
{
    int workers_number;
    std::cin >> workers_number;
    std::vector<int> demand_coefficients(workers_number);
    for (int i = 0; i < workers_number; ++i)
    {
        std::cin >> demand_coefficients[i];
    }
    return demand_coefficients;
}

void write_workers_indices(const std::vector<int>& workers_indices, std::ostream& output) {
    std::cout << workers_indices.size() << std::endl;
    for (int i = 0; i < workers_indices.size(); ++i)
    {
        std::cout << workers_indices[i] << std::endl;  
    }
}

std::vector<int> find_maximal_subsequence(const std::vector<int>& demand_coefficients)
{
    int workers_number = demand_coefficients.size();
    std::vector<int> longest_common_subsequence(workers_number, std::numeric_limits<int>::min());
    std::vector<int> previous_worker_indeces_in_subsequence(workers_number, 0);
    std::vector<int> worker_indeces_in_subsequence(workers_number + 1, 0);
    longest_common_subsequence[0] = std::numeric_limits<int>::max();
    worker_indeces_in_subsequence[0] = -1;
    int length_maximal_subsequence = 0;
    for (int worker_index = 0; worker_index < workers_number; ++worker_index)
    {
        int left_bound_binsearch = 0;
        int right_bound_binsearch = workers_number - 1;
        while (left_bound_binsearch <= right_bound_binsearch)
        {
            int middle_element_binsearch = (left_bound_binsearch + right_bound_binsearch) / 2;
            if (demand_coefficients[worker_index] <= 
                longest_common_subsequence[middle_element_binsearch])
            {
                left_bound_binsearch = middle_element_binsearch + 1;
            }
            else
            {
                right_bound_binsearch = middle_element_binsearch - 1;
            }
        }
        int insertion_position = left_bound_binsearch;
        longest_common_subsequence[insertion_position] = demand_coefficients[worker_index];
        worker_indeces_in_subsequence[insertion_position] = worker_index;
        previous_worker_indeces_in_subsequence[worker_index] =
            worker_indeces_in_subsequence[insertion_position - 1];
        if (insertion_position > length_maximal_subsequence)
        {
            length_maximal_subsequence = insertion_position;
        }
    }
    std::vector<int> worker_indices(length_maximal_subsequence);
    int current_position = worker_indeces_in_subsequence[length_maximal_subsequence];
    int first_free_cell = 0;
    while (current_position != -1)
    {
        worker_indices[first_free_cell] = current_position + 1;
        current_position = previous_worker_indeces_in_subsequence[current_position];
        first_free_cell++;
    }
    reverse(worker_indices.begin(), worker_indices.end());
    return worker_indices;
}

int main() {
    const std::vector<int> demand_coefficients = read_demand_coefficients(std::cin);
    const std::vector<int> workers_indices = find_maximal_subsequence(demand_coefficients);
    write_workers_indices(workers_indices, std::cout);
    return 0;
}