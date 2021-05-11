#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <type_traits>

class Object {
public:
    Object() {}

    Object(const Object& other) {}

    Object& operator=(const Object& other) {
        return *this;
    }
};

class ObjectRef {
public:
    ObjectRef() = default;

    explicit ObjectRef(Object* data): data_(data) {}

    bool operator==(const ObjectRef& other) const { return data_ == other.data_; }

    bool operator!=(const ObjectRef& other) const { return data_ != other.data_; }

    const Object* get() const { return static_cast<Object*>(data_); }

    const Object* operator->() const { return get(); }

protected:
    Object* data_;
};

#define DEFINE_OBJECT_REF_METHODS(ClassName, ParentClass, ObjectName)           \
    ClassName() = default;                                                      \
    explicit ClassName(Object* ptr): ParentClass(ptr) {}                        \
    ClassName(const ClassName& other) = default;                                \
    ClassName& operator=(const ClassName& other) = default;                     \
    ObjectName* operator->() const { return static_cast<ObjectName*>(data_); }  \
    const ObjectName* get() const { return static_cast<ObjectName*>(data_); }   \
    using ContainerType = ObjectName;

#endif // _OBJECT_H_