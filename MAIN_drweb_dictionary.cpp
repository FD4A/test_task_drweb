#include <iostream>
#include "concrete_dictionary.hpp"

void test_simple();
void test_exception();
void test_simple_string_and_struct();
void test_exception_string_and_struct();

int main(int argc, char **argv)
{
    test_simple();
    test_exception();
    test_simple_string_and_struct();
    test_exception_string_and_struct();
    return 0;
}
