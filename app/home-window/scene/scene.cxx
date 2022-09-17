#include "scene.hxx"

#include <QGraphicsItem>

namespace project {

constexpr auto frame_scale = 2.0f / 3.0f;
constexpr auto frame_width = 852.0f * frame_scale;
constexpr auto frame_height = 480.0f * frame_scale;

Scene::Scene(QObject* parent)
    : QGraphicsScene(0, 0, frame_width, frame_height, parent)
{
	setBackgroundBrush(QBrush(QColor(0xFE, 0xFE, 0xFE)));
	auto* square = new QGraphicsRectItem(width() / 2.0f - 32, height() / 2.0f - 32, 64, 64);
	addItem(square);
}

}  // namespace project
