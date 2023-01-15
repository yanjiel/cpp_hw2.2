#include <iostream>
#include <vector>  
#include <algorithm> 

double median1(std::vector<double> vec) {
    std::sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 1) {
        return vec[vec.size() / 2];
    }
    else {
        return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
    }
}

double median2(std::vector<double> vec) {
    if (vec.size() % 2 == 1) {
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2 + 1, vec.end());
        return vec[vec.size() / 2];
    }
    else {
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2 + 1, vec.end());
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2, vec.begin() + vec.size() / 2 + 1);
        return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
    }
}

double median3(std::vector<double> vec) {
    if (vec.size() % 2 == 1) {
        std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
        return vec[vec.size() / 2];
    }
    else {
        std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());
        std::nth_element(vec.begin(), vec.begin() + vec.size() / 2 - 1, vec.begin() + vec.size() / 2);
        return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
    }
}

template<typename T>
T median4(std::vector<T> vec) {
    if (vec.size() % 2 == 1) {
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2 + 1, vec.end());
        return vec[vec.size() / 2];
    }
    else {
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2 + 1, vec.end());
        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2, vec.begin() + vec.size() / 2 + 1);
        return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2;
    }
}

int main() {
    double input;
    std::vector<double> vec;

    std::cout << "please input some doubles to calc median for:" << std::endl;
    while (std::cin >> input) {
        vec.push_back(input);
    };

    std::cout << "Median calced by full sort is:" << median1(vec) << std::endl;
    std::cout << "Median calced by partial sort is:" << median2(vec) << std::endl;
    std::cout << "Median calced by nth_element is:" << median3(vec) << std::endl;
    std::cout << "Median calced by function template is:" << median4(vec) << std::endl;

    return 0;
}