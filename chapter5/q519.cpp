#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

void Disp(std::vector<double> &in_vec)
{
    // Generate 20 columns.
    double min = *std::min_element(in_vec.begin(), in_vec.end());
    double max = *std::max_element(in_vec.begin(), in_vec.end());
    std::vector<double> columns;
    double interval = (max - min)/38;
    double col_min = min - interval;
    for (int i = 0; i < 20; i++) {
        columns.push_back(col_min);
        col_min += 2*interval;
    }

    // Count elements.
    std::vector<int> count(20, 0);
    std::for_each(in_vec.begin(), in_vec.end(),
        [&count, &min, &interval](double &x)
        {
            count[ceil((x - min)/interval)/2]++;
        });
    
    // Regularize count.
    double count_segment = double(*std::max_element(count.begin(), count.end()))/60;
    std::for_each(count.begin(), count.end(),
        [&count_segment](int &x)
        {
            x /= count_segment;
        });
    
    // Output.
    for (int i = 0; i < 20; i++) {
        std::cout.width(8);
        std::cout << std::fixed << std::setprecision(2)
            << columns[i] + interval << "  ";
        for (int j = 0; j < count[i]; j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::mt19937 rand_seed(std::random_device{}());
    std::uniform_real_distribution<> uni_gen(-10.0, 10.0);
    double mean = uni_gen(rand_seed);
    std::normal_distribution<double> normal_gen(mean, 1.0);
    std::vector<double> test_vec;
    for (int i = 0; i < 1'000'000; i++) {
        test_vec.push_back(normal_gen(rand_seed));
    }
    Disp(test_vec);
    return 0;
}
