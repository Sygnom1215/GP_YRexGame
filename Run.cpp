#include"Console.h"
#include"Run.h"

void Openscreen()
{
	cout << "		���� ����		" << endl;
	Sleep(5000);
	Mapbase();
	system("cls");
	Mapping();
}

void Mapbase()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (i == (size_y - 1))
				map[i][j] = 1;

			else
				map[i][j] = 0;
		}
	}

	map[c_y][c_x] = 2;
}

void Jump(int cot)
{
	int cx, cy;

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == 2)
			{
				cx = j;
				cy = i;
			}
		}
	}

	if (cot < 4)
	{
		if (map[cy - 1][cx] == 3)
			map[cy][cx] = 0;
		else
		{
			map[cy - 1][cx] = 2; map[cy][cx] = 0;
			Mapping();
		}
	}
	if (cot >= 4)
	{
		if (map[cy + 1][cx] == 3)
			map[cy][cx] = 0;
		else
		{
			map[cy][cx] = 0; map[cy + 1][cx] = 2;
			Mapping();
		}
	}
}

void Obstaclemaker()
{
	int b;
	int obs[5][size_y - 1];

	b = rand() % 4;

	if (b == 0)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 0;
		obs[b][size_y - 2] = 3;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 1)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 3;
		obs[b][size_y - 2] = 3;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 2)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 3;
		obs[b][size_y - 2] = 0;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 3)
	{
		obs[b][size_y - 10] = 3;
		obs[b][size_y - 9] = 3;
		obs[b][size_y - 8] = 3;
		obs[b][size_y - 7] = 3;
		obs[b][size_y - 6] = 3;
		obs[b][size_y - 5] = 3;
		obs[b][size_y - 4] = 3;
		obs[b][size_y - 3] = 0;
		obs[b][size_y - 2] = 0;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
}

void Obstaclemove()
{
	int obstime/*��ֹ� ��ε� �ð�*/, run2 = 1, k, cot = 1, time = 0, ctime = 0;
	//������ �� �� �� �Ų����� �ϱ����� ���� ������ ������ ��� 0���� �ʱ�ȭ������  
	obstime = rand() % otime + otime - 100; //ù ��ֹ� ���� 

	while (run2)
	{
		//����Ű�� ������ ��
		if (_kbhit())
		{
			k = _getch();
			//p�� ���� ������ Ű(������ ���� �̺�Ʈ �߻� ���� Ȯ���� ���� ����), �̰� �ص� �ӵ��� ���� ���� 
			if (k == 'p')
				score += 1000;

			if (k == ' ')
			{
				while (cot <= 6)
				{
					//�� 
					if (cot == 1)
					{
						system("cls");
						Jump(cot);
						++cot;
						Sleep(30);
					}
					if ((time % 25) == 0 && cot > 1)
					{
						system("cls");
						Jump(cot);
						if (cot == 6)
							time = 0;
						++cot;
					}

					//��ֹ� 
					if ((time % 22) == 0)
					{
						++score; //����
						Score();
						for (int i = 0; i < size_y - 1; i++)
						{
							for (int j = 0; j < size_x; j++)
							{
								if (j != 0 && map[i][j] != 2 && (map[i][j - 1] != 2 || map[i][j] == 3))
								{
									map[i][j - 1] = map[i][j];
									map[i][j] = 0;
								}
							}
						}
						system("cls");
						Mapping();
						Sleep(speed);
					}

					//���� ������ ��
					run2 = Gameover();
					if (run2 == 0)
						break;

					//��ֹ� ���� 
					if ((ctime % obstime) == 0)
					{
						Obstaclemaker();
						system("cls");
						Mapping();
						ctime = 0;
						obstime = rand() % otime + otime - 100;
					}
					time++;
					ctime++;
				}
				cot = 1;
			}
		}
		//���� Ű�� �ȴ����� ��
		//��ֹ� 
		if ((time % 22) == 0)
		{
			++score; //����
			Score();
			for (int i = 0; i < size_y - 1; i++)
			{
				for (int j = 0; j < size_x; j++)
				{
					if (j != 0 && map[i][j] != 2 && (map[i][j - 1] != 2 || map[i][j] == 3))
					{
						map[i][j - 1] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			system("cls");
			Mapping();
			Sleep(speed);
		}

		//���� ������ �� 
		run2 = Gameover();

		//��ֹ� ���� 
		if ((ctime % obstime) == 0)
		{
			Obstaclemaker();
			system("cls");
			Mapping();
			ctime = 0;
			obstime = rand() % otime + otime - 100;
		}
		time++;
		ctime++;
	}
	speed = spd;
	otime = oti;
}

int Gameover()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == 2)
				return 1;

			if (i == size_y - 1 && j == size_x - 1 && map[i][j] != 2)
			{
				system("cls");
				Mapping();
				return 0;
			}
		}
	}
}

void Score()
{
	if ((score % 100) == 0 && speed > 20)
	{
		speed -= 5;
		otime -= 20;
	}
	if ((score % 100) == 0 && speed <= 10)
		speed--;
}

int Endscreen()
{
	int answer;

	system("cls");
	cout << "		gameover	" << endl;
	cout << "/t/t Score : " << score / 2 << "/t/t";
	cout << "1. Retry /t 2. ExitGame";
	cin >> answer;
	if (answer == 1)
	{
		system("cls");
		Mapbase();
		Mapping();
		return 1;
	}
	else if (answer == 8282)
	{
		speed = 10;
		otime = 181;
		system("cls");
		Mapbase();
		Mapping();
		return 1;
	}
	else
	{
		system("cls");
		return 0;
	}
}