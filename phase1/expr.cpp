#include "expr.h"
#include <assert.h>

Imm::Imm(DataType dtype, int value) {
    assert(dtype.is_int());
    ImmNode* data = new ImmNode();
    data->dtype = dtype;
    data->value = value;
    data_ = std::move(data);
}