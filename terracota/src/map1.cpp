#include "map1.h"
#include "layer.h"
#include "background.h"
#include "ui.h"
#include "bat.h"


Map1::Map1(ObjectID id)
	: Level(id), m_stage(nullptr)
{
	m_stage = new Stage(this,"map1"); 
	add_child(m_stage);
	generate_map();
}

Map1::~Map1()
{
}

void 
Map1::generate_map()
{
	Environment* env = Environment::get_instance();
	shared_ptr<Texture> handle;
	handle = get_texture("res/images/stages/first_map/map.png");

	Background* background = new Background("background",handle);

	env->camera->set_limits(Rect(0, 0, 3423, 1552));

    //**** ADICIONANDO OBJETOS NO CENARIO   ***////
    handle = get_texture("res/images/stages/first_map/fonte.png"); 
    Layer* fonte = new Layer("fonte",handle,0,0,470,325);
    fonte->set_position(1490,875);
	

    handle = get_texture("res/images/stages/first_map/casas.png"); 
    Layer* casas = new Layer("casas",handle,0,0,1397,699);
    casas->set_position(-10,390);


    handle = get_texture("res/images/stages/first_map/arvore.png");
    Layer* arvore = new Layer("arvore",handle,0,0,614,456);
    arvore->set_position(1750,350);

    handle = get_texture("res/images/stages/first_map/luz.png");
    Layer* luz =  new Layer("luz",handle,0,0,1626,1275);
    luz->set_position(1520,200);


    handle = get_texture("res/images/stages/first_map/calcada1.png");
    Layer* calcada1 =  new Layer("calcada1",handle,0,0,2582,647);
    calcada1->set_position(525,700);


    /** colocando objetos em ordem **/

    m_stage->add_layer(background);
    m_stage->add_layer(calcada1);
    m_stage->add_layer(fonte);
    m_stage->add_layer(casas);
    m_stage->add_layer(arvore);
    m_stage->add_layer(luz);

}


shared_ptr<Texture> 
Map1::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}
