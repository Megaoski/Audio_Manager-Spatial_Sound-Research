#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "j2Entity.h"
#include "j2EntityManager.h"
#include "Player.h"
#include "Enemy.h"
#include "j1Render.h"


j1Scene::j1Scene() : j1Module()
{
	name = "scene";
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	

	
	P1 = App->entity_manager->CreateEntity(P1, ENTITY_TYPE::PLAYER, {70,900}, fx_player, nullptr, 1, -1, 100, 270, 30);	
	DO = App->entity_manager->CreateEntity(DO, ENTITY_TYPE::ENEMY, {200,700 }, fx_do, nullptr/*"audio/fx/do.wav"*/, 2, -1, DEFAULT_FX_VOLUME, 0, 200);
	/*RE = App->entity_manager->CreateEntity(RE, ENTITY_TYPE::ENEMY, { 300,800 }, fx_re, "audio/fx/re.wav", 3, -1, DEFAULT_FX_VOLUME, 45, 200);
	MI = App->entity_manager->CreateEntity(MI, ENTITY_TYPE::ENEMY, { 400,900 }, fx_mi, "audio/fx/mi.wav", 4, -1, DEFAULT_FX_VOLUME, 90, 200);
	FA = App->entity_manager->CreateEntity(FA, ENTITY_TYPE::ENEMY, { 300,1000 }, fx_fa, "audio/fx/fa.wav", 5, -1, DEFAULT_FX_VOLUME, 135, 200);
	SOL = App->entity_manager->CreateEntity(SOL, ENTITY_TYPE::ENEMY, { 70,1100 }, fx_sol, "audio/fx/sol.wav", 6, -1, DEFAULT_FX_VOLUME, 180, 200);*/
	LA = App->entity_manager->CreateEntity(LA, ENTITY_TYPE::ENEMY, { -100,1000 }, fx_la, nullptr, 7, -1, DEFAULT_FX_VOLUME, 225, 200);
	/*SI = App->entity_manager->CreateEntity(SI, ENTITY_TYPE::ENEMY, { -200,900 }, fx_si, "audio/fx/si.wav", 8, -1, DEFAULT_FX_VOLUME, 270, 200);*/
	/*DO2 = App->entity_manager->CreateEntity(DO2, ENTITY_TYPE::ENEMY, { -200,700 }, fx_do2, nullptr, 9, -1, DEFAULT_FX_VOLUME, 315, 200);*/

	//TEST = App->entity_manager->CreateEntity(TEST, ENTITY_TYPE::ENEMY, { -200,700 }, fx_test_spatial, nullptr/* "audio/fx/change.wav"*/, 10, -1, DEFAULT_FX_VOLUME, 90, 200);

	//LOAD FX FOR WHEN NO USING ENTITIES
	fx_do = App->audio->LoadFx("audio/fx/do.wav");
	fx_re = App->audio->LoadFx("audio/fx/re.wav");
	fx_mi = App->audio->LoadFx("audio/fx/mi.wav");
	fx_fa = App->audio->LoadFx("audio/fx/fa.wav");
	fx_sol = App->audio->LoadFx("audio/fx/sol.wav");
	fx_la = App->audio->LoadFx("audio/fx/la.wav");
	fx_si = App->audio->LoadFx("audio/fx/si.wav");
	fx_do2 = App->audio->LoadFx("audio/fx/do2.wav");
	
	
	fx_test_spatial = App->audio->LoadFx("audio/fx/change.wav");

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;
	

	int x, y;
	
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	//SPATIAL SOUND WHILE MOVING BETWEEN ENTITIES
	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		App->audio->Spatial(DO, P1, fx_do, 17, 0, 10);
		App->audio->Spatial(LA, P1, fx_la, 18, 0, 10);
	}


	////EXERCISE NOTAS ENTITIES
	//if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	//	App->audio->PlayFx(fx_do, 1, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	//	App->audio->PlayFx(fx_re, 2, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	//	App->audio->PlayFx(fx_mi, 3, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	//	App->audio->PlayFx(fx_fa, 4, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
	//	App->audio->PlayFx(fx_sol, 5, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_Y) == KEY_DOWN)
	//	App->audio->PlayFx(fx_la, 6, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_U) == KEY_DOWN)
	//	App->audio->PlayFx(fx_si, 7, 0, DEFAULT_FX_VOLUME, NULL, NULL);
	//if (App->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
	//	App->audio->PlayFx(fx_do2, 8, 0, DEFAULT_FX_VOLUME, NULL, NULL);


	//AUDIO TESTING

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		App->audio->PauseMusic();
	}

	if (App->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
	{
		App->audio->MusicPos(0);//WE RESET THE SONG TO THE START
		App->audio->ResumeMusic();
	}
	
	if (App->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN)
	{
		App->audio->SetVolume(-1, MIX_MAX_VOLUME / 2);
	}

	
	if (App->input->GetKey(SDL_SCANCODE_J) == KEY_DOWN)
	{
		App->audio->Channels(16);
		LOG("CHANNELS: %d", App->audio->Channels(-1));//ME DICE EL NUMERO DE CANALES ALOCADOS
		LOG("CHANNELS PLAYING: %d", App->audio->ChannelsPlaying(-1));//ME DICE EL NUMERO DE CANALES SIENDO USADOS
		LOG("DECODERS PLAYING: %d", App->audio->Decoders());//ME DICE EL NUMERO DE MUSIC DECODERS
	}

	

	
	
	
	LOG("ENTITIES: %d", App->entity_manager->GetEntitiesInfo().size()); //ME DICE CUANTAS HAY, 6

		
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	
	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
