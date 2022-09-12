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
	~HomeWindow() override = default;

signals:
	void quit_confirmed();

private:
	QLayout* _layout;  // QWidget (base class) will own layout, but useful to access from member
};

}  // namespace project

#endif  // HOME_WINDOW_HXX
