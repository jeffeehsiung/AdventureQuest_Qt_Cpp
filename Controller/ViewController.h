#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <memory>
#include <QObject>
#include <QWidget>
#include <vector>
#include "View/Game2DView.h"
#include "View/GameTextView.h"
#include "Model/EnemyModel.h"
#include "Model/ProtagonistModel.h"
#include "Model/TileModel.h"


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
    ViewController(
//                   QGraphicsView* graphicsView,
                   const std::vector<EnemyModel*>& enemyModels,
                   const std::vector<TileModel*>& tileModels,
                   const std::vector<ProtagonistModel*>& protagonistModels)
        : QObject(nullptr), currentViewIndex(0),
//        graphicsView(graphicsView),
        enemyModels(enemyModels),
        tileModels(tileModels),
        protagonistModels(protagonistModels) {
        // Initialize and configure your views here
        addView<Game2DView>();
//        addView<GameTextView>();

//        // Create a QGraphicsScene
//        QGraphicsScene* scene = new QGraphicsScene(this);

        // Connect signals and slots for synchronization
        for (auto& view : views) {
            connect(view.get(), &ViewType::updateSceneSignal, this, &ViewController::updateViews);
        }

        // Add entities from provided collections
        addEntitiesFromCollections();

        // Set the initial view
        setCurrentView(currentViewIndex);

//        // Set the scene for the graphicsView
//        graphicsView->setScene(scene);


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
//    QGraphicsView* graphicsView;
    std::vector<std::unique_ptr<ViewType>> views;
    const std::vector<EnemyModel*>& enemyModels;
    const std::vector<TileModel*>& tileModels;
    const std::vector<ProtagonistModel*>& protagonistModels;

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

    // Function to add entities from collections to the current view
    void addEntitiesFromCollections() {
        if (currentViewIndex < views.size()) {
            auto& currentView = views[currentViewIndex];

            // Add EnemyModels
            for (const auto& enemyModel : enemyModels) {
                currentView->addEntity(*enemyModel);
            }

            // Add TileModels
            for (const auto& tileModel : tileModels) {
                currentView->addEntity(*tileModel);
            }

            // Add ProtagonistModels
            for (const auto& protagonistModel : protagonistModels) {
                currentView->addEntity(*protagonistModel);
            }

//            scene = &(*currentView);
//            scene = currentView.get();
        }
    }
};

#endif // VIEWCONTROLLER_H
