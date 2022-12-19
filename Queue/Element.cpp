#include <sstream>
#include "Element.h"

Element::Element(const int value) noexcept
	: value(value), next(nullptr) 
{
}

Element::~Element()
{
	this->next = nullptr;
}

std::string Element::ToString() const noexcept
{
	std::stringstream buffer;
	buffer << this->value;
	return buffer.str();
}

bool Element::operator==(const Element& other)
{
	return this->value == other.value;
}

bool Element::operator!=(const Element& other)
{
	return this->value == other.value;
}
