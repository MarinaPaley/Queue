#include "Element.h"

Element::Element(const int value) noexcept
	: value(value), next(nullptr) 
{
}

Element::~Element()
{
	this->next = nullptr;
}
