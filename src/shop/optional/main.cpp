#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> InitVectorInt1000() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1000, 2000);
    std::vector<int> res;

    for (int n = 0; n < 1000; ++n)
        res.push_back(distrib(gen));

    return res;
}

bool IsEven(const int i) {
    return i % 2 == 0;
}

int main() {

    std::vector<int> vec_a = InitVectorInt1000();
    std::vector<int> vec_b = vec_a;
    std::vector<int> vec_c = vec_a;

    std::cout << "-> starting remove vec_b even elements with erase()" << std::endl;
    auto time_start = std::chrono::high_resolution_clock::now();
    auto it = vec_b.begin();
    while (it != vec_b.end()) {
        if (IsEven(*it)) {
            it = vec_b.erase(it);
        }
        else {
            ++it;
        }
    }
    auto time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_b even elements with erase() is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    std::cout << "-> starting remove vec_c even elements with erase(remove_if())" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    vec_c.erase(std::remove_if(vec_c.begin(), vec_c.end(), IsEven), vec_c.end());
    time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_c even elements with erase(remove_if()) is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    vec_b = vec_a;
    vec_c = vec_a;
    vec_b[777] = vec_c[777] = 2500;

    std::cout << "-> starting remove vec_b[777] with erase()" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    vec_b.erase(vec_b.begin() + 777);
    time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_b[777] with erase() is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    std::cout << "-> starting remove vec_c[777] elements with erase(remove())" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    vec_c.erase(std::remove(vec_c.begin(), vec_c.end(), 2500), vec_c.end());
    time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_c[777] elements with erase(remove()) is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    vec_b = std::vector<int>(1000, 1500);
    vec_c = vec_b;

    std::cout << "-> starting remove vec_b [250:] elements with erase()" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    vec_b.erase(vec_b.begin() + 250, vec_b.end());
    time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_b [250:] elements with erase() is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    std::cout << "-> starting remove vec_c [250:] elements with erase(remove())" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    vec_c.erase(std::remove(vec_c.begin() + 250, vec_c.end(), 1500), vec_c.end());
    time_end = std::chrono::high_resolution_clock::now();
    std::cout << "-> removing vec_c [250:] elements with erase(remove()) is complete. Total time: "
        << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count() << "ms."
        << std::endl;

    return 0;
}
