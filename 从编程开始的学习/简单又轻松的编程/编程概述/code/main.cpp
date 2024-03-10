#include <cstdlib>
#include <fstream>

#include "turing_machine.hpp"

auto GetConfigStr(const std::string &file_name) {
    std::ifstream f;
    f.open(file_name, std::ios::in);
    std::string tape_str, table_str;
    f >> tape_str >> table_str;
    f.close();
    return std::make_pair(tape_str, table_str);
}

int main(int argc, char *argv[]) {
    const auto [tape_str, table_str] = GetConfigStr("config");
    auto turing_machine = TuringMachine(tape_str, table_str);
    bool is_auto_run = false;

    if (argc >= 2) turing_machine.goto_start = atoi(argv[1]);
    if (argc >= 3) is_auto_run = atoi(argv[2]);

    if (is_auto_run) {
        if (argc >= 4)
            turing_machine.autoRun(atoi(argv[3]));
        else
            turing_machine.autoRun();
        return 0;
    }

    while (true) {
        turing_machine.show();
        getchar();
        const auto move = turing_machine.oneStep();
        if (move == MOVE::STOP) break;
    }
    turing_machine.show();

    return 0;
}
