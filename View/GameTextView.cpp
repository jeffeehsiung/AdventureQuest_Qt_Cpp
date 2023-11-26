#include "GameTextView.h"

// member functions...
void GameTextView::addEntity(std::unique_ptr<EntityTextItem> item) {
    // Add the item to the text edit
    this->append(item->getText());
    // Store the unique pointer
    entityTextItems.push_back(std::move(item));
}

void GameTextView::updateView() {
    // Update the view as necessary
}

void GameTextView::drawWorld() {
    // Draw the world as necessary
}