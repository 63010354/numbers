#include<iostream>
#include<algorithm>
using namespace std;

int num, card[1000];
int i, lend, j;

int change()
{
	for (i = num - 1; i >= 0; i--)
	{
		j = 1;
		do
		{
			if (card[i] < card[i - j])
			{
				lend = card[i - j];
				card[i - j] = card[i];
				card[i] = lend;
				j++;
			}
			else if (card[i] > card[i - j] || card[i] == card[i - j])
			{
				j++;
			}

		} while (i - j >= 0);
	}
	return 0;
}

int main()
{
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cin >> card[i];
	}

	change();
	i = 0;
	while (card[i] == 0)
	{
		i++;
		if (card[i] != 0)
		{
			swap(card[i], card[0]);
			break;
		}
	}

	for (i = 0; i < num; i++)
	{
		cout << card[i];
	}
}
