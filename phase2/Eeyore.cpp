#include "Eeyore.hpp"

std::vector<EeyoreStatement *> eeyore_statements;
std::vector<EeyoreStatement *> eeyore_initializations;
std::map<std::string, FunctionAttributes> eeyore_functions;
Enviroment enviroment;

std::string Assignment::emit_tigger(Enviroment &env) {

}


std::string IfGoto::emit_tigger(Enviroment &env) {
    
}


std::string Label::emit_tigger(Enviroment &env) {
    
}


std::string PassParameter::emit_tigger(Enviroment &env) {
    
}


std::string CallFunction::emit_tigger(Enviroment &env) {
    
}


std::string Return::emit_tigger(Enviroment &env) {
    
}


std::string DefineVariable::emit_tigger(Enviroment &env) {
    
}


std::string FunctionHeader::emit_tigger(Enviroment &env) {
    
}


std::string FunctionEnd::emit_tigger(Enviroment &env) {
    
}