#include <iostream>



// QUEUE  (FIFO) ( First In First Out - 임의의 구조체 안에 먼저 들어간 정보가 먼저 빠져나옴 ) 

enum command
{
	// 큐에 값을 집어 넣는다는 뜻
	ENQUEUE = 1,
	//큐에서 값을 뺀다는 뜻
	DEQUEUE = 2,
	Quit = 3
};

// 큐의 크기를 정함.
const int QUEUE_SIZE{ 10 };

struct Queue
{
	// 스택과 마찬가지로 값을 넣고 뺄 배열을 선언
	int QArray[QUEUE_SIZE]{};

	// 큐는 파이프 처럼 양쪽이 뚫려있는 형태이므로 값이 들어오고 빠져나가는 시작 점과 끝점으로 사용할 변수를 선언
	// 스택과 비교하자면 스택에서는 값이 들어오고 나가는 위치로 사용했던 변수가 하나인거고
	// 큐에서는 값이 들어오는 변수와 값이 빠져나가는 변수가 있는 형태
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
			std::cout << "잘못된 명령입니다." << std::endl;
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

	// tail의 값이 head의 값과 동일하다면 리턴
	if ((queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "QUEUE is FULL!" << std::endl;
		return;
	}

	// 값이 들어올 배열의 인덱스 즉, 임의의 구조체에 값을 넣을 때 사용할 포커스의 위치를 정해주는 것.
	// 기본값이 0인 tail에 1을 더한 후 큐 사이즈로 나눈 나머지 값을 지정해준다.
	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	 
	// tail과 같은 값의 인덱스에 내가 입력한 값을 넣음.
	queue.QArray[queue.tail] = value;
}

void Dequeue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "QUEUE is already EMPTY" << std::endl;
	}

	// Push했을 때와 마찬가지로
	// Pop의 경우에도 함수가 실행될 때 head의 위치를 옮겨준다.
	queue.head = (queue.head + 1) % QUEUE_SIZE;
}

void QueueMessage(Queue& queue)
{
	int i = queue.head;
	if (queue.head == queue.tail)
	{
		std::cout << "Empty" << std::endl;
	}

	// head와 tail이 같아질 때까지 반복하며 tail의 인덱스에 있는 값을 출력해준다.
	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.QArray[i] << std::endl;
	}

	std::cout << "-----------" << std::endl;
}
