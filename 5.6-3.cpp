// 5.6-3.cpp 



#include <iostream>

template <class T>
class vector {
private:
	T* arr;
	unsigned int using_index;
	unsigned int size;

public:
	vector() {
		arr = new T[3];
		using_index = 0;
		size = 3;
	}

	void push_back(T value) {
		if (size - 1 < using_index) {
			T* copy_arr = new T[size];
			std::swap(copy_arr, arr);

			delete[] arr;

			size += 3;

			arr = new T[size];
			for (int i = 0; i < size - 3; i++) {
				arr[i] = copy_arr[i];
			}

			delete[] copy_arr;
		}

		arr[using_index++] = value;
	}

	T at(int index) const {
		if (index >= using_index || index < 0) throw std::runtime_error("this index doesn't exist");

		return arr[index];
	}

	int sizee() const {
		return using_index;
	}

	int capacity() const {
		return size;
	}

	~vector() {
		delete[] arr;
	}
};

int main() {
	try {
		vector<int> Z;

		Z.push_back(2);
		Z.push_back(3);
		Z.push_back(2);
		Z.push_back(3);

		std::cout << Z.at(2) << " " << Z.capacity() << " " << Z.sizee();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}