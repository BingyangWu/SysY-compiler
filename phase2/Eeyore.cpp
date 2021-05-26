#include "Eeyore.hpp"
#include <string>

std::vector<EeyoreStatement *> eeyore_statements;
std::vector<EeyoreStatement *> eeyore_initializations;
std::map<std::string, FunctionAttributes> eeyore_functions;
Enviroment enviroment;

std::string Assignment::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Assignment " + variable + " " + dim + " " + operand_one + " " + binary_op + " " + operand_two + "\n";
    
    if (binary_op == "[]") { // variable = operand_one[operand_two]

    }
    else if (dim != "") { // variable[dim] = operand_one

    }
    else {
        if (binary_op == "") { // variable = operand_one

        }
        else if (operand_two == "") { // variable = binary_op operand_one

        }
        else { // variable = operand_one binary_op operand_two

        }
    }
    
    return code_segment;
}


std::string IfGoto::emit_tigger(Enviroment &env) {
    std::string code_segment = "// IfGoto " + label + " " + operand_one + " " + binary_op + " " + operand_two + "\n";
    
    if (binary_op != "") {
        std::string register_one = env.get_register(operand_one, code_segment);
        std::string register_two = env.get_register(operand_two, code_segment);
        code_segment += "if " + register_one + " " + binary_op + " " + register_two + " ";
    }
    code_segment += "goto " + label + "\n";

    return code_segment;
}


std::string Label::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Label " + label + "\n";

    code_segment += label + ":\n";

    return code_segment;
}


std::string PassParameter::emit_tigger(Enviroment &env) {
    std::string code_segment = "// PassParameter " + parameter + "\n";

    std::string register_name = env.get_parameter_register();
    code_segment += "store " + register_name + " " + env.variable_table[register_name] + "\n";
    code_segment += "load " + env.variable_table[parameter] + " " + register_name + "\n";

    return code_segment;
}


std::string CallFunction::emit_tigger(Enviroment &env) {
    std::string code_segment = "// CallFunction " + return_variable + " " + function_name + "\n";
    
    code_segment += "call " + function_name + "\n";
    if (return_variable != "") {
        code_segment += "store a0 " + env.variable_table[return_variable] + "\n";
    }

    for (int i = 0; i < env.parameter_id; ++i) {
        code_segment += "load " + std::to_string(i) + " a" + std::to_string(i) + "\n";
    }
    env.parameter_id = 0;

    return code_segment;
}


std::string Return::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Return " + return_variable + "\n";

    if (return_variable != "") {
        code_segment += "load " + env.variable_table[return_variable] + " a0\n";
    }
    code_segment += "return\n";

    return code_segment;
}


std::string DefineVariable::emit_tigger(Enviroment &env) {
    std::string code_segment = "// DefineVariable " + variable_name + " " + std::to_string(variable_size) + "\n";

    if (variable_size) {
        code_segment += env.variable_table[variable_name] + " = malloc " + std::to_string(variable_size) + "\n";
    }
    else {
        code_segment += env.variable_table[variable_name] + " = 0\n";
    }

    return code_segment;
}


std::string FunctionHeader::emit_tigger(Enviroment &env) {
    std::string code_segment = "// FunctionHeader " + function_name + " " + std::to_string(parameters_num) + "\n";
    code_segment += function_name + " [" + std::to_string(parameters_num) + "] [" + std::to_string(eeyore_functions[function_name].stack_size) + "]\n";
    return code_segment;
}


std::string FunctionEnd::emit_tigger(Enviroment &env) {
    std::string code_segment = "// FunctionEnd " + function_name + "\n";
    code_segment += "end " + function_name + "\n";
    return code_segment;
}