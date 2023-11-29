#include "GameTextView.h"

// member functions...
void GameTextView::addEntity(const Entity& entity) {
    std::unique_ptr<EntityTextItem> entityTextItem = std::make_unique<EntityTextItem>(entity);
    entityTextItems.push_back(std::move(entityTextItem));
}
void GameTextView::updateView() {
    // Update the scene to reflect the changes
    emit updateSceneSignal(); // Emit the signal to indicate that the scene needs updating
}
void GameTextView::setBackground(int backgroundNumber){}

void GameTextView::animateEntityAction(QString const&){}
/** zooming should be handeled by graphicsView
void GameTextView::zoomIn(){}
void GameTextView::zoomOut(){} */


