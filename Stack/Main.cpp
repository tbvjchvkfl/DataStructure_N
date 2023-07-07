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
	// ������ ������ �־��� ���� �� �� �ֵ��� �迭 (  �迭�� ũ��� �� ���Ÿ���� ������ ��� )
	int Array[STACK_SIZE]{};


	// �� �迭�� ������ �� ���� �ʾ��� ���� �����ϱ� ���� �⺻���� ���� ��ġ�� ����� ����
	// �ش� ������ �� Array��� �迭�� �ε����� ���� ������.
	// �迭�� �ƹ��͵� ������ �ʾҴٶ�� ���� ǥ���ϱ� ���� -1�� ������ ��.
	// UI���� ��Ŀ������ �뵵
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

	// ���� �迭�� ��� �ε����� ���� ���� �ִ� ���¶�� ����
	// �迭�� 0�� �ε������� ���� ä�����µ�, STACK_SIZE�� ���� 10�̾���. topIndex�� -1���� ���� ���ذ��� �����ϹǷ� STACK_SIZE���� -1�� ���� �� 
	// ���� 10�� ���� ���� ���� �迭�� 10�� �ε������� ����ϸ� 11���� ����ϴ°Ŵϱ� 0~9�� �ε������� ���� ���� �� �ִµ�, 10�� �ε������� ���� ���� �� ����.
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "Stack is FULL!!!" << std::endl;
		return;
	}

	// �ش� �Լ��� ����Ǹ� �� Stack�� ����ִ� �迭(Array�� ���� ���� ���� )
	// ���� ����!!!
	// �迭�� �ε����� topIndex�� �־��µ�, topIndex�� �⺻���� -1
	// �迭�� �ε����� 0���� �����ϱ� ������ topIndex�� ���� ���Ͽ� 0���� ������� �Ŀ� �Է��� ��(�Ű�����)�� �־���. => stack.topIndex�� +1�� �Ǹ� 0�� �ǹǷ� 0�� �ε������� ������.
	stack.Array[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{
	
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	// topIndex�� ������ �ٿ���
	// �� �� ���� �����ϸ� topIndex�� ������ UI�� ��Ŀ���� �����ִ� ���¶�� �����ϸ� �� ��.
	// �� ��Ŀ���� �ϳ��� �������ִ� ��.
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
	// ������ ������ topIndex �־� �ְ� �ݺ��ϸ� �迭�� �ε������� ���
	// i �� �ϳ��� �����ؾ���. => Push���� ��� topIndex �� ���������� ������. �迭�� Ư�� �ε���( i �� )���� 0�� �ε������� ���ִ� ���� ����ؾߵǱ� ����
	for (int i = stack.topIndex; i >= 0; i--)
	{
		std::cout << stack.Array[i] << std::endl;
	}
}
