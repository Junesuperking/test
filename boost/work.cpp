#include "work.hpp"
#include <iostream>
#include <unistd.h>

Work::Work() {
	count = 0;
	time_interval = 1;
	thread_flag = true;
}

Work::~Work() {

}

bool Work::Start() {
	main_thread.reset(new boost::thread(boost::bind(&run, this)));
	return true;
}

void Work::Stop() {
	if (thread_flag) {
		thread_flag = false;
		main_thread->join();
	}
	return;
}

void Work:: run(Work* self) {
	while (flag) {
		//业务逻辑
		std::cout << self->count << std::endl;
		//boost::this_thread::sleep_for(boost::chrono::milliseconds(self->time_interval));
		//sleep(2);
		boost::this_thread::sleep(boost::posix_time::seconds(self->time_interval));
		self->count ++;
	}
	return;
}
