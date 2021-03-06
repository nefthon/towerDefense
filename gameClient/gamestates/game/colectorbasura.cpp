#include "colectorbasura.h"
#include "units/unit_manager.h"

ColectorBasura::ColectorBasura() {
}


ColectorBasura::~ColectorBasura() {
}

void ColectorBasura::onTick(UnitManager* listado) {
    // Colector de basura de enemigos.
    while (size()) {    // Mientras la lista no est� vac�a:
        Unit* pUnit = at(size() - 1);    // �ltimo enemigo en el colector.
        if (pUnit)
            listado->borraUnit(pUnit);    // Lo borra del listado principal.
        pop_back();                // Borra la �ltima entrada del colector.
    }
}