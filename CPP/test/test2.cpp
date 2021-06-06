#include <iostream>

using namespace std;

class Time {
public:
	Time() : h(0), m(0), s(0) {	}
	Time(int s_) {
		s = s_;
	}
	Time(int m_, int s_) {
		m = m_;
		s = s_;
	}
	Time(int h_,int m_,int s_) {
		h = h_;
		m = m_;
		s = s_;
	}
	int     h;
	int     m;
	int     s;
};

int         main(void)
{
	Time t1(2, 45, 59);
	Time t2(45, 44);
	Time t3(12);
	Time t4;
	t4 = Time();
	cout << t1.h << "시" << t1.m << "분" << t1.s << "초" << endl;
	cout << t2.h << "시" << t2.m << "분" << t2.s << "초" << endl;
	cout << t3.h << "시" << t3.m << "분" << t3.s << "초" << endl;
	cout << t4.h << "시" << t4.m << "분" << t4.s << "초" << endl;
	cout << endl;
	return (0);
}