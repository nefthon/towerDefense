#include "connection_manager.h"

#include "../../game.h"

ConnectionManager::ConnectionManager() {

    this->setCenter((float)gGame._screenWidth * -0.5f, (float)gGame._screenHeight / 2.0f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    _networkStatus = Disconnected;
    _fuente = gGame._globalFont;
    _statusTextColor = sf::Color(255, 255, 255);

    _statusText.setFont(_fuente);
    _statusText.setString("Cargando...");
    _statusText.setOrigin(_statusText.getGlobalBounds().width / 2, _statusText.getGlobalBounds().height / 2);
    _statusText.setPosition(this->getSize().x / 2, this->getSize().y * 0.75f);
}

short ConnectionManager::getNetworkStatus() {

    return _networkStatus;
}

void ConnectionManager::setNetworkStatus(short status) {

    _networkStatus = status;
}

void ConnectionManager::setStatusText(std::string t) {

    _previousText = _statusText;
    _statusText.setString(t);
    
    _animating = true;
}

void ConnectionManager::onTick() {

    if (_animating) { doAnimate(); }

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(_statusText);
    gGame._gameWindow->draw(_previousText);
}

void ConnectionManager::doAnimate() {

    if (_animating) {

        _targetDistance = ((gGame._screenHeight * 0.4f) - (_previousText.getPosition().y));

        if (_targetDistance < -1.f) {
            _previousText.move(0, _targetDistance * _easingQty);
            _statusTextColor.a = (sf::Uint8)-_targetDistance;
            _previousText.setFillColor(_statusTextColor);
        }
        else {
            _targetDistance = 0;
            _animating = false;
        }
    }
}

void ConnectionManager::handleInput(sf::Event &event) {

}

ConnectionManager::~ConnectionManager() {
}