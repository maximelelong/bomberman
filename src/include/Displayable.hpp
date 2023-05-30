#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP

#include "SFMLRenderer.hpp"

class Displayable
{
public:

    virtual void display(SFMLRenderer& renderer) = 0;
};

#endif