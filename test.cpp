#include <string>
#include <cassert>
#include "concrete_dictionary.hpp"

void test_simple()
{
    std::cout << "start " << __FUNCTION__ << '\n';
    concrete_dictionary<std::string,std::string> D;

    std::string red("RED");
    std::string xred("#FF0000");
    std::string green("GREEN");
    std::string xgreen("#00FF00");
    std::string blue("BLUE");
    std::string xblue("#0000FF");
    std::string white("WHITE");

    std::cout << D;

    D.set(red, xred);
    D.set(green, xgreen);
    D.set(blue, xblue);

    assert( true==D.is_set(red) );
    assert( true==D.is_set(green) );
    assert( true==D.is_set(blue) );
    assert( false==D.is_set(white) );

    std::string colorR = D.get(red);
    std::string colorG = D.get(green);
    std::string colorB = D.get(blue);

    assert( xred==colorR );
    assert( xgreen==colorG );
    assert( xblue==colorB );

    std::cout << "[OK] finish " << __FUNCTION__ << "()\n";
}

void test_exception()
{
    std::cout << "start " << __FUNCTION__ << '\n';
    concrete_dictionary<std::string,std::string> D;

    std::string red("RED");
    std::string xred("#FF0000");
    std::string green("GREEN");
    std::string xgreen("#00FF00");
    std::string blue("BLUE");
    std::string xblue("#0000FF");
    std::string white("WHITE");

    std::cout << D;

    D.set(red, xred);
    D.set(green, xgreen);
    D.set(blue, xblue);

    assert( true==D.is_set(red) );
    assert( true==D.is_set(green) );
    assert( true==D.is_set(blue) );
    assert( false==D.is_set(white) );

    std::string colorR = D.get(red);
    std::string colorG = D.get(green);
    std::string colorB = D.get(blue);

    try
    {
        std::string colorW = D.get(white);
    }
    catch ( const not_found_exception_mydict<std::string>& msg )
    {
        std::cout << "[OK] finish " << __FUNCTION__ << "()\n";
    }
}




