#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <memory>
#include <QObject>
#include <QWidget>
#include <vector>
#include "View/Game2DView.h"
#include "View/GameTextView.h"

/**
 * The header file you provided for the ViewController class is a template class.
 * Typically, for template classes, the implementation (i.e., the function definitions)
 * is included in the header file itself. This is because the compiler needs access to
 * the template code during compilation to generate the necessary code for the specific
 * template parameter types.
*/
template <typename ViewType>
class ViewController : public QObject {
public:
    // Constructor that takes ownership of a view
    ViewController() : QObject(nullptr), currentViewIndex(0) {
        // Initialize and configure your views here
        addView<Game2DView>();
        addView<GameTextView>();

        // Connect signals and slots for synchronization
        for (auto& view : views) {
            connect(view.get(), &ViewType::updateSceneSignal, this, &ViewController::updateViews);
        }

        // Set the initial view
        setCurrentView(currentViewIndex);
    }

    QWidget* getCurrentView() const {
        return views[currentViewIndex];
    }

public slots:
    // Slot to switch views
    void switchView() {
        currentViewIndex = (currentViewIndex + 1) % views.size();
        setCurrentView(currentViewIndex);
    }

private slots:
    // Slot to update all views based on game state
    void updateViews() {
        for (auto& view : views) {
            view->updateView();
        }
    }

private:
    /**
     * Keep track of multiple views and update all of them when needed
    **/
    std::vector<std::unique_ptr<ViewType>> views;
    int currentViewIndex;

    template<typename T>
    void addView() {
        views.push_back(std::make_unique<T>());
    }

    void setCurrentView(int index) {
        for (int i = 0; i < views.size(); ++i) {
            views[i]->setVisible(i == index);
        }
        updateViews();
    }
};

#endif // VIEWCONTROLLER_H
