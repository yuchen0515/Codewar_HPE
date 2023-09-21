#include <iostream>
#include <vector>
#include <string>

// Time Complex. ==> N ^ 5

int main() {
    int32_t n = 0;
    std::cin >> n;

    std::string temp;
    std::getline(std::cin, temp);

    std::vector<std::string> str;

    for (int32_t i = 0 ; i < n ; i++) {
        std::getline(std::cin, temp);
        str.emplace_back(temp);
    }

    int32_t total = 0;

    for (int32_t i = 0 ; i < n ; i++) {
        for (int32_t j = 0 ; j < n ; j++) {
            for (int32_t k = 1 ; k <= n ; k++) {
                if (i + k > n || j + k > n) {
                    continue;
                }
                bool valid = true;

                for (int32_t m = i ; m < i + k ; m++) {
                    for (int32_t p = j ; p < j + k ; p++) {
                        if (str[m][p] == '#') {
                            valid = false;
                            m = n;
                            break;
                        }
                    }
                }
                if (valid) {
                    total += 1;
                }
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
