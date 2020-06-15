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
        std::vector<Node*> get_children(){
            return children;
        }

        bool get_is_final(){
            return is_final;
        }

        void set_is_final(bool value){
            is_final = value;
        }

        int get_count(){
            return count;
        }

        void increment_count(){
            count++;
        }

        char get_letter(){
            return letter;
        }

        explicit Node(const char character){
            letter = character;
            is_final = false;
            count = 0;
        }

        int search_letter(const char searched){
            for (int i = 0; i < this->children.size(); i++){
                if (this->children[i]->letter == searched){
                    return i;
                }
            }
            return -1;
        }

        int add_letter(const char added){
            int i;
            bool to_end = true;
            for (i = 0; i < this->children.size(); i++){
                if (added < this->children[i]->letter){
                    to_end = false;
                    break;
                }
            }
            if (!to_end){
                this->children.resize(this->children.size()+1);
                for (int j = this->children.size()-1; j > i; j--){
                    this->children[j] = this->children[j-1];
                }
                this->children[i] = new Node(added);
                return i;
            }else{
                this->children.push_back(new Node(added));
                return this->children.size()-1;
            }
        }
    };

    Node* list_of_people;

 public:
    Lottery(){
        list_of_people = new Node(NULL);
    }

    void add_people(const std::string name){
        Node* current_alphabet = list_of_people;
        char current_character = name[0];
        for (int i = 1; i < name.size(); i++){
            int index = current_alphabet->search_letter(current_character);
            if (index == -1){
                index = current_alphabet->add_letter(current_character);
            }
            current_alphabet->get_children()[index]->increment_count();
            current_alphabet = current_alphabet->get_children()[index];
            current_character = name[i];
        }
        int ind = current_alphabet->search_letter(current_character);
        if (ind == -1){
            ind = current_alphabet->add_letter(current_character);
        }
        current_alphabet->get_children()[ind]->increment_count();
        current_alphabet->get_children()[ind]->set_is_final(true);
    }

    std::string search_winner(const int number_winner){
        std::string result = "";
        Node* current = list_of_people;
        int sum = 0;
        while (sum + 1 != number_winner || !current->get_is_final()){
            if (current->get_is_final()){
                sum++;
            }
            int i;
            for (i = 0; number_winner > sum; i++){
                sum += current->get_children()[i]->get_count();
            }
            i--;
            sum -= current->get_children()[i]->get_count();
            result+=current->get_children()[i]->get_letter();
            current = current->get_children()[i];
        }
        return result;
    }
};

std::vector<std::string> get_commands(std::istream& input = std::cin){
    int acts;
    input >> acts;
    std::vector<std::string> commands(acts);
    for (int i = 0; i < acts; i++){
        input >> commands[i];
    }
    return commands;
}

std::vector<std::string> get_winners(const std::vector<std::string>& commands){
    Lottery* lottery = new Lottery();
    std::vector<std::string> winners(0);
    for (int i = 0; i < commands.size(); i++){
        if (isdigit(commands[i][0])){
            winners.push_back(lottery->search_winner(stoi(commands[i])));
        }else{
            lottery->add_people(commands[i]);
        }
    }
    return winners;
}

void print_winners(const std::vector<std::string>& winners,
                   std::ostream& output = std::cout){
    for (int i = 0; i < winners.size(); i++){
        output << winners[i] << std::endl;
    }
}

int main()
{
    const std::vector<std::string> commands = get_commands();
    const std::vector<std::string> winners = get_winners(commands);
    print_winners(winners);
}
