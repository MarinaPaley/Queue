#pragma once
#include "Element.h"
#include <initializer_list>
#include <string>

/**
* \brief Очередь.
*/
class Queue 
{
private:
	/**
	* \Конец очереди.
	*/
	Element* tail;

	/**
	* \brief Голова очереди.
	*/
	Element* head;

	/**
	* \brief Размер очереди.
	*/
	size_t size;

	/**
	* \brief Удаление из головы очереди.
	* \return true, если удалили.
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
	* \brief Инициализирует объект класса Очередь.
	*/
	Queue() noexcept;

	/**
	* \brief Инициализирует объект класса Очередь.
	* \param elements Элементы, которые будут в очереди.
	*/
	Queue(const std::initializer_list<int> elements) noexcept;

	/**
	* \brief Деструктор.
	*/
	~Queue();

	/**
	* \brief Метод добавления элемента в очередь.
	* \return true, если добавили.
	*/
	bool Push(Element* element) noexcept;

	/**
	* \brief Определяет, пустая ли очередь.
	* \return true, если пустая.
	*/
	bool IsEmpty() const noexcept;

	/**
	* \brief Очистка очереди.
	*/
	void Clear() noexcept;

	size_t GetSize() const noexcept;

	std::string ToString() const noexcept;

	Iterator cbegin() const;

	Iterator cend() const;
};

