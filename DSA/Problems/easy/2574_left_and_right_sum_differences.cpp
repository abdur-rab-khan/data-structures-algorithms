
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

struct SumDifferences {
   private:
    std::vector<int> numbers;

   public:
    SumDifferences(const std::vector<int>& nums) { numbers = nums; }

    std::vector<int> leftRightDifference() {
        std::vector<int> diffArray(numbers.size());

        int prefix = 0;
        int suffix = std::accumulate(numbers.begin(), numbers.end(), 0);

        for (int i = 0; i < numbers.size(); i++) {
            suffix -= numbers[i];
            int diff = abs(prefix - suffix);

            diffArray[i] = diff;
            prefix += numbers[i];
        }

        return diffArray;
    }

    void print(const std::vector<int>& numbers) {
        std::cout << "Sum difference are: ";
        for (const int& n : numbers) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> numbers = {10, 4, 8, 3};
    std::unique_ptr<SumDifferences> sumDiff = std::make_unique<SumDifferences>(numbers);

    sumDiff->print(sumDiff->leftRightDifference());

    return 0;
}