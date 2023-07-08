#include <iostream>



// QUEUE  (FIFO) ( First In First Out - ������ ����ü �ȿ� ���� �� ������ ���� �������� ) 

enum command
{
	// ť�� ���� ���� �ִ´ٴ� ��
	ENQUEUE = 1,
	//ť���� ���� ���ٴ� ��
	DEQUEUE = 2,
	Quit = 3
};

// ť�� ũ�⸦ ����.
const int QUEUE_SIZE{ 10 };

struct Queue
{
	// ���ð� ���������� ���� �ְ� �� �迭�� ����
	int QArray[QUEUE_SIZE]{};

	// ť�� ������ ó�� ������ �շ��ִ� �����̹Ƿ� ���� ������ ���������� ���� ���� �������� ����� ������ ����
	// ���ð� �����ڸ� ���ÿ����� ���� ������ ������ ��ġ�� ����ߴ� ������ �ϳ��ΰŰ�
	// ť������ ���� ������ ������ ���� ���������� ������ �ִ� ����
	int head{};
	int tail{};
};

void UserInteract(Queue& queue);
void Enqueue(Queue& queue, int value);
void Dequeue(Queue& queue);
void QueueMessage(Queue& queue);


int main()
{
	std::cout << "Circlear QUEUE" << std::endl;

	Queue DataStructure;

	UserInteract(DataStructure);

	int command{};

	while (true)
	{
		QueueMessage(DataStructure);
		std::cout << ">";
		std::cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "\tvalue : ";
			std::cin >> value;
			Enqueue(DataStructure, value);
		}
		break;
		case DEQUEUE:
		{
			Dequeue(DataStructure);
		}
		break;
		case Quit:
		{
			return 0;
		}
		break;

		default:
			std::cout << "�߸��� ����Դϴ�." << std::endl;
			break;
		}
	}
}

void UserInteract(Queue& queue)
{
	std::cout << "Queue" << std::endl;
	std::cout << "1. Enqueue" << std::endl;
	std::cout << "2. Dequeue" << std:: endl;
	std::cout << "3. Quit" << std::endl;
	std::cout << "-------------------------------" << std::endl;
}



void Enqueue(Queue& queue, int value)
{

	// tail�� ���� head�� ���� �����ϴٸ� ����
	if ((queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "QUEUE is FULL!" << std::endl;
		return;
	}

	// ���� ���� �迭�� �ε��� ��, ������ ����ü�� ���� ���� �� ����� ��Ŀ���� ��ġ�� �����ִ� ��.
	// �⺻���� 0�� tail�� 1�� ���� �� ť ������� ���� ������ ���� �������ش�.
	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	 
	// tail�� ���� ���� �ε����� ���� �Է��� ���� ����.
	queue.QArray[queue.tail] = value;
}

void Dequeue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "QUEUE is already EMPTY" << std::endl;
	}

	// Push���� ���� ����������
	// Pop�� ��쿡�� �Լ��� ����� �� head�� ��ġ�� �Ű��ش�.
	queue.head = (queue.head + 1) % QUEUE_SIZE;
}

void QueueMessage(Queue& queue)
{
	int i = queue.head;
	if (queue.head == queue.tail)
	{
		std::cout << "Empty" << std::endl;
	}

	// head�� tail�� ������ ������ �ݺ��ϸ� tail�� �ε����� �ִ� ���� ������ش�.
	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.QArray[i] << std::endl;
	}

	std::cout << "-----------" << std::endl;
}
