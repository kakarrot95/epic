#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree implementation
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    // Update the Fenwick Tree at index i by adding value
    void update(int i, int value) {
        i++; // Fenwick Tree is 1-indexed
        while (i < tree.size()) {
            tree[i] += value;
            i += i & -i; // Move to the parent in the binary representation of index i
        }
    }

    // Query the cumulative frequency up to index i
    int query(int i) {
        i++; // Fenwick Tree is 1-indexed
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i; // Move to the parent in the binary representation of index i
        }
        return sum;
    }
};

// Function to count the number of elements on the left that are smaller than the current element
vector<int> countSmallerOnLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result;
    FenwickTree fenwickTree(n);

    for (int i = 0; i < n; ++i) {
        result.push_back(fenwickTree.query(arr[i] - 1));
        fenwickTree.update(arr[i], 1);
    }

    return result;
}

int main() {
    // Example usage:
    vector<int> arr = {4, 2, 5, 1, 3};
    vector<int> result = countSmallerOnLeft(arr);

    cout << "Number of elements on the left that are smaller than the current element:\n";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
