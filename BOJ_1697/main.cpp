
#include <iostream>

using namespace std;

static const int queue_size = 1000000;

static int circular_queue[queue_size];
int front = 0;
int rear = 0;
int current_step_rear = 0;
int step = 0;


static int is_visited[100001];

int get_next_queue_position(int _current_pos)
{
	return (_current_pos + 1) % queue_size;
}

int main()
{
	int subin_pos = -1;
	int bro_pos = -1;
	cin >> subin_pos >> bro_pos;

	circular_queue[rear] = subin_pos;
	rear = get_next_queue_position(rear);
	current_step_rear = rear;

	is_visited[subin_pos] = 1;

	while (true)
	{
		for (; front != current_step_rear; front = get_next_queue_position(front))
		{
			if (circular_queue[front] != bro_pos)
			{
				if (circular_queue[front] - 1 >= 0 &&
					is_visited[circular_queue[front]-1] == 0)
				{
					circular_queue[rear] = circular_queue[front] - 1;
					is_visited[circular_queue[rear]] = 1;
					rear = get_next_queue_position(rear);
				}

				if (circular_queue[front] + 1 <= 100000 &&
					is_visited[circular_queue[front]+1] == 0)
				{
					circular_queue[rear] = circular_queue[front] + 1;
					is_visited[circular_queue[rear]] = 1;
					rear = get_next_queue_position(rear);
				}

				if (circular_queue[front] * 2 <= 100000 &&
					is_visited[circular_queue[front]*2] == 0)
				{
					circular_queue[rear] = circular_queue[front] * 2;
					is_visited[circular_queue[rear]] = 1;
					rear = get_next_queue_position(rear);
				}
			}
			else
			{
				cout << step;
				return 0;
			}

		}

		current_step_rear = rear;
		step++;
	}

	return 0;
}
