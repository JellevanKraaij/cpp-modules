#include <iostream>
#include <ostream>
#include <sstream>
#include <utility>
#include <vector>

enum type { NUMBER, OPERATOR };

inline bool isoperator(int c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void errorExit(void) {
    std::cerr << "Error" << std::endl;
    exit(EXIT_FAILURE);
}

std::ostream& operator<<(std::ostream& s, const std::vector<std::pair<type, int> >& v) {
    std::cout << '[';
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i].first == NUMBER)
            s << v[i].second;
        else
            s << (char)v[i].second;
        if (i + 1 < v.size())
            s << ',';
    }
    std::cout << ']';
    return (s);
}

std::vector<std::pair<type, int> > parseArgs(int argc, char** argv) {
    std::vector<std::pair<type, int> > tokens;
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; argv[i][j]; j++) {
            if (isspace(argv[i][j]))
                continue;
            if (isnumber(argv[i][j]))
                tokens.push_back(std::make_pair(NUMBER, argv[i][j] - '0'));
            else if (isoperator(argv[i][j]))
                tokens.push_back(std::make_pair(OPERATOR, argv[i][j]));
            else
                errorExit();
        }
    }
    return (tokens);
}

int executeOperator(const int a, const int b, const char op) {
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

int calculateResult(std::vector<std::pair<type, int> >& tokens) {
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
            errorExit();
    }
    if (tokens.size() != 1 || tokens[0].first != NUMBER)
        errorExit();
    return (tokens[0].second);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::vector<std::pair<type, int> > tokens = parseArgs(argc, argv);
    std::cout << calculateResult(tokens) << std::endl;
    return (0);
}