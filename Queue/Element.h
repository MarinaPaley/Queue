#pragma once
#include<string>
/**
* \brief Элемент очереди.
*/
struct Element
{
	/**
	* \brief Значение элемента.
	*/
	int value;

	/**
	* \brief Инициализирует объект класса Элемент.
	* \param value Значение элемента.
	*/
	Element(const int value) noexcept;

	/**
	* \brief Деструктор.
	*/
	~Element();

	/**
   * \brief Ссылка на предыдущий элемент.
   */
	Element* next;

	std::string ToString() const noexcept;

	bool operator ==(const Element& other);
	bool operator !=(const Element& other);
};