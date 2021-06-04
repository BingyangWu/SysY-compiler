#include <string>
#include <iostream>

void emit_global_variable_declaration(std::string dst, std::string init_value) {
    std::string code = "";



    std::cout << code;
}

void emit_global_array_declaration(std::string dst, std::string array_size) {
    std::string code = "";


    
    std::cout << code;
}

void emit_function_header(std::string func_name, std::string param_num, std::string stack_size) {
    std::string code = "";


    
    std::cout << code;
}

void emit_function_end(std::string func_name) {
    std::string code = "";


    
    std::cout << code;
}

void emit_reg_binary_operation_reg(std::string dst, std::string src_reg1, std::string binop, std::string src_reg2) {
    std::string code = "";


    
    std::cout << code;
}

void emit_reg_binary_operation_imm(std::string dst, std::string src_reg, std::string binop, std::string src_imm) {
    std::string code = "";


    
    std::cout << code;
}

void emit_reg_not_reg(std::string dst, std::string src) {
    std::string code = "";


    
    std::cout << code;
}

void emit_assignment(std::string dst, std::string src) {
    std::string code = "";


    
    std::cout << code;
}

void emit_assignment_imm(std::string dst, std::string imm) {
    std::string code = "";


    
    std::cout << code;
}

void emit_array_assignment_reg(std::string array_name, std::string dim, std::string src) {
    std::string code = "";


    
    std::cout << code;
}

void emit_reg_assignment_array(std::string dst, std::string array_name, std::string dim) {
    std::string code = "";


    
    std::cout << code;
}

void emit_conditional_goto(std::string reg1, std::string binop, std::string reg2, std::string label) {
    std::string code = "";


    
    std::cout << code;
}

void emit_goto(std::string label) {
    std::string code = "";


    
    std::cout << code;
}

void emit_label(std::string label) {
    std::string code = "";


    
    std::cout << code;
}

void emit_call(std::string func_name) {
    std::string code = "";


    
    std::cout << code;
}

void emit_return() {
    std::string code = "";


    
    std::cout << code;
}

void emit_store(std::string reg, std::string offset) {
    std::string code = "";


    
    std::cout << code;
}

void emit_load_stack(std::string offset, std::string reg) {
    std::string code = "";


    
    std::cout << code;
}

void emit_load_variable(std::string global_var, std::string reg) {
    std::string code = "";


    
    std::cout << code;
}

void emit_loadaddr_stack(std::string offset, std::string reg) {
    std::string code = "";


    
    std::cout << code;
}

void emit_loadaddr_variable(std::string global_var, std::string reg) {
    std::string code = "";


    
    std::cout << code;
}