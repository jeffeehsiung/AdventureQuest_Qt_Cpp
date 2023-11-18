// TextViewController.h

#ifndef TEXTVIEWCONTROLLER_H
#define TEXTVIEWCONTROLLER_H

#include "ViewController.h"
#include "GameTextView.h"
#include "EntityTextItem.h"

class TextViewController : public ViewController<GameTextView, EntityTextItem> {
public:
    using ViewController::ViewController;  // Inherit constructors

    void complexTextualDescription() {
        // Complex textual logic specific to the GameTextView
    }

    // ...other specialized methods for text...
};

#endif // TEXTVIEWCONTROLLER_H
