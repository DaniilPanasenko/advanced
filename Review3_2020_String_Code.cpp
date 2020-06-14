#include <iostream>
#include <vector>
#include <cctype>

class Lottery {
 private:
    class Node {
     private:
        std::vector<Node*> children;
        bool is_final;
        int count;
        char letter;

     public:
        std::vector<Node*> get_children();

        bool get_is_final();

        void set_is_final(bool value);

        int get_count();

        void increment_count();

        char get_letter();

        explicit Node(const char character);

        int search_letter(const char searched);

        int add_letter(const char added);
    };

    Node* list_of_people;

 public:
    Lottery();

    void add_people(const std::string name);

    std::string search_winner(const int number_winner);
};

std::vector<std::string> get_commands(std::istream& input = std::cin);

std::vector<std::string> get_winners(const std::vector<std::string>& commands);

void print_winners(const std::vector<std::string>& winners, std::ostream& output = std::cout);

int main()
{
    const std::vector<std::string> commands = get_commands();
    const std::vector<std::string> winners = get_winners(commands);
    print_winners(winners);
}
