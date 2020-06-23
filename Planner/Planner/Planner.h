#define _CRT_SECURE_NO_WARNINS

class Planner {
private:


public:
	int time0, time1;
	string name = new char[256];
	vector<int> timeV;
	vector<string> timeLine;


	Planner(string str, int a, int b)
	{
		name = str;
		time0 = a;
		time1 = b;

		init_time();
		marker(time0, time1);

	}

	void init_time(int start_h = 7, int stop_h = 23, int start_m = 0, int start_s = 0, int stop_m = 0, int stop_s = 0, int step_h = 0, int step_m = 15, int step_s = 0)
	{
		int start = start_h * 60 + start_m + start_s / 60;
		int stop = stop_h * 60 + stop_m + stop_s / 60;
		int step = step_h * 60 + step_m + step_s / 60;


		int k = 0;
		timeV.push_back(start);
		timeLine.push_back("_");
		while (timeV[k] < stop)
		{

			timeV.push_back(timeV[k] + step);
			timeLine.push_back("|_");
			k++;


		}

	}

	void marker(int time0, int time1)
	{

		int k = timeV.size();
		int i = 0;
		int t = 0;
		time0 = time0 * 60;
		time1 = time1 * 60;

		while (time0 > timeV[i])
		{
			i++;
		}


		while (time1 < timeV[timeV.size() - 1 - t])
		{
			t++;
		}

		for (int r = i; r <= timeV.size() - 1 - t; r++)
		{
			timeLine[r] = "|*";

		}
		cout << "" << endl;
		/*for (int i = 0; i < k; i++)
		{
			cout << timeLine[i];
		}*/
	}

	void append_to_file_data(char* path, FILE* fp, int count_task)
	{
		fp = fopen(path, "a+");

		fprintf(fp, "%s %d %d \n", name, time0, time1);

		fclose(fp);
	}




	void append_to_file_timeFull(char* path, FILE* fp)
	{
		fp = fopen(path, "a+");

		for (int i = 0; i < 65; i++)
		{
			fprintf(fp, "%s \n", timeLine[i]);
		}

		fclose(fp);
	}







	~Planner() {
	}

};
