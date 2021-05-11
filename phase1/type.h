#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

#include <string>

enum DataTypeCode {
    kInt = 0,
    kConst,
    kVoid
};

class DataType {
public:
    DataType(DataTypeCode code=kInt): data_(code) {}

    operator std::string() const {
        switch (code()) {
            case kInt: return "int";
            case kConst: return "const int";
            case kVoid: return "void";
        }
    }

    int code() const { return static_cast<int>(data_); }

    bool is_int() { return code() == kInt; }

private:
    DataTypeCode data_;
};

enum BinaryOpTypeCode {
    kAdd = 0,
    kSub,
    kMul,
    kDiv,
    kMod,
    kEQ,
    kNEQ,
    kLT,
    kGT,
    kLEQ,
    kGEQ,
    kAnd,
    kOr
};

class BinaryOpType {
public:
    BinaryOpType() {}
    BinaryOpType(BinaryOpTypeCode code): data_(code) {}

    operator std::string() const {
        switch (code()) {
            case kAdd: return "+";
            case kSub: return "-";
            case kMul: return "*";
            case kDiv: return "/";
            case kMod: return "%";
            case kEQ: return "==";
            case kNEQ: return "!=";
            case kLT: return "<";
            case kGT: return ">";
            case kLEQ: return "<=";
            case kGEQ: return ">=";
            case kAnd: return "&&";
            case kOr: return "||";
        }
    }

    int code() const { return static_cast<int>(data_); }

private:
    BinaryOpTypeCode data_;
};

#endif // _DATA_TYPE_H_