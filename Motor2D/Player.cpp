#include "Player.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Audio.h"
#include "j1Scene.h"
#include "p2Log.h"
#include <math.h>

Player::Player() : j2Entity(ENTITY_TYPE::PLAYER)
{
}

Player::~Player()
{
}

bool Player::Start()
{
	entity_rect = { 13,4,32,57 };
	entity_tex = App->tex->Load("textures/sprites.png");
	
	
	if (!clock)
	{
		timer.Start();
		
	}

	

	/*App->audio->PlayFx(App->scene->fx, 1, -1, 10, 90, 30);*/

	return true;
}

bool Player::Update(float dt, bool do_logic)
{


	/*if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)*/
	//App->audio->Spatial(App->scene->TEST, App->scene->P1, App->scene->fx_test_spatial, 10, -1, 10);


	

	iPoint last_pos = position;

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		position.y -= 5;
		
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		position.y += 5;
		
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		position.x -= 5;
		
	}
	

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		position.x += 5;
		
	}

	

	App->render->FollowPlayer(position.x - last_pos.x, position.y - last_pos.y);

	
	if(!clock)
		LOG("TIMER: %f", timer.ReadSec());
	return true;
}

bool Player::CleanUp()
{
	App->tex->UnLoad(entity_tex);
	return true;
}

void Player::Draw()
{
	App->render->Blit(entity_tex, position.x - 16, position.y -64, &entity_rect);
}

