#pragma once
#include<string>
/**
* \brief ������� �������.
*/
struct Element
{
	/**
	* \brief �������� ��������.
	*/
	int value;

	/**
	* \brief �������������� ������ ������ �������.
	* \param value �������� ��������.
	*/
	Element(const int value) noexcept;

	/**
	* \brief ����������.
	*/
	~Element();

	/**
   * \brief ������ �� ���������� �������.
   */
	Element* next;

	std::string ToString() const noexcept;

	bool operator ==(const Element& other);
	bool operator !=(const Element& other);
};