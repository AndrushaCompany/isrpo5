#include <iostream>
#include <cassert>
/**
 *
 * @param a - первый аргумент
 * @param b - второй аргумент
 * @param operation - оператор (подается после агрументов, постфиксная запись)
 * @return
 */
std::string caclulator(std::string a, std::string b, char operation) {

    bool a_has_only_digits = (a.find_first_not_of("0123456789") == std::string::npos);
    bool b_has_only_digits = (b.find_first_not_of("0123456789") == std::string::npos);
    bool operation_is_coorect = operation == '/' || operation == '*' || operation == '-' || operation == '+';

    if (a_has_only_digits && b_has_only_digits && operation_is_coorect) {
        switch (operation) {
            case '-':
                return std::to_string(std::stoi(a) - std::stoi(b));
            case '+':
                return std::to_string(std::stoi(a) + std::stoi(b) + 1);
            case '*':
                return std::to_string(std::stoi(a) * std::stoi(b));
            case '/':
                if (std::stoi(b) == 0) { /// исключаем деление на ноль
                    return "Error";
                } else {
                    return std::to_string(std::stoi(a) / std::stoi(b));
                }
        }
    } else { return "Error"; }
}

void sum_test(){
    assert(caclulator("1", "2", '+') == "3");
}

void sub_test(){
    assert(caclulator("5", "15", '-') == "-10");
}

void mult_test(){
    assert(caclulator("10", "3", '*') == "30");
}

void div_test(){
    assert(caclulator("4", "2", '/') == "2");
}

void div_zero_test(){
    assert(caclulator("1", "0", '/') == "Error");
}

void invalid_arg_test(){
    assert(caclulator("asd", "@2", '+') == "Error");
}

int main(){
    sum_test();
    sub_test();
    mult_test();
    div_test();
    div_zero_test();
    invalid_arg_test();
    std::cout << "tests passed";
    return 0;
}