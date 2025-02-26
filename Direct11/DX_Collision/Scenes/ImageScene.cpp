#include "framework.h"
#include "ImageScene.h"

ImageScene::ImageScene()
{
	image = new ImageRect(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(80, 300));
	player = new ImageRect(Vector2(0, 0), Vector2(80, 300));

	bg = new ScrollingBG(Vector2(WIN_CENTER_X, WIN_CENTER_Y),
		Vector2(WIN_WIDTH, WIN_HEIGHT));
}

ImageScene::~ImageScene()
{
	delete player;
	delete image;
	delete bg;
}

void ImageScene::Update()
{
	player->pos = mouse_pos;

	if (KEY_PRESS(VK_F2))
		image->pos = { WIN_CENTER_X, WIN_CENTER_Y };



	if(Control::Get()->Press(VK_LEFT)) // 가상 키 코드를 이용해 어떤 키를 검사할 것인지를 명시
		image->pos.x -= WIN_WIDTH / 2 * DELTA;




	// assert(image->pos.x > 0);
	// 0 이하의 값이 들어갔을 경우 런타임 경고문을 발생시키며,
	// 무시하지 않을 경우 여기서 코드 실행을 일시 중단시키는 코드

	// 이 기능을 이용하면 직접 중단점을 정확한 타이밍에 클릭하려 시도하지 않아도,
	// 조건만 맞는 즉시 프로그램을 일시정지하여 각 인스턴스의 값들을 확인할 수 있음

	// 단, 이 함수는 "디버그 모드"일 때만 동작


	//if (image->pos.x <= 0)
	//	image->pos.x += WIN_WIDTH;

	player->Update();
	image->Update();
	bg->Update();
}

void ImageScene::Render()
{
	bg->Render();
	player->Render();
	image->Render();
}

void ImageScene::PostRender()
{
	ImGui::SliderFloat2("image's pos", (float*)&image->pos, -WIN_WIDTH, WIN_WIDTH);
	ImGui::SliderFloat3("image's rot", (float*)&image->rot, -2 * M_PI, 2 * M_PI);
	// SliderFloatX : X개의 실수 데이터를 받아서,
	//				  이를 슬라이더 바 형식으로 ImGui 창에 출력하여
	//				  해당 데이터의 현재 값의 확인 및 직접적인 조절을 시행
	
	// 각각의 매개변수는 다음과 같은 의미 - 
	/*
	문자열 - "이 바를 통해서 관리하게 될 데이터에 붙인 이름"으로,
			ImGui에서의 변수명 같은 것이라 보면 OK
			-> 같은 이름을 다른 ImGui 항에서 사용할 경우,
			실제로 가리키는 데이터가 다름에도 불구하고 두 값을 전부 건드리게 된다
			따라서 가급적이면 이 이름 = ID가 일치하지 않게 만들 것

	변수 포인터 - "이 바를 통해서 관리할 데이터의 주소"
				 몇 개의 데이터를 다루건 그 시작점만 알면 되므로,
				 실제 데이터 개수가 일치하지 않는다 하더라도
				 바에서 다루는 데이터의 개수보다 많기만 하다면 OK

	MIN, MAX - 이 항에 만들어진 슬라이더 바의 최소값과 최대값
			   가리키는 데이터의 한도 자체는 이 값과 전혀 상관없지만,
			   이 바 자차게 표시 가능한 한도값과
			   그 동시에 이 바를 통해서 조절 가능한 값의 한도를 이걸 통해서 설정
	*/

	player->PostRender();
}
