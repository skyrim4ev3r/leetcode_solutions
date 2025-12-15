class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        const size_t len{arr.size()};

        if (len < 3 || arr[1] <= arr[0] || arr[len - 1] >= arr[len - 2]) {
            return false;
        }

        size_t index{1};

        while (index < len && arr[index] > arr[index - 1]) {
            index += 1;
        }

        if (index == 1 || index == len || arr[index] == arr[index - 1]) {
            return false;
        }

        while (index < len && arr[index] < arr[index - 1]) {
            index += 1;
        }

        return index == len;
    }
};
