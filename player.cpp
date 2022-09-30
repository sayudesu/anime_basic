#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	//キャラクターのアニメーション1コマ当たりのフレーム数
	constexpr int kAnimeChangeFrame = 8;
}

Player::Player()
{
	for (auto& handle : m_handle)
	{
		handle - 1;
	}
	m_animeNo = 0;
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kPlayerGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kPlayerGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_animeNo = 0;
	m_dirNo = 0;
	m_animeFreme = 0;
}

void Player::update()
{	
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isKey = false;
	if (padState & PAD_INPUT_UP)
	{
		m_dirNo = 3;
		isKey = true;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_dirNo = 0;
		isKey = true;
	}
	else if (padState & PAD_INPUT_LEFT)
	{
		m_dirNo = 1;
		isKey = true;
		
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_dirNo = 2;
		isKey = true;
	}

	//キャラクターのアニメーション
	if(isKey) m_animeFreme++;

	if (m_animeFreme >= kPlayerGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFreme = 0;
	}

	int tempAnimeNo = m_animeFreme / kAnimeChangeFrame;
	m_animeNo = m_dirNo * kPlayerGraphicDivX +tempAnimeNo;

}

void Player::draw()
{
	
	DrawExtendGraph(32, 32, Game::kScreenWidth - 32, Game::kScreenHeight - 32, m_handle[m_animeNo], true);
}