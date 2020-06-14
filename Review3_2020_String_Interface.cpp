#include <iostream>
#include <vector>
#include <cctype>

struct Node{
    std::vector<Node*> childs;
    bool finally;
    int count;
    char letter;
    explicit Node(char let){
        letter = let;
        childs.resize(0);
        finally = false;
        count = 0;
    }
};

int search_letter(Node* node, char added);

int add_letter(Node* node, char added);

Node* list_of_people = new Node(0);

void add_people(std::string name);

std::string search_winner(int num_winner);

int main()
{
    int acts;
    std::cin >> acts;
    for (int i = 0; i < acts; i++){
        std::string command;
        std::cin >> command;
        if (isdigit(command[0])){
            std::cout << search_winner(stoi(command));
            std::cout<< std::endl;
        }else{
            add_people(command);
        }
    }
}
