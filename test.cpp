//// chronometer.cpp
////
//
//#include <iostream>
//#include <chrono>
//
//using namespace std;
//using namespace std::chrono;
//
//
//auto time_then = high_resolution_clock::now();
//
//int main() {
//
//	auto time_now = high_resolution_clock::now();
//
//	// duration_cast() is the function
//	// we can use nanoseconds, microseconds, milliseconds, seconds
//	// minutes and hours
//	auto time_elapsed = duration_cast<microseconds>(time_now - time_then);
//
//	// To get the value of duration use the count()
//	// member function on the duration object
//	cout << time_elapsed.count() << " microseconds" << endl;
//	cout << typeid(time_elapsed).name() << endl; //print the type of the variable
//
//	return 0;
//}