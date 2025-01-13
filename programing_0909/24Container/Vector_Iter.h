#pragma once

template<typename T>
class Vector
{
public:
	class Iterator
	{
	public:
		Iterator() : _ptr(nullptr) {}
		Iterator(T* ptr) { _ptr = ptr; }
		Iterator(const Iterator& other) { _ptr = other._ptr; }

		T& operator*() const
		{
			return *_ptr;
		}

		Iterator operator++(int)
		{
			Iterator result = Iterator(*this);
			result._ptr = _ptr++;			

			return result;
		}

		Iterator& operator++()
		{
			++_ptr;

			return *this;
		}

		bool operator==(const Iterator& other) const
		{
			return _ptr == other._ptr;
		}

		bool operator!=(const Iterator& other) const
		{
			return _ptr != other._ptr;
		}

	private:
		T* _ptr;
	};
	Iterator begin() { return Iterator(_data); }
	Iterator end() { return Iterator(&_data[_size]); }//fd로 밀려있는 접근금지 영역

	Vector() : _size(0), _capacity(0), _data(nullptr) {}
	~Vector()
	{
		_size = 0;
		_capacity = 0;
		delete _data;
	}

	void reserve(unsigned __int64 capacity)
	{
		// 기존에 수용량이 크거나 같았다.
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data != nullptr)
			delete _data;

		_data = newData;
	}

	void push_back(const T& data)
	{
		// 꽉차있는 경우
		if (_size == _capacity)
		{
			if (_capacity <= 1)
			{
				reserve(_capacity + 1);
			}
			else
				reserve(_capacity * 1.5f);
		}

		_data[_size] = data;

		_size++;
	}

	void pop_back()
	{
		--_size;
	}

	T operator[](unsigned __int64 index)
	{
		if (index >= _size)
		{
			// ERROR
			int* temp = (int*)0xDEADBEEF;
			(*temp) = 1;
		}

		return _data[index];
	}

	void clear()
	{
		_size = 0;
	}

	void insert(T value, unsigned __int64 index)
	{
		// 꽉차있는 경우
		if (_size == _capacity)
		{
			if (_capacity <= 1)
			{
				reserve(++_capacity);
			}
			else
				reserve(_capacity * 1.5f);
		}

		for (int i = index + 1; i < _size; i++)
		{
			_data[i + 1] = _data[i];
		}

		_data[index + 1] = value;
		_size++;
	}

	unsigned __int64 size() { return _size; }
	unsigned __int64 capacity() { return _capacity; }

private:
	unsigned __int64 _size;
	unsigned __int64 _capacity;
	T* _data;
};