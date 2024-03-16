#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <cmath>

class Calculator : public QWidget {
public:
    Calculator(QWidget *parent = nullptr) : QWidget(parent) {
        // Set up the layout
        QGridLayout *layout = new QGridLayout(this);
        QLineEdit *display = new QLineEdit();
        layout->addWidget(display, 0, 0, 1, 5);

        // Create buttons for numbers and operations
        const QString buttons[5][5] = {
            {"7", "8", "9", "/", "sqrt"},
            {"4", "5", "6", "*", "pow"},
            {"1", "2", "3", "-", "sin"},
            {"0", ".", "=", "+", "cos"},
            {"Clear", "Clear All", "Backspace", "(", ")"}
        };

 for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                QPushButton *button = new QPushButton(buttons[i][j]);
                layout->addWidget(button, i + 1, j);
                connect(button, &QPushButton::clicked, this, [=]() {
                    handleButtonPress(button->text(), display);
                });
            }
        }

        setLayout(layout);
    }
