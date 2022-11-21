#pragma once
/**
* \brief Элемент очереди.
*/
class Element
{
private:
	/**
	* \brief Значение элемента.
	*/
	int value;

public:
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
};