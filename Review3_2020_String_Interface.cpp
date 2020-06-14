#include <iostream>
#include <vector>
#include <cctype>

struct Node{
    std::vector<Node*> childs;
    bool finally;
    int count;
    char letter;
    explicit Node(char character);
};

int search_letter(Node* node, char searched);

int add_letter(Node* node, char added);

void add_people(Node* list_of_people, std::string name);

std::string search_winner(Node* list_of_people, int number_winner);

std::vector<std::string> get_commands();

std::vector<std::string> get_winners(std::vector<std::string> commands);

void print_winners(std::vector<std::string> winners);

int main()
{
    std::vector<std::string> commands = get_commands();
    std::vector<std::string> winners = get_winners(commands);
    print_winners(winners);
}
