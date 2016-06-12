#include <string>
#include <fstream>
#include <iostream>
//Poco
#include <Poco\DateTime.h>
#include <Poco\NumberFormatter.h>
#include <Poco\Format.h>
using namespace std;



class pop_8_num {
public:
	//The generator of this class, aiming to generate the whole needed pi once
	pop_8_num() {
		fstream f("./source/Pi.txt");
		string buf;
		while (getline(f, buf)) {
			Pi += buf;
		}
		length = Pi.length();
	}

	auto begin() {
		return *this;
	}
	auto end() {
		return pop_8_num(length);
	}

	string operator *() {
		string result = "";
		for (int i = 0; i < 8 && current_pos != length; i++) {
			result += Pi[current_pos++];
			if (i == 3) {
				result += " ";
			}
		}
		return result;
	}
	
	auto operator ++() {
		//Do nothing
		return *this;
	}

	bool operator !=(pop_8_num other) {
		if (this->current_pos != other.current_pos)
			return true;
		else
			return false;
	}

private:
	string Pi;
	int length = 0; // Pi
	int current_pos = 0;

	pop_8_num(int i) :pop_8_num() {
		current_pos = i;
	}
};

void create_the_lrc() {
	Poco::Timespan last_time;
	Poco::Timespan span_time(3,207500);
	fstream f("Ô²ÖÜÂÊÖ®¸è.lrc", ios::trunc | ios::out);
	for (auto i : pop_8_num()) {
		last_time += span_time;
		auto hour = last_time.hours();
		auto minute = last_time.minutes();
		auto seconds = last_time.seconds();
		auto milliseconds = last_time.milliseconds();
		if (hour != 0) {
			minute += hour * 60;
		}
		if (minute >= 68 && seconds > 26) break;
		string s = Poco::format("[%02d:%02d.%02d]", minute, seconds, milliseconds/10);
		f << s << i << endl;
	}
	f.close();

}




int main() {
	create_the_lrc();
	//If you are a Linux/Unix user, just delete this.
	system("pause");

	return 0;
}