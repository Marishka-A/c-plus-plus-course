#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::set<std::string>> dictionary_synonyms;

    size_t n = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string command, word1, word2;
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> word1 >> word2;
            dictionary_synonyms[word1].insert(word2);
            dictionary_synonyms[word2].insert(word1);
        } else if (command == "COUNT") {
            std::cin >> word1;
            size_t count = 0;
            if (auto it = dictionary_synonyms.find(word1); it != dictionary_synonyms.end()) {
                count = it->second.size();
            }
            std::cout << count << std::endl;
        } else if (command == "CHECK") {
            std::cin >> word1 >> word2;
            if (auto it = dictionary_synonyms.find(word1); it != dictionary_synonyms.end() && it->second.find(word2) != it->second.end()) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}