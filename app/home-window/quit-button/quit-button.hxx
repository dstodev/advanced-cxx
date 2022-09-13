#ifndef QUIT_BUTTON_HXX
#define QUIT_BUTTON_HXX

#include <QPushButton>

namespace project {

class QuitButton : public QPushButton
{
	Q_OBJECT

public:
	explicit QuitButton(QWidget* parent = nullptr);
	virtual ~QuitButton() override = default;

signals:
	void quit_confirmed();
};

}  // namespace project

#endif  // QUIT_BUTTON_HXX
