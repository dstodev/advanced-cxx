#ifndef HOME_WINDOW_HXX
#define HOME_WINDOW_HXX

#include <memory>

#include <QLayout>
#include <QWidget>

namespace project {

class HomeWindow : public QWidget
{
	Q_OBJECT

public:
	explicit HomeWindow(QWidget* parent = nullptr);
	virtual ~HomeWindow() override = default;

private:
	QLayout* _layout;  // Base class will own, but useful to access from member
};

}  // namespace project

#endif  // HOME_WINDOW_HXX
