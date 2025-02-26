#pragma once
class DungreedScene :public Scene
{
public:
	DungreedScene();
	~DungreedScene();

	void PreUpdate() override;
	void Update() override;

	void Render() override;
	void PostRender() override;

private:

	shared_ptr<class Player> _player;
	shared_ptr<Quad> _bg;
	shared_ptr<class Track> _track;

	shared_ptr<class Bow_Monster> _boss;

	shared_ptr<class HpBar> _hpBar;

	shared_ptr<Effect> _effect;

};

