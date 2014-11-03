#pragma once

template <typename T>
struct Node
{
	T m_data;
	Node* m_next;

	Node()
	{
		m_next = nullptr;
	}
};

template <typename T>
class LinkedList
{
	Node<T>* m_head;
	std::size_t m_size;

public:
	LinkedList();

	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void erase(const std::size_t& position);
	void erase(const T& value);
	void clear();
	bool search(const T& value) const;
	Node<T>* getHead() const;
	std::size_t size() const;
};

template<typename T> 
LinkedList<T>::LinkedList()
{
	m_size = 0;
	m_head = nullptr;
}

template<typename T> 
void LinkedList<T>::push_front(const T& data)
{
	Node<T>* newHead = new Node<T>();
	newHead->m_data = data;
	newHead->m_next = m_head;
	m_head = newHead;
	++m_size;
}

template<typename T> 
void LinkedList<T>::push_back(const T& data)
{
	Node<T>* tmp = m_head;
	Node<T>* node = new Node<T>();
	node->m_data = data;

	if (tmp == nullptr)
	{
		m_head = node;
	}
	else
	{
		while (tmp->m_next != nullptr)
		{
			tmp = tmp->m_next;
		}
		tmp->m_next = node;
	}
	++m_size;
}

template<typename T> 
void LinkedList<T>::pop_front()
{
	if (m_size == 0) return;
	Node<T>* tmp = m_head->m_next;
	delete m_head;
	m_head = tmp;
	--m_size;
}

template<typename T> 
void LinkedList<T>::pop_back()
{
	if (m_size == 0) return;
	if (m_size-- == 1)
	{
		delete m_head;
		m_head = nullptr;
		return;
	}
	Node<T>* tmp = m_head;
	Node<T>* tmp2 = nullptr;
	while (tmp->m_next != nullptr)
	{
		tmp2 = tmp;
		tmp = tmp->m_next;
	}
	delete tmp;
	tmp2->m_next = nullptr;
}

template<typename T> 
void LinkedList<T>::erase(const std::size_t& position)
{
	if (m_size == 0 || position >= m_size) return;

	if (position == 0 || m_size == 1)
	{
		return pop_front();
	}
	if (position == m_size - 1)
	{
		return pop_back();
	}

	// Now we got a position > 0 and < (m_size - 1) and two or more elements in the list
	Node<T>* tmp = m_head;
	Node<T>* tmpPrevious = nullptr;
	int counter = 0;
	while (tmp != nullptr)
	{
		++counter;
		tmpPrevious = tmp;
		tmp = tmp->m_next;
		if (counter == position)
		{
			tmpPrevious->m_next = tmp->m_next;
			delete tmp;
			--m_size;
			return;
		}
	}
}

template<typename T>
void LinkedList<T>::erase(const T& value)
{
	Node<T>* tmp = m_head;
	Node<T>* tmpPrevious = m_head;
	while (tmp != nullptr)
	{
		if (tmp->m_data == value)
		{
			if (tmp == tmpPrevious) // It's the front
			{
				return pop_front();
			}
			if (tmp->m_next == nullptr) // It's the back
			{
				return pop_back();
			}

			tmpPrevious->m_next = tmp->m_next;
			delete tmp;
			--m_size;
			return;
		}
		tmpPrevious = tmp;
		tmp = tmp->m_next;
	}
}

template<typename T> 
bool LinkedList<T>::search(const T& value) const
{
	Node<T>* tmp = m_head;
	while (tmp != nullptr)
	{
		if (tmp->m_data == value)
		{
			return true;
		}
		tmp = tmp->m_next;
	}
	return false;
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return m_head;
}

template<typename T> 
std::size_t LinkedList<T>::size() const
{
	return m_size;
}

template<typename T>
void LinkedList<T>::clear()
{
	Node<T>* next = m_head;
	Node<T>* toDelete = m_head;
	while (next != nullptr)
	{
		next = toDelete->m_next;
		delete toDelete;
		toDelete = next;
	}
	m_head = nullptr;
	m_size = 0;
}