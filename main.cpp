#include <iostream>
using namespace std;

// Clase Balon
class Balon {
public:
    float x, y;
    float vx, vy;

    void actualizar() {
        vy -= 9.8; // gravedad
        x += vx;
        y += vy;
    }
};

// Clase Jugador
class Jugador {
public:
    float x, y;
    float velocidad;

    void moverse(float dx) {
        x += dx * velocidad;
    }

    void saltar() {
        cout << "Saltando..." << endl;
    }

    void golpearBalon(Balon &b) {
        b.vy = 15;
        cout << "Golpeo el balon" << endl;
    }
};

// Clase RivalIA
class Rival : public Jugador {
public:
    void decidirMovimiento(Balon b) {
        if (b.x > x) {
            moverse(1);
        } else {
            moverse(-1);
        }
    }
};

// MAIN
int main() {
    Jugador jugador;
    Rival rival;
    Balon balon;

    jugador.velocidad = 2;
    rival.velocidad = 1.5;

    jugador.moverse(1);
    jugador.saltar();
    jugador.golpearBalon(balon);

    rival.decidirMovimiento(balon);

    return 0;
}
