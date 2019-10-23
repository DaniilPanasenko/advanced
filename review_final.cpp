#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::vector<int> read_demand_coefficients(std::istream& input = std::cin);

void write_workers_indices(const std::vector<int>& workers_indices, std::ostream& output = std::cout);

std::vector<int> find_maximal_subsequence(const std::vector<int>& demand_coefficients);

std::vector<int> read_demand_coefficients(std::istream& input)
{
  int length;
  std::cin >> length;
  std::vector<int> demand_coefficients(length);
  for (int i = 0; i < length; ++i)
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
  int length = demand_coefficients.size();
  std::vector<int> LCS(length, std::numeric_limits<int>::min());
  std::vector<int> previous(length, 0);
  std::vector<int> position(length + 1, 0);
  LCS[0] = std::numeric_limits<int>::max();
  position[0] = -1;
  int length_LCS = 0;
  for (int index = 0; index < length; ++index)
  {
    int first = 0;
    int last = LCS.size() - 1;
    while (first <= last)
    {
	  int middle = (first + last) / 2;
      if (demand_coefficients[index] <= LCS[middle])
      {
        first = middle + 1;
      }
      else
      {
        last = middle - 1;
      }
    }
    int insert = first;
    LCS[insert] = demand_coefficients[index];
    position[insert] = index;
    previous[index] = position[insert - 1];
    if (insert > length_LCS)
    {
      length_LCS = insert;
    }
  }
  std::vector<int> worker_indices(length_LCS);
  int current_position = position[length_LCS];
  int temp = 0;
  while (current_position != -1)
  {
    worker_indices[temp] = current_position + 1;
    current_position = previous[current_position];
	temp++;
  }
  reverse(worker_indices.begin(), worker_indices.end());
  return worker_indices;
}

int main() {
  const std::vector<int> demand_coefficients = read_demand_coefficients();
  const std::vector<int> workers_indices = find_maximal_subsequence(demand_coefficients);
  write_workers_indices(workers_indices);
  return 0;
}