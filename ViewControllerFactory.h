#ifndef VIEWCONTROLLERFACTORY_H
#define VIEWCONTROLLERFACTORY_H

#include <memory>
#include "ViewType.h"

class ViewController; // Forward declaration

class ViewControllerFactory {
public:
    virtual ~ViewControllerFactory() {}
    virtual std::unique_ptr<ViewController> createViewController(ViewType type) = 0;
};

#endif // VIEWCONTROLLERFACTORY_H
