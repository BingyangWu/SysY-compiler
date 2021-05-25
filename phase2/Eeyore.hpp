#ifndef _TIGGER_HPP_
#define _TIGGER_HPP_

#include <vector>
#include <map>
#include <string>


class EeyoreStatement {
public:
};


class Assignment : public EeyoreStatement {
public:
    std::string variable, dim, operand_one, binary_op, operand_two;

    Assignment(std::string variable, std::string dim, std::string operand_one, std::string binary_op, std::string operand_two):
        variable(variable), dim(dim), operand_one(operand_one), binary_op(binary_op), operand_two(operand_two) {}
};


class IfGoto : public EeyoreStatement {
public:
    std::string label, operand_one, binary_op, operand_two;

    IfGoto(std::string label, std::string operand_one, std::string binary_op, std::string operand_two):
        label(label), operand_one(operand_one), binary_op(binary_op), operand_two(operand_two) {}
};


class Label : public EeyoreStatement {
public:
    std::string label;

    Label(std::string label): label(label) {}
};


class PassParameter : public EeyoreStatement {
public:
    std::string parameter;

    PassParameter(std::string parameter): parameter(parameter) {}
};


class CallFunction : public EeyoreStatement {
public:
    std::string return_variable, function_name;

    CallFunction(std::string return_variable, std::string function_name):
        return_variable(return_variable), function_name(function_name) {}
};


class Return : public EeyoreStatement {
public:
    std::string return_variable;

    Return(std::string return_variable): return_variable(return_variable) {}
};


class DefineVariable : public EeyoreStatement {
public:
    std::string variable_name;
    int variable_size;

    DefineVariable(std::string variable_name, std::string variable_size):
        variable_name(variable_name), variable_size(std::stoi(variable_size)) {}
};


class FunctionHeader : public EeyoreStatement {
public:
    std::string function_name;
    int parameters_num;

    FunctionHeader(std::string function_name, std::string parameters_num):
        function_name(function_name), parameters_num(std::stoi(parameters_num)) {}
};


class FunctionEnd : public EeyoreStatement {
public:
    std::string function_name;

    FunctionEnd(std::string function_name):
        function_name(function_name) {}
};


class FunctionAttributes {
public:
    int start_pos, end_pos, stack_size;
};


extern std::vector<EeyoreStatement *> eeyore_statements;
extern std::vector<EeyoreStatement *> eeyore_initializations;
extern std::map<std::string, FunctionAttributes> eeyore_functions;

#endif