#pragma once
#include<string>
/**
* \brief ������� �������.
*/
class Element
{
private:
	/**
	* \brief �������� ��������.
	*/
	int value;

public:
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
};