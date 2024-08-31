#include "RPN.hpp"

#include <string>
#include <vector>

#include <iostream>

enum type { NUMBER, OPERATOR };

static inline bool isoperator(int c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

static std::vector<std::pair<type, int> > parseInput(const std::string& input) {
    std::vector<std::pair<type, int> > tokens;
    std::cout << "input: " << input << std::endl;
    for (size_t i = 0; i < input.length(); i++) {
        if (std::isspace(input[i]))
            continue;
        if (std::isdigit(input[i]))
            tokens.push_back(std::make_pair(NUMBER, input[i] - '0'));
        else if (isoperator(input[i]))
            tokens.push_back(std::make_pair(OPERATOR, input[i]));
        else
        {
            std::cout << "Error: bad input, unknown character: " << input[i] << std::endl;
            throw std::exception();
        }
    }
    return (tokens);
}

static inline int executeOperator(const int a, const int b, const char op) {
    switch (op) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
    }
    return (0);
}

static int calculateResult(std::vector<std::pair<type, int> >& tokens) {
    while (tokens.size() > 2) {
        bool found = false;
        for (size_t i = 0; i + 2 < tokens.size(); ++i) {
            if (tokens[i].first != NUMBER || tokens[i + 1].first != NUMBER || tokens[i + 2].first != OPERATOR)
                continue;
            tokens[i].second = executeOperator(tokens[i].second, tokens[i + 1].second, tokens[i + 2].second);
            tokens.erase(tokens.begin() + i + 1, tokens.begin() + i + 3);
            found = true;
        }
        if (!found)
        {
            std::cout << "Error: bad input, no operator" << std::endl;
            throw std::exception();
        }
    }
    if (tokens.size() != 1 || tokens[0].first != NUMBER)
    {
        if (tokens.size() != 1)
            std::cout << "Error: bad input, size != 1" << std::endl;
        else
            std::cout << "Error: bad input, first != NUMBER" << std::endl;
        throw std::exception();
    }
    return (tokens[0].second);
}

int RPNcalculate(const std::string& input) {
    std::vector<std::pair<type, int> > tokens = parseInput(input);
    return (calculateResult(tokens));
}
