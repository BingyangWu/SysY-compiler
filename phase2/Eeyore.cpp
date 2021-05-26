#include "Eeyore.hpp"
#include <string>

std::vector<EeyoreStatement *> eeyore_statements;
std::vector<EeyoreStatement *> eeyore_initializations;
std::map<std::string, FunctionAttributes> eeyore_functions;
Enviroment enviroment;

std::string Assignment::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Assignment " + variable + " " + dim + " " + operand_one + " " + binary_op + " " + operand_two + "\n";
    return code_segment;
}


std::string IfGoto::emit_tigger(Enviroment &env) {
    std::string code_segment = "// IfGoto " + label + " " + operand_one + " " + binary_op + " " + operand_two + "\n";
    return code_segment;
}


std::string Label::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Label " + label + "\n";
    return code_segment;
}


std::string PassParameter::emit_tigger(Enviroment &env) {
    std::string code_segment = "// PassParameter " + parameter + "\n";
    return code_segment;
}


std::string CallFunction::emit_tigger(Enviroment &env) {
    std::string code_segment = "// CallFunction " + return_variable + " " + function_name + "\n";
    return code_segment;
}


std::string Return::emit_tigger(Enviroment &env) {
    std::string code_segment = "// Return " + return_variable + "\n";
    return code_segment;
}


std::string DefineVariable::emit_tigger(Enviroment &env) {
    std::string code_segment = "// DefineVariable " + variable_name + " " + std::to_string(variable_size) + "\n";
    return code_segment;
}


std::string FunctionHeader::emit_tigger(Enviroment &env) {
    std::string code_segment = "// FunctionHeader " + function_name + " " + std::to_string(parameters_num) + "\n";
    return code_segment;
}


std::string FunctionEnd::emit_tigger(Enviroment &env) {
    std::string code_segment = "// FunctionEnd " + function_name + "\n";
    return code_segment;
}