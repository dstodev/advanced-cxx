#ifndef HOME_WINDOW_HXX
#define HOME_WINDOW_HXX

#include <memory>

#include <QGridLayout>
#include <QPushButton>

namespace project {

// https://wiki.qt.io/Qt_for_Beginners

class HomeWindow : public QWidget
{
	Q_OBJECT
public:
	explicit HomeWindow(QWidget* parent = nullptr);
	~HomeWindow() override = default;

private:
	QGridLayout* _layout;
};

}  // namespace project

#endif  // HOME_WINDOW_HXX
