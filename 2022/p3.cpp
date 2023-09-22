#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

class compare {
    public:
        bool operator()(const std::pair<int32_t, int32_t> &a, const std::pair<int32_t, int32_t> &b) {
            return a.second > b.second;
        }
};
int main() {
    std::unordered_map<std::string, std::pair<int32_t, int32_t>> ans;
    std::unordered_map<int32_t, std::string> ind_map;
    std::string temp;

    for (int32_t i = 0 ; i < 4 ; i++) {
        std::getline(std::cin, temp);
        std::pair<int32_t, int32_t> tp = std::make_pair(0, 0);

        ans[temp] = tp;
        ind_map[3 - i] = temp;
    }

    for (int32_t i = 0 ; i < 6 ; i++) {
        char tp;

        std::string team_a;
        int32_t score_a = 0;

        std::string team_b;
        int32_t score_b = 0;

        std::cin >> team_a >> score_a >> tp >> score_b >> team_b;
        std::getline(std::cin, temp);

        if (score_a > score_b) {
            ans[team_a].first += 3;
        } else if (score_a == score_b) {
            ans[team_a].first += 1;
            ans[team_b].first += 1;
        } else {
            ans[team_b].first += 3;
        }
        ans[team_a].second += (score_a - score_b);
        ans[team_b].second += (score_b - score_a);
    }

    std::vector<std::pair<int32_t, int32_t>> arr;


    int32_t i = 0;
    for (auto& [key, value] : ans) {
        arr.emplace_back(std::make_pair(i++, value.first * 100 + value.second));
    }

    std::sort(arr.begin(), arr.end(), compare());

    for (auto& [ind, value] : arr) {
        std::cout << ind_map[ind] << " " << ans[ind_map[ind]].first << " " << ans[ind_map[ind]].second << std::endl;
    }

    return 0;
}
 
