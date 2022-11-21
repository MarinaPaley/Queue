#pragma once
#include "Element.h"
#include <initializer_list>
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
   * \brief ����� ���������� �������� � �������.
   * \return true, ���� ��������.
   */
	bool Add(Element* element) noexcept;

	/**
	* \brief �������� �� ������ �������.
	* \return true, ���� �������.
	*/
	Element* Remove() noexcept;
public:
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
	* \brief ����������, ������ �� �������.
	* \return true, ���� ������.
	*/
	bool IsEmpty() const noexcept;

	/**
	* \brief ������� �������.
	*/
	void Clear() noexcept;

	size_t GetSize() const noexcept;
};
