#include <iostream>
#include <vector>
#include <string>

// Time Complex. ==> N ^ 3

int main() {
    int32_t n = 0;
    std::cin >> n;

    std::string temp;
    std::getline(std::cin, temp);

    std::vector<std::string> str;
    std::vector<std::vector<int32_t>> prefix;

    for (int32_t i = 0 ; i < n + 1 ; i++) {
        std::vector<int32_t> tp(n + 1, 0);
        prefix.emplace_back(tp);
    }

    for (int32_t i = 0 ; i < n ; i++) {
        std::getline(std::cin, temp);
        str.emplace_back(temp);

        for (int32_t j = 0 ; j < n ; j++) {
            prefix[i + 1][j + 1] += prefix[i][j + 1];
            prefix[i + 1][j + 1] += prefix[i + 1][j];
            prefix[i + 1][j + 1] -= prefix[i][j];
            if (temp[j] == '.') {
                prefix[i + 1][j + 1] += 1;
            }
        }
    }

    int32_t total = 0;

    for (int32_t s = 1 ; s <= n ; s++) {
        for (int32_t i = 0 ; i <= n - s ; i++) {
            for (int32_t j = 0 ; j <= n - s ; j++) {
                auto size = prefix[i + s][j + s] - prefix[i][j + s] - prefix[i + s][j] + prefix[i][j];
                if (size == (s * s)) {
                    total += 1;
                }

            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
