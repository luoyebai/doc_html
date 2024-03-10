// STD
#include <array>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

// TURING MACHINE
#include "turing_machine.hpp"

std::vector<std::string> StringSplit(const std::string &str, char delim) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) elems.push_back(item);
    }
    return elems;
}

void GotoXY(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
    return;
}

TuringMachine::TuringMachine(const std::string &tape_str,
                             const std::string &table_str,
                             const STATE head_init) {
    this->init(tape_str, table_str, head_init);
    return;
}

TuringMachine::TuringMachine(const std::string &tape_str,
                             const std::string &table_str) {
    this->init(tape_str, table_str, STATE::A);
    return;
}

void TuringMachine::show() {
    if (this->goto_start) GotoXY(0, 0);
    std::string put_head(tape_.size(), ' ');
    put_head[head_.tape_index] = static_cast<char>(head_.state + 'A');
    std::cout << put_head << "\n";
    put_head[head_.tape_index] = '|';
    std::cout << put_head << "\n";
    for (const auto val : tape_) std::cout << val;
    std::cout << "\n";
    return;
}

MOVE TuringMachine::oneStep() {
    const auto table_data = this->table_.data;
    auto &index = this->head_.tape_index;
    auto &state = this->head_.state;
    auto &val = this->tape_[index];
    const auto next_state = table_data[state][val].next_state;
    const auto next_val = table_data[state][val].next_val;
    const auto move = table_data[state][val].move;
    if (move == MOVE::ERROR) return MOVE::ERROR;
    if (move == MOVE::RIGHT) ++index;
    if (move == MOVE::LEFT) --index;
    // At tape end -> tape add zero
    if (index == this->tape_.size()) {
        this->tape_.push_back(BIT::ZERO);
        this->tape_[index - 1] = next_val;
    } else {
        val = next_val;
    }
    state = next_state;
    return move;
}

MOVE TuringMachine::getTableMove(char c) {
    assert(c == 'L' || c == 'R' || c == 'E' || c == 'S');
    switch (c) {
        case 'L':
            return MOVE::LEFT;
        case 'R':
            return MOVE::RIGHT;
        case 'E':
            return MOVE::RIGHT;
        case 'S':
            return MOVE::STOP;
    }
    return MOVE();
}

Tape TuringMachine::initTape(const std::string &tape_str) {
    Tape tape;
    for (const auto c : tape_str) {
        assert(c == '0' || c == '1');
        if (c == '0')
            tape.push_back(BIT::ZERO);
        else
            tape.push_back(BIT::ONE);
    }
    return tape;
}

Table TuringMachine::initTable(const std::string &table_str) {
    Table table;
    const auto &str_vec = StringSplit(table_str, ',');
    assert(str_vec.size() == 2 * (STATE::SIZE));
    size_t state_index = 0;
    bool val_index = 0;
    for (const auto str : str_vec) {
        assert(str.size() == 3);
        assert(str[0] >= 'A' && str[0] <= 'Z');
        assert(str[1] == '0' || str[1] == '1');
        auto data = Table::Data();
        data.next_state = STATE(str[0] - 'A');
        data.next_val = BIT(str[1] - '0');
        data.move = getTableMove(str[2]);
        table.data[state_index][val_index] = data;
        state_index += val_index;
        val_index = !val_index;
    }
    return table;
}

void TuringMachine::init(const std::string &tape_str,
                         const std::string &table_str, const STATE head_init) {
    this->head_ = Head{head_init};
    this->tape_ = this->initTape(tape_str);
    this->table_ = this->initTable(table_str);
    return;
}

void TuringMachine::autoRun() {
    this->autoRun(500);
    return;
}

void TuringMachine::autoRun(size_t milliseconds) {
    while (true) {
        this->show();
        const auto move = this->oneStep();
        if (move == MOVE::ERROR) {
            std::cout << "Error\n";
            return;
        }
        if (move == MOVE::STOP) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
    this->show();
    return;
}
