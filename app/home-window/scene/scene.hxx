#ifndef SCENE_HXX
#define SCENE_HXX

#include <QGraphicsScene>

namespace project {

class Scene : public QGraphicsScene
{
	Q_OBJECT

public:
	explicit Scene(QObject* parent = nullptr);
	virtual ~Scene() override = default;
};

}  // namespace project

#endif  // SCENE_HXX
