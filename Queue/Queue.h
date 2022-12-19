#pragma once
#include "Element.h"
#include <initializer_list>
#include <string>

/**
* \brief �������.
*/
class Queue 
{
private:
	/**
	* \����� �������.
	*/
	Element* tail;

	/**
	* \brief ������ �������.
	*/
	Element* head;

	/**
	* \brief ������ �������.
	*/
	size_t size;

	/**
	* \brief �������� �� ������ �������.
	* \return true, ���� �������.
	*/
	Element* Remove() noexcept;

public:
	class Iterator
	{
	public:
		explicit Iterator(Element*);
		~Iterator() = default;

		Iterator operator++();
		int operator*() const;
		bool operator==(Iterator& const other);
		bool operator!=(Iterator& const other);

	private:
		Element* current;
	};

	/**
	* \brief �������������� ������ ������ �������.
	*/
	Queue() noexcept;

	/**
	* \brief �������������� ������ ������ �������.
	* \param elements ��������, ������� ����� � �������.
	*/
	Queue(const std::initializer_list<int> elements) noexcept;

	/**
	* \brief ����������.
	*/
	~Queue();

	/**
	* \brief ����� ���������� �������� � �������.
	* \return true, ���� ��������.
	*/
	bool Push(Element* element) noexcept;

	/**
	* \brief ����������, ������ �� �������.
	* \return true, ���� ������.
	*/
	bool IsEmpty() const noexcept;

	/**
	* \brief ������� �������.
	*/
	void Clear() noexcept;

	size_t GetSize() const noexcept;

	std::string ToString() const noexcept;

	Iterator cbegin() const;

	Iterator cend() const;
};

