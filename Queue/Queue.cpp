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
		this->Add(element);
	}
}

Queue::~Queue()
{
	this->Clear();
}

bool Queue::Add(Element* element) noexcept
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
