#include "quit-button.hxx"

#include <QMessageBox>


namespace project {

QuitButton::QuitButton(QWidget* parent)
    : QPushButton("&Quit", parent)
{
	auto* confirm = new QMessageBox(this);
	confirm->setText("Whoa! Are you sure you want to quit?");
	confirm->setInformativeText("How sure are you?");
	confirm->setMinimumSize(200, 200);  // suppresses a warning on Windows
	confirm->setStandardButtons(QMessageBox::Yes | QMessageBox::No);  // Clicking Yes will emit the accepted() signal
	confirm->setWindowTitle("Sureness Verifier");

	connect(this, &QPushButton::clicked, confirm, &QMessageBox::exec);
	connect(confirm, &QMessageBox::accepted, this, &QuitButton::quit_confirmed);
}

}  // namespace project
