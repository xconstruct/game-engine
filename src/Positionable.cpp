#include "Positionable.h"
#include <SDL/SDL.h>

Positionable::Positionable(float x, float y, float w, float h) {
	m_pos = Vector2(x, y);
	m_size = Vector2(w, h);
}

const Vector2 &Positionable::pos() const {
	return m_pos;
}

void Positionable::setPos(float x, float y) {
	m_pos.x = x;
	m_pos.y = y;
}

void Positionable::setPos(const Vector2 &pos) {
	m_pos = pos;
}

void Positionable::addPos(float x, float y) {
	m_pos.x += x;
	m_pos.y += y;
}

void Positionable::addPos(const Vector2 &pos) {
	m_pos += pos;
}

const Vector2 &Positionable::size() const {
	return m_size;
}

void Positionable::setSize(float w, float h) {
	m_size.x = w;
	m_size.y = h;
}

void Positionable::setSize(const Vector2 &size) {
	m_size = size;
}
