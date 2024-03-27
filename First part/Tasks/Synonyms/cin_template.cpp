#include <iostream>

int main()
{
    // some container
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        std::string command;
        std::cin >> command;
        if (command == "ADD")
        {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            // logic
        }
        else if (command == "COUNT")
        {
            std::string word;
            int num;
            std::cin >> word >> num;
            // logic
        }
        else if (command == "CHECK")
        {
            std::string word;
            int num;
            std::cin >> word >> num;
            // logic
        }
    }
}
