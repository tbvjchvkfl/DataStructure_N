#include <iostream>


// STACK (LIFO) (Last In First Out - 임의의 구조체 안에 먼저 들어간 정보가 가장 마지막에 빠져나옴


// 스택 사이즈로 사용할 상수를 선언
const int STACK_SIZE{ 10 };


// 커맨드로 사용할 데이터들
enum Command 
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};

struct Stack
{
	// 스택으로 사용할 구조체는 실제 사용자와 상호작용하는 배열과 그와 관련된 정보들을 담고있어야한다.
	// 
	// 임의의 정보를 넣었다 뺐다 할 수 있도록 배열 (  배열의 크기는 위 상수타입의 변수로 사용 )
	int Array[STACK_SIZE]{};


	// 위 배열에 정보가 들어가 있지 않았을 때를 구분하기 위해 기본값이 안전 장치로 사용할 변수
	int topIndex{ -1 };
};

// 구조체를 매개변수로 사용할 땐 주소를 참조해오는 것이 좋음.
void UserInteract(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);
void StackMessage(Stack& stack);


int main()
{	
	// 구조체 만들었으면 바로 메인에 선언해주는 습관을 들이자!!!
	// 구조체 생성 순서 ( 전역에 구조체 생성 -> 메인에 구조체 타입의 변수 생성 )
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
			std::cout << "잘못된 명령입니다." << std::endl;
		}
			break;
		}
	}
	return 0;
}


// 사용자와 직접적으로 상호작용할 요소들에 대한 내용
// 위에 Command 
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
