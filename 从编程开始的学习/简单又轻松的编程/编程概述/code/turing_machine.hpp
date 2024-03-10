#ifndef TURING_MACHINE_HPP
#define TURING_MACHINE_HPP

#include <array>
#include <string>
#include <vector>

std::vector<std::string> StringSplit(const std::string &str, char delim);

void GotoXY(int x, int y);

enum BIT { ZERO, ONE };
enum MOVE { LEFT, RIGHT, ERROR, STOP };
enum STATE { A, B, C, D, SIZE };

struct Head {
    STATE state;
    size_t tape_index = 0;
};

struct Table {
    struct Data {
        STATE next_state;
        BIT next_val;
        MOVE move;
    };
    std::array<std::array<Table::Data, 2>, STATE::SIZE> data;
};

using Tape = std::vector<BIT>;

class TuringMachine {
   public:
    bool goto_start = false;
    explicit TuringMachine(const std::string &tape_str,
                           const std::string &table_str, const STATE head_init);
    explicit TuringMachine(const std::string &tape_str,
                           const std::string &table_str);
    void show();
    void autoRun();
    void autoRun(size_t milliseconds);
    MOVE oneStep();

   private:
    void init(const std::string &tape_str, const std::string &table_str,
              const STATE head_init);
    MOVE getTableMove(char c);
    Tape initTape(const std::string &tape_str);
    Table initTable(const std::string &table_str);
    Tape tape_;
    Head head_;
    Table table_;
};

#endif  // !TURING_MACHINE_HPP
