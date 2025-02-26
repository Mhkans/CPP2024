#pragma once
// DirectX를 이용해 만들어지는 프로그렘의 "본체",
// 즉 DX의 본격적인 실행을 관리할 인스턴스로서 사용되는 클래스

// 지금은 멤버도 함수도 간단하지만,
// DX의 프레임워크를 구축해나가면서 차차 추가되는 내용이 많아지게 될 것
class Program
{
private:
	class Scene* scene;

public:
	Program();
	~Program();

	void Update();
	void Render();

	void Create();
	void Delete();
};