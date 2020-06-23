#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>

#include <iterator>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <stdlib.h>


using namespace std;

#include "Planner.h"


bool check_file(char* path, FILE* fp);
int scan_from_file();
void print_menu();
void sort_task_alf();
void sort_task_start_time();
void print_full_timeLine(vector<string>& timeFull);
void append_to_file_count_task(char* path, FILE* fp, int count_task);
void print_All_Task(int count_task, vector<Planner>& t);




int main()
{
	vector<Planner> t;
	vector<string> timeFull(65);

	for (int i = 0; i < 65; i++)
	{
		timeFull[i] = "|_";
	}

	int flag = 1;
	string str;
	int a = 0, b = 0;


	string razmer_text;
	int razmer = 0;
	int i = 0;


	FILE *fp = 0;
	char path[] = "PlannerData.txt";

	int count_task = 0;
	int flag1 = 0;
	bool f = 0;





	f = check_file(path, fp);

	system("cls");
	if (f)
	{
		system("cls");

		cout << "1...............Create new Planner" << endl;
		cout << "2...............Scan from File" << endl;

		cin >> flag1;
	}
	if (flag1 == 1)
	{

		print_menu();
		cin >> flag;
		system("cls");
	}


	if (flag1 == 2)
	{


		//опеределение длины текста начало
		ifstream file("text.txt", ios::in | ios::ate);
		if (file) {

			ifstream::streampos filesize = file.tellg();
			razmer_text.reserve(filesize);
			file.seekg(0);
			razmer = filesize;
			cout << "DDDD= " << razmer;
			file.close();
		}
		//опеределение длины текста конец

		fopen(path, "r");
		fp = fopen(path, "r");

		fscanf(fp, "%d", &count_task);



		char* str1 = new  char[255];
		for (i = 0; i < count_task; i++)
		{



			fscanf(fp, "%s", str1);
			fscanf(fp, "%d", &a);
			fscanf(fp, "%d", &b);
			Planner z(str1, a, b);

			t.push_back(z);

			for (int i = 0; i < 64; i++)
			{


				if (z.timeLine[i] == "|*" || timeFull[i] == "|*")
				{
					timeFull[i] = "|*";

				}

			}
			timeFull[64] = "\n";
		}


		fclose(fp);

		print_menu();
		cin >> flag;
		system("cls");
		scan_from_file();
	}



	while (flag != 4)
	{




		switch (flag) {
		case 1:
		{
			cout << "Input task name: ";
			cin >> str;

			cout << "\nInput task start h 7-23: ";
			cin >> a;
			cout << "\nInput task finish h " << a << "-23: ";
			cin >> b;

			Planner z(str, a, b);

			t.push_back(z);
			count_task++;

			for (int i = 0; i < 64; i++)
			{


				if (z.timeLine[i] == "|*" || timeFull[i] == "|*")
				{
					timeFull[i] = "|*";

				}

			}
			timeFull[64] = "\n";

		}
		break;


		break;
		case 2:
		{
			print_full_timeLine(timeFull);
		}
		break;
		case 3:
		{
			print_All_Task(count_task, t);
		}
		break;

		}




		print_menu();
		cin >> flag;
		system("cls");

	}


	fopen(path, "w+");
	fp = fopen(path, "w+");

	fprintf(fp, "%d", count_task);
	fprintf(fp, "\n");



	for (i = 0; i < count_task; i++)
	{

		str = t[i].name;
		char * writable = new char[str.size() + 1];
		copy(str.begin(), str.end(), writable);
		writable[str.size()] = '\0';




		fprintf(fp, "%s", writable);
		fprintf(fp, " ");
		fprintf(fp, "%d", t[i].time0);
		fprintf(fp, " ");
		fprintf(fp, "%d", t[i].time1);
		fprintf(fp, "\n");

	}
	fclose(fp);


	system("pause");
	return 0;
}





bool check_file(char* path, FILE* fp)
{
	if ((fp = fopen(path, "r")) != NULL)
	{
		cout << "You can read data from File";
		return 1;
	}
	return 0;
}

int scan_from_file()
{

	return 0;
}

void print_menu()
{
	cout << "1................Create New Task" << endl;
	cout << "2................Print FullTimeLine" << endl;
	cout << "3................Print AllTask" << endl;
	cout << "4................Finish Work With Planner" << endl;

}



void print_full_timeLine(vector<string>& timeFull)
{
	for (int i = 0; i < 65; i++)
	{
		cout << timeFull[i];
	}
}


void append_to_file_count_task(char* path, FILE* fp, int count_task)
{
	fp = fopen(path, "w+");

	fprintf(fp, "%d", count_task);
	fprintf(fp, "\n");

	fclose(fp);
}








void print_All_Task(int count_task, vector<Planner>& t)
{
	cout << "|----| |--------------------------------| |-------| |-------|" << endl;
	cout << "|-ID-| |--------------Name--------------| |-Start-| |--End--|" << endl;
	cout << "|----| |--------------------------------| |-------| |-------|" << endl;
	for (int i = 0; i < count_task; i++)
	{
		cout << "|";
		cout << setw(4) << left << i;
		cout << "|";

		cout << " |";
		cout << setw(32) << left << t[i].name;
		cout << "|";

		cout << " |";
		cout << setw(7) << left << t[i].time0;
		cout << "|";

		cout << " |";
		cout << setw(7) << left << t[i].time1;
		cout << "|";


		cout << "\n|----| |--------------------------------| |-------| |-------|" << endl;


	}
}