#ifndef GAMETEXTVIEW_H
#define GAMETEXTVIEW_H

#include <QTextEdit>
#include "GameView.h"
// ... other includes ...

class GameTextView : public QTextEdit, public GameView {
    Q_OBJECT

public:
    GameTextView(QWidget* parent = nullptr) : QTextEdit(parent) {
        // Set the common text-based background
        QString textBackground = generateTextBackground();
        this->setText(textBackground);
        // Configure the text edit as necessary
    }

    // derived class specific addEntity method here to add EntityTextItems to the text edit
    void addEntity(std::unique_ptr<EntityTextItem> item);
    
    // Implement GameView interface methods here, if any
    void updateView() override;
    void drawWorld() override;
    void switchView() override;
    void zoomIn() override;
    void zoomOut() override;
    void animateEntityAction(const QString& action) override;

private:
    QString generateTextBackground() {
        // Generate and return a QString representing the text-based background
        QString background;
        // ... generate your background ...
        return background;
    }
   
};

#endif // GAMETEXTVIEW_H