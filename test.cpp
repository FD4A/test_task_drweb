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

    std::cout << D;
    std::cout << "[OK] finish " << __FUNCTION__ << "()\n" << std::endl;
}

void test_exception()
{
    std::cout << "start " << __FUNCTION__ << '\n';
    concrete_dictionary<std::string,std::string> D;
    std::string white("WHITE");

    try
    {
    	std::string colorW = D.get(white);
    }
    catch ( const not_found_exception_mydict<std::string>& msg )
    {
    	std::cerr << "not_found_exception_mydict " << msg.get_key() << '\n';
    	std::flush(std::cerr);
    	std::cout << "[OK] finish " << __FUNCTION__ << "()\n" << std::endl;
    	return;
    }
    bool resul_test_exception = false;
    assert(resul_test_exception);
}


struct color
{
	unsigned char r=255;
	unsigned char g=255;
	unsigned char b=255;
	color() = default;
	color(unsigned char r_, unsigned char g_, unsigned char b_): r{r_}, g{g_}, b{b_}
		{}

	bool operator==(const color& c) const
	{
		if(r==c.r && g==c.g && b==c.b)
			{return true;}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const color& c)
	{
		os << static_cast<unsigned int>(c.r) << ' ' << static_cast<unsigned int>(c.g) << ' ' << static_cast<unsigned int>(c.b);
		return os;
	}
};
void test_simple_string_and_struct()
{
    std::cout << "start " << __FUNCTION__ << '\n';

    concrete_dictionary<std::string,color> D;

    std::string red("RED");
    color sred(255,0,0);
    std::string green("GREEN");
    color sgreen(0,255,0);
    std::string blue("BLUE");
    color sblue(0,0,255);
    std::string white("WHITE");

    D.set(red, sred);
    D.set(green, sgreen);
    D.set(blue, sblue);

    assert( true==D.is_set(red) );
    assert( true==D.is_set(green) );
    assert( true==D.is_set(blue) );
    assert( false==D.is_set(white) );

    color colorR = D.get(red);
    color colorG = D.get(green);
    color colorB = D.get(blue);

    assert( sred==colorR );
    assert( sgreen==colorG );
    assert( sblue==colorB );

    std::cout << D;
    std::cout << "[OK] finish " << __FUNCTION__ << "()\n\n";
}

void test_exception_string_and_struct()
{
    std::cout << "start " << __FUNCTION__ << '\n';
    concrete_dictionary<std::string,color> D;
    std::string white("WHITE");

    try
    {
    	color colorW = D.get(white);
    }
    catch ( const not_found_exception_mydict<std::string>& msg )
    {
    	std::flush(std::cout);
    	std::cerr << "not_found_exception_mydict " << msg.get_key() << '\n';
    	std::flush(std::cerr);
    	std::cout << "[OK] finish " << __FUNCTION__ << "()\n" << std::endl;
    	return;
    }
    bool test_exception_string_and_struct = false;
    assert(test_exception_string_and_struct);
}
