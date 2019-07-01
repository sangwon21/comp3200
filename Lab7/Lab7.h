#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		unsigned int length = keys.size() > values.size() ? values.size() : keys.size();

		for (unsigned int i = 0; i < length; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto i = m.begin(); i != m.end(); ++i)
		{
			v.push_back(i->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto i = m.begin(); i != m.end(); ++i)
		{
			v.push_back(i->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		for (auto i = v.rbegin(); i != v.rend(); ++i)
		{
			rv.push_back((*i));
		}
		return rv;
	}
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> combined;

	std::vector<T>::iterator iter;
	for (unsigned int i = 0; i < v1.size(); i++)
	{
		iter = find(combined.begin(), combined.end(), v1[i]);
		if (iter == combined.end())
		{
			combined.push_back(v1[i]);
		}
	}
	for (unsigned int i = 0; i < v2.size(); i++)
	{
		iter = find(combined.begin(), combined.end(), v2[i]);
		if (iter == combined.end())
		{
			combined.push_back(v2[i]);
		}
	}
	return combined;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	std::map<K, V> combined;
	std::map<K, V>::iterator iter;

	for (auto i = m1.begin(); i != m1.end(); ++i)
	{
		iter = combined.find(i->first);
		if (iter == combined.end())
		{
			combined.insert(std::pair<K, V>(i->first, i->second));
		}
	}

	for (auto i = m2.begin(); i != m2.end(); ++i)
	{
		iter = combined.find(i->first);
		if (iter == combined.end())
		{
			combined.insert(std::pair<K, V>(i->first, i->second));
		}
	}
	return combined;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		os << v[i] << ", ";
		if (i == v.size() - 1)
		{
			os << v[i];
		}
	}
	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
	for (auto i = m.begin(); i != m.end(); ++i)
	{
		os << "{ " << i->first << ", " << i->second << " }" << std::endl;
	}
	return os;
}