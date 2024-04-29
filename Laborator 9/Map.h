#pragma once


template
<typename T, typename T2>
class Map
{
public:
	struct Element
	{
		T key;
		T2 value;
		int index;
	};
private:
	Element* v;
	int elements, current;
	int getPosition(const T& key);
public:

	void Set(T key, T2 value);
	Map();
	bool Get(const T& key, T2& value);
	int Count();
	bool Delete(const T& key);
	T2& operator[] (const T& key);
	Element*  begin();
	Element*  end();
};



template<typename T, typename T2>
inline int Map<T, T2>::getPosition(const T& key)
{
	for (int i = 0; i < current; i++)
		if (v[i].key == key)
			return i;
	return -1;
}

template<typename T, typename T2>
inline void Map<T, T2>::Set(T key, T2 value)
{
	int pos = getPosition(key);
	if (pos != -1)
		v[pos].value = value;
	else {
		if (current == elements) {
			Element* v1 = new Element[elements * 2];
			for (int i = 0; i < elements; i++)
				v1[i] = v[i];
			delete[] v;
			v = v1;
		}
		v[current] = { key, value , current};
		current++;
	}
}

template<typename T, typename T2>
inline Map<T, T2>::Map()
{
	elements = 1;
	current = 0;
	v = new Element[elements];
}

template<typename T, typename T2>
inline bool Map<T, T2>::Get(const T& key, T2& value)
{
	int pos = getPosition(key);
	if (pos == -1) return false;
	value = v[pos].value;
	return true;
}

template<typename T, typename T2>
inline int Map<T, T2>::Count()
{
	return current;
}

template<typename T, typename T2>
inline bool Map<T, T2>::Delete(const T& key)
{
	int pos = getPosition(key);
	if (pos == -1) return false;
	for (int j = pos; j + 1 < current; j++) {
		swap(v[j], v[j + 1]);
		v[j].index--;
	}
	current--;
	return true;
}

template<typename T, typename T2>
inline T2& Map<T, T2>::operator[](const T& key)
{
	int pos = getPosition(key);
	if (pos == -1) 
		Set(key, nullptr);
	pos = getPosition(key);
	return v[pos].value;
}

template<typename T, typename T2>
inline typename Map<T, T2>::Element* Map<T, T2>::begin()
{
	return &v[0];
}

template<typename T, typename T2>
inline typename Map<T,T2>::Element* Map<T, T2>::end()
{
	return &v[current];
}

