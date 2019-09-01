#include "Animator.hpp"
#include "AssetManager.hpp"

Animator::Animator(sf::Sprite& sprite)
: m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr) {}

Animator::Animation& Animator::CreateAnimation(std::string const& name,
        std::string const& textureName, sf::Time const& duration, bool loop) {
    
    m_Animations.push_back(
        Animator::Animation(name, textureName, duration, loop));

    if (m_CurrentAnimation == nullptr)
        SwitchAnimation(&m_Animations.back());

    return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation) {
    // 改变精灵的纹理
    if (animation != nullptr) {
        m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
    }
    m_CurrentAnimation = animation;
    m_CurrentTime = sf::Time::Zero; // 重置时间
}

bool Animator::SwitchAnimation(std::string const& name) {
    auto animation = FindAnimation(name);
    if (animation != nullptr) {
        SwitchAnimation(animation);
        return true;
    }
    return false;
}

Animator::Animation* Animator::FindAnimation(std::string const& name) {
    for (auto it = m_Animations.begin(); it != m_Animations.end(); it++) {
        if (it->m_Name == name) {
            return &*it;
        }
    }
    return nullptr;
}

std::string Animator::GetCurrentAnimationName() const {
    if (m_CurrentAnimation != nullptr) {
        return m_CurrentAnimation->m_Name;
    }
    return "";
}

void Animator::Update(sf::Time const& dt) {
    if (m_CurrentAnimation == nullptr) return ;

    m_CurrentTime += dt;

    // 获取当前帧
    float scaledTime = m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds();
    int numFrames = m_CurrentAnimation->m_Frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);


    // 如果动画在进行，则计算当前帧
    if (m_CurrentAnimation->m_Looping) {
        currentFrame %= numFrames;
    } else if (currentFrame >= numFrames) { // 如果当前帧不小于总的帧数，设为最后一帧
        currentFrame = numFrames-1;
    }

    m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}
