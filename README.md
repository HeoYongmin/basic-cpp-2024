# Basic-cpp-2024
IoT 시스템개발자 심화 프로그래밍 언어 학습리포지토리

## 1일차
- 개발환경 설치
	- Visual Studio 2022 Community 설치
	- C, C++ 소스코드 실행
	- C++에 대해 설명

- 제어문
	1. 선택제어문 
		- if, switch
		- if, else 문(C언어종류) / elif = Python
		- 반복문 For
		- 반복문 While
		- Overloading(재정의), Overriding
		
	2. 반복제어문 
		- for,while
		- for(초기식; 조건식; 증감식){
			1. 초기식을 가지고 조건식을 따진다.
			2. 참이면 for문의 실행문 실행
			3. 증감식을 실행
			4. 조건식을 따지고
			2.
			3.
			4.
			2.
			3.
			4.
			.
			.
			.
		}

	
- 지역변수 = 로컬변수
	1. 선언되어진 범위 안에서만 사용이 가능(static 영역에 저장)

- 자료형
	1. 문자 : 문자(char),문자열
	2. 숫자 : 정수(int),실수
	
- 정수로 계산하기

## 2일차
// class 안에 들어 가는 함수 = Method

- Default Value
- Reference 함수
	- 반환형 Reference Type
- Name Space
- 전역,지역변수
- C에서 메모리
	- 스택 : 지역변수, 매개변수
	- HEAP : 사용자에게 할당된 영역
		= Malloc() -> free()반환 = 사용을 할려면 Malloc으로 할당을 받는다
	- data: 함수, 전역변수, 상수, 문자 리터럴
	
	- // A & B = 비트 And 연산자
	- // A && B = 논리 And 연산자 = 논리 곱

		
-------------- clang04_test--------------

## 3일차
- Class
	- 멤버변수와 멤버함수로 구성된다.
	- 클래스 내부에는 멤버들의 선언으로 작성된다.
	- 멤버함수의 정의를 외부로 빼낸다.(스코프연산자 사용)
	- 일반적으로 멤버변수는 private, 멤버함수 public의 접근제한을 사용한다.
## 4일차
- 정보은닉

- 캡슐화

- 생성자와 소멸자
	- 생성자(클래스 이름과 같은 멤버함수로 출력은 없다.)
	- 객체 생성시 자동으로 호출되는 멤버함수
	- 모든 클래스는 디폴트 생성자를 가지고 있다.
	- 만약 명시적으로 생성자를 작성하면 디폴트 생성자의 호출은 불가하며 디폴트 생성자가 필요한 경우는 명시적으로 작성한다.
	- 멤버변수들의 초기화를 담당한다.

- 멤버 이니셜라이즈
	- 객체 생성전에 선언과 동시에 초기화가 필요한 경우에 사용한다.
	- const 변수와 참조변수의 초기화에 사용

## 5일차
- 포인터 배열: 포인터를 저장하는 배열
- 배열 포인터: 배열을 가리키는 포인터
- 소멸자
	- 객체 생성시 반드시 호출되는 것이 생성자라면
	- 객체소멸시 반드시 호출되는 것은 소멸자
	- 클래스의 이름 앞에 ~가 붙은 형태의 이름을 갖는다.
- 객체 배열
	- 객체 기반의 배열은 다음의 형태로 선언(SoSimple)이 클래스 이름
- 객체 포인터 배열
	- 객체의 주소 값 저장이 가능한 포인터 변수로 이뤄진 배열
- this 포인터
	- 객체 자신을 가리키는 용도로 사용되는 포인터
- 복사 생성자
	- 객체를 복사할 때 호출되는 생성자
	따라서 복사할 객체를 입력으로 가져야 하는데 이 때 원본 객체의 참조를 입력으로 받는다.

## 6일차
- 얕은 복사, 깊은 복사
	- 얕은 복사: 멤버 대 멤버의 복사, 주소만 복사되고 그 주소가 가리키는 데이터는 공유
	- 깊은 복사: 객체가 가리키는 메모리 주소까지 실제로 복사하는 것

- 클래스의 friend 선언
- 함수의 friend 선언
- Static

## 7일차
- static 
	-


- 키워드 mutable

- 상속

## 8일차
- 1.변수 2.함수 3.제어문 정복

- 다형성
	- 오버로딩(Overloading) - 다중정의
	- 오버라이딩(Overriding) - 재정의, 상속관계에서 사용

- 가상함수
	- virtual 키워드의 선언을 통해서 이뤄짐
	- 이렇게 가상함수가 선언되고 나면 이 함수를 오버라이딩 하는 함수도 가상함수가 됨

- 가상소멸자
	- virtual로 선언된 소멸자를 가리켜 가상 소멸자라 함

- 가상의 원리와 다중상속(패스)

## 9일차
- 연산자 오버로딩1


- 연산자 오버로딩2

## 10일차
- 상속 구조에서의 대입 연산자 호출

- 배열의 인덱스 연산자 오버로딩

- delete 연산자 오버로딩에 대한 상세한 이해

- 포인터 연산자 오버로딩

- 스마트 포인터

- () 연산자의 오버로딩과 펑터

## 11일차
- 임시객체로의 자동 형 변환과 형 변환 연산자

- String 클래스

- 템플릿

## 12일차
- 


- 클래스 템플릿