#include <iostream>
#include <vector>
#include <cctype>

class Lottery{
 private:
    class Node{
     public:
        std::vector<Node*> childs;
        bool finally;
        int count;
        char letter;

        explicit Node(char character);

        int search_letter(char searched);

        int add_letter(char added);
    };

    Node* list_of_people;

 public:
    Lottery();

    void add_people(std::string name);

    std::string search_winner(int number_winner);
};

std::vector<std::string> get_commands(std::istream& input = std::cin);

std::vector<std::string> get_winners(std::vector<std::string> commands);

void print_winners(std::vector<std::string> winners, std::ostream& output = std::cout);

int main()
{
    std::vector<std::string> commands = get_commands();
    std::vector<std::string> winners = get_winners(commands);
    print_winners(winners);
}
