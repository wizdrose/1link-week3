#include"StudentContrller.h"
#include<list>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<thread>
#include<vector>.
#include<Windows.h>
void WINAPI readThread();
void writeList(string path, string s)
{
		ofstream fo;
		fo.open(path, ios::out | ios::app);
		fo << s << endl;
		fo.close();
}
vector<string> Read(string path)
{
	vector<string> lst_file;
	ifstream f;
	string line;
	f.open(path, ios::in);
	while (getline(f, line))
	{
		lst_file.push_back(line);
	}
	f.close();
	return lst_file;
}
vector<string> list_file=Read("ListFile.txt");
int main()
{
	HANDLE handel = CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)readThread, 0, NULL, 0);
	StudentContrller std_controller;
	char selection1, selection2;
	list<Student> list_student;
	bool quit = false;
	bool back = false;
	while (!quit) {
		system("cls");
		cout << "WELCOME TO STUDENT MANAGEMENT SYSTEM" << endl;
		cout << "__1. VIEW LIST		__" << endl;
		cout << "__2.  SEARCH STUDENT	__" << endl;
		cout << "__3. STATISTIC STUDENTS	__" << endl;
		cout << "__4. QUIT__" << endl;
		fflush(stdin);
		cin >> selection1;
		switch (selection1)
		{
		case '1':
			system("cls");
			back = false;
			while (!back) 
			{
				system("cls");
				std_controller.listStudent(list_student);
				cout << "1. ADD STUDENT" << endl;
				cout << "2. MODIFY STUDENT" << endl;
				cout << "3. DELETE STUDENT" << endl;
				cout << "4. SORT STUDENT" << endl;
				cout << "5.BACK" << endl;
				cin >> selection2;
				switch (selection2)
				{
				case '1':
					system("cls");
					list_student = std_controller.addStudent();
					system("pause");
					break;
				case '2':
					system("cls");
					std_controller.modifyStudent();
					system("pause");
					break;
				case '3':
					system("cls");
					std_controller.deleteStudent();
					system("pause");
					break;
				case '4':
					system("cls");
					std_controller.sortStudent();
					system("pause");
					break;
				case '5':
					back = true;
					break;
				default:
					break;
				}
			}
			system("pause");
			break;
		case '2':
			system("cls");
			std_controller.searchStudent(list_student);
			system("pause");
			break;
		case '3':
			system("cls");
			std_controller.statisticStudent();
			system("pause");
			break;
		case '4':
			quit = true;
			break;
		default:
			break;
		}
	}
	CloseHandle(handel);
	system("pause");
	return 0;
}
void WINAPI readThread()
{
	list_file = Read("ListFile.txt");
	StudentRepository std_repository;
	StudentContrller std_controller;
	string path = "C:\\Users\\wizdrose\\Documents\\Visual Studio 2015\\Projects\\TestThread\\TestThread\\Content\\";
	/*cout << "Your path: ";
	cin >> path;*/
	string searchPattern = "*.txt";
	string fullSearchPath = path + searchPattern;
	WIN32_FIND_DATA FindData;
	HANDLE hFind;

	while (1)
	{
		hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);
		string line;
		do
		{

			string file_path = path + FindData.cFileName;
			//cout << file_path<<endl;
			auto it = std::find(list_file.begin(), list_file.end(), file_path);
			if (it == list_file.end())
			{
				list_file.push_back(file_path);
				writeList("ListFile.txt", file_path);
				ifstream file;
				file.open(file_path.c_str(), ios::in);
				while (getline(file, line))
				{
					Student student;
					Point point;
					int id;
					string name;
					string address;
					string sex;
					float math;
					float physical;
					float alchemist;
					bool flag = true;
					try
					{

						int position = line.find("\t");
						id = stoi(line.substr(0, position));
						line = line.substr(position + 1);
						position = line.find("\t");
						name = line.substr(0, position).c_str();
						line = line.substr(position + 1);
						position = line.find("\t");
						address = line.substr(0, position).c_str();
						line = line.substr(position + 1);
						position = line.find("\t");
						sex = line.substr(0, position).c_str();
						line = line.substr(position + 1);
						position = line.find("\t");
						math = stof((line.substr(0, position)).c_str());
						line = line.substr(position + 1);
						position = line.find("\t");
						physical = stof((line.substr(0, position)).c_str());
						position = line.find("\t");
						alchemist = stof((line.substr(0, position)).c_str());
						student.setId(id);
						student.setName(name);
						student.setAddress(address);
						student.setSex(sex);
						point.setMath(math);
						point.setPhysical(physical);
						point.setAlchemist(alchemist);
						student.setPoint(point);
						if (std_controller.checkID(student.getId()))
						{
							continue;
						}
						else
						{
							std_repository.Write(student, "Text.txt");
						}
					}
					catch (const std::exception&)
					{
						flag = false;
					}
					if (flag == false) { continue; }
				}
				file.close();
			}
		} while (FindNextFile(hFind, &FindData) > 0);

		Sleep(3000);

	}


}