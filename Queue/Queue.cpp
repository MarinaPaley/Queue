#include <sstream>
#include "Queue.h"

Queue::Queue() noexcept
	: tail(nullptr), head(nullptr), size(0)
{
}

Queue::Queue(const std::initializer_list<int> elements) noexcept
	: Queue()
{
	for (auto it = elements.begin(); it != elements.end(); it++)
	{
		auto element = new Element(*it);
		this->Push(element);
	}
}

Queue::~Queue()
{
	this->Clear();
}

bool Queue::Push(Element* element) noexcept
{
	if (this->IsEmpty())
	{
		this->tail = this->head = element;
		this->size++;
		return true;
	}

	this->tail->next = element;
	this->tail = this->tail->next;
	this->size++;
	return true;
}

Element* Queue::Remove() noexcept
{
	auto temp = this->head;
	this->head = this->head->next;
	this->size--;
	return temp;
}

bool Queue::IsEmpty() const noexcept
{
	return this->head == nullptr;
}

void Queue::Clear() noexcept
{
	while (!this->IsEmpty())
	{
		this->Remove();
	}
}

size_t Queue::GetSize() const noexcept
{
	return this->size;
}

std::string Queue::ToString() const noexcept
{
	std::stringstream buffer;
	buffer << "{ ";
	auto temp = this->head;
	while (temp->next != nullptr)
	{
		buffer << temp->ToString() << ", ";
		temp = temp->next;
	}
	buffer << temp->ToString() << " }";

	return buffer.str();
}

Queue::Iterator Queue::cbegin() const
{
	return Iterator(this->head);
}

Queue::Iterator Queue::cend() const
{
	return Iterator(this->tail->next);
}


Queue::Iterator::Iterator(Element* element) : current(element)
{
}


Queue::Iterator Queue::Iterator::operator++()
{
	current = current->next;
	return Iterator(this->current);
}

int Queue::Iterator::operator*() const
{
	return this->current->value;
}

bool Queue::Iterator::operator==(Iterator& const other)
{
	return this->current == other.current;
}

bool Queue::Iterator::operator!=(Iterator& const other)
{
	return this->current != other.current;
}

