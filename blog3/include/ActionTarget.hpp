#ifndef ACTIONTARGET_HPP
#define ACTIONTARGET_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <list>
#include "ActionMap.hpp"

template<typename T = int>
class ActionTarget {
public:
    ActionTarget(const ActionTarget<T> &) = delete;
    ActionTarget<T> &operator=(const ActionTarget<T> &) = delete;

    using FuncType = std::function<void(const sf::Event &event)>;

    ActionTarget(const ActionMap<T> &map);

    bool processEvent(const sf::Event &event) const;
    void processEvents() const;

    void bind(const T &key, const FuncType &callback);
    void unbind(const T &key);

private:
    std::list<std::pair<T, FuncType>> _eventsRealTime;
    std::list<std::pair<T, FuncType>> _eventsPoll;

    const ActionMap<T> &_actionMap;
};

#endif