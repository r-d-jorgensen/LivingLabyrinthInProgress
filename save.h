#pragma once
#include <iostream>
#include <fstream>
#include "char.h"

std::ostream & operator << (std::ostream &out, const character & in);

std::istream & operator >> (std::istream & in, character & out);

void saveout(character & in, std::string txt);

character savein(std::string txt);


