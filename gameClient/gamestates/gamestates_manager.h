#pragma once
#include <map>
#include <string>

#include "gamestate.h"

class GameStatesManager {   
private:
    std::map<std::string, GameState*> estados;
    GameState* estadoActual;
	bool _gameStarted;

public:

    /*
    M�todo que se ejecuta solo la primera vez, para a�adir los estados esenciales (menu, partida...)
    */
    void initEstados();
    /*
    Obtener el estado actual
    */
    GameState* getEstadoActual();

    std::string getEstadoActualNombre();
    /*
    Cambiar el estado actual
    */
    void setEstadoActual(std::string estado);
    /*
    Crear una partida nueva
    */
    void newGame(bool iniciarAutomaticamente = true);
    /*
	Comprobar si hay una partida existente
	*/
	bool isGameStarted();

    GameStatesManager();
    ~GameStatesManager();
};