#include <iostream>

#include "Tile.h"
#include "../../Game.h"
#include "../SpriteManager.h"
#include "Grid.h"

Tile::Tile() {
	if (!sfSprite.getTexture()) {
		sfSprite = gGame._spriteManager->loadFromTexture("tile1", *gGame._textureManager->loadFromFile("tile", "media/Tiles/tile_gris_1.png"));
	}
}


Tile::~Tile() {
}

void Tile::attatchToGrid(Grid* grid, bool isBorderTile) {
    _grid = grid;
    if (isBorderTile)
		sfSprite.setColor(sf::Color::Black);    // TODO cambiar esto para que muestre otro tile en vez de colorearlo (cosa que no hace).

	sfSprite.setPosition((float)(_grid->_posX * 32), (float)(_grid->_posY * 32));
}

void Tile::detatchFromGrid() {
    _grid = nullptr;
}

sf::Sprite Tile::getSprite() {
    return gGame._spriteManager->getRef("tile");
}
