#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

void GotoXY(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
    return;
}

void ShowVecInt(const std::vector<int>& v) {
    for (const auto x : v) std::cout << x << " ";
    std::cout << "\n";
    return;
}

int main(int argc, char* argv[]) {
    system("clear");
    std::vector<int> v{0, 0, 0, 0, 0};
    for (size_t i = 0; i < 10; ++i) {
        auto& x = v[i];
        GotoXY(0, 0);
        ShowVecInt(v);
        getchar();
        if (i == v.size()) v.push_back(0);
        v[i] = -1;
        x = 1;
        std::cout << &x << " " << &(v[i]);
    }
    return 0;
}
