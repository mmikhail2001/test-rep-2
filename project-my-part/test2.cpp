#include <iostream>
#include <vector>

struct A 
{ 
    virtual void a() = 0;
};

struct B
{ 
    virtual void b() = 0;
};

struct C : A, B
{
    virtual void b() override { puts("Bb"); }
    virtual void a() override { puts("Aa"); }
};

void bar(B *b)
{
    b->b();
}

void foo(A *a)
{
    a->a();
    B *b = dynamic_cast<B *>(a);
    bar(b);
}

int main()
{
    C c;
    foo(&c);
}