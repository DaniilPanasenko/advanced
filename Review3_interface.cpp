#include <iostream>
#include <random>
#include <vector>

class cortesianTree {
	struct node
	{
		int value, priority, count;
		int64_t summa;
		bool reverse;
		node* left, * right;
		node(const int Value, const int Priority, node* Left, node* Right)
		{
			value = Value;
			priority = Priority;
			left = Left;
			right = Right;
			summa = value + getSum(left) + getSum(right);
			count = 1 + getCount(left) + getCount(right);
			reverse = false;
		}
	};

	static int getCount(node* tree);

	static int64_t getSum(node* tree);

	static void updateSum(node* tree);

	static void updateCount(node* tree);

	node* root;

	void push(node* tree);

	node* merge(node* tree1, node* tree2);

	struct NodePair
	{
		node* node1;
		node* node2;
		NodePair(node* n1, node* n2)
		{
			node1 = n1;
			node2 = n2;
		}
	};

	NodePair split(node* tree, const int splitkey, const int less = 0);

public:
	cortesianTree()
	{
		root = NULL;
	}

	void insert(const int pos, const int val);

	void reverse(const int left, const int right);

	int64_t sumFromAToB(const int left, const int right);
};

struct tripleQueryBounds
{
	int query;
	int left;
	int right;
};

int get_countStudents(std::istream& input = std::cin);

int get_countQueries(std::istream& input = std::cin);

void output_SumsOnSections(cortesianTree row, const std::vector<tripleQueryBounds>& queries, std::ostream& output = std::cout);

std::vector<tripleQueryBounds> get_Queries(const int countQueries, std::istream& input = std::cin);

cortesianTree FillRow(cortesianTree row, const int countStudents, std::istream& input = std::cin);

int main()
{
	cortesianTree row;
	int countStudents = get_countStudents();
	int countQueries = get_countQueries();
	row = FillRow(row, countStudents);
	std::vector<tripleQueryBounds> queries = get_Queries(countQueries);
	output_SumsOnSections(row, queries);
	return 0;
}