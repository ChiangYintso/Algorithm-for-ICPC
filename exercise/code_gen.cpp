//
// Created by Jiang Yinzuo on 2020/8/21.
//

#include <cstdio>
#include <array>
#include <stack>
#include <string>
#include <unordered_map>

struct Expression {
    std::string opcode, operand1, operand2, result;
} exp_list[100];

static int nxq = 0;

enum Type {
    INT, CHAR, BOOL
};

enum StatType {
    VAR, TYPE, COMMA, COLON, N, T, D
};

class Statement {
public:
    StatType type;
    std::string name;
    std::string att;
    std::string place;
};

namespace var {

struct VarInfo {
    unsigned long addr;
    Type type;
};

static unsigned long addr = 0x1;
static std::unordered_map<std::string, VarInfo> var_list;

inline void fill(std::string &var, Type type) {
    var_list[var] = {addr++, type};
}

inline unsigned long entry(std::string &var) {
    return var_list[var].addr;
}

}

#define ST_LIST_LEN 8

class Reducer {
private:
    std::array<Statement, ST_LIST_LEN> &st_list;
    static StatType re_list[][10];
public:
    Reducer(std::array<Statement, ST_LIST_LEN> &st_list) : st_list(st_list) {}

    void check_reduce() {

    }

    void reduce() {
        if (st_list.empty()) return;
        std::stack<Statement> reduce_stack;

        reduce_stack.push(*st_list.begin());
        auto iter = st_list.begin() + 1;
        while (!(reduce_stack.size() == 1 && reduce_stack.top().type == StatType::N)) {
            check_reduce();
            if (iter != st_list.end()) {
                reduce_stack.push(*(iter++));
            }
        }

    }
};

StatType Reducer::re_list[][10] = {
        {StatType::TYPE},
        {StatType::VAR, StatType::COLON, StatType::T},
        {StatType::VAR, StatType::COMMA, StatType::D},
        {StatType::D}
};

int main() {
    std::array<Statement, ST_LIST_LEN> tk_list = {{{StatType::VAR, "x"},
                                                          {StatType::COMMA},
                                                          {StatType::VAR, "y"},
                                                          {StatType::COMMA},
                                                          {StatType::VAR, "z"},
                                                          {StatType::COLON},
                                                          {StatType::TYPE, "real"}}};
    Reducer reducer(tk_list);
    reducer.reduce();
    return 0;
}