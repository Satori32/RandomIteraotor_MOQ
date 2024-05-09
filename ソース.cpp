#include <iostream>
#include <random>

//not good.
//i hope to make to iterator type RandomFlow.
//extramely bad.baaaaaaaaaaaaaaaad,

template<class T>
class RandomNumberIterator {
public:
	typename T::result_type operator()() {
		R = E();
		C++;
		return E;
	}
	RandomNumberIterator<T>& operator++() {
		R = E();
		C++;
		return *this;
	}
	RandomNumberIterator<T>& operator++(int) {
		R = E();
		C++;
		return *this;
	}

	typename T::result_type operator *() {
		return R;
	}

	typename T::result_type Role(std::size_t Co, bool IsReset) {
		if (IsReset) { E.seed(D); }

		for (std::size_t i = 0; i < Co; i++) {
			(*this)();
		}

		return R;

	}
protected:
	//std::uint32_t D =typename decltype(T)::default_seed;
	std::uint32_t D = 15;
	T E;
	typename T::result_type R = 0;
	std::uintmax_t C = 0;

};

int main() {
	RandomNumberIterator<std::mt19937> X;
	
	for (std::uintmax_t i = 0; i < 16; i ++){
		std::cout << *X << std::endl;
		X++;
	}

	return 0;

}