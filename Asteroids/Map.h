#pragma once

// Game includes
#include "Vector.h"

class Map
{
public:
    static void Init(int _lenght, int _weight); // m�thode static car l�espace sera le m�me pour tous les objets Coordonnees
    static inline int GetLenght() { return m_mapLenght; };
    static inline int GetWeight() { return m_mapWeight; };
    Map();
    Map(float _posX, float _posY);

    // inline pour plus de performance, revient en terme de performance � un acc�s direct � l�attribut
    inline float getX() const { return m_x; };
    inline float getY() const { return m_y; };

    void operator+=(Vector const& _vector);
    float CalculateDistance(Map const& _other) const;

private:
    void Recompute(); // recalcule les coordonn�es pour qu�elles soient dans les limites ; inutile d�y acc�der de l�ext�rieur, donc priv�e
    float m_x{ m_mapLenght / 2.f };
    float m_y{ m_mapWeight / 2.f };

    // longueur et hauteur de l�espace sont static, partag�s par tous les objets Coordonnees
    static int m_mapLenght;
    static int m_mapWeight;
};

