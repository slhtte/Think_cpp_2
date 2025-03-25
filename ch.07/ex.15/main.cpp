#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "../../require.h"

struct Word
{
    char symbol;
    bool guessed;
};

std::vector<Word> create_riddle(const std::string &str)
{
    std::vector<Word> res;

    for (const char &c : str)
    {
        res.emplace_back(Word{c, false});
    }

    return res;
}

std::vector<std::string> read_file()
{
    std::ifstream in("in_file");
    assure(in);

    std::string tmp{};
    std::vector<std::string> res;
    while (in >> tmp)
    {
        res.emplace_back(std::string{tmp});
    }

    return res;
}

std::string fill_word(const std::vector<Word> &word)
{
    std::string res{};

    for (const auto& s : word)
    {
        res += s.guessed ? s.symbol : '_';
    }

    return res; 
}

void print_now(const std::string &str, const size_t &counter)
{
    for (const auto &s : str)
    {
        std::cout << s << " ";
    }

    std::cout << "(" << counter << ")\n";
}

bool guessed(const std::vector<Word> &riddle)
{
    for (const auto &s : riddle)
    {
        if (!s.guessed)
        {
            return false;
        }
    }

    return true;
}

void check_symbol(const char symbol, std::vector<Word> &riddle)
{
    for(auto &s : riddle)
    {
        if (!s.guessed)
        {
            if (symbol == s.symbol)
            {
                s.guessed = true;
                std::cout << "Yes!!!\n";
                return;
            }
        }
    }

    std::cout << "No=((((\n";
}

void play_game(std::vector<Word> &riddle)
{
    size_t counter{riddle.size() + riddle.size()/2};

    std::cout << "Let's start!!! Your word contains " << riddle.size() << " letters\n";
    print_now(fill_word(riddle), counter);

    while (counter--)
    {
        std::cout << "\tInput symbol: ";
        char s;
        std::cin >> s;
        std::cout << "\n";
        check_symbol(s, riddle);
        print_now(fill_word(riddle), counter);
        
        if (guessed(riddle))
        {
            break;
        }
    }

    if (guessed(riddle))
    {
        std::cout << "You are WINNER!!!\n";
    }
    else{
        std::string res{};
        for (const auto &s : riddle)
        {
            res += toupper(s.symbol); // + " ";
            res += " ";
        }

        std::cout << "The word was " << res << "\n";
        std::cout << "You are LOOOOOOSER\n";
    }
}

int main()
{
    std::vector<std::string> file{read_file()};

    srand(time_t(0));
    size_t word_number = rand() % file.size();

    std::vector<Word> riddle{create_riddle(file[word_number])};

    play_game(riddle);
}