#ifndef TEXTVIEWCONTROLLER_H
#define TEXTVIEWCONTROLLER_H

#include "ViewController.h"
#include <QTextEdit>

class TextViewController : public ViewController {
private:
    QTextEdit* textView;

public:
    TextViewController(QTextEdit* view) : textView(view) {}

    void updateView() override {
        // Implement how the text elements are updated, e.g., refreshing the text display
        textView->update();
    }
};

#endif // TEXTVIEWCONTROLLER_H
