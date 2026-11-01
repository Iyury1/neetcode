// Backtracking patterns: recursive DFS, explicit-stack DFS, and iterative enumeration.
// Compile: g++ -std=c++17 -O2 -Wall -Wextra -pedantic backtracking_patterns.cpp -o patterns
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// BEGIN subsets_recursive
Matrix subsetsRecursive(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    std::vector<int> path;

    auto dfs = [&](auto&& self, int start) -> void {
        result.push_back(path);  // Every node is a valid subset.
        for (int i = start; i < n; ++i) {
            path.push_back(nums[i]);
            self(self, i + 1);  // Only move forward: no reordering.
            path.pop_back();    // Undo the choice.
        }
    };

    dfs(dfs, 0);
    return result;
}
// END subsets_recursive

// BEGIN subsets_iterative_dfs
Matrix subsetsIterativeDFS(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    struct Frame { int next; };  // Next candidate in this call's for-loop.
    std::vector<Frame> stack{{0}};
    std::vector<int> path;
    Matrix result{{}};           // Emit the root: empty subset.

    while (!stack.empty()) {
        if (stack.back().next == n) {
            stack.pop_back();
            if (!stack.empty()) path.pop_back(); // Undo child choice.
            continue;
        }
        const int i = stack.back().next++;
        path.push_back(nums[i]);
        result.push_back(path);   // Emit on entry to the child.
        stack.push_back({i + 1}); // Simulate dfs(i + 1).
    }
    return result;
}
// END subsets_iterative_dfs

// BEGIN subsets_include_exclude
Matrix subsetsIncludeExclude(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    std::vector<int> path;

    auto dfs = [&](auto&& self, int i) -> void {
        if (i == n) {
            result.push_back(path);
            return;
        }
        self(self, i + 1);     // Exclude nums[i].
        path.push_back(nums[i]);
        self(self, i + 1);     // Include nums[i].
        path.pop_back();
    };

    dfs(dfs, 0);
    return result;
}
// END subsets_include_exclude

// BEGIN subsets_bitmask
Matrix subsetsBitmask(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n >= 64) throw std::length_error("64-bit mask supports n <= 63");
    Matrix result;
    const std::uint64_t count = std::uint64_t{1} << n;

    for (std::uint64_t mask = 0; mask < count; ++mask) {
        std::vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (std::uint64_t{1} << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(std::move(subset));
    }
    return result;
}
// END subsets_bitmask

// BEGIN combinations_recursive
Matrix combinationsRecursive(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    if (k < 0 || k > n) return result;
    std::vector<int> path;

    auto dfs = [&](auto&& self, int start) -> void {
        if (static_cast<int>(path.size()) == k) {
            result.push_back(path);  // Only size-k nodes are valid.
            return;
        }
        const int need = k - static_cast<int>(path.size());
        for (int i = start; i <= n - need; ++i) { // Prune short branches.
            path.push_back(nums[i]);
            self(self, i + 1);
            path.pop_back();
        }
    };

    dfs(dfs, 0);
    return result;
}
// END combinations_recursive

// BEGIN combinations_iterative_dfs
Matrix combinationsIterativeDFS(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    if (k < 0 || k > n) return result;
    struct Frame { int next; };
    std::vector<Frame> stack{{0}};
    std::vector<int> path;

    while (!stack.empty()) {
        if (static_cast<int>(path.size()) == k) {
            result.push_back(path);
            stack.pop_back();
            if (!stack.empty()) path.pop_back();
            continue;
        }
        const int need = k - static_cast<int>(path.size());
        if (stack.back().next > n - need) { // No valid choice left.
            stack.pop_back();
            if (!stack.empty()) path.pop_back();
            continue;
        }
        const int i = stack.back().next++;
        path.push_back(nums[i]);
        stack.push_back({i + 1});
    }
    return result;
}
// END combinations_iterative_dfs

// BEGIN combinations_lexicographic
Matrix combinationsLexicographic(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    if (k < 0 || k > n) return result;

    std::vector<int> idx(k);
    std::iota(idx.begin(), idx.end(), 0); // First: [0, 1, ..., k-1].
    while (true) {
        std::vector<int> combination;
        for (int i : idx) combination.push_back(nums[i]);
        result.push_back(std::move(combination));

        int p = k - 1;                  // Rightmost index we can increase.
        while (p >= 0 && idx[p] == n - k + p) --p;
        if (p < 0) break;               // Last combination was emitted.
        ++idx[p];
        for (int j = p + 1; j < k; ++j) idx[j] = idx[j - 1] + 1;
    }
    return result;
}
// END combinations_lexicographic

// BEGIN permutations_recursive
Matrix permutationsRecursive(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    Matrix result;
    std::vector<int> path;
    std::vector<bool> used(n, false);

    auto dfs = [&](auto&& self) -> void {
        if (static_cast<int>(path.size()) == n) {
            result.push_back(path); // A complete arrangement.
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            self(self);              // No start index: all unused choices.
            path.pop_back();
            used[i] = false;
        }
    };

    dfs(dfs);
    return result;
}
// END permutations_recursive

// BEGIN permutations_iterative_dfs
Matrix permutationsIterativeDFS(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    struct Frame {
        int next;     // Next index to test at this recursion level.
        int chosen;   // Index selected by the parent, or -1 for root.
    };
    std::vector<Frame> stack{{0, -1}};
    std::vector<int> path;
    std::vector<bool> used(n, false);
    Matrix result;

    while (!stack.empty()) {
        const bool complete = static_cast<int>(path.size()) == n;
        if (complete) result.push_back(path);
        if (complete || stack.back().next == n) {
            const int chosen = stack.back().chosen;
            stack.pop_back();
            if (chosen >= 0) {
                path.pop_back();
                used[chosen] = false;
            }
            continue;
        }
        const int i = stack.back().next++;
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        stack.push_back({0, i});   // Simulate recursive call.
    }
    return result;
}
// END permutations_iterative_dfs

// BEGIN permutations_next_permutation
Matrix permutationsNextPermutation(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end()); // Must start at first ordering.
    Matrix result;
    do {
        result.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    return result;
}
// END permutations_next_permutation

static Matrix canonical(Matrix m) {
    std::sort(m.begin(), m.end());
    return m;
}

int main() {
    for (const auto& nums : std::vector<std::vector<int>>{{}, {3}, {3, 1, 2}, {4, 2, 1, 3}}) {
        const auto expectedSubsets = canonical(subsetsRecursive(nums));
        assert(canonical(subsetsIterativeDFS(nums)) == expectedSubsets);
        assert(canonical(subsetsBitmask(nums)) == expectedSubsets);
        assert(canonical(subsetsIncludeExclude(nums)) == expectedSubsets);
        for (int k = 0; k <= static_cast<int>(nums.size()) + 1; ++k) {
            const auto expectedCombinations = canonical(combinationsRecursive(nums, k));
            assert(canonical(combinationsIterativeDFS(nums, k)) == expectedCombinations);
            assert(canonical(combinationsLexicographic(nums, k)) == expectedCombinations);
        }
        const auto expectedPermutations = canonical(permutationsRecursive(nums));
        assert(canonical(permutationsIterativeDFS(nums)) == expectedPermutations);
        assert(canonical(permutationsNextPermutation(nums)) == expectedPermutations);
    }
    assert(combinationsRecursive({1, 2}, -1).empty());
    assert(combinationsIterativeDFS({1, 2}, -1).empty());
    assert(combinationsLexicographic({1, 2}, -1).empty());
    std::cout << "All pattern implementations agree for distinct inputs.\n";
}
