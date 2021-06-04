#ifndef _RISCV_HPP_
#define _RISCV_HPP_

#include <string>

void emit_global_variable_declaration(std::string dst, std::string init_value);

void emit_global_array_declaration(std::string dst, std::string array_size);

void emit_function_header(std::string func_name, std::string param_num, std::string stack_size);

void emit_function_end(std::string func_name);

void emit_reg_binary_operation_reg(std::string dst, std::string src_reg1, std::string binop, std::string src_reg2);

void emit_reg_binary_operation_imm(std::string dst, std::string src_reg, std::string binop, std::string src_imm);

void emit_reg_not_reg(std::string dst, std::string src);

void emit_assignment(std::string dst, std::string src);

void emit_assignment_imm(std::string dst, std::string imm);

void emit_array_assignment_reg(std::string array_name, std::string dim, std::string src);

void emit_reg_assignment_array(std::string dst, std::string array_name, std::string dim);

void emit_conditional_goto(std::string reg1, std::string binop, std::string reg2, std::string label);

void emit_goto(std::string label);

void emit_label(std::string label);

void emit_call(std::string func_name);

void emit_return();

void emit_store(std::string reg, std::string offset);

void emit_load_stack(std::string offset, std::string reg);

void emit_load_variable(std::string global_var, std::string reg);

void emit_loadaddr_stack(std::string offset, std::string reg);

void emit_loadaddr_variable(std::string global_var, std::string reg);

#endif