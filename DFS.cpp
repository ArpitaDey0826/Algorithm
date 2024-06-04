#include <iostream>
#include <vector>

using namespace std;

// Depth-First Search (DFS) to generate all permutations
void dfsPermutations(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if the current permutation is complete
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    // Explore all possible choices for the next element in the permutation
    for (int i = 0; i < nums.size(); ++i) {
        if (!visited[i]) {
            // Choose nums[i] as the next element in the permutation
            visited[i] = true;
            current.push_back(nums[i]);

            // Recursively generate permutations
            dfsPermutations(nums, visited, current, result);

            // Backtrack: remove the last added element
            current.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<bool> visited(nums.size(), false);
    vector<int> current;
    vector<vector<int>> result;

    // Generate all permutations using DFS
    dfsPermutations(nums, visited, current, result);

    // Output all permutations
    cout << "All permutations of {1, 2, 3, 4, 5}:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

