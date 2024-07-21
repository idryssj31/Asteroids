#include "Map.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Map::m_mapLenght{ 0 };
int Map::m_mapWeight{ 0 };

void Map::Init(int _lenght, int _weight)
{
    // on envoie un message d’erreur si l’espace était déjà initialisé
    if (m_mapLenght != 0 || m_mapWeight != 0) {
        std::cerr << "Attention : l’espace était déjà initialisé !" << std::endl;
    }
    m_mapLenght = _lenght;
    m_mapWeight = _weight;
}

Map::Map()
{
    if (m_mapLenght == 0 || m_mapWeight == 0) {
        std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
    }
}

Map::Map(float _posX, float _posY) : m_x(_posX), m_y(_posY)
{
    Recompute();
}

void Map::operator+=(Vector const& _vector)
{
    m_x += _vector.x;
    m_y += _vector.y;
    Recompute();
}

float Map::CalculateDistance(Map const& _other) const
{
    auto delta = Vector{ static_cast<float>(std::min({abs(m_x - _other.m_x), abs(m_x - _other.m_x - m_mapLenght), abs(m_x - _other.m_x + m_mapLenght)})), static_cast<float>(std::min({abs(m_y - _other.m_y), abs(m_y - _other.m_y - m_mapWeight), abs(m_y - _other.m_y + m_mapWeight)})) };
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}

void Map::Recompute()
{
    while (m_x > m_mapLenght) {
        m_x -= m_mapLenght;
    }
    while (m_x < 0) {
        m_x += m_mapLenght;
    }
    while (m_y > m_mapWeight) {
        m_y -= m_mapWeight;
    }
    while (m_y < 0) {
        m_y += m_mapWeight;
    }
}
