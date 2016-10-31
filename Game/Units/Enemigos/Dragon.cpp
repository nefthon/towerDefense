#include "Dragon.h"
#include "../../Game.h"

Dragon::Dragon()
{
	int randomNumber = rand() % ((4 - 0) + 1);

	setNombre("Dragon prueba");
	setRutaImagen("media/unit_dragon.png");
	animatedSprite.setDireccion(randomNumber);
    animatedSprite._speed = 1.0f;
}


Dragon::~Dragon()
{
}
