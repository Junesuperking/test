#include <iostream>
#include <list>
#include <map>

#include <time.h>

#define N 4

using namespace std;

class LRU {
	public:
		LRU(int);
		~LRU();
	public:
		void refer(int);
		void display();
	private:
		int size;
		list<int> cache;
		map<int, list<int>::iterator> ma;
};

LRU::LRU(int n):size(n){

}

LRU::~LRU() {

}

void LRU::refer(int value) {
	if (ma.find(value) == ma.end()) {
		if (cache.size() == size) {
			int last = cache.back();
			cache.pop_back();
			ma.erase(last);
		}
	}
	else {
		cache.erase(ma[value]);
	}
	cache.push_front(value);
	ma[value] = cache.begin();
}

void LRU::display() {
	for (auto it = cache.begin(); it != cache.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}


int main() {
	srand(time(NULL));
	LRU ca(3);
	for (int i = 0; i < N; ++i) {
		int tmp = rand() % 10 + 1;
		cout << tmp << " ";
		ca.refer(tmp);
	}
	cout << endl;
	ca.display();

	return 0;
}
