#ifndef _TIGGER_HPP_
#define _TIGGER_HPP_

#include <vector>
#include <map>
#include <string>
#include <iostream>


class Enviroment;
class EeyoreStatement {
public:
    virtual std::string emit_tigger(Enviroment &env) = 0;
};


class FunctionAttributes {
public:
    int start_pos, end_pos, stack_size, paramter_num;

    FunctionAttributes(): start_pos(0), end_pos(0), stack_size(0), paramter_num(0) {}
};


extern std::vector<EeyoreStatement *> eeyore_statements;
extern std::vector<EeyoreStatement *> eeyore_initializations;
extern std::map<std::string, FunctionAttributes> eeyore_functions;


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

    DefineVariable(std::string variable_name, int variable_size):
        variable_name(variable_name), variable_size(variable_size) {}
    
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


class Enviroment {
public:
    std::string current_function;
    int global_variable_counter;
    std::map<std::string, std::string> variable_table;
    std::map<std::string, std::string> register_files;
    std::map<std::string, int> variable_type;
    int parameter_id;

    Enviroment(): current_function(""), global_variable_counter(0), parameter_id(0) {
        for (int i = 0; i < 7; ++i) {
            register_files["t"+std::to_string(i)] = "";
        }

        for (int i = 0; i < 8; ++i) {
            register_files["a"+std::to_string(i)] = "p" + std::to_string(i);
        }

        for (int i = 0; i < 8; ++i) {
            variable_table["p"+std::to_string(i)] = std::to_string(i);
            variable_table["a"+std::to_string(i)] = std::to_string(i);
        }
    }

    void enter_function(std::string function_name, std::string parameter_num, int lineno) {
        eeyore_functions[function_name].start_pos = lineno;
        eeyore_functions[function_name].stack_size = 8;
        eeyore_functions[function_name].paramter_num = std::stoi(parameter_num);
        current_function = function_name;
    }

    void exit_function(std::string function_name, int lineno) {
        eeyore_functions[function_name].end_pos = lineno;
        current_function = "";
    }

    void declare(std::string variable, int size) {
        if (current_function == "") {
            variable_table[variable] = "v" + std::to_string(global_variable_counter++);
            
            eeyore_statements.push_back(new DefineVariable(variable, size));
        }
        else {
            int &offset = eeyore_functions[current_function].stack_size;
            variable_table[variable] = std::to_string(offset);
            offset += size > 0 ? size / 4 : 1;
        }

        variable_type[variable] = size > 0;
    }

    bool is_array(std::string var_name) {
        if (var_name[0] == 'p')
            return false;
        return variable_type[var_name] > 0;
    }

    std::string find_register() {
        for (int i = 0; i < 7; ++i) {
            std::string register_name = "t"+std::to_string(i);
            if (register_files[register_name] == "") {
                register_files[register_name] = "-";
                return register_name;
            }
        }

        std::cerr << "get register fail!\n";
        return "error";
    }

    std::string lookup_table(std::string var_name) {
        if (var_name[0] >= '0' && var_name[0] <= '9')
            return var_name;
        return variable_table[var_name];
    }

    std::string get_register(std::string var, std::string &code_segment) {
        // if (opt && var[0] != 't' && var[0] != 'T' && var[0] != 'p') 
        //     return var;
        
        std::string empty_register = "";

        if (var[0] == 'p') {
            empty_register = var;
            empty_register[0] = 'a';
            return empty_register;
        }

        empty_register = find_register();
        
        register_files[empty_register] = var;
        if (var[0] >= '0' && var[0] <= '9')
            code_segment += empty_register + " = " + var + "\n";
        else
            code_segment += "load " + lookup_table(var) + " " + empty_register + "\n";
        return empty_register;
    }

    std::string get_parameter_register(std::string &code_segment) {
        if (parameter_id == 0) {
            for (int i = 0; i < 8; ++i) {
                code_segment += "store a" + std::to_string(i) + " " + std::to_string(i) + "\n";
            }
        }
        std::string parameter_register = "a" + std::to_string(parameter_id++);
        return parameter_register;
    }

    void release_register(std::string register_name) {
        if (register_name[0] != 'a') {
            register_files[register_name] = "";
        }
    }
};
extern Enviroment enviroment;


#endif