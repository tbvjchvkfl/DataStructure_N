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
	// 임의의 정보를 넣었다 뺐다 할 수 있도록 배열 (  배열의 크기는 위 상수타입의 변수로 사용 )
	int Array[STACK_SIZE]{};


	// 위 배열에 정보가 들어가 있지 않았을 때를 구분하기 위해 기본값이 안전 장치로 사용할 변수
	// 해당 변수는 위 Array라는 배열의 인덱스로 사용될 변수임.
	// 배열에 아무것도 들어가있지 않았다라는 것을 표현하기 위해 -1로 설정한 것.
	// UI에서 포커스같은 용도
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

	// 만약 배열의 모든 인덱스에 값이 들어와 있는 상태라면 리턴
	// 배열의 0번 인덱스부터 값이 채워지는데, STACK_SIZE의 값은 10이었다. topIndex는 -1부터 값을 더해가며 증가하므로 STACK_SIZE에서 -1을 해준 것 
	// 값을 10개 까지 넣을 껀데 배열의 10번 인덱스까지 사용하면 11개를 사용하는거니까 0~9번 인덱스까지 값을 넣을 수 있는데, 10번 인덱스에는 값을 넣을 수 없음.
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		std::cout << "Stack is FULL!!!" << std::endl;
		return;
	}

	// 해당 함수가 실행되면 위 Stack에 들어있던 배열(Array에 값을 집어 넣음 )
	// 주의 사항!!!
	// 배열의 인덱스에 topIndex를 넣었는데, topIndex의 기본값은 -1
	// 배열의 인덱스는 0부터 시작하기 때문에 topIndex에 값을 더하여 0으로 만들어준 후에 입력한 값(매개변수)를 넣어줌. => stack.topIndex에 +1이 되면 0이 되므로 0번 인덱스부터 시작함.
	stack.Array[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{
	
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	// topIndex의 개수를 줄여줌
	// 좀 더 쉽게 이해하면 topIndex는 임의의 UI에 포커스가 들어와있는 상태라고 이해하면 될 듯.
	// 그 포커스를 하나씩 감소해주는 것.
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
	// 임의의 변수에 topIndex 넣어 주고 반복하며 배열의 인덱스들을 출력
	// i 는 하나씩 감소해야함. => Push했을 경우 topIndex 는 지속적으로 증가함. 배열의 특정 인덱스( i 값 )부터 0번 인덱스까지 들어가있는 값을 출력해야되기 때문
	for (int i = stack.topIndex; i >= 0; i--)
	{
		std::cout << stack.Array[i] << std::endl;
	}
}
