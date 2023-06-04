#include "Block.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
    bool result = true;
    
    // Tests constructor
    Block block(5, 3, true);
    result &= block.x() == 5;
    result &= block.y() == 3;
    result &= block.isDestructible() == true;

    if (result)
        std::cout << "Test constructor: OK" << std::endl;
    else {
        std::cout << "Test constructor: KO" << std::endl;
        return 1;
    }

    // test operator <<
    std::stringstream ss;
    ss << block;
    std::string expected = "Block: x=5, y=3, isDestructible=1";
    result &= ss.str() == expected;

    if (result)
        std::cout << "Test operator <<: OK" << std::endl;
    else {
        std::cout << "Test operator <<: KO" << std::endl;
        std::cout << "\t" << "Expected: '" << expected << "' but got '" << ss.str() << "'" << std::endl;
        return 1;
    }

    return 0;
}