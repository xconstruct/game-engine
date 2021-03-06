#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <memory>
#include <utility>

#include "Color.h"
#include "Rect.h"
#include "components/Positionable.h"

enum class DrawLayer {
	Background,
	World,
	Foreground,
};

enum class BlendMode {
	Add,
	Blend,
	Screen,
};

class Renderable : public Positionable {
public:
	typedef std::shared_ptr<Renderable> Ptr;

	Renderable();
	virtual ~Renderable();

	DrawLayer drawLayer() const;
	void setDrawLayer(DrawLayer layer);

	float zIndex() const;
	void setZIndex(float zIndex);

	const Vector2 &parallax() const;
	void setParallax(const Vector2 &parallax);

	const Rect &boundingRect() const;
	void setBoundingRect(const Rect &rect);

	float scale() const;
	void setScale(float scale);

	const Color &color() const;
	void setColor(const Color &color);

	BlendMode blendMode() const;
	void setBlendMode(BlendMode blendMode);

	virtual void render();

private:
	float m_zIndex;
	DrawLayer m_drawLayer;
	Vector2 m_parallax;
	Rect m_boundingRect;
	float m_scale;
	Color m_color;
	BlendMode m_blendMode;
};

#endif /* end of include guard: RENDERABLE_H */
