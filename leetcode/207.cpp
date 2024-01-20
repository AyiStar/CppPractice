// https://leetcode.com/problems/course-schedule
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <map>


class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        has_pred_ = std::vector<char>(numCourses, 0);
        visit_status_ = std::vector<char>(numCourses, 0);
        out_dict_.clear();
        for (int i = 0; i < numCourses; i++) {
            out_dict_.insert({i, std::vector<int>{}});
        }
        int m{static_cast<int>(prerequisites.size())};
        for (int i = 0; i < m; i++) {
            out_dict_.at(prerequisites[i][0]).push_back(prerequisites[i][1]);
            has_pred_[prerequisites[i][1]] = 1;
        }
        for (int i = 0; i < numCourses; i++) {
            if (has_pred_[i]) {
                continue;
            }
            if (dfs(i)) {
                return false;
            }
        }
        for (int status: visit_status_) {
            if (status == 0) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int vertex) {
        visit_status_[vertex] = 1;
        bool has_circle = false;
        for (int next: out_dict_[vertex]) {
            if (visit_status_[next] == 1) {
                return true;
            } else if (visit_status_[next] == 0) {
                has_circle = has_circle || dfs(next);
            }
        }
        visit_status_[vertex] = 2;
        return has_circle;
    }


    std::vector<char> has_pred_;
    std::vector<char> visit_status_;
    std::map<int, std::vector<int>> out_dict_;
};


TEST_CASE("SIMPLE_EXAMPLE") {
    std::vector<std::vector<int>> input1{{1, 0}};
    std::vector<std::vector<int>> input2{{1, 0}, {0, 1}};
    REQUIRE(Solution().canFinish(2, input1));
    REQUIRE(!Solution().canFinish(2, input2));
}
