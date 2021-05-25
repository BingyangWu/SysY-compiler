#ifndef _TIGGER_HPP_
#define _TIGGER_HPP_

#include <vector>
#include <map>
#include <string>


class Enviroment;
class EeyoreStatement {
public:
    virtual std::string emit_tigger(Enviroment &env) = 0;
};


class FunctionAttributes {
public:
    int start_pos, end_pos, stack_size;

    FunctionAttributes(): start_pos(0), end_pos(0), stack_size(0) {}
};


extern std::vector<EeyoreStatement *> eeyore_statements;
extern std::vector<EeyoreStatement *> eeyore_initializations;
extern std::map<std::string, FunctionAttributes> eeyore_functions;


class Enviroment {
public:
    std::string current_function;
    int global_variable_counter;
    std::map<std::string, std::string> variable_table;

    Enviroment(): current_function(""), global_variable_counter(0) {}

    void enter_function(std::string function_name, int lineno) {
        eeyore_functions[function_name].start_pos = lineno;
        current_function = function_name;
    }

    void exit_function(std::string function_name, int lineno) {
        eeyore_functions[function_name].end_pos = lineno;
        current_function = "";
    }

    void declare(std::string variable, int size) {
        if (current_function == "")
            variable_table[variable] = "v" + std::to_string(global_variable_counter++);
        else {
            int &offset = eeyore_functions[current_function].stack_size;
            variable_table[variable] = offset;
            offset += size;
        }
    }
};
extern Enviroment enviroment;


class Assignment : public EeyoreStatement {
public:
    std::string variable, dim, operand_one, binary_op, operand_two;

    Assignment(std::string variable, std::string dim, std::string operand_one, std::string binary_op, std::string operand_two):
        variable(variable), dim(dim), operand_one(operand_one), binary_op(binary_op), operand_two(operand_two) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


class IfGoto : public EeyoreStatement {
public:
    std::string label, operand_one, binary_op, operand_two;

    IfGoto(std::string label, std::string operand_one, std::string binary_op, std::string operand_two):
        label(label), operand_one(operand_one), binary_op(binary_op), operand_two(operand_two) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


class Label : public EeyoreStatement {
public:
    std::string label;

    Label(std::string label): label(label) {}

    virtual std::string emit_tigger(Enviroment &env);
};


class PassParameter : public EeyoreStatement {
public:
    std::string parameter;

    PassParameter(std::string parameter): parameter(parameter) {}

    virtual std::string emit_tigger(Enviroment &env);
};


class CallFunction : public EeyoreStatement {
public:
    std::string return_variable, function_name;

    CallFunction(std::string return_variable, std::string function_name):
        return_variable(return_variable), function_name(function_name) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


class Return : public EeyoreStatement {
public:
    std::string return_variable;

    Return(std::string return_variable): return_variable(return_variable) {}

    virtual std::string emit_tigger(Enviroment &env);
};


class DefineVariable : public EeyoreStatement {
public:
    std::string variable_name;
    int variable_size;

    DefineVariable(std::string variable_name, std::string variable_size):
        variable_name(variable_name), variable_size(std::stoi(variable_size)) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


class FunctionHeader : public EeyoreStatement {
public:
    std::string function_name;
    int parameters_num;

    FunctionHeader(std::string function_name, std::string parameters_num):
        function_name(function_name), parameters_num(std::stoi(parameters_num)) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


class FunctionEnd : public EeyoreStatement {
public:
    std::string function_name;

    FunctionEnd(std::string function_name):
        function_name(function_name) {}
    
    virtual std::string emit_tigger(Enviroment &env);
};


#endif