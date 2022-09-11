#ifndef HOME_WINDOW_HXX
#define HOME_WINDOW_HXX

#include <memory>

#include <QGridLayout>
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
	QGridLayout* _layout;
};

}  // namespace project

#endif  // HOME_WINDOW_HXX
