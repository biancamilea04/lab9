#include <iostream>
#include <tuple>

template <class K, class V>
class Map {
	K key[1024];
	V val[1024];
	int size;
public:
	Map(): size(0) {};


	void Set(K KEY, V VALUE) {
		int sw = 0;

		for (int i = 0; i < size; i++) {
			if (key[i] == KEY) {
				sw = 1;
				val[i] = VALUE;
				break;
			}
		}

		if (sw == 0) {
			key[size] = KEY;
			val[size] = VALUE;
			size++;
	   }

	};
	bool Get(const K& KEY, V& VALUE) {

		for (int i = 0; i < size; i++) {
			if (key[i] == KEY) {
				VALUE = val[i];
				return true;
			}
		}
		return false;
	}

	int Count() {
		return size;
	}
	void Clear() {
	  
		size = 0;
	}

	bool Delete(const K& KEY) {

		for (int i = 0; i < size; i++) {
			if (key[i] == KEY) {
				for (int j = i; j < size - 1; j++) {
					key[j] = key[j + 1];
					val[j] = val[j + 1];
				}
				size--;
				return true;
			}	
		}
		return false;

	}

	V& operator[](K KEY) {

		for (int i = 0; i < size; i++) {
			if (key[i] == KEY)
				return val[i];
		}

		key[size] = KEY;
		size++;
		return val[size - 1];

	};

	bool Includes(const Map<K, V>& map) {
		if (size != map.size)
			return false;
		for (int i = 0; i < size; i++) {
			if (key[i] != map.key[i]) {
				return false;
			}
		}

		return true;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << " m[ " << key[i] << " ] = " << val[i] << std::endl;
		}
	}

	class MyIterator {
		K *keyPtr;
		V *valPtr;
		int index;
	public:
		MyIterator(K* k, V* v, int i) : keyPtr(k), valPtr(v), index(i) {}

		MyIterator& operator++() {
			index++;
			return *this;
		}
		bool operator!=(MyIterator Other) {
			return index != Other.index;
		}

		std::tuple<K&, V&, int> operator*() {
			return { keyPtr[index], valPtr[index], index };
		}

	};

	MyIterator begin() {
		return MyIterator(key, val, 0);
	}

	MyIterator end() {
		return MyIterator(key, val, size);
	}

};