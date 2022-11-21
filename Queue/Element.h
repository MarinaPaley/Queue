#pragma once
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
};