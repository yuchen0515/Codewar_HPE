#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int32_t> arr(4, 0);
    int32_t total = 0;

    for (int32_t i = 0 ; i < 4 ; i++) {
        std::cin >> arr[i];
        total += arr[i];
    }

    int32_t ans = 0;
    if (total < 2 * arr[0]) {
        ans = 0;
    } else if (arr[0] == 0) {
        ans = 1;
    } else {
        std::unordered_map<int32_t, int32_t> permut_map;

        permut_map[0] = 1;
        permut_map[1] = 1;
        permut_map[2] = 2;
        permut_map[3] = 6;
        permut_map[4] = 24;

        int32_t permut = permut_map[arr[0]];
        for (int32_t r = 0 ; r <= arr[1] ; r++) {
            if (r > arr[0]) {
                continue;
            }
            for (int32_t b = 0 ; b <= arr[2] ; b++) {
                if (r + b > arr[0]) {
                    continue;
                }
                int32_t g = arr[0] - r - b;
                if (arr[3] < g) {
                    continue;
                }

                int32_t res = permut;
                res /= permut_map[r];
                res /= permut_map[b];
                res /= permut_map[g];

                ans += res;
            }
        }
        if (arr[0] == 3) {
            ans *= 4;
        } else if (arr[0] == 2) {
            ans *= 6;
        } else if (arr[0] == 1) {
            ans *= 4;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
