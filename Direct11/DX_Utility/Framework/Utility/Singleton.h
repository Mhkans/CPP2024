#pragma once
// Singleton 디자인 패턴을 이용하기 위해,
// 템플릿 클래스로서 Singleton을 적요이킨 클래스를 만들어두고
// 이 디자인 패턴을 적용시킬 클래스에 상속해서 이용
template<typename T>
class Singleton
{
protected:
	static T* instance;

public:
	static T* Get()
	{
		if (instance == nullptr)
			instance = new T();

		return instance;
	}

	static void Delete() { delete instance; }
};

template<typename T>
T* Singleton<T>::instance = NULL;