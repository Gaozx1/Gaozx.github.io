#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
	system("color F1");
	char a;
	while (1) {
		cout << "请输入 f(找东西)/p(输入物品位置,格式：名字 (空格）地点)/s(结束)";
		cin >> a;
		if (a == 'f') {
			string find;
			 cin>> find;
			ifstream infile("findthin.Gaozx1");
			if (!infile.is_open()) {
				cerr << "无法打开文件进行读取。" << endl;
				continue;
			}
			bool found = false;
			string wp;
			string where;
			while(infile >> wp>>where) {
				if (wp == find) {
					cout << where<<endl;
					found = true;
					break;
				};
			}
			if (!found) {
				cout << "未找到该物品。" << endl;
			}
			infile.close();
		} else if(a=='p'){
			ofstream outfile;
			outfile.open("findthin.Gaozx1", std::ios::app);
			if (!outfile.is_open()) {
				cerr << "无法打开文件进行追加。" << endl;
				continue;
			}
			string a, b;
			cin >> a >> b;
			outfile << a << " " << b << endl;
			outfile.close();
		}else if(a=='s')return 0;
		system("pause");
		system("cls");
	}
	return 0;
}
//效果不美观，欢迎修改
