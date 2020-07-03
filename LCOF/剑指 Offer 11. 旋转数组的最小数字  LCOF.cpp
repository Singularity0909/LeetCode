// Version 1
class Solution {
public:
    int minArray(vector<int>& numbers) {
        return *min_element(numbers.begin(), numbers.end());
    }
};

// Version 2
class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (size_t i = 0; i < numbers.size() - 1; i++)
            if (numbers[i] > numbers[i + 1])
                return numbers[i + 1];
        return numbers[0];
    }
};

// Version 3
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] < numbers[right])
                right = mid;
            else if (numbers[mid] > numbers[right])
                left = mid + 1;
            else
                right--;
        }
        return numbers[left];
    }
};