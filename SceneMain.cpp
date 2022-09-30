#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	//グラフィックファイル名
	const char* const kPlayerGraphicFilename = "data/char.png";
}

SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle - 1;
	}
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph(kPlayerGraphicFilename, Player::kPlayerGraphicDivNum, Player::kPlayerGraphicDivX, Player::kPlayerGraphicDivY, Player::kPlayerGraphicSizeX, Player::kPlayerGraphicSizeY, m_hPlayerGraphic);

	for (int  i = 0; i < Player::kPlayerGraphicDivNum; i++)
	{
		m_player.setHandle(i,m_hPlayerGraphic[i]);
	}
	m_player.init();
}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
}