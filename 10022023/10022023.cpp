#include <iostream>
#include <thread>
#include <chrono>



//Многопоточные приложения
//параллелизм  и конкурентность. Parallelism and Concurrency
//параллелизм ускоряет выполнение программы



void work() {
	std::cout << "Work started!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::cout << "Work thread:" << std::this_thread::get_id();
	std::cout<<"Work ended!" << std::endl;

}






int main() {

	

	std::cout << "Main thread" << std::this_thread::get_id() << std::endl;
	std::thread t1(work);
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	std::thread t2(work);
	std::cout << "Hello!" << std::endl;

	//race condition - гонка данных
	int x = 1;


	t1.join();
	t2.join();





}