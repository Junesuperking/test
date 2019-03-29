#include <iostream>
#include <thread>
#include <mutex>

#define N 100

using namespace std;

std::mutex mtx;
volatile int counter = 0;

void CalcFunc() {
	for (auto i = 0; i < N; ++i) {
		if (mtx.try_lock()) 
		{
		//	mtx.lock();
			++counter;
			mtx.unlock();
		}
	}
}

int main(void) {

	std::thread threads[10];

	for (auto i = 0; i < 10; ++ i) {
		threads[i] = std::thread(CalcFunc);
	}

	//for (auto& th : threads) th.join();
	for (auto& th : threads) {
		th.join();
	}
	cout << counter << " success increase the counter\n";

	return 0;
}
