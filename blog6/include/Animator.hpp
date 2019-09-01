#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

class Animator {
public:
    struct Animation {
        std::string m_Name;
        std::string m_TextureName;
        std::vector<sf::IntRect> m_Frames;
        sf::Time m_Duration;
        bool m_Looping;

        Animation(std::string const& name, std::string const& textureName, 
            sf::Time const& duration, bool looping)
        : m_Name(name), m_TextureName(textureName),
        m_Duration(duration), m_Looping(looping) {}

        void AddFrames(sf::Vector2i const& startFrom, 
            sf::Vector2i const& frameSize, unsigned int frames) {

            sf::Vector2i current = startFrom;
            for (unsigned int i = 0; i < frames; i++) {
                m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
                current.x += frameSize.x;
            }
        }
    };

    Animator(sf::Sprite& sprite);

    Animator::Animation& CreateAnimation(std::string const& name,
        std::string const& textureName, sf::Time const& duration, bool loop = false);

    void Update(sf::Time const& dt);

    // 是否切换成功
    bool SwitchAnimation(std::string const& name);

    std::string GetCurrentAnimationName() const;

private:
    Animator::Animation* FindAnimation(std::string const& name);

    void SwitchAnimation(Animator::Animation* animation);

    sf::Sprite& m_Sprite;
    sf::Time m_CurrentTime;
    std::list<Animator::Animation> m_Animations;
    Animator::Animation* m_CurrentAnimation;

};

#endif


