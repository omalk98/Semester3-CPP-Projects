//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       5 
// Date:		   Oct 11, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <utility>
#include <exception>
namespace sdds {
	template <typename T>
	class Collection
	{
		std::string m_name;
		T* m_collection;
		size_t m_size;
		void (*funcPtr)(const Collection<T>&, const T&);
		void reset() {
			delete[] m_collection;
			m_collection = nullptr;
		}
	public:
		Collection(const char* name = {}) {
			m_name = name;
			m_collection = nullptr;
			m_size = 0;
			funcPtr = nullptr;
		}
		Collection(const Collection<T>&) = delete;
		Collection<T>& operator=(const Collection<T>&) = delete;
		Collection(Collection<T>&& collection) { *this = std::move(collection); }
		Collection<T>& operator=(Collection<T>&& collection) {
			m_name = collection.m_name;
			m_size = collection.m_size;
			m_collection = collection.m_collection;
			collection.m_name = 0;
			collection.m_size = 0;
			collection.m_collection = nullptr;
		}
		~Collection() { reset(); }
		const std::string& name()const { return m_name; }
		size_t size()const { return m_size; }
		void setObserver(void (*observer)(const Collection<T>&, const T&)) { funcPtr = observer; }
		Collection<T>& operator+=(const T& item) {
			bool exists = false;
			for (size_t i = 0; i < m_size && !exists; ++i)
				exists = m_collection[i].title() == item.title();
			if (!exists) {
				T* temp{ nullptr };
				temp = new T [++m_size];

				if (m_size - 1)
					for (size_t i = 0; i < m_size - 1; ++i)
						temp[i] = m_collection[i];
				temp[m_size - 1] = item;
				reset();
				m_collection = std::move(temp);
				if (funcPtr) funcPtr(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx)const { 
			if (idx >= m_size) throw std::out_of_range{ "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items." };
			return m_collection[idx]; 
		}
		T* operator[](const std::string& title)const {
			bool exists = false;
			size_t idx = 0;
			for (; idx < m_size && !exists; ++idx) {
				exists = m_collection[idx].title() == title;
				if (exists) break;
			}
			return (exists) ? &m_collection[idx] : nullptr;
		}
		std::ostream& display(std::ostream& os) {
			for (size_t i = 0; i < m_size; ++i)
				os << m_collection[i];
			return os;
		}
	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, Collection<T>& collection) { return collection.display(os); }
}
#endif //!SDDS_COLLECTION_H