#include <string>
#include <iostream>
#include <map>

int STK = -1;

void emit_global_variable_declaration(std::string dst, std::string init_value) {
    printf("  .global   %s\n"
           "  .section  .sdata\n"
           "  .align    2\n"
           "  .type     %s, @object\n"
           "  .size     %s, 4\n"
           "%s:\n"
           "  .word     %s\n\n", dst.c_str(), dst.c_str(), dst.c_str(), dst.c_str(), init_value.c_str());
}

void emit_global_array_declaration(std::string dst, std::string array_size) {
    printf("  .comm %s, %s, 4\n\n", dst.c_str(), array_size.c_str());
}

void emit_function_header(std::string func_name, std::string param_num, std::string stack_size) {
    STK = std::stoi(stack_size);
    STK = (STK / 4 + 1) * 16;

    printf("  .text\n"
           "  .align  2\n"
           "  .global %s\n"
           "  .type   %s, @function\n"
           "%s:\n"
           "  addi    sp, sp, -%d\n"
           "  sw      ra, %d-4(sp)\n\n", func_name.c_str(), func_name.c_str(), func_name.c_str(), STK, STK);
}

void emit_function_end(std::string func_name) {
    printf("  .size   %s, .-%s\n\n", func_name.c_str(), func_name.c_str());
}

std::string get_register_name(std::string name) {
    if (name[0] == 't') {
        int id = std::stoi(name.substr(1));
        return "t" + std::to_string(id + 1);
    }
    else return name;
}

void emit_reg_binary_operation_reg(std::string reg1, std::string reg2, std::string binop, std::string reg3) {
    static std::map<std::string, std::string> instruction_map = {
        {"+", "add"},
        {"-", "sub"},
        {"*", "mul"},
        {"/", "div"},
        {"%", "rem"},
        {"<", "slt"},
        {">", "sgt"}
    };
    reg1 = get_register_name(reg1);
    reg2 = get_register_name(reg2);
    reg3 = get_register_name(reg3);

    if (binop == "+" || binop == "-" || binop == "*" || binop == "/" || binop == "%" || binop == "<" || binop == ">") {
        printf("%s %s, %s, %s\n\n", instruction_map[binop].c_str(), reg1.c_str(), reg2.c_str(), reg3.c_str());
    }
    else if (binop == "<=") {
        printf("sgt %s, %s, %s\n"
               "seqz %s, %s\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
    else if (binop == ">=") {
        printf("slt %s, %s, %s\n"
               "seqz %s, %s\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
    else if (binop == "&&") {
        printf("snez %s, %s\n"
               "snez t0, %s\n"
               "and %s, %s, t0\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
    else if (binop == "||") {
        printf("or %s, %s, %s\n"
               "snez %s, %s\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
    else if (binop == "!=") {
        printf("xor %s, %s, %s\n"
               "snez %s, %s\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
    else if (binop == "==") {
        printf("xor %s, %s, %s\n"
               "seqz %s, %s\n\n", reg1.c_str(), reg2.c_str(), reg3.c_str(), reg1.c_str(), reg1.c_str());
    }
}

void emit_reg_binary_operation_imm(std::string dst, std::string src_reg, std::string binop, std::string src_imm) {
    printf("error!!!\n\n");
}

void emit_reg_not_reg(std::string dst, std::string src) {
    dst = get_register_name(dst);
    src = get_register_name(src);
    printf("seqz %s, %s\n\n", dst.c_str(), src.c_str());
}

void emit_assignment(std::string dst, std::string src) {
    dst = get_register_name(dst);
    src = get_register_name(src);
    printf("mv %s, %s\n\n", dst.c_str(), src.c_str());
}

void emit_assignment_imm(std::string dst, std::string imm) {
    dst = get_register_name(dst);
    printf("li %s, %s\n\n", dst.c_str(), imm.c_str());
}

void emit_array_assignment_reg(std::string array_name, std::string dim, std::string src) {
    array_name = get_register_name(array_name);
    dim = get_register_name(dim);
    src = get_register_name(src);
    int int12 = std::stoi(dim);

    if (int12 >= -2048 && int12 <= 2047) {
        printf("sw %s, %d(%s)\n\n", src.c_str(), int12, array_name.c_str());
    }
    else {
        printf("li t0, %d\n", int12);
        printf("sw %s, t0(%s)\n\n", src.c_str(), array_name.c_str());
    }
}

void emit_reg_assignment_array(std::string dst, std::string array_name, std::string dim) {
    dst = get_register_name(dst);
    array_name = get_register_name(array_name);
    dim = get_register_name(dim);
    int int12 = std::stoi(dim);

    if (int12 >= -2048 && int12 <= 2047) {
        printf("lw %s, %d(%s)\n\n", dst.c_str(), int12, array_name.c_str());
    }
    else {
        printf("li t0, %d\n", int12);
        printf("lw %s, t0(%s)\n\n", dst.c_str(), array_name.c_str());
    }
}

void emit_conditional_goto(std::string reg1, std::string binop, std::string reg2, std::string label) {
    static std::map<std::string, std::string> instruction_map = {
        {"<", "blt"},
        {">", "bgt"},
        {"<=", "ble"},
        {">=", "bge"},
        {"!=", "bne"},
        {"==", "beq"}
    };
    reg1 = get_register_name(reg1);
    reg2 = get_register_name(reg2);

    printf("%s %s, %s, .%s\n\n", instruction_map[binop].c_str(), reg1.c_str(), reg2.c_str(), label.c_str());
}

void emit_goto(std::string label) {
    printf("j .%s:\n\n", label.c_str());
}

void emit_label(std::string label) {
    printf(".%s:\n\n", label.c_str());
}

void emit_call(std::string func_name) {
    printf("call %s\n\n", func_name.c_str());
}

void emit_return() {
    printf("lw ra, %d-4(sp)\n"
           "addi sp, sp, %d\n"
           "ret\n\n", STK, STK);
}

void emit_store(std::string reg, std::string offset) {
    int int10 = std::stoi(offset);
    reg = get_register_name(reg);

    if (int10 >= -512 && int10 <= 511) {
        printf("sw %s, %d*4(sp)\n\n", reg.c_str(), int10);
    }
    else {
        printf("li t0, %d*4\n", int10);
        printf("sw %s, t0(sp)\n\n", reg.c_str());
    }
}

void emit_load_stack(std::string offset, std::string reg) {
    int int10 = std::stoi(offset);
    reg = get_register_name(reg);

    if (int10 >= -512 && int10 <= 511) {
        printf("lw %s, %d*4(sp)\n\n", reg.c_str(), int10);
    }
    else {
        printf("li t0, %d*4\n", int10);
        printf("lw %s, t0(sp)\n\n", reg.c_str());
    }
}

void emit_load_variable(std::string global_var, std::string reg) {
    reg = get_register_name(reg);
    
    printf("lui reg, %%hi(%s)\n"
           "lw reg, %%lo(%s)(%s)\n\n", global_var.c_str(), global_var.c_str(), reg.c_str());
}

void emit_loadaddr_stack(std::string offset, std::string reg) {
    int int10 = std::stoi(offset);
    reg = get_register_name(reg);

    if (int10 >= -512 && int10 <= 511) {
        printf("addi %s, sp, %d*4\n\n", reg.c_str(), int10);
    }
    else {
        printf("li t0, %d*4\n", int10);
        printf("add %s, sp, t0\n\n", reg.c_str());
    }
}

void emit_loadaddr_variable(std::string global_var, std::string reg) {
    reg = get_register_name(reg);

    printf("la %s, %s\n\n", reg.c_str(), global_var.c_str());
}