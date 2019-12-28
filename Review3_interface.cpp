#include <iostream>
#include <random>
#include <vector>

class CartesianTree {
  struct Node
  {
    int value, priority, count;
    int64_t sum;
	bool reverse;
	Node* left, * right;
	Node(const int _value, const int _priority, Node* _left, Node* _right);
  };

  static int getCount(Node* tree);

  static int64_t getSum(Node* tree);

  static void updateSum(Node* tree);

  static void updateCount(Node* tree);

  Node* root;

  void push(Node* tree);

  Node* merge(Node* tree1, Node* tree2);

  struct NodePair
  {
	Node* node1;
	Node* node2;
	NodePair(Node* n1, Node* n2);
  };

  NodePair split(Node* tree, const int splitkey, const int less = 0);

public:
  CartesianTree()
  {
	root = NULL;
  }

  void insert(const int position, const int value);

  void reverse(const int leftBound, const int rightBound);

  int64_t sumFromAToB(const int leftBound, const int rightBound);
};

struct tripleQueryBounds
{
  int queryType;
  int leftBound;
  int rightBound;
};

int get_countStudents(std::istream& input = std::cin);

int get_countQueries(std::istream& input = std::cin);

void output_SumsOnSections(CartesianTree row, const std::vector<tripleQueryBounds>& queries, std::ostream& output = std::cout);

std::vector<tripleQueryBounds> get_Queries(const int countQueries, std::istream& input = std::cin);

CartesianTree FillRow(CartesianTree row, const int countStudents, std::istream& input = std::cin);

int main()
{
  CartesianTree row;
  int countStudents = get_countStudents();
  int countQueries = get_countQueries();
  row = FillRow(row, countStudents);
  std::vector<tripleQueryBounds> queries = get_Queries(countQueries);
  output_SumsOnSections(row, queries);
  return 0;
}

