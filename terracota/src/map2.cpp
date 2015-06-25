#include "map2.h"
#include "layer.h"
#include "background.h"
#include "ui.h"
#include "bat.h"


Map2::Map2(ObjectID id)
	: Level(id), m_stage(nullptr)
{
	m_stage = new Stage(this,"map2"); 
	add_child(m_stage);
	generate_map();
}

Map2::~Map2()
{
}

void 
Map2::generate_map()
{
	Environment* env = Environment::get_instance();
	shared_ptr<Texture> handle;
	handle = get_texture("res/images/stages/second_map/0.png");

	Background* background = new Background("background",handle);

	env->camera->set_limits(Rect(0, 0, 3011, 1440));

    //**** ADICIONANDO OBJETOS NO CENARIO   ***////
    handle = get_texture("res/images/stages/second_map/1.png"); 
    Layer* agua = new Layer("agua",handle,0,0,701,360);
    agua->set_position(1850,760);
	
    handle = get_texture("res/images/stages/second_map/10.png"); 
    Layer* casa = new Layer("casa",handle,0,0,439,496);
    casa->set_position(1673,325);

    handle = get_texture("res/images/stages/second_map/2.png"); 
    Layer* door = new Layer("door",handle,0,0,249,249);
    door->set_position(956,380);

    handle = get_texture("res/images/stages/second_map/7.png"); 
    Layer* madeira = new Layer("madeira",handle,0,0,211,102);
    madeira->set_position(1315,630);

    handle = get_texture("res/images/stages/second_map/11.png");
    Layer* arvore =  new Layer("arvore",handle,0,0,514,370);
    arvore->set_position(560,300);

    handle = get_texture("res/images/stages/second_map/14.png");
    Layer* grama1 =  new Layer("grama1",handle,0,0,2377,404);
    grama1->set_position(400,500);

    handle = get_texture("res/images/stages/second_map/3.png");
    Layer* grama2 =  new Layer("grama2",handle,0,0,511,357);
    grama2->set_position(400,700);

    handle = get_texture("res/images/stages/second_map/5.png");
    Layer* grama3 =  new Layer("grama3",handle,0,0,511,357);
    grama3->set_position(1900,550);

    handle = get_texture("res/images/stages/second_map/4.png");
    Layer* grama4 =  new Layer("grama4",handle,0,0,511,357);
    grama4->set_position(100,520);

    handle = get_texture("res/images/stages/second_map/6.png");
    Layer* madeira2 =  new Layer("madeira2",handle,0,0,206,113);
    madeira2->set_position(220,700);

    handle = get_texture("res/images/stages/second_map/13.png");
    Layer* pedra1 =  new Layer("pedra1",handle,0,0,168,105);
    pedra1->set_position(400,650);

    handle = get_texture("res/images/stages/second_map/9.png");
    Layer* galho =  new Layer("galho",handle,0,0,147,449);
    galho->set_position(2370,280);

    handle = get_texture("res/images/stages/second_map/8.png");
    Layer* casa2 =  new Layer("casa2",handle,0,0,463,791);
    casa2->set_position(6,550);

    m_stage->add_layer(background);
    m_stage->add_layer(agua);
    m_stage->add_layer(casa);
    m_stage->add_layer(door);
    m_stage->add_layer(madeira);
    m_stage->add_layer(madeira2);
    m_stage->add_layer(grama4);
    m_stage->add_layer(pedra1);
    m_stage->add_layer(grama1);
    m_stage->add_layer(grama2);
    m_stage->add_layer(grama3);
    m_stage->add_layer(arvore);
    m_stage->add_layer(galho);
    m_stage->add_layer(casa2);
}


shared_ptr<Texture> 
Map2::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}
