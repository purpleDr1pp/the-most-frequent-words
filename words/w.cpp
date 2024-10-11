#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>

int main() {

    size_t k;
    std::cin >> k;
    std::unordered_map<std::string, int> words;
    std::string word;
    while (std::cin >> word) {
        ++words[word];
    }

    using TPair = std::pair<int, std::string>;
    std::priority_queue<TPair> pq;
    for (const auto& [word, freq] : words) {
        pq.push({ -freq, word });
        if (pq.size() > k) {
            pq.pop();
        }
    }

    std::vector<TPair> top;
    top.reserve(k);

    while(!pq.empty()) {
        const auto& [freq, word] = pq.top();
        top.push_back({ -freq, word });  // возвращаем настоящую частоту
        pq.pop();
    }

    std::reverse(top.begin(), top.end());

    for (const auto& [freq, word] : top) {
        std::cout << word << "\t" << freq << "\n";
    }
}
