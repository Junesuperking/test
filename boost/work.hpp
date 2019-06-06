#ifndef _WORK_
#define _WORK_
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

extern volatile bool flag;

typedef boost::shared_ptr<boost::thread> thread_ptr;

class Work{
	public:
		Work();
		~Work();
		bool Start();
		void Stop();

	private:
		//由于成员函数隐式默认有this指针参数，线程无法绑定函数，所以，此处函数声明为静态函数，显式带一个this指针参数
		static void run(Work* self);

	//线程相关
	private:
		thread_ptr main_thread;
		volatile bool thread_flag;

	private:
		int count;
		int time_interval;

};
#endif
