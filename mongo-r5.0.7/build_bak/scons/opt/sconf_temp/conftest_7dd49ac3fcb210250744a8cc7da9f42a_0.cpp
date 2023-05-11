
class Base {
public:
    virtual void foo() const = 0;
protected:
    ~Base() {};
};

class Derived : public Base {
public:
    virtual void foo() const {}
};
