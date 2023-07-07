#include <iostream>


// STACK (LIFO) (Last In First Out - ������ ����ü �ȿ� ���� �� ������ ���� �������� ��������


// ���� ������� ����� ����� ����
const int STACK_SIZE{ 10 };


// Ŀ�ǵ�� ����� �����͵�
enum Command 
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};

struct Stack
{
	// �������� ����� ����ü�� ���� ����ڿ� ��ȣ�ۿ��ϴ� �迭�� �׿� ���õ� �������� ����־���Ѵ�.
	// 
	// ������ ������ �־��� ���� �� �� �ֵ��� �迭 (  �迭�� ũ��� �� ���Ÿ���� ������ ��� )
	int Array[STACK_SIZE]{};


	// �� �迭�� ������ �� ���� �ʾ��� ���� �����ϱ� ���� �⺻���� ���� ��ġ�� ����� ����
	int topIndex{ -1 };
};

// ����ü�� �Ű������� ����� �� �ּҸ� �����ؿ��� ���� ����.
void UserInteract(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);
void StackMessage(Stack& stack);


int main()
{	
	// ����ü ��������� �ٷ� ���ο� �������ִ� ������ ������!!!
	// ����ü ���� ���� ( ������ ����ü ���� -> ���ο� ����ü Ÿ���� ���� ���� )
	Stack Datastructure;

	int command{};

	UserInteract(Datastructure);
	
	while (true)
	{
		StackMessage(Datastructure);
		std::cout << ">";
		std::cin >> command;

		switch (command)
		{
		case PUSH:
		{
			int value{};
			std::cin >> value;
			Push(Datastructure, value);
		}
		break;
		case POP:
		{
			Pop(Datastructure);
		}
		break;
		case QUIT:
		{
			return 0;
		}
		break;
		default:
		{
			std::cout << "�߸��� ����Դϴ�." << std::endl;
		}
			break;
		}
	}
	return 0;
}


// ����ڿ� ���������� ��ȣ�ۿ��� ��ҵ鿡 ���� ����
// ���� Command 
void UserInteract(Stack& stack)
{
	std::cout << "STACK" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "1. Push" << std::endl;
	std::cout << "2. Pop" << std::endl;
	std::cout << "3. Quit" << std::endl;
}

void Push(Stack& stack, int value)
{
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "Stack is FULL!!!" << std::endl;
		return;
	}
	
	stack.Array[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	stack.topIndex--;
}

void StackMessage(Stack& stack)
{
	std::cout << "---stack ---" << std::endl;
	if (stack.topIndex < 0)
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	for (int i = stack.topIndex; i >= 0; i--)
	{
		std::cout << stack.Array[i] << std::endl;
	}
}
