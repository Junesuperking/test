#include <iostream>
#include <signal.h>
#include <unistd.h>

#include "work.hpp"

using namespace std;

volatile bool flag = true;

void func(int signum) {
	flag = false;
}

int main(void)
{
	//捕捉信号，注册函数，修改flag的值
	signal(SIGINT, func);
	//SIGKILL 这个信号不能被捕获或忽略，同时接收这个信号的进程在收到这个信号时不能执行任何清理
	//signal(SIGKILL, func);
	signal(SIGSEGV, func);
	signal(SIGTERM, func);
	signal(SIGQUIT, func);
	Work a;
	a.Start();

	while (flag) {
		cout << "hello world" << endl;
		sleep(2);
	}
	cout << "exit begin" << endl;
	a.Stop();
	return 0;
}
