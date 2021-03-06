#include "big_button.h"

#include <logger/logger.h>

#include <../gameClient/game.h>

BigButton::BigButton(std::string texturePath, std::string texto) {

    buttonFont = gGame._globalFont;

    this->setSize(sf::Vector2f(256, gGame._screenHeight * 0.6f));
    this->setOrigin(this->getGlobalBounds().width / 2, 0.f);

    buttonText = sf::Text(texto, buttonFont);
    buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height * 2);
    buttonText.setPosition(this->getGlobalBounds().width / 2, this->getGlobalBounds().height);

    //if (!buttonTexture.loadFromFile(texturePath)) {
    //
    //    _LOG(Log::LOGLVL_ERROR, "Error cargando la textura de BigButton");
    //}

    buttonSprite.setTexture(buttonTexture);
}

void BigButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    target.draw(static_cast<sf::RectangleShape>(*this));
    target.draw(buttonText, states);
}

BigButton::~BigButton() {
}
